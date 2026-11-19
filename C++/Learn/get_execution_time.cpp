#include<bits/stdc++.h>
#include<chrono>
using namespace std;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    // code here
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    cout<<endl<<"Execution Time : "<<duration<<"ns"<<endl;
    return 0;
}