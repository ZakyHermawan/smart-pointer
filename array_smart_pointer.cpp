#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::cin;


int main() {
    std::unique_ptr<int[]> ptr(std::make_unique<int[]>(5));
    for (int i{ 0 }; i < 5; ++i) {
        ptr[i] = i + 1;
    }

    for (int i{ 0 }; i < 5; ++i) {
        cout << ptr[i] << endl;
    }

    return 0;
}