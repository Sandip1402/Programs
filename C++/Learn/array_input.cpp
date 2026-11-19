// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // array inputs
    string str;
    getline(cin, str);
    vector<int> arr;

    /* if input is "1 2 3 4 5" */

    int num;
    stringstream ss(str);
    while(ss >> num) {arr.push_back(num);}
    
    /* if input is comma separated array -> "1,2,3,4" */

    // stringstream ss(str);
    // string token;
    // while(getline(ss, token, ',')){
    //     arr.push_back(stoi(token));
    // }

    /* if input is within brackets -> "[1,2,3,4]" */

    // str.erase(remove(str.begin(), str.end(), '['), str.end());
    // str.erase(remove(str.begin(), str.end(), ']'), str.end());
    // string token;
    // stringstream ss(str);
    // while(getline(ss, token, ',')){
    //     arr.push_back(stoi(token));
    // }

    for(int i = 0; i < arr.size(); i++){
        cout << (arr[i]) << " ";
    }

    return 0;
}