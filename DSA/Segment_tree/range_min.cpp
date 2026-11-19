/*
    Link : https://www.geeksforgeeks.org/problems/range-minimum-query/1
    Given an integer array arr[] and a 2D integer array queries[][] of size q × 2, 
    process all the queries using 0-based indexing.

    Each query [l, r] asks for the minimum element present in the subarray arr[l...r].

    Constraints:
    1 ≤ arr.size() ≤ 105
    1 ≤ queries.size() ≤ 105
    1 ≤ arr[i] ≤ 109
    0 ≤ l ≤ r < arr.size()
*/


#include <bits/stdc++.h>
using namespace std;
vector<int>arr(1000005);
vector<int>seg(4000005);

void buildsegtree(int idx, int low, int high){
    if(low == high){
        seg[idx] = arr[low];
        return;
    }

    int mid = low + (high - low) / 2;
    buildsegtree(2 * idx + 1, low, mid);
    buildsegtree(2 * idx + 2, mid + 1, high);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r){
    // completely within range
    if(low >= l && high <= r){ return seg[idx]; }

    // completely out of range
    if(low > r || high < l){ return INT_MAX; }

    // partially in range
    int mid = low + (high - low) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return min(left, right);
}

int main()
{
    int n;
    cout << "Array size : " << endl;
    cin >> n;
    cout << "Enter array values : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "array is : " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Building segment tree ...." << endl;
    buildsegtree(0, 0, n-1);
    cout << "Segment tree build complete." << endl;
    
    for(int i = 0; i < 5; i++){
        int l, r;
        cout << "Give Queries, first left, then right : " << endl;
        cin >> l >> r;
        cout << "Minimum in range (" << l <<","<< r <<") is : " << query(0, 0, n-1, l, r) << endl;
    }
    return 0;
}