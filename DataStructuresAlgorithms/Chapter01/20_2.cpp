#include <iostream>


// ��20_2: ֤�� ��20_1 �б�д�Ĵ���, ������F_n��n>2ʱ, F_i�ļ������һ��.
//
// �ش�: �⻹��Ҫ֤��? ֻҪn-1��n-2����1ʱ, �����������Ե���������fibonacci(ʵ����Զ��ֹ����) ...
// ֤��: ���Ҿʹ�ӡ��ĳ����������֤�����ּ����˶��, �ݶ�����: 5
int fibonacci_20_2(int n) {
    if (n <= 1) return n;
    if (n == 5) std::cout << "hint: 5" << "; n: " << n << std::endl;   
    return fibonacci_20_2(n - 1) + fibonacci_20_2(n - 2);
}

int test_fibonacci_20_2(void) {
    fibonacci_20_2(10);
    return 0;
}
