#include <iostream>
#include <string.h>
using namespace std;
class Customer
{
    private:
        int cust_id;
        char name[20];
        char email[20];
        char mobile[15];
    public:
        Customer()
        {
            cust_id = 0;
            strcpy(name, "xyz");
            strcpy(email, "xyz@gmail.com");
            strcpy(mobile, "00000000000");
        }
        Customer(int id, char n[], char e[], char m[])
        {
            cust_id = id; 
            strcpy(name, n); 
            strcpy(email, e); 
            strcpy(mobile, m);
        }
        void display()
        {
            cout << "customer id :" << cust_id << endl;
            cout << "name :" << name << endl;
            cout << "email :" << email << endl;
            cout <<"mobile :" << mobile << endl;
        }
};
class Numbers
{
    private:
        int size, *arr;
    public:
        Numbers(int x)
        {
            size = x;
            arr = new int [size];
        }
        Numbers(Numbers &n)
        {
            size = n.size;
            arr = new int[size];
            for(int i = 0; i < size; i++)
            {
                arr[i] = n.arr[i];
            }
        }
        ~Numbers()
        {
            delete []arr;
        }
};
class Time
{
    private:
            int h, m, s;
    public:
            void setTime(int x, int y, int z)
            {
                h = x;
                m = y; 
                s = z;
            }
            void normalize()
            {
                m += s / 60;                              
                s %= 60;
                h += m / 60;
                m %= 60;
            }
            void showTime()
            {
                cout << "Time - " << h << ":" << m << ":" << s << endl;
            }
            Time add(Time t)
            {
                Time temp;
                temp.h = h + t.h;
                temp.m = m + t.m;
                temp.s = s + t.s;
                temp.normalize();
                return temp;
            }
            bool is_greater(Time t)
            {
                if(h > t.h )
                return true;
                else if(m > t.m)
                return true;
                else if(s > t.m)
                return true;
                else
                return false;
            }
            Time operator+(Time t)
            {
                Time x;
                x.s = s + t.s;
                x.m = m + t.m;
                x.h = h + t.h;
                x.normalize();
                return x;
            }
            bool operator>(Time t)
            {
                if(h > t.h )
                return true;
                else if(m > t.m)
                return true;
                else if(s > t.s)
                return true;
                else
                return false;
            }
            Time operator++()// pre increment
            {
                s++;
                normalize(); 
                return *this;               
            }
            Time operator++(int) // post increment
            {
                Time t = *this;
                s++;
                normalize();
                return t;
            }
};
int main()
{
    // Complex c[5] = {Complex(1,2), Complex(2,3), Complex(3,4), Complex(1,8), Complex(2,9)};
    Time t1,t2,t3;
    t1.setTime(2,58,59);
    t2.setTime(2,58,00);
    t3 = t1 + t2;
    t3.showTime();
    return 0;
}
