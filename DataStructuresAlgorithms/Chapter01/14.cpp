#include <iostream>
#include <memory>
#include <algorithm>
#include <map>


// 题14: 
// 编写一个函数 changeLength2D, 它改变一个二维数组的大小(见题13).
template<typename T>
void changeLength2D(T**& originArr, int originRows, int originCols, int newerRows, int newerCols) {

    // new rows
    T ** newerArr = new T * [newerRows];
    // new cols
    for (int i = 0; i < newerRows; ++i) {
        newerArr[i] = new T[newerCols];
    }

    // 取最小的行和最小的列
    int min_rows = originRows < newerRows ? originRows : newerRows;
    int min_cols = originCols < newerCols ? originCols : newerCols;

    // 赋值给新的二维数组
    for (int i = 0; i < min_rows; ++i) {
        for (int j = 0; j < min_cols; ++j) {
            newerArr[i][j] = originArr[i][j];
        }
    }

    // 删除原来的二维数组
    for (int i = 0; i < originRows; ++i) {
        delete[] originArr[i];
    }
    delete[] originArr;

    // 将新的二维数组写回到原来的二维数组
    originArr = newerArr;

    // TODO: 这里如何管理 newerArr 这个指针? 能删除吗?
    // 回答: 这里不能删除newerArr这个二维数组, 
    //       因为它赋值给了 originArr, 要在外部使用完之后才能删除. 
}


int test_changeLength2D() {
    const int originRows = 5;
    const int originCols = 5;
    const int newerRows = 3;
    const int newerCols = 3;

    // 这里没有采用 new , 因此在changeLength2D函数里面不能delete[], 导致无法resize二维数组大小.
    // int originArr[originRows][originCols] = {
    //     {1, 2, 3, 4, 5},
    //     {2, 3, 4, 5, 6},
    //     {3, 4, 5, 6, 7},
    //     {4, 5, 6, 7, 8},
    //     {5, 6, 7, 8, 9},
    // };
    // int * originArr_ptr[originRows] = {
    //     originArr[0],
    //     originArr[1],
    //     originArr[2],
    //     originArr[3],
    //     originArr[4],
    // };
    // int** originArr_ptp = originArr_ptr;


    int ** originArr = new int * [originRows];
    //for (int i = 0; i < originRows; ++i) {
    //    originArr[i] = new int[originCols];
    //}
    //originArr[0][0] = 1;
    //originArr[0][1] = 2;
    //originArr[0][2] = 3;
    //originArr[0][3] = 4;
    //originArr[0][4] = 5;
    //originArr[1][0] = 2;
    //originArr[1][1] = 3;
    //originArr[1][2] = 4;
    //originArr[1][3] = 5;
    //originArr[1][4] = 6;
    //originArr[2][0] = 3;
    //originArr[2][1] = 4;
    //originArr[2][2] = 5;
    //originArr[2][3] = 6;
    //originArr[2][4] = 7;
    //originArr[3][0] = 4;
    //originArr[3][1] = 5;
    //originArr[3][2] = 6;
    //originArr[3][3] = 7;
    //originArr[3][4] = 8;
    //originArr[4][0] = 5;
    //originArr[4][1] = 6;
    //originArr[4][2] = 7;
    //originArr[4][3] = 8;
    //originArr[4][4] = 9;

    // TODO: 这里如何取简化指针的创建和数据填充的代码?
    // FIXED: 优化数据填充.
    originArr[0] = new int[5]{ 1,2,3,4,5 };
    originArr[1] = new int[5]{ 2,3,4,5,6 };
    originArr[2] = new int[5]{ 3,4,5,6,7 };
    originArr[3] = new int[5]{ 4,5,6,7,8 };
    originArr[4] = new int[5]{ 5,6,7,8,9 };

    changeLength2D(originArr, originRows, originCols, newerRows, newerCols);

    for (int i = 0; i < newerRows; ++i) {
        for (int j = 0; j < newerCols; ++j) {
            std::cout << "originArr_ptr[i][j]: " << originArr[i][j] << "; i: " << i << "; j: " << j << std::endl;
        }
    }

    for (int i = 0; i < newerRows; ++i) {
        delete[] originArr[i];
    }
    delete[] originArr;

    return 0;
}