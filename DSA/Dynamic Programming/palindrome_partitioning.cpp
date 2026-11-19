// problem is to partition a string with minimum cuts so that each partition itself is a palindrome

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string& str){
    while(i <= j && str[i] == str[j]){
        i++; j--;
    }
    return i > j;
}

// recursion solution
int sol_recur(int i, string& str){
    if(i == str.size()) { return 0; }

    int minCost = INT_MAX;
    for(int j = i; j < str.size(); j++){
        if(isPalindrome(i, j, str)){
            int cost = 1 + sol_recur(j+1, str);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

// dp - memoization top-down
int sol_memo(int i, vector<int>&memo, string& str){
    if(i == str.size()) return 0;
    if(memo[i] != -1) return memo[i];

    int minCost = INT_MAX;
    for(int j = i; j < str.size(); j++){
        if(isPalindrome(i, j, str)){
            int cost = 1 + sol_memo(j+1, memo, str);
            minCost = min(cost, minCost);
        }
    }

    return memo[i] = minCost;
}

// dp - tabulisation bottom-up
int sol_tab(string& str){
    int n = str.size();
    vector<int>tab(n+1, 0);
    tab[n] = 0;

    for(int i = n-1; i >= 0; i--){

        int minCost = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, str)){
                int cost = 1 + tab[j+1];
                minCost = min(cost, minCost);
            }
        }
        tab[i] = minCost;
    }

    return tab[0];
}

int main()
{
    string str;
    getline(cin, str);

    // cout<<isPalindrome(0, 4, str)<<endl;
    cout<<sol_recur(0, str) - 1<<endl;

    vector<int>memo(str.size(), -1);
    cout<<sol_memo(0, memo, str) - 1<<endl;

    cout<<sol_tab(str) - 1<<endl;
    return 0;
}
