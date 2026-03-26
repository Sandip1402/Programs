// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    vector<vector<int>> key;
    key = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, 
            {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}};

    string keyString = "";
    for (const auto &row : key)
    {
        for (int num : row)
        {
            keyString += to_string(num);
        }
    }
    cout << keyString << endl;

    // float a = 9.985954;
    // cout << fixed << setprecision(4) << a;
    return 0;
}