

// 程序 1-11
template<typename T>
void make2dArray(T**& x, int numberOfRows, int numberOfColumns) {
    x = new T * [numberOfRows];

    for (int i = 0; i < numberOfRows; ++i) {
        x[i] = new T[numberOfColumns];
    }
}   


int test_make2dArray(void) {
    int** arr2d;
    const int numberOfRows = 5;
    const int numberOfColumns = 5;
    make2dArray(arr2d, numberOfRows, numberOfColumns);
    return 0;
}


// 题12: 
// 为程序 make2dArray(程序1-11)编写一个通用型算法, 它的第三个参数不是整数numberOfColumns,
// 而是一维数组rowSize. 它创建一个二维数组, 第i行的列数是rowSize[i].
template<typename T>
void make2dArray_modify(T**& x, int numberOfRows, int * rowSize) {
    x = new T * [numberOfRows];

    for (int i = 0; i < numberOfRows; ++i) {
        x[i] = new T[rowSize[i]];
    }
}


int test_make2dArray_modify(void) {
    int** arr2d;
    const int numberOfRows = 5;
    int rowSize[numberOfRows] = { 5,6,7,8,9 };
    make2dArray_modify(arr2d, numberOfRows, rowSize);
    return 0;
}