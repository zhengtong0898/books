#include <iostream>


// factorial: �׳�(�ݹ�)
// �ݹ麯�������ǰ����, ����self-call���Ǹ�����, һֱ����ͷ,
// Ȼ���ھ�ͷ��������ò�Ľ��: 1, ����һ��Ľ�����м��㲢���ؽ��, һֱ���ص�����. 
int factorial(int n) {
    std::cout << "һֱ���뵽��ͷ: " << n << std::endl;
    if (n <= 1) {
        std::cout << "����: " << n << ", ��һ������: " << 0 << "; ��ǰ�����: " << n << std::endl;
        return 1;
    }else {
        auto previous_n = factorial(n - 1);
        auto result = n * previous_n;
        std::cout << "����: " << n << ", ��һ������: " << previous_n << "; ��ǰ�����: " << result << std::endl;
        return result;
    }
}


int test_factorial(void) {
    std::cout << factorial(5) << std::endl;
    return 0;
}


// output
// һֱ���뵽��ͷ: 5
// һֱ���뵽��ͷ : 4
// һֱ���뵽��ͷ : 3
// һֱ���뵽��ͷ : 2
// һֱ���뵽��ͷ : 1
// ���� : 1, ��һ������ : 0; ��ǰ�����: 1
// ���� : 2, ��һ������ : 1; ��ǰ�����: 2
// ���� : 3, ��һ������ : 2; ��ǰ�����: 6
// ���� : 4, ��һ������ : 6; ��ǰ�����: 24
// ���� : 5, ��һ������ : 24; ��ǰ�����: 120
// 120