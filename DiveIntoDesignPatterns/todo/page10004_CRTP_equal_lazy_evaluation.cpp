#include <chrono> 
#include <iostream> 
using namespace std;
typedef std::chrono::high_resolution_clock Clock;


/******************************************************************************
 *
 * 问题: CRTP 也是 lazy evaluation?
 * 
 * 说明: CRTP是利用c++的模板特性, 来完成编译期代码生成, 
 *       以及运行时对象向下转换, 最后调用具体对象的方法来计算出具体结果.
 *       这种当使用时才转换的行为统统被称为 lazy evaluation.
 *
 * 回答: 所以CRTP 是 lazy evaluation.
 *
 * 补充: 像 python3 中的 range 就是 lazy evaluation, 因为它一次只计算一个结果.
 *       像 python3 中的 yield 就是 lazy evaluation, 因为它一次只计算一个结果.
 *       那些 多态转换, 也是lazy evaluation, 因为它再需要的时候才转换.
 *          
 * 备注: CRTP的效率是virtual的千分之三倍, 效率略微有提高, 但是并不明显.
 *
 * 参考: https://www.geeksforgeeks.org/curiously-recurring-template-pattern-crtp-2/
 *       https://www.modernescpp.com/index.php/recursion-list-manipulation-and-lazy-evaluation
 *       https://www.modernescpp.com/index.php/c-is-still-lazy
 *
 ******************************************************************************/
class Dimension {
private:
    int mX, mY;

public:
    Dimension(int _X, int _Y): mX(_X), mY(_Y) {}
};


template<typename T>
class ImageDispather {
protected:
    int dimensionX, dimensionY;

public:
    void 
    Draw() {
        // Dispatch call to exact type 
        static_cast<T*>(this)->Draw();
    }

    Dimension 
    GetDimensionInPixels() {
        // Dispatch call to exact type 
        static_cast<T*>(this)->GetDimensionInPixels();
    }

};


class TiffImage: public ImageDispather<TiffImage> {
public:
    void 
    Draw() {
        // Uncomment this to check method dispatch 
        // cout << "TiffImage::Draw() called" << endl; 
    }

    Dimension 
    GetDimensionInPixels() {
        return Dimension(dimensionX, dimensionY);
    }
};


int test_ImageDispather() {
    // An Image type pointer pointing to Tiffimage 
    ImageDispather<TiffImage> * pImage = new TiffImage;

    // Store time before virtual function calls 
    auto then = Clock::now();

    // Call Draw 1000 times to make sure performance 
    // is visible 
    for (int i = 0; i < 1000; ++i)
        pImage->Draw();

    // Store time after virtual function calls 
    auto now = Clock::now();

    cout << "Time taken: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count()
        << " nanoseconds" << endl;

    return 0;
}