#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::cin;


class Resource
{
public:
    Resource() {
        cout << "Resource Acquired" << endl;
    }
    ~Resource() {
        cout << "Resource Destroyed" << endl;
    }
    void hello() { cout << "hello" << endl; }
};

int main() {
    std::shared_ptr<Resource> ptr(new Resource());
    {
        std::shared_ptr ptr2(ptr);
        cout << "kill one shared_ptr" << endl;
    }
    cout << "kill another shared_ptr" << endl;



    return 0;
}