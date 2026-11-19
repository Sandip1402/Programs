#include<iostream>
using namespace std;

void tower_of_hanoi(int n, const char &home, const char &dest, const char &aux){
    if(n == 1){
        cout << "move top disk from tower "<< home << " to " << dest <<endl;
        return;
    }

    tower_of_hanoi(n-1, home, aux, dest);
    cout << "move disk " << n <<" from tower " << home << " to " << dest <<endl;
    tower_of_hanoi(n-1, aux, dest, home);
}

int main(){
    int n;
    cout << "No. of Disks :" ;
    cin >> n;
    tower_of_hanoi(n, 'A', 'B', 'C');

    return 0;
}