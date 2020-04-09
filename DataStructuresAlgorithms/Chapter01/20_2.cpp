#include <iostream>


// 题20_2: 证明 题20_1 中编写的代码, 当计算F_n且n>2时, F_i的计算多于一次.
//
// 回答: 这还需要证明? 只要n-1和n-2大于1时, 函数体内明显调用了两次fibonacci(实际上远不止两次) ...
// 证明: 那我就打印出某个数字来验证该数字计算了多次, 暂定数字: 5
int fibonacci_20_2(int n) {
    if (n <= 1) return n;
    if (n == 5) std::cout << "hint: 5" << "; n: " << n << std::endl;   
    return fibonacci_20_2(n - 1) + fibonacci_20_2(n - 2);
}

int test_fibonacci_20_2(void) {
    fibonacci_20_2(10);
    return 0;
}
