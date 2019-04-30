#ifndef Complex_H
#define Complex_H

#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>

using namespace std;

class Complex
{
    float a;
    float b;
	int StringToInt(string num);
	int ExtractReal(string num);
    int ExtractImaginary(string num);	
    
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
};

#endif // Complex_H
