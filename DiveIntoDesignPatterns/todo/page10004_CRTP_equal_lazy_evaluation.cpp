#include <chrono> 
#include <iostream> 
using namespace std;
typedef std::chrono::high_resolution_clock Clock;


/******************************************************************************
 *
 * ����: CRTP Ҳ�� lazy evaluation?
 * 
 * ˵��: CRTP������c++��ģ������, ����ɱ����ڴ�������, 
 *       �Լ�����ʱ��������ת��, �����þ������ķ����������������.
 *       ���ֵ�ʹ��ʱ��ת������Ϊͳͳ����Ϊ lazy evaluation.
 *
 * �ش�: ����CRTP �� lazy evaluation.
 *
 * ����: �� python3 �е� range ���� lazy evaluation, ��Ϊ��һ��ֻ����һ�����.
 *       �� python3 �е� yield ���� lazy evaluation, ��Ϊ��һ��ֻ����һ�����.
 *       ��Щ ��̬ת��, Ҳ��lazy evaluation, ��Ϊ������Ҫ��ʱ���ת��.
 *          
 * ��ע: CRTP��Ч����virtual��ǧ��֮����, Ч����΢�����, ���ǲ�������.
 *
 * �ο�: https://www.geeksforgeeks.org/curiously-recurring-template-pattern-crtp-2/
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