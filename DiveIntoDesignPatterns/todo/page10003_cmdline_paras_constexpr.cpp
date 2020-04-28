#include <iostream>


/*
 *
 * 问题: 命令行参数能不能用 constexpr 编译期来分流?
 *  
 * 回答: 不能, 因为 char ** 不是一个constexpr 变量.
 * 
 */


int test_page10003(int argc, char ** argv) {

    // 编译期报错: 
    // error C2131 : expression did not evaluate to a constant
    // message : failure was caused by a read of a variable outside its lifetime
    // message : see usage of 'argc'
    //
    // 报错信息: argc 在编译期是一个还没有创建的对象(a variable outside its lifetime).
    // static_assert(argc == 1);

    return 0;
}