#include <bits/stdc++.h>
#include <vector>
using namespace std;
int lis(vector<int> a,vector<int> b, int arr[][100],int n1,int n2){
    if(n1==0 || n2==0){
        return 0;
    }
    else if(arr[n1][n2]!=-1){
        return arr[n1][n2];
    }
    else{
        if(a[n1-1]==b[n2-1]){
            arr[n1-1][n2-1]=lis(a,b,arr,n1-1,n2-1);
            return arr[n1-1][n2-1];
        }
        else{
            arr[n1-1][n2]=lis(a,b,arr,n1-1,n2);
            arr[n1][n2-1]=lis(a,b,arr,n1,n2-1);
            return max(arr[n1-1][n2],arr[n1][n2-1]);
        }
    }
}
int main(){
    vector<int> arr;
    vector<int> dummy;
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cout<<"Enter element number "<<i+1<<": ";
        cin>>val;
        arr.push_back(val);
        dummy.push_back(val);
    }
    int dp[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }
    sort(dummy.begin(),dummy.end());
    cout<<"Length of longest increasing subsequence="<<lis(arr,dummy,dp,n,n);
    return 0;
}