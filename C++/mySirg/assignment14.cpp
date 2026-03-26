#include <iostream>
using namespace std;
class complex
{
    private:
        int real, img;
    public:
        complex(int r=0, int i=0): real(r),img(i){}
        void showcomplex()
        {
            cout <<"real" << real << "imaginary" << img << endl;
        }
        friend complex operator+(complex, complex);
        friend complex operator-(complex, complex);
        friend complex operator*(complex, complex);
};
complex operator+(complex x, complex y)
{
    complex temp;
    temp.real =  x.real + y.real;
    temp.img = x.img + y.img;
    return temp;
}
complex operator-(complex x, complex y)
{
    complex temp;
    temp.real = x.real - y.real;
    temp.img = x.img - y.img;
    return temp;
}
complex operator*(complex x, complex y)
{
    complex temp;
    temp.real = x.real * y.real - x.img * y.img;
    temp.img = x.real * y.img + y.real * x.img;
    return temp;
}
class Time
{
    private:
        int hr, min, sec;
    public:
        Time(int h = 0, int m = 0, int s = 0){hr = h; min = m; sec = s;}
        void showTime()
        {
            cout <<hr<<":"<< min <<":"<<sec;
        }
        friend ostream& operator<< (ostream &, Time);
        friend istream& operator>> (istream&, Time &);
        Time operator=(int)
        {
            Time t;
            t.hr = hr;
            t.min = min;
            t.sec = sec;
            return t;
        }
};
ostream& operator<< (ostream& dout , Time t)
{
    cout << t.hr<<":"<<t.min<<":"<<t.sec;
    return dout;
}
istream& operator>> (istream& din, Time &t)
{
    cin >> t.hr >> t.min >> t.sec;
    return din;
}
class Array
{
    private:
        int size;
        int *p;
    public:
        Array(int s=0)
        {
            cout << "enter array :" << endl;
            size = s;
            p = new int[size];
            for(int i = 0; i < size; i++)
            cin >> p[i];            
        }
        void showArray()
        {
            cout << "array is :" << endl;
            for(int i = 0; i < size; i++)
            cout << *(p + i) << endl;
        }
        Array operator=(Array& a) // deep copy ? address must change of new array with same value
        {
            size = a.size;
            p = new int [a.size];
            for(int i = 0; i < a.size; i++)
            *(p + i) = *(a.p + i);
        }
        friend void operator+(Array&,Array);
        // mysirg
        // friend Array* operator+(Array, Array);
};
void operator+(Array& a, Array b)
{
    int i;
    int j = 0;
    int k = a.size;
    int temp[k];
    a.size = k + b.size;
    for(i = 0; i < k; i++,j++)
    temp[j] = *(a.p + j);
    a.p = new int [a.size];
    i = 0;
    j = 0;
    while(j < k)
        {
            *(a.p + i) = temp[j];
            i++; j++;
        }
    j = 0;
    while(i < k + b.size)
        {
            *(a.p + i) = *(b.p + j);
            i++; j++;
        }
}
// mysirg
// Array* operator+(Array a1, Array a2)
// {
//     Array *arrptr = new Array();
//     arrptr -> size = a1.size + a2.size;
//     arrptr -> p = new int[arrptr -> size];
//     int i,k;
//     for(i = 0, k = 0; i < a1.size; i++, k++)
//     arrptr->p[k] = a1.p[i];
//     for(i = 0; i < a2.size; i++, k++)
//     arrptr->p[k] = a2.p[i];
//     return arrptr;
// }
int main()
{
    // Time t;
    // cout << "enter time :"; 
    // t >> (cin);
    // t << (cout);
    Array a(4),b(3),c;
    a + b;
    a.showArray();
    return 0;
}