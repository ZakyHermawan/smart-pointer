#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Person
{
private:
    std::string m_name;
    std::weak_ptr<Person> m_partner;

public:
    Person(const std::string& name) : m_name{ name }
    {
        cout << m_name << " created" << endl;
    }

    ~Person()
    {
        cout << m_name << " destroyed" << endl;
    }

    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        if (p1 == nullptr || p2 == nullptr)
        {
            return false;
        }
        p1->m_partner = p2;
        p2->m_partner = p1;
        cout << p1->getName() << " is now partnered with " << p2->getName() << endl;

    }

    const std::shared_ptr<Person> getPartner() const { return m_partner.lock(); }
    const std::string& getName() const { return m_name; }

};




int main() {
    std::shared_ptr<Person> nyafi{ std::make_shared<Person>("Nyafi") };
    std::shared_ptr<Person> ricky{ std::make_shared<Person>("Ricky") };

    partnerUp(nyafi, ricky);

    std::shared_ptr<Person> partner{ ricky->getPartner() };
    cout << ricky->getName() << "'s partner is: " << partner->getName() << endl;

    return 0;
}