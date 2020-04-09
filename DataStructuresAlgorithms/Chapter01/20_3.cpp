#include <iostream>
#include <vector>
#include <algorithm>


// 题20_3: 编写非递归函数计算斐波那契(Fibonacci)F_n. 
//         对每个斐波那契数, 你的代码应该只计算一次.
// 
// 公式定义: F0 = 0, F1 = 1; Fn = F(n-1) + F(n-2) n > 1;
long long fibonacci_20_3(int n) {
    if (n <= 1) return n;

    int prev_one = 0, prev_two = 1, current = 0;
    for (int i = 0; i < n; ++i) {
        prev_one = prev_two;
        prev_two = current;
        current = prev_one + prev_two;
    }

    return current;
}


int test_fibonacci_20_3(void) {
    std::cout << fibonacci_20_3(36) << std::endl;
    return 0;
}

