#include <iostream>
using namespace std;
class fraction
{
    private:
        long numerator;
        long denominator;
    public:
        fraction(long n = 0, long d = 0): numerator(n), denominator(d){} // value assign by initializer list
        void showfraction()
        {
            cout << numerator << "/" << denominator << endl;
        }
        fraction operator+(fraction x)
        {
            fraction y;
            y.numerator = x.denominator * numerator + denominator * x.numerator;
            y.denominator = denominator * x.denominator;
            long h = hcf(y.numerator, y.denominator);
            y.numerator /= h;
            y.denominator /= h;
            return y;
        }
        long hcf(long a, long b)
        {
            long l;
            for(l = a < b ? a : b; l > 0; l--)
            {
                if(a % l == 0 && b % l == 0)
                return l;
            }
        }
        bool operator<(fraction t)
        {
            float a = (float)numerator / denominator;
            float b = (float)t.numerator / t.denominator;
            if(a < b)
            return true;
            else 
            return false;
        }
};
class Distance
{
    private:
        int km, m, cm;
    public:
        Distance(int k = 0, int m1 = 0, int c = 0){km = k; m = m1; cm = c;}
        Distance operator+(Distance a)
        {
            Distance t;
            t.km = km + a.km;
            t.m = m + a.m;
            t.cm = cm + a.cm;
            return t;
        }
        void normalize()
        {
            m += cm / 100;
            km += m / 1000;
            m %= 1000;
            cm %= 100;
        }
        void showdistance ()
        {
            normalize();
            cout << "km = " << km << ", m = " << m << ", cm = " << cm << endl;
        }
        Distance operator--()
        {
            if(km == 0 && m == 0 && cm == 0)
            return *this;
            else{
            if(cm == 0 && m == 0)
            {
                km--;
                m = 999;
                cm = 100;
            }
            else if(cm == 0){
                cm = 100;
                m--;
            }
            }
            --cm;
            return *this;
        }
        Distance operator--(int)
        {
            Distance t = *this;
            if(km == 0 && m == 0 && cm == 0);
            else{
            if(cm == 0 && m == 0)
            {
                --km;
                m = 999;
                cm = 100;
            }
            else if(cm == 0)
            {
                cm = 100;
                --m;
            }
            --cm;
            return t;
            }
        }
};
class Array
{
    private:
        int *arr; int size;
    public:
        Array(int s = 0)
            {
                size = s;
                arr = new int [size];
            }
        void setArray()
        {
            for(int i = 0; i < size; i++)
            cin >> *(arr + i);
        }
        void showArray()
        {
            for(int i = 0; i < size; i++)
            cout << *(arr + i) << " " << endl;
        }
        int& operator[](int a)
        {
            if(a < size && a >= 0) // returning reference because it will allow to make changes
            return arr[a];
            cout << "Invalid array index.";
            return arr[0];             
        }
        ~Array()
        {
            delete []arr;
        }
};
int main()
{
    Array a(3);
    a.setArray();
    int b = a[2];
    cout << endl;
    cout << b;
    return 0;
}