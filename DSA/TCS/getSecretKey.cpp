#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, T, I;
    cin>>N>>M;

    vector<vector<int>>grid;
    for(int i = 0; i < N; i++){
        vector<int>row;
        int x;
        for(int j = 0; j < M; j++){
            cin>>x;
            row.push_back(x);
        }
        grid.push_back(row);
    }

    cin>>T;
    cin>>I;

    vector<pair<int,vector<int>>>clues;
    int x;
    for(int i = 0; i < I; i++){
        cin>>x;
        vector<int>subGrid;
        int y;
        for(int j = 0; j < 4; j++){
            cin >> y;
            subGrid.push_back(y);
        }
        clues.push_back({x,subGrid});
    }

    return 0;
}