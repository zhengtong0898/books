#include <iostream>

// 题19: 编写非递归程序计算阶乘n!的积.
int factorial_non_recursive(int n) {
    if (n <= 1) return 1;

    int fact = 2;
    for (int i = 3; i <= n; ++i) {                
        fact *= i;
    }
    return fact;
}


int test_factorial_non_recursive(void) {

    std::cout << factorial_non_recursive(5) << std::endl;

    return 0;
}
