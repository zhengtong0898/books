#include <iostream>


/******************************************************************************
*
* 问题: 同类对象的私有成员可以相互访问吗?
* 回答: 可以
*
*******************************************************************************/
class Person121 {
private:
    std::string name;
    
public:
    Person121(std::string n): name(n) {}
    void show_other_person_private_member(Person121& rhs) {
        static int count = 0;
        if (count > 3) return void();
        count += 1;
        std::cout << rhs.name << std::endl;
        // 相互访问(内嵌/递归)
        rhs.show_other_person_private_member(*this);
    }
};


int main(void) {

    Person121 a("zhangsan");
    Person121 b("lisi");
    a.show_other_person_private_member(b);


    std::cout << "access private" << std::endl;

    return 0;
}