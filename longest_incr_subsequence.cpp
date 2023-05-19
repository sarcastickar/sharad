#include <bits/stdc++.h>
#include <vector>
using namespace std;
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
    sort(dummy.begin(),dummy.end());
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i-1]==dummy[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"Length of longest increasing subsequence="<<dp[n][n];
    return 0;
}