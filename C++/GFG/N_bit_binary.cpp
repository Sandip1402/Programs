//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
        int c=n,limit=0,dec;
        int max_value = pow(2,n)-1;
        while(c>0){
            c-=2;
            limit+=pow(2,c);
        }
        for(int i=0; i<=limit; i++){
            dec = (max_value ^ i);
            string s = convert(dec);
            ans.push_back(s);
        }
        return ans;
	}
    string convert(int dec){
        string s;
        while(dec!=0){
            if(dec%2==1)
            s.push_back('1');
            else
            s.push_back('0');
            dec/=2;
        }
        int size=s.length();
        for(int i=0; i<size/2; i++)
        {
            char ch=s[i];
            s[i]=s[size-i-1];
            s[size-i-1]=s[i];
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() 
{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);
   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
    return 0;
}
// } Driver Code Ends