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

void useResource(Resource* resource) {
    if (resource)
        resource->hello();
}

int main() {
    std::unique_ptr<Resource> r(std::make_unique<Resource>());

    // use get() to get a pointer to the Resource
    useResource(r.get());

    return 0;
}