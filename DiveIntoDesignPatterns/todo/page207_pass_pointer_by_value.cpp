#include <iostream>

/******************************************************************************
*
* 问题: 指针当作值变量传递给函数, 会赋值一个指针出来吗?
*
* 答案: 会, 因为指针是一个long类型, 属于常量数据, 所以会对指针进行复制.
*      但是, 指针指向的 数据/对象 的地址不会发生变化.
*
*******************************************************************************/
class Person207 {

};


void do_nothing(Person207 * p) {
    std::cout << "inside do_nothing:  p: " <<  p << std::endl;              // 00000219B4420BC0
    std::cout << "inside do_nothing: &p: " << &p << std::endl;              // 00000084F16FF5F0
}


int test_Person207(void) {

    Person207 * p = new Person207{};

    std::cout << "inside main:  p: " << p << std::endl;                     // 00000219B4420BC0
    std::cout << "inside main: &p: " << &p << std::endl;                    // 00000084F16FF618
    do_nothing(p);

    std::cout << "finish" << std::endl;
    delete p;

    return 0;
}