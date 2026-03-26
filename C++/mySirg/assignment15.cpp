#include <iostream>
#include <string.h>
using namespace std;
class Complex
{
    private:
        int real, imaginary;
    public:
        Complex(int r = 0, int img = 0){real = r; imaginary = img;}
        void showComplex()
        {
            cout << "real = " << real <<"," << "imaginary = " << imaginary;
        }
        friend Complex operator-(Complex c);
};
Complex operator-(Complex c)
{
    Complex a;
    a.real = -c.real;
    a.imaginary = -c.imaginary;
    return a;
        }
class Integer
{
    private:
        int a;
    public:
        Integer(int x = 0){a = x;}
        friend bool operator!(Integer); 
        friend bool operator==(Integer, Integer);
};
bool operator==(Integer x, Integer y)
{
    return x.a == y.a;
}
// will return false if i has nonzero value and true if it has zero value
bool operator!(Integer i)
{
    return !(i.a);
}
class Cordinate
{
    private:
        int x,y;
    public:
        Cordinate(int x1 = 0, int y1 = 0){x = x1; y = y1;}
        void showCordinate()
        {
            cout << "x = " << x << ",y = " << y << endl;
        }
        Cordinate operator,(Cordinate c)
        {
            return c;
        }
        friend ostream& operator<<(ostream& dout, Cordinate a);
        friend istream& operator>>(istream& din, Cordinate &a);
};
ostream& operator<<(ostream& dout, Cordinate a)
{
    dout << "x = " << a.x << ",y = " << a.y;
    return dout;
}
istream& operator>>(istream& din, Cordinate &a)
{
    din >> a.x >> a.y;
    return din;
}
class Student 
{
    private:
        char name[20];
        int roll;
        int age;
    public:
        void setStudent(char n[],int r,int a)
        {
            strcpy(name,n);
            roll = r;
            age = a;
        }
        void showStudent()
        {
            cout << "student name :" << name << endl;
            cout << "roll :" << roll << endl;
            cout << "age :" << age << endl;
        }
        bool operator==(Student x)
        {
            return (strcmp(name,x.name) == 0 && roll == x.roll && age == x.age);
        }
};
int main()
{
    Complex c(4,5);
    -c;
    c.showComplex();
    return 0;
}