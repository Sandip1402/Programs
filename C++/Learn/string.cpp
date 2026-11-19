#include<iostream>
#include<string>
#include<algorithm> // reverse function
#include<vector>
using namespace std;
string sortstring(string s)
{
    // time complexity O(length of string)
    vector<int>freq(26,0); // creates a int array freq of size 26 and assigns 0 to every block
    // counts frequency
    for(int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        freq[index]++;
    }
    // sorted string
    int j = 0;
    for(int i = 0; i < freq.size(); i++)
    {
        while(freq[i]--) // 0 means false
        s[j++] = i + 'a';
    }
    return s;
}
bool anagram(string s1, string s2)
{
    // time complexity O(length of string)
    // space complexity O(26) - constant
    vector<int>freq(26,0);
    if(s1.size() != s2.size())
    {
        return false;
    }
        int s = 0;
        for(int i = 0; i<s1.size(); i++)
        {
            int index = s1[i] - 'a';
            freq[index]++;
        }
        for(int i = 0; i<s2.size(); i++)
        {
            int index = s2[i] - 'a';
            freq[index]--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] != 0)
            return false;
        }
    return true;
}
bool isomorphic(string s1, string s2) 
{
    // time complexity O(length of string)
    // space complexity O(256) - constant
    vector<int>v1(128,-1);
    vector<int>v2(128,-1);
    if(s1.size() != s2.size())
    return false;
    for(int i=0; i<s1.size(); i++)
    {
        if(v1[s1[i]] != v2[s2[i]]) // character converts to integer index of v1
        {
            return false;
        }
        v1[s1[i]] = v2[s2[i]] = i; 
    }
    return true;
}
string longest_prefix(vector<string> &str)
{
    // 1.
    sort(str.begin(),str.end()); // sorting of string 
    // time complexity of sort function for string O(nlongn * m), n = no of string, m = general length of string
    string s1 = str[0]; 
    string s2 = str[str.size() - 1]; 
    string ans = ""; // initializing with nothing(jsst like integer initialize with 0)
    int i=0, j=0;
    while(i < s1.size() && j < s2.size())
    {
        if(s1[i] == s2[j])
        {
            ans += s1[i];
            i++; j++;
        }
        else
        return ans;
    }
    // 2.keeping first string constant and compare it with others to get common length of prefix
}
int longestones(string str, int k)
{
    // max length of consecutive 1's in a binary string
    // sliding window technique
    // time complexity - O(n) , n - length of input string
    // space complexity - O(1)
    int start = 0,end = 0,count_zero = 0, max_length = 0;
    for(;end < str.size(); end++)
    {
        if(str[end] == '0')
        count_zero++;
        while(count_zero > k)
        {
            if(str[start] == '0')
            count_zero--;
            start++; // contracting window
        }
        max_length = max(max_length, end-start+1); // assigns which one is bigger
    }
    return max_length;
}
int main()
{
    string str;
    cout << "enter a binary string :" << endl;
    cin >> str;
    int k;
    cout << "enter no. of flips :" << endl;
    cin >> k;
    cout << "longest consecutive one's after flipping : " << longestones(str,2);
    // int size;
    // cout << "enter length of array of string :" <<endl;
    // cin >> size;
    // vector <string> str(size);
    // cout << "enter strings :" << endl;
    // for(int i=0; i<size; i++)
    // cin >> str[i];
    // cout << "longest prefix :" << longest_prefix(str) << endl;
    // cout << "enter two strings :" << endl;
    // cin >> str1 >> str2;
    // if(isomorphic(str1,str2))
    // cout <<"isomorphic"<< endl;
    // else
    // cout <<"not isomorphic"<< endl;
    // reverse(str1.begin(),str1.end());
    // cout << str1;
    // char ch = 'e';
    // if(anagram(str1,str2))
    // cout << "strings are anagram." << endl;
    // else
    // cout<< "string are not anagram." << endl;
    // cout << str1.size();
    // cout << str1.length();
    // int a = 413;
    // string s1 = to_string(a);
    // string s2 = to_string(b);
    // s1 += "2";
    // cout << s1;
    // str1.push_back(ch);
    // cout << str1;
    // cout << str2.substr(2,1); substr(start, length)
    // cout<< str1 + str2;
    return 0;
}