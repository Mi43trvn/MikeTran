#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

enum class Suit { Hearts, Diamonds, Clubs, Spades};
enum class Rank { 
    Two = 2, Three, Four, Five, 
    Six, Seven, Eight, Nine, Ten, 
    Jack = 10, Queen = 10, King = 10, Ace = 11 
};
struct Card {
    Suit suit;
    Rank rank;
};

std::string suitToString(Suit suit) {
    switch (suit) {
        case Suit::Hearts: return "Hearts";
        case Suit::Diamonds: return "Diamonds";
        case Suit::Clubs: return "Clubs";
        case Suit::Spades: return "Spades";
    }
    return "";
}
std::string rankToString(Rank rank) {
    switch (rank) {
        case Rank::Jack: return "J";
        //case Rank::Queen: return "Q";
       // case Rank::King: return "K";
        case Rank::Ace: return "A";
        default: return std::to_string(static_cast<int>(rank));
    }
};

void printCard(const Card& card) {
    std::cout << rankToString(card.rank) << " of " << suitToString(card.suit) << std::endl;
}

class Deck {
    private:
    std::vector<Card> cards;

    public:
    Deck() {
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 2; rank <= 14; rank++) {
                cards.push_back({static_cast<Suit>(suit), static_cast<Rank>(rank)});
            }
        }
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    Card draw() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

    bool empty() const {
        return cards.empty();
    }
};

/* int main() {
    Deck deck;
    deck.shuffle();

    std::cout << "Drawing 5 cards:\n";
    for (int i = 0; i < 5; i++) {
        Card card = deck.draw();
        printCard(card);
        std::cout << "\n";
    }

    return 0;
}
*/
class Hand {
private:
    std::vector<Card> cards;

public:
    void addCard(const Card& c) {
        cards.push_back(c);
    }

    int value() const {
        int total = 0;
        int aces = 0;

        for (const Card& c : cards) {
            int r = static_cast<int>(c.rank);

            if (r >= 2 && r <= 10) {
                total += r;
            } else if (r >= static_cast<int>(Rank::Jack) &&
                       r <= static_cast<int>(Rank::King)) {
                total += 10;
            } else if (c.rank == Rank::Ace) {
                total += 11;
                aces++;
            }
        }

        // Adjust Aces from 11 → 1 if needed
        while (total > 21 && aces > 0) {
            total -= 10;
            aces--;
        }

        return total;
    }

    void print() const {
        for (const Card& c : cards) {
            printCard(c);
            std::cout << ", ";
        }
        std::cout << "Value: " << value() << "\n";
    }
};

int main() {
    Deck deck;
    deck.shuffle();

    Hand player;
    Hand dealer;

    // Initial deal
    player.addCard(deck.draw());
    dealer.addCard(deck.draw());
    player.addCard(deck.draw());
    dealer.addCard(deck.draw());

    std::cout << "Dealer shows: ";
    printCard(dealer.draw()); // show only first card
    std::cout << "\n\n";

    std::cout << "Your hand: ";
    player.print();

    // Player turn
    while (true) {
        std::cout << "Hit or stand? (h/s): ";
        char choice;
        std::cin >> choice;

        if (choice == 'h') {
            player.addCard(deck.draw());
            std::cout << "Your hand: ";
            player.print();

            if (player.value() > 21) {
                std::cout << "You bust! Dealer wins.\n";
                return 0;
            }
        } else {
            break;
        }
    }

    // Dealer turn
    std::cout << "\nDealer's hand: ";
    dealer.print();

    while (dealer.value() < 17) {
        dealer.addCard(deck.draw());
        std::cout << "Dealer hits: ";
        dealer.print();
    }

    if (dealer.value() > 21) {
        std::cout << "Dealer busts! You win.\n";
        return 0;
    }

    // Compare hands
    std::cout << "\nFinal Results:\n";
    std::cout << "Your hand: ";
    player.print();
    std::cout << "Dealer's hand: ";
    dealer.print();

    if (player.value() > dealer.value()) {
        std::cout << "You win!\n";
    } else if (player.value() < dealer.value()) {
        std::cout << "Dealer wins.\n";
    } else {
        std::cout << "Push (tie).\n";
    }

    return 0;
}