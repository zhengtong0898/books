// ���� 1-8
 int abc_1_8(int a, int b, int c) {
     if (a <= 0 || b <= 0 || c <= 0) throw "All parameters should be > 0";
     return a + b * c;
 }


// ��10: �޸ĳ��� 1-8, ʹ�׳����쳣����������. ��� a��b��c ��С��0, ��ô�׳����쳣ֵ��1; ��� a��b��c ������0, ��ô�׳����쳣ֵ��2; ����û���쳣.
//       ��дһ��������, Ӧ���޸ĺ�Ĵ���; �����쳣�׳�, ��׽�쳣; �����쳣ֵ�����Ϣ.
int abc_1_8_modify(int a, int b, int c) {
    if (a < 0  && b < 0  && c < 0)  throw 1;
    if (a == 0 && b == 0 && c == 0) throw 2;
    return a + b * c;
}


int test_abc_1_8_modify(void) {
    abc_1_8_modify(0, 0, 0);
    abc_1_8_modify(-1, -1, -1);
    abc_1_8_modify(1, 1, 1);
    return 0;
}
