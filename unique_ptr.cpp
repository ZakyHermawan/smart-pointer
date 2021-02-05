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
};

int main() {
    std::unique_ptr<Resource> r(new Resource());
    std::unique_ptr<Resource> r2;


    cout << "Is r  null ? " << (static_cast<bool>(r) ? "Yes" : "No") << endl;
    cout << "Is r2  null ? " << (static_cast<bool>(r2) ? "Yes" : "No") << endl;

    cout << "Transfer ownership..." << endl;

    r2 = std::move(r);

    cout << "Is r  null ? " << (static_cast<bool>(r) ? "Yes" : "No") << endl;
    cout << "Is r2  null ? " << (static_cast<bool>(r2) ? "Yes" : "No") << endl;

    return 0;
}