#include<bits/stdc++.h>
#define ll long long;
using namespace std;

    int missingNum(vector<int>& arr) {
        // using triangle number method
        int n = arr.size();
        
        // (n+1)th triangular number
        long long nth = (n + 1)*(n + 2) / 2;
        
        long long sum = 0;
        for(int i = 0; i < n; i++){ 
            sum = ( sum + arr[i] ); 
        }
        return nth - sum;
    }

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        vector<int>arr;
        
	     
    }
    return 0;
}