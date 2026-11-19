#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findpair(int N, vector<int>&A){
    int pairs=0;
    vector<int>leftSum(N);
    vector<int>rightSum(N);
    leftSum[0] = A[0];
    rightSum[N-1] = A[N-1];
    for(int i=1; i<N; i++){
        leftSum[i] = leftSum[i-1] + A[i];
        rightSum[N-i-1] = rightSum[N-i] + A[N-i-1];
    }
    for(int i=N-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            if(leftSum[j] == rightSum[i])
                pairs++;
        }
    }
    return pairs;
}


int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    cout<<findpair(N, A);
    return 0;
}