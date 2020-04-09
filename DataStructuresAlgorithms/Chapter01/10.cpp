// 程序 1-8
 int abc_1_8(int a, int b, int c) {
     if (a <= 0 || b <= 0 || c <= 0) throw "All parameters should be > 0";
     return a + b * c;
 }


// 题10: 修改程序 1-8, 使抛出的异常类型是整型. 如果 a、b、c 都小于0, 那么抛出的异常值是1; 如果 a、b、c 都等于0, 那么抛出的异常值是2; 否则没有异常.
//       编写一个主函数, 应用修改后的代码; 若有异常抛出, 则捕捉异常; 根据异常值输出信息.
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
