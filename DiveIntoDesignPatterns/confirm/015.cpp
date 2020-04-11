#include <iostream>
#include <string>
#include <assert.h>


class Animal015 {
private:
    std::string gender;
protected:
    std::string name;
public:
    Animal015(std::string n, std::string g): name(n), gender(g) {}
};


class Cat015: public Animal015 {
public:
    Cat015(std::string n, std::string g): Animal015(n, g) {}
    void name_assert(std::string expect) {
        assert(name == expect);           // 继承能访问基类protected属性
        // assert(gender == expect);      // 继承不能访问基类private属性(编译期报错).
    }
};


class SubCat015 : public Cat015 {
public:
    SubCat015(std::string n, std::string g): Cat015(n, g) {}
    void name_assert(std::string expect) {
        assert(name == expect);           // 多级继承也能访问基类protected属性
    }
};


int test_Animal015(void) {

    auto cat = Cat015("paofu", "male");
    cat.name_assert("paofu");

    auto sub_cat = SubCat015("baicun", "female");
    sub_cat.name_assert("baicun");

    return 0;
}