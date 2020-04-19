#include <iostream>


/******************************************************************************
*
* 问题: 一个抽象类是否可以定义一个抽象函数, 由派生来通过覆盖实现时返回不同类型?
*
* 答案: 不可以, 这将产生二义性(ambiguous); 编译器对覆盖(多态)的要求是, 
*       参数数量和参数类型必须保持一致, 返回类型也必须返回一致.
*
* 但是: 有一种特殊情况, 派生类在覆盖时可以返回"不同类型", 这种类型叫做: CoVariant.
*       这些"不同类型"必须继承同一个祖先, 并且在抽象类的抽象方法的返回值类型定义上
*       一定要是这个祖先并且是指针类型, 以下面程序代码为例.
*
*******************************************************************************/
class Interface109 {
public:
    virtual ~Interface109() {}
    virtual void set_foo() = 0;
};


class Small109 : public Interface109 {
public:
    void set_small_foo() {
        std::cout << "set small 109 foo" << std::endl;
    }
    void set_foo() {
        std::cout << "Small109 foo" << std::endl;
    }
};


class Big109 : public Interface109 {
public:
    void set_bigfoo() {
        std::cout << "set big 109 foo" << std::endl;
    }
    void set_foo() {
        std::cout << "Big109 foo" << std::endl;
    }
};


class AbstractClass109 {
public:
    virtual ~AbstractClass109() {}
    virtual Interface109 * get_result() = 0;
};


class SmallDerivedClass109 : public AbstractClass109 {
public:
    Small109 * get_result() {
        return new Small109;
    }
};


class BigDerivedClass109 : public AbstractClass109 {
public:
    Big109 * get_result() {
        return new Big109;
    }
};



int test_return_difftype109(void) {

    AbstractClass109 * ac = new SmallDerivedClass109;
    Interface109 * is109 = ac->get_result();
    Small109 * s109 = dynamic_cast<Small109*>(is109);
    s109->set_foo();
    s109->set_small_foo();


    std::cout << "return difftype" << std::endl;

    return 0;
}