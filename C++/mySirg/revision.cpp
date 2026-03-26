#include<iostream>
using namespace std;
class item
{
    private:
            int a,b;
    public:
            void setdata(int x,int y){a=x;b=y;}
            void showdata(){cout<<a<<' '<<b<<' '<<endl;}
            friend complex complex:: addition(item b);
        //     friend void f1(item i,complex c);
            // friend void complex::add(item i);
};
class complex
{
    private:
            int c,d;
            const int e;
    public:
            complex():e(4){}
            void setdata(int v, int w){c=v;d=w;}
            virtual void showdata(){cout<<c<<' '<<d<<' '<<e<<endl;}
        //     void add(item i);
        //     friend void f1(item i,complex c);
            // friend complex operator+(complex,item);
            complex addition(item b);
};
complex complex:: addition(item b)
{
        complex temp;
        // temp.c=c+b.a;
        // temp.d=d+b.b;
        return temp;
}
//operator as friend
// void complex::add(item i)
// {
//     cout <<i.a+i.b;
// }
// void f1(item i,complex c)
// {
//     cout<<i.a+i.b<<endl;
//     cout<<c.d+c.c<<endl;
// }
int main()
{
    // item i1;
    // // auto it=NULL;
    // i1.setdata(10,20);
    // item *p = &i1;
    // // f1(i1);   
    // // i1.showdata();
    // // complex*p=&i1;
    // p->showdata();
    // complex a,b,c;
    // a.showdata();
    // b.showdata();
    // b.setdata(3,5);
    // c.setdata(5,3);
    // a=b+c;
    // a.showdata();
    return 0;
}