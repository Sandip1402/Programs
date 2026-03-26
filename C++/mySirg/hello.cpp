#include <iostream>
#include <fstream>
#include <climits>
#include <math.h> 
#include <string.h> 
using namespace std;
class complex
{
	int a;
	int b;
	public :
			complex() {a = 0; b = 0;}; // constructor overload
			complex(int x) {a = x; b = 0;}; // constructor overload
			complex(int x, int y) {a = x; b = y;}; // constructor overload
			// explicit copy constructor
			complex(complex &c)
			{
				a = c.a;
				b = c.b;
			}
			void input(int x, int y)
			{
				a = x;
				b = y;
			}
			void display();
			// friend operator
			friend complex operator+(complex,complex);
			// complex operator+(complex c)
			// {
			// 	complex temp;
			// 	temp.a = a + c.a;
			// 	temp.b = b + c.b;
			// 	return temp;
			// }
			// *** important
			friend ostream& operator<< (ostream&,complex);
			friend istream& operator>> (istream&,complex&);
};
ostream& operator<< (ostream& dout,complex c)
{
	dout << "\na = " << c.a <<" b = " << c.b;
	return dout;
}
istream& operator>> (istream& din,complex& c)
{
	din >> c.a >> c.b;
	return din;
}
complex operator+(complex c, complex d)
{
	complex temp;
	temp.a = c.a + d.a;
	temp.b = c.b + d.b;
	return temp;
}			
void complex :: display()
{
	cout <<"a = " << a << " b = " << b << endl;
}
class Person
{
    private:
        char name[20];
        int age;
    protected:
        void setName(char n[]) { strcpy(name,n);}
        void setage(int x){age = x;}
    public:
        char* getName() { return name;}
        int getage(){ return age;}
};
class employee :public Person
{
    private:
        float salary;
    protected:
        void setsalary(float a){salary = a;}
    public:
        float getsalary(){return salary;}
};
class Updatedemployee :public employee
{
    public:
        void setemployee(char n[], int a, float b)
        {
            setName(n);
            setage(a);
            setsalary(b);
        }
        void showemployee()
        {
            cout << getName() << "  " << getage() << "  " << getsalary() << endl;
        }
};
void writeTOfile(char filename[], char data[])
{
	ofstream fout;
	fout.open(filename,ios::out);
	fout<<data;
	fout.close();
}
void readFromfile(char filename[])
{
	char x;
	ifstream fin;
	fin.open(filename,ios::in);
	if(!fin)
	{
		cout << "file not found";
	}
	else
	{
		x = fin.get();
		while(!fin.eof())
		{
			cout << x;
			x = fin.get();// reads space also
		}
		fin.close();
	}
}
class a
{

};
class b1 : virtual public a
{

};
class b2 : virtual public a
{

};
class c : public b1, public b2
{

};
int main() 
{
	a obj;
	cout << sizeof(obj);
   return 0;
}
