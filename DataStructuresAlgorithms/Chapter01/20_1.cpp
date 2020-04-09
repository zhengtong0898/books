#include <iostream>


// ��20_1: ��д�ݹ麯������쳲�������(Fibonacci)F_n
// Ҫ����û���ἰ��������, ���Բ�ȡĬ�ϵ� F_0=0, F_1=1
int fibonacci_20_1(int n) {
    if (n <= 1) return n;   // F_0=0, F_1=1
    return fibonacci_20_1(n - 1) + fibonacci_20_1(n - 2);
}


int test_fibonacci_20_1(void) {
    fibonacci_20_1(0);     // 0
    fibonacci_20_1(1);     // 1
    fibonacci_20_1(2);     // 1
    fibonacci_20_1(3);     // 2
    fibonacci_20_1(4);     // 3
    fibonacci_20_1(5);     // 5
    fibonacci_20_1(6);     // 8
    fibonacci_20_1(7);     // 13
    fibonacci_20_1(8);     // 21
    fibonacci_20_1(9);     // 34
    fibonacci_20_1(10);    // 55

    return 0;
}
