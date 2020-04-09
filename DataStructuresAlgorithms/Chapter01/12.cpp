

// ���� 1-11
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


// ��12: 
// Ϊ���� make2dArray(����1-11)��дһ��ͨ�����㷨, ���ĵ�����������������numberOfColumns,
// ����һά����rowSize. ������һ����ά����, ��i�е�������rowSize[i].
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