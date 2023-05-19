// Majority Search : O(n2)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        int val;
        cin>>val;
        arr[i]=val;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        int v=arr[i];
        for(int j=0;j<n;j++){
            if(v==arr[j]){
                cnt++;
            }
        }
        if(cnt>n/2){
            flag=1;
            cout<<"Majority Element = "<<v<<endl;
            break;
        }
    }
    if(flag==0){
        cout<<"No Majority Element Found."<<endl;
    }
}