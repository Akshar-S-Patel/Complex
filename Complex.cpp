#include "Complex.h"

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

void Complex :: input(string input) { 
	string cnum;
	cout<<input;
	cin>>cnum;
	if(cnum.at(cnum.length() - 1) == 'i') {
		a = this->ExtractReal(cnum);
		b = this->ExtractImaginary(cnum);
	}
	else {
		cout<<"Plz Give Proper Input Eg :- 3+6i\n" ;
		this->input(input);
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
    cin>>C.a>>C.b;
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

main() {
	Complex c1,c2;
    c1.input("Enter A Complex Number : ");
    c2.input("Enter A Complex Nunber : ");
    cout<<"Real Part ="<<c1.getReal()<<" And Imaginary Part ="<<c1.getImag();
    cout<<"\nReal Part ="<<c2.getReal()<<" And Imaginary Part ="<<c2.getImag();
    cout<<"\nYour Enter C1 : "<<c1<<endl<<"Your Enter C2 : "<<c2<<endl;
    cout<<"Addition : "<<c1+c2<<endl;
    cout<<"Subtraction : "<<c1-c2<<endl;
    cout<<"MultiPlication : "<<c1*c2<<endl;
    cout<<"Division : "<<c1/c2<<endl;
    cout<<"Inverse  C1: "<<c1.ComplaxInverse()<<" C2: "<<c2.ComplaxInverse()<<endl;
    cout<<"Negative : "<<-c1<<" "<<-c2<<endl;
    cout<<"Positive : "<<+c1<<" "<<+c2<<endl;
    cout<<"Addition With 3 : "<<c1+3<<" "<<" Subtraction With 6 : "<<c2-6<<endl;
    cout<<c1.Conjugate()<<" "<<c2.Conjugate();
    getch();
    return 0;
}
