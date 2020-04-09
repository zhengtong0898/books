// ��07: ��дһ��ģ�庯�� mismatch, ����ֵ��ʹ����ʽ a[i] != b[i] ��������С����i, 0 <= i < n;
// ����: ��дһ��ģ�庯�� mismatch, ���ص�һ�� a[i] != b[i] ��������ֵ.
#include <iostream>

template<typename T>
int mismatch(T* a, T* b, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) continue;
        return i;
    }
    return n;
}


int test_mismatch(void) {

    int a_arr[] = { 1,2,6,4,5 };
    int b_arr[] = { 1,2,3,4,5,6,7 };
    int a_length = sizeof(a_arr) / sizeof(a_arr[0]);
    int b_length = sizeof(b_arr) / sizeof(b_arr[0]);
    int min_length = a_length > b_length ? b_length : a_length;
    int hint = mismatch(a_arr, b_arr, min_length);
    std::cout << "hint: " << hint << std::endl;

    return 0;
}