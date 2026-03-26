// program to find out a value from given array, that left values are smaller &
// right values are greater
#include<bits/stdc++.h>
using namespace std;
int leftSmallRightGreater(vector<int>& arr){
    queue<int>ans;
    int i=0, ls_max=-1;
    while(i<arr.size()){
        if(ans.empty() && arr[i]>ls_max){
            ans.push(arr[i]);
        }
        else if(!ans.empty()){
            if(arr[i]>arr[i-1] && arr[i]>ans.front()){
                ans.push(arr[i]);
            }
            else if(arr[i]<arr[i-1]){
                ls_max=ans.front();
                ans.pop();
            }
        }
        i++;
    }
    if(ans.size()>1)
        return ans.front();
    else
        return -1;
}
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }
    cout<<leftSmallRightGreater(arr);
    return 0;
}