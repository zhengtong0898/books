#include <iostream>
#include <vector>
#include <algorithm>


// ��20_3: ��д�ǵݹ麯������쳲�����(Fibonacci)F_n. 
//         ��ÿ��쳲�������, ��Ĵ���Ӧ��ֻ����һ��.
// 
// ��ʽ����: F0 = 0, F1 = 1; Fn = F(n-1) + F(n-2) n > 1;
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

