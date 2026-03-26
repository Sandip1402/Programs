j#include<iostream>
#include<cstring>
using namespace std;
// program to find a substring within a main string
void searchSub(){
    int i,j;
    char str[]="\nC++ is better than C";
    int len = strlen(str);
    char *substr = new char[len];
    cout<<"The main sting is : "<<str;
    cout<<"\n\nEnter the substring to be searched: ";
    cin>>substr;
    int k,len2=strlen(substr);
    cout<<len2<<endl;
    for(i=0; i<len; i++){
        k=i;
        for(j=0;j<len2;j++){
            if(str[k]==substr[j]){
                if(j==len2-1){
                    cout<<"\nThe substring is present in the main string";
                    exit(0);
                }
                k++;
            }
            else
                break;
        }
    }
    if(i==len)
    cout<<"\nThe substring is not present in the main string";
}
// pointers to function
typedef void (*FunPtr)(int,int);
void Add(int i, int j){
    cout<<i<<"+"<<j<<"="<<i+j;
}
void Subtract(int i, int j){
    cout<<i<<"-"<<j<<"="<<i-j;
}
// pointers to objects
class item {
    int code;
    float price;
    public:
        void getdata(int x,float y){
            code=x;
            price=y;
        }
        void showdata(void){
            cout<< "code :"<< code<<endl;
            cout<< "price :"<< price<<endl;
        }
};
// pure virtual function
class Balagurusamy{
    public:
        virtual void example()=0; // pure virtual function
};
class c:public Balagurusamy{
    public:
        void example(){
            cout<<"C++ text book written by Balagurusamy."<<endl;
        }
};
class oops:public Balagurusamy{
    public:
        void example(){
            cout<<"Explains oops concept with c++."<<endl;
        }
};
const int size = 2;
int main(){
// pointers to function
    // FunPtr ptr;
    // ptr=&Add;
    // ptr(1,2);
    // cout<<endl;
    // ptr=&Subtract;
    // ptr(3,2);
// pointers to objects
    // item *p = new item [::size]; // use :: to avoid ambigouity error or rename global variable name 
    // item *d = p;
    // int x, i;
    // float y;
    // for(int i=0; i<::size; i++){
    //     cout << "input code and price for item "<< i+1;
    //     cin>>x>>y;
    //     p->getdata(x,y);
    //     p++;
    // }
    // for(int i=0; i<::size; i++){
    //     cout << "input code and price for item "<< i+1;
    //     d->showdata();
    //     d++;
    // }
// pure virtual function
    Balagurusamy* array[2];
    c e1;
    oops e2;
    array[0]=&e1;
    array[1]=&e2;
    array[0]->example();
    array[1]->example() ;
    return 0;
}