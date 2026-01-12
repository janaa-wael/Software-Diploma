#include <iostream>
#include <math.h>
using namespace std;

class Point{
private:
    double x;
    double y;
public:
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    float getX(void)
    {
        return x;
    }
    float getY(void)
    {
        return y;
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    float distanceTo(Point p) const
    {
        return sqrt(pow(x-p.getX(),2) + pow(y-p.getY(),2));
    }
    void print() const
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
};

int main()
{
    Point p(3.2, 4.6);
    p.print();
}