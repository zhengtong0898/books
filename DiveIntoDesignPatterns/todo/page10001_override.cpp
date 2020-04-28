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
 * ����: override ��ʲô��˼?
 * 
 * ��: ���߶�����������ĸ�����һ�����⺯��, 
 *       д override �Ͳ�д override ��һ����Ч��.
 * 
 * �ο�: https://stackoverflow.com/a/18198377/12353483
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
    ddo.foo();              // д�� override
    ddo.bar();              // ûд override

    // output:
    // DerivedOne: foo
    // DerivedOne : two

    return 0;
}
