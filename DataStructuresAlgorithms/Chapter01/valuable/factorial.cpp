#include <iostream>


// factorial: 阶乘(递归)
// 递归函数会挂起当前函数, 进入self-call的那个函数, 一直到尽头,
// 然后在尽头出计算出该层的结果: 1, 与上一层的结果进行计算并返回结果, 一直返回到顶层. 
int factorial(int n) {
    std::cout << "一直进入到尽头: " << n << std::endl;
    if (n <= 1) {
        std::cout << "层数: " << n << ", 上一层结果是: " << 0 << "; 当前结果是: " << n << std::endl;
        return 1;
    }else {
        auto previous_n = factorial(n - 1);
        auto result = n * previous_n;
        std::cout << "层数: " << n << ", 上一层结果是: " << previous_n << "; 当前结果是: " << result << std::endl;
        return result;
    }
}


int test_factorial(void) {
    std::cout << factorial(5) << std::endl;
    return 0;
}


// output
// 一直进入到尽头: 5
// 一直进入到尽头 : 4
// 一直进入到尽头 : 3
// 一直进入到尽头 : 2
// 一直进入到尽头 : 1
// 层数 : 1, 上一层结果是 : 0; 当前结果是: 1
// 层数 : 2, 上一层结果是 : 1; 当前结果是: 2
// 层数 : 3, 上一层结果是 : 2; 当前结果是: 6
// 层数 : 4, 上一层结果是 : 6; 当前结果是: 24
// 层数 : 5, 上一层结果是 : 24; 当前结果是: 120
// 120