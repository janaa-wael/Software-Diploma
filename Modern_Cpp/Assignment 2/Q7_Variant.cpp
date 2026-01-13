#include <iostream>
#include <variant>
#include <cmath>

using namespace std;

// Shape definitions
struct Circle {
    double radius;
};

struct Rectangle {
    double width;
    double height;
};

struct Triangle {
    double base;
    double height;
};

// Variant holding different shapes
using Shape = variant<Circle, Rectangle, Triangle>;

// Visitor to compute area
double area(const Shape& shape)
{
    return visit([](auto&& s) -> double {
        using T = decay_t<decltype(s)>;

        if constexpr (is_same_v<T, Circle>)
            return M_PI * s.radius * s.radius;

        else if constexpr (is_same_v<T, Rectangle>)
            return s.width * s.height;

        else if constexpr (is_same_v<T, Triangle>)
            return 0.5 * s.base * s.height;
    }, shape);
}

int main()
{
    Shape s1 = Circle{5};
    Shape s2 = Rectangle{4, 6};
    Shape s3 = Triangle{3, 8};

    cout << "Circle area: " << area(s1) << endl;
    cout << "Rectangle area: " << area(s2) << endl;
    cout << "Triangle area: " << area(s3) << endl;
}
