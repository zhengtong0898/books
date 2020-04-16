#include <iostream>


/******************************************************************************
* 抽象类(纯虚函数)                                                             *
* 语法: virtual return-type function() = 0;                                   *
* 抽象类不能被实例化, 也不能声明成员变量, 也不能对声明的纯虚函数做实现             *
* 抽象类只能通过继承, 由派生类来实现这些纯虚函数                                 *
*                                                                             *
* 这种表现与OOP的接口概念是一致的, 因此在c++中抽象类就是接口.                     *
*                                                                             *
* 参考: https://en.cppreference.com/w/cpp/language/abstract_class             *
*******************************************************************************/
class AbstractClass074 {
public:
    // 抽象类必须声明虚析构函数, 这样才能通过vtable找到派生类并触发派生类的析构函数.
    virtual ~AbstractClass074() {};                 
    virtual void hello() = 0;
};


class AbstractChildren : public AbstractClass074 {
public:
    virtual ~AbstractChildren() {
        std::cout << "AbstractChildren destroy" << std::endl;
    }

    virtual void hello() {
        std::cout << "hello" << std::endl;
    }
};


int test_AbstractClass074(void) {

    AbstractClass074 * abs_obj = new AbstractChildren;
    abs_obj->hello();
    delete abs_obj;
    std::cout << "hello world!" << std::endl;

    return 0;
}