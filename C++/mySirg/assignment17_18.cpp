#include<iostream>
#include<string.h>
#include<cctype>
#include<math.h>
using namespace std;
class Time
{
    private:
        int hr, min, sec;
    public:
        void setTime(int hr, int min, int sec){this -> hr = hr; this ->min = min; this ->sec = sec;};
        void sethr(int h){hr = h;}
        void setmin(int m){min = m;}
        void setsec(int s){sec = s;}
        int gethr(){return hr;}
        int getmin(){return min;}
        int getsec(){return sec;}
        int checkTime()
        {
            return hr*3600 + min*60 + sec;
        }
        void showTimearray(Time a[], int size)
        {
            for(int i = 0; i < size; i++)
                cout << a[i].hr << ":" << a[i].min << ":" << a[i].sec << endl;
        }
};
Time* arrayTime(int size)
{
    Time *a;
    a = new Time[size];
    return a;
}
void sortTime(Time a[], int size)
{
    Time temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(a[i].checkTime()< a[j].checkTime())
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
class String
{
    private:
        int size;
        char *p;
    public:
        void inputString(char a[])
        {
            size = strlen(a);
            p = new char[size + 1];
            strcpy(p,a);
        }
        void printString()
        {
            for(int i = 0; i < size; i++)
            cout << p[i] << " ";
        }
        void lower()
        {
            int i;
            for(i = 0; i < size; i++)
            {
                if(p[i] >= 'A' && p[i] <= 'Z')
                p[i] = p[i] + 32;
            }
        }
        void upper()
        {
            int i;
            for(i = 0; i < size; i++)
            {
                if(p[i] >= 'a' && p[i] <= 'z')
                p[i] = p[i] - 32;
            }
        }        
        char* getString()
        {
            return p;
        }
        int getlength()
        {
            return size;
        }
        ~String()
        {
            delete []p;
        }
};
class Person
{
    private:
        char name[20];
        int age;
    protected:
        void setname(char n[20])
        {
            strcpy(name,n);
        }
        void setage(int a){age = a;}
    public:
        char* getname()
        {
            return name;
        }
        int getage()
        {
            return age;
        }
};
class Employee : public Person
{
    private:
        float salary;
    protected:
        void setsalary(float s)
        {
            salary = s;
        }
    public:
        void setEmployee(char n[], int a, float s)
        {
            setname(n);
            setage(a);
            setsalary(s);
        }
        void showEmployee()
        {
            cout << getname() <<"   " << getage() << "   " << salary <<endl;
        }
};
class Circle
{
    private:
        float rad;
    public:
        void setRadius(float r){rad = r;}
        float getRadius()
        {
            return rad;
        }
        float getArea()
        {
            return 3.14 * rad * rad;
        }
};
class ThickCircle : public Circle 
{
    private:
        int thickness;
    public:
        void setthickness(int t){thickness = t;}
        int getthickness(){return thickness;}
        float getArea()
        {
            return (3.14 * (getRadius() + thickness) * (getRadius() + thickness)) - (3.14 * getRadius() * getRadius());
        }
};
class Cordinate
{
    private:
        int x, y;
    public:
        void setCordinate()
        {
            cout << "enter x cordinate :";
            cin >> x;
            cout << "enter y cordinate :";
            cin >> y;
        }
        int getDistnace()
        {
            return sqrtf(pow(x,2) + pow(y,2));
        }
        float getDistance(Cordinate a)
        {
            return (float) sqrtf(pow(x - a.x,2) + pow(y - a.y,2));
        }
};
class shape
{
    private:
        char shapeName[20];
    public:
        void setshape(Cordinate x1, Cordinate y1)
        {
            strcpy(shapeName, "straight line");
        }
};
class StraightLine : private shape
{
    private:
        Cordinate x,y;
    public:
        void setCordinate()
        {
            cout << "enter first point -" << endl;
            x.setCordinate();
            cout << "enter second point -" << endl;
            y.setCordinate();
        }
        void setLine(Cordinate x1, Cordinate y1)
        {
            setshape(x1,y1);
        }
        void getDistance()
        {
            float a;
            a = x.getDistance(y);
            cout << "length of line : " << a;
        }
        void showLine();
};
int main()
{
    String s;
    char ar[] = "string";
    s.inputString(ar);
    s.upper();
    s.printString();
    return 0;
}