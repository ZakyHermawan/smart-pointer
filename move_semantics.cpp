#include <iostream>

using std::cout;
using std::endl;
using std::cin;


template <typename T>
class Auto_ptr
{
private:
    T* m_ptr;

public:
    Auto_ptr(T* ptr = nullptr) : m_ptr{ ptr }
    {

    }

    Auto_ptr(const Auto_ptr& a) = delete;
    Auto_ptr operator=(const Auto_ptr& a) = delete;

    Auto_ptr& operator=(Auto_ptr&& object) noexcept {
        if (&object == this) {
            return *this;
        }
        cout << "pindah woi" << endl;
        delete m_ptr;
        m_ptr = object.m_ptr;
        object.m_ptr = nullptr;
        return *this;
    }

    Auto_ptr(Auto_ptr&& object) noexcept
        : m_ptr(object.m_ptr) {
        object.m_ptr = nullptr;
    }


    ~Auto_ptr() {
        delete m_ptr;
    }

    bool isNull() const {
        return m_ptr == nullptr;
    }


    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

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
    Auto_ptr<Resource> r(new Resource());
    Auto_ptr<Resource> r2;


    cout << "Is r  null ? " << (r.isNull() ? "Yes" : "No") << endl;
    cout << "Is r2  null ? " << (r2.isNull() ? "Yes" : "No") << endl;

    cout << "Transfer ownership..." << endl;

    r2 = std::move(r);

    cout << "Is r  null ? " << (r.isNull() ? "Yes" : "No") << endl;
    cout << "Is r2  null ? " << (r2.isNull() ? "Yes" : "No") << endl;


    return 0;
}