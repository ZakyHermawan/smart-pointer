#include <iostream>
#include <exception>

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

    Auto_ptr& operator=(Auto_ptr& object) {
        if (&object == this) {
            return *this;
        }
        if (m_ptr != nullptr) {
            delete m_ptr;
        }
        m_ptr = object.m_ptr;
        object.m_ptr = nullptr;
        return *this;
    }

    Auto_ptr(Auto_ptr& object) {
        m_ptr = object.m_ptr;
        if (object.m_ptr != nullptr) {
            object.m_ptr = nullptr;
        }
    }

    ~Auto_ptr() {
        delete m_ptr;
    }

    bool isNull() {
        if (m_ptr == nullptr)
            return true;
        return false;
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

    cout << "Apakah r  null ? " << (r.isNull() ? "Yes" : "No") << endl;
    cout << "Apakah r2  null ? " << (r2.isNull() ? "Yes" : "No") << endl;

    cout << "Transfering ownership..." << endl;

    r2 = r;

    cout << "Apakah r  null ? " << (r.isNull() ? "Yes" : "No") << endl;
    cout << "Apakah r2  null ? " << (r2.isNull() ? "Yes" : "No") << endl;

    return 0;
}