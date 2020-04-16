#include <iostream>


/******************************************************************************
* 常规的继承, 多态下的派生类的析构函数无法触发.                                  *
*******************************************************************************/
class BaseInherit01 {
public:
    BaseInherit01() {
        std::cout << "BaseInherit01 init" << std::endl;
    }

    ~BaseInherit01() {
        std::cout << "BaseInherit01 Destroy" << std::endl;
    }
};



class DerivedClass01: public BaseInherit01 {
public:
    DerivedClass01(): BaseInherit01() {
        std::cout << "DerivedClass01 init" << std::endl;
    }
    ~DerivedClass01() {
        std::cout << "DerivedClass01 Destroy" << std::endl;
    }
};



/******************************************************************************
* 创建常规继承的对象,                                                          *
* 基类的构造函数可以正常触发, 派生类的构造函数也能正常触发.                       *
* 基类的析构函数可以正常触发, 派生类的析构函数也能正常触发.                       *
*******************************************************************************/
int test_basic_init_and_destroy(void) {

    DerivedClass01 * dc = new DerivedClass01;
    delete dc;
    std::cout << "cast inderit" << std::endl;

    // output:
    // 
    // BaseInherit01 init                           触发 基类   构造函数
    // DerivedClass01 init                          触发 派生类 构造函数
    // DerivedClass01 Destroy                       触发 派生类 析构函数
    // BaseInherit01 Destroy                        触发 基类   析构函数
    // cast inderit

    return 0;
}


/******************************************************************************
* 创建多态继承的对象,                                                          *
* 基类的构造函数可以正常触发, 派生类的构造函数正常触发.                          *
* 基类的析构函数可以正常触发, 派生类的析构函数不能正常触发.                       *
*******************************************************************************/
int test_polymorphic_init_and_destroy(void) {

    BaseInherit01 * dc = new DerivedClass01;    //  多态
    delete dc;
    std::cout << "cast inderit" << std::endl;

    // output
    // BaseInherit01 init                           触发 基类   构造函数
    // DerivedClass01 init                          触发 派生类 构造函数
    // BaseInherit01 Destroy                        触发 基类   析构函数
    // cast inderit
    //
    // 注意: 这里少触发了派生类的析构函数.

    return 0;
}


/******************************************************************************
* 解决多态继承无法触发派生类析构函数问题, 采用 virtual 声明析构函数.              *
*******************************************************************************/
class BasePolymorphic01 {
public:
    BasePolymorphic01() {
        std::cout << "BasePolymorphic01 init" << std::endl;
    }
    virtual ~BasePolymorphic01() {
        std::cout << "BasePolymorphic01 Destroy" << std::endl;
    }
};


class DerivedPolymorphic01: public BasePolymorphic01 {
public:
    DerivedPolymorphic01() {
        std::cout << "DerivedPolymorphic01 init" << std::endl;
    }
    ~DerivedPolymorphic01() {
        std::cout << "DerivedPolymorphic01 Destroy" << std::endl;
    }
};


int test_polymorphic2_init_and_destroy(void) {

    BasePolymorphic01 * bp = new DerivedPolymorphic01;
    delete bp;

    // output
    // BasePolymorphic01 init                       触发 基类   构造函数
    // DerivedPolymorphic01 init                    触发 派生类 构造函数
    // DerivedPolymorphic01 Destroy                 触发 派生类 析构函数
    // BasePolymorphic01 Destroy                    触发 基类   析构函数
    // cast inderit

    std::cout << "cast inderit" << std::endl;

    return 0;
}
