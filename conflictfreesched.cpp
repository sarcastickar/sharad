#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of intervals: ";
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++){
        cout<<"Enter start time of interval "<<i+1<<": ";
        cin>>a[i][0];
        cout<<"Enter end time of interval "<<i+1<<": ";
        cin>>a[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i][1]>a[j][1]){
                int temp0=a[j][0];
                int temp1=a[j][1];
                a[j][0]=a[i][0];
                a[j][1]=a[i][1];
                a[i][0]=temp0;
                a[i][1]=temp1;
            }
        }
    }
    cout<<"Sorted Intervals based on end time:\n";
    for(int i=0;i<n;i++){
        cout<<a[i][0]<<" "<<a[i][1]<<"\n";
    }
    int cnt=0;
    int cend=0;
    string s="";
    for(int i=0;i<n;i++){
        if(a[i][0]>=cend){
            cnt+=1;
            s+="("+to_string(a[i][0])+","+to_string(a[i][1])+") , ";
            cend=a[i][1];
        }
    }
    cout<<"Maximum number of conflict free schedules/intervals = "<<cnt<<"\n";
    cout<<"Longest Conflict free schedules: "<<s;
}