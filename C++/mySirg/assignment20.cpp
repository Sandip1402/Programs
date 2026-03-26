#include<iostream>
using namespace std;
class A
{
    public:
        int a, b;
        void setData(int a, int b)
        {
            this ->a = a; 
            this ->b = b;
        }
        void showData()
        {
            cout << "a =" << a << ",b = " << b;
        }
        void input()
        {
            cout << "enter two number :" << endl;
            cin >> a >> b;
        }
};
class B : public A
{
    private:
        int c;
    public:
        void input()
        {
            cout << "enter three number :" << endl;
            cin >> a >> b >> c;
        }
};
int main()
{

    return 0;
}