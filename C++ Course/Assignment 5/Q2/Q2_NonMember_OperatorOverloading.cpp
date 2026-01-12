#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex() : real(0), imaginary(0) {}

    Complex(double r, double i) : real(r), imaginary(i) {}

    double getReal(void)  // Fixed return type
    {
        return real;
    }

    double getImaginary(void)  // Fixed return type
    {
        return imaginary;
    }
    Complex operator+ (Complex& c)
    {
        Complex c1(real+c.real, imaginary + c.imaginary);
        return c1;
    }
    Complex operator- (Complex& c)
    {
        Complex c1(real-c.real, imaginary - c.imaginary);
        return c1;
    }
    Complex operator* (Complex& c)
    {
        Complex c1(real*c.real, imaginary*c.imaginary);
        return c1;
    }
    Complex operator/ (Complex& c)
    {
        Complex c1(real/c.real, imaginary/c.imaginary);
        return c1;
    }
    // Friend function for operator <<
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
    
};

// Overloading << operator
ostream& operator<<(ostream& os, const Complex& c)
{
    os << c.real << " + " << c.imaginary << "i\n";
    return os;
}

istream& operator>>(istream& is, Complex& c)
{
    cout << "Enter real part: ";
    is >> c.real;
    cout << "Enter imaginary part: ";
    is >> c.imaginary;
    return is;
}


int main()
{
    Complex c(1.5, 2.3);  // Now supports double values
    Complex c1(3,5);
    cin >> c;
    cout << c << endl;
    cout << c + c1 << endl;
    cout << c*c1 << endl;
    cout << c/c1 << endl;
    cout << c-c1 << endl;
}
