#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,n;
    cout<<"Enter value of a:";
    cin>>a;
    cout<<"Enter value of b:";
    cin>>b;
    cout<<"Enter value of n:";
    cin>>n;
    long long ans=1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    cout<<"(a^b) % n = "<<ans%n;
    return 0;
}