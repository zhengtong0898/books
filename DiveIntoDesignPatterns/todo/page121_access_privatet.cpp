#include <iostream>


/******************************************************************************
*
* ����: ͬ������˽�г�Ա�����໥������?
* �ش�: ����
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
        // �໥����(��Ƕ/�ݹ�)
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