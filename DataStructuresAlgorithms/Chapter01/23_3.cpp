#include <iostream>


// 题 23_3:
// 编写一个C++递归函数计算gcd(x,y).


int gcd(int x, int y) {
    if (y <= 0) return x;
    int new_y = x % y;
    return gcd(y, new_y);
}


int test_gcd(void) {
    std::cout << gcd(20, 30) << std::endl;     // 10
    std::cout << gcd(112, 42) << std::endl;    // 14
    return 0;
}
