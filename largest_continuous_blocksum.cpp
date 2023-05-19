#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter number of elements of array:";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    int summ[n];
    for(int i=0;i<n;i++){
        summ[i]=0;
    }
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s<0){
            s=0;
        }
        summ[i]=s;
    }
    int ans=0;
    cout<<"Maximum sum ending at every index:\n";
    for(int i=0;i<n;i++){
        ans=max(ans,summ[i]);
        cout<<summ[i]<<" ";
    }
    cout<<"\nLargest Continuous Block Sum = "<<ans;
}