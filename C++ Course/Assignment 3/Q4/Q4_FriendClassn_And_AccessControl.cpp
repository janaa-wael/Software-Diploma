#include <iostream>
using namespace std;

class Box{
private:
    int length;
    int width;
    int height;
    friend class BoxManipulator;
public:
    Box(int length, int width, int height)
    : length(length), width(width), height(height)
    {

    }

    int getLength(void)
    {
        return length;
    }
    int getWidth(void)
    {
        return width;
    }
    int getHeight(void)
    {
        return height;
    }
    void setLength(int length)
    {
        this->length = length;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
};

class BoxManipulator{
    public:
        void resize(Box& box, double newLength, double newWidth, double newHeight)
        {
            box.length = newLength;
            box.width = newWidth;
            box.height = newHeight;
        }
        int volume(Box& box)
        {
            return box.length*box.width*box.height;
        }
};

int main()
{
    Box b(2,3,4);
    BoxManipulator bm;
    cout << "Volume of Box = " << bm.volume(b);
    bm.resize(b,3,4,5);
    cout << "\nVolume of Box After Resizing = " << bm.volume(b);
}