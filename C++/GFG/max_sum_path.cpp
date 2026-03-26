// find the path between two array to get maximum sum
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int sum=0;
        int i=l1,j=l2,sw;
        while(i>0 && j>0){
            if(A[i-1]>B[j-1])
                sw=0;
            else if(A[i-1]==B[j-1]){
                if(A[i-2]>B[j-2])
                    sw=0;
                else
                    sw=1;
            }
            else
                sw=1;
            switch(sw){
                case 0: while(A[i-1]!=B[j-1]){
                            sum+=A[i-1];
                            i--;
                        }
                        break;
                case 1: while(A[i-1]!=B[j-1]){
                            sum+=B[j-1];
                            j--;
                        }
                        break;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
}


// } Driver Code Ends