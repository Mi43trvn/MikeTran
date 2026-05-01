#include <iostream>
#include <vector>

int main() {
    //initialize the two vectors
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    //remember original size of numbers1
    std::size_t originalSize = numbers1.size();

    //resize numbers1 to hold all elements after interlacing
    numbers1.resize(originalSize + numbers2.size());

    //set up iterators
    auto it1 = numbers1.begin();  // iterator into numbers1
    auto it2 = numbers2.begin();  // iterator into numbers2

    // first insertion point is after the first element of numbers1
    if (it1 != numbers1.end()) {
        ++it1;
    }

    //interlace numbers2 into numbers1 using insert and iterators
    std::size_t insertedCount = 0;

    while (it2 != numbers2.end() && insertedCount < originalSize) {
        // insert current element from numbers2 at position it1
        it1 = numbers1.insert(it1, *it2);
        ++it2;
        ++insertedCount;

        // move it1 forward: skip inserted element
        if (it1 != numbers1.end()) {
            ++it1;
        }
        // skip next original element
        if (it1 != numbers1.end()) {
            ++it1;
        }
    }

    //print the interlaced vector
    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
