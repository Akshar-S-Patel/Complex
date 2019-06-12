#ifndef Complex_H
#define Complex_H

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Complex
{
    public:
        Complex();
        Complex operator+();
        Complex operator-();
        Complex operator+(int);
        Complex operator-(int);
        Complex operator+(Complex);
        Complex operator-(Complex);
        Complex operator*(Complex);
        Complex operator/(Complex);
        int inline getReal();
        int inline getImag();
        void input(string input);
        Complex ComplaxInverse();
        Complex Conjugate();
        friend istream& operator >>(istream &,Complex &);
        friend ostream& operator <<(ostream &,Complex);

    private:
        float a;
        float b;
        int StringToInt(string num);
        int ExtractReal(string num);
        int ExtractImaginary(string num);

};

#endif // Complex_H
