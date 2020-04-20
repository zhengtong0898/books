#include <iostream>
#include <string>


/******************************************************************************
*
* ²Î¿¼: https://stackoverflow.com/a/1008289/12353483
*
*******************************************************************************/
class Singleton {
private:
    Singleton() {}

public:
    Singleton(const Singleton & s) = delete;
    void operator=(const Singleton & s) = delete;

public:
    static Singleton & get_instance() {
        static Singleton singleton{};
        return singleton;
    }
};


int main(void) {
    auto & s = Singleton::get_instance();
    auto & b = Singleton::get_instance();
    std::cout << &s << std::endl;
    std::cout << &b << std::endl;

    std::cout << "singleton 2" << std::endl;

    return 0;
}