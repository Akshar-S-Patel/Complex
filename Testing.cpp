#include "Complex.h"

using namespace std;

int main() {
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
    return 0;
}
