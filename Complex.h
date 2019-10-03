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

Complex :: Complex() {
    a = 0;
    b = 0;
}

Complex Complex :: Conjugate() {
	Complex temp;
	temp.a = this->a;
	temp.b = -this->b;
	return temp;
}

int Complex :: StringToInt(string num) {
	int Num = 0;
	string num1;
	if(num[0] == '-')
		num1 = num.substr(1);
	else
		num1 = num;
	int size = num1.size();
	for(int i = 0,j = size ; i < size; i++) {
		Num += (num1[--j] -'0')*pow(10,i);
	}
	return num[0]=='-'?-Num:Num;
}

int Complex :: ExtractReal(string num) {
	string Int ;
	int i = 0 ;
	do{
		Int += string(1,num[i]);
		i++;
	}while(string(1,num[i]) != string(1,'+') && string(1,num[i]) != string(1,'-') );
	return this->StringToInt(Int) ;
}

int Complex :: ExtractImaginary(string num) {
	int i=0 ;
	string Int;
	do{
		i++;
	}while(string(1,num[i]) != string(1,'+') && string(1,num[i]) != string(1,'-'));
	if(num[i] == '+')
		i++;
	for( ; string(1,num[i]) != string(1,'i') ; i++) {
		Int += string(1,num[i]);
	}
	return this->StringToInt(Int) ;
}

int inline Complex :: getReal() {
	return a;
}

int inline Complex :: getImag() {
	return b;
}

void Complex :: input(string _input) {
	string cnum;
	cout<<_input;
	cin>>cnum;

	if(cnum.at(cnum.length() - 1) == 'i') {
		a = this->ExtractReal(cnum);
		b = this->ExtractImaginary(cnum);
	}
	else {
		cout<<"Plz Give Proper Input Eg :- 3+6i\n" ;
		this->input(_input);
	}
}

Complex Complex :: ComplaxInverse() {
    Complex temp;
    temp.a = a/((a*a)+(b*b));
    temp.b = -b/((a*a)+(b*b));
    return(temp);
}

Complex Complex :: operator+(Complex C) {
    Complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}

Complex Complex :: operator-(Complex C) {
    Complex temp;
    temp.a = a - C.a;
    temp.b = b - C.b;
    return temp;
}

Complex Complex :: operator*(Complex C) {
    Complex temp;
    temp.a = (a*C.a)-(b*C.b);
    temp.b = (a*C.b)+(b*C.a);
    return temp;
}

Complex Complex :: operator/(Complex C) {
    Complex temp;
    C = C.ComplaxInverse();
    temp = (*this) * C;
    return temp;
}

Complex Complex :: operator+() {
    Complex temp;
    temp.a = +a;
    temp.b = +b;
    return temp;
}

Complex Complex :: operator-() {
    Complex temp;
    temp.a = -a;
    temp.b = -b;
    return temp;
}

Complex Complex :: operator+(int c) {
    Complex temp;
    temp.a = a + c;
    temp.b = b;
    return(temp);
}

Complex Complex :: operator-(int c) {
    Complex temp;
    temp.a = a - c;
    temp.b = b ;
    return(temp);
}

istream& operator >>(istream &in,Complex &C) {
    C.input("");
    return(in);
}

ostream& operator <<(ostream &out,Complex C) {
    if(C.b >= 0)
    {
        cout<<C.a<<"+"<<C.b<<"i";
        return(out);
    }
    else if(C.b < 0)
    {
        cout<<C.a<<C.b<<"i";
        return(out);
    }
}

#endif // Complex_H
