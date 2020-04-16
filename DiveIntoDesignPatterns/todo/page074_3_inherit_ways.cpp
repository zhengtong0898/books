#include <iostream>
#include <string>


/******************************************************************************
* 公有继承                                                                     *
* 基类的公有数据和公有方法,将成为派生类的公有数据和公有方法.                      *
* 基类的保护数据和保护方法,将成为派生类的保护数据和保护方法.                      *
* 基类的私有数据和私有方法,不会继承给派生类              .                       *
*******************************************************************************/
class BasePublic {
private:
    std::string age;
protected:
    std::string gender;
public:
    std::string name;
    BasePublic(std::string n): name(n), gender("a"), age("b") {}
    virtual ~BasePublic() {}
};


class ChildrenPublic : public BasePublic {
public:
    ChildrenPublic(std::string n): BasePublic(n) {}
    ~ChildrenPublic() {
        std::cout << "destroy" << std::endl;
    }

    void hello() {
        // 派生类无法访问基类的 age 成员变量.
        std::cout << "hello: name: " << name << "; gender: " << gender << std::endl;
    }
};


int test_public_inherit(void) {

    BasePublic * intf = new ChildrenPublic("ssss");
    ChildrenPublic * cd = dynamic_cast<ChildrenPublic*>(intf);
    cd->hello();
    delete intf;
    std::cout << "hello world!" << std::endl;

    return 0;
}


/******************************************************************************
* 私有继承                                                                     *
* 基类的公有数据和公有方法,将成为派生类的私有数据和私有方法.                      *
* 基类的保护数据和保护方法,将成为派生类的私有数据和私有方法.                      *
* 基类的私有数据和私有方法,不会继承给派生类              .                       *
*******************************************************************************/


/******************************************************************************
* 保护继承                                                                     *
* 基类的公有数据和公有方法,将成为派生类的保护数据和保护方法.                      *
* 基类的保护数据和保护方法,将成为派生类的保护数据和保护方法.                      *
* 基类的私有数据和私有方法,不会继承给派生类              .                       *
*******************************************************************************/


/******************************************************************************
* 虚拟继承                                                                     *
* 语法: class DerivedClass: public virtual BaseClass {}                       *
*                                                                             *
* 虚拟继承是为了解决多继承里面的相同祖先问题, 声明了虚拟继承后编译器将会           *
* 自行检测多个继承对象里面是否存在相同的祖先, 如果存在则化一.                     *
*******************************************************************************/
