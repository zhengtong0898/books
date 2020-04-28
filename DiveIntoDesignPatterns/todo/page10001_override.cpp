#include <iostream>


class Base222 {
public:
    virtual 
    ~Base222() {};

    virtual void 
    foo() = 0;

    virtual void 
    bar() = 0;

};


/******************************************************************************
 *
 * 问题: override 是什么意思?
 * 
 * 答案: 告诉读者这个函数的父类是一个虚拟函数, 
 *       写 override 和不写 override 是一样的效果.
 * 
 * 参考: https://stackoverflow.com/a/18198377/12353483
 *
 ******************************************************************************/
class DerivedOne : Base222 {
public:
    DerivedOne() : Base222() {}

    void 
    foo() override {
        std::cout << "DerivedOne: foo" << std::endl;
    }

    void 
    bar() {
        std::cout << "DerivedOne: two" << std::endl;
    }
};


int test_DerivedOne(void) {

    DerivedOne ddo {};
    ddo.foo();              // 写了 override
    ddo.bar();              // 没写 override

    // output:
    // DerivedOne: foo
    // DerivedOne : two

    return 0;
}
