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
    long long ans=a;
    long long t=a;
    long long cnt=1;
    while(t>=ans && cnt<b){
        ans*=a;
        cnt++;
        t=ans%n;
        if(t<10 && t<ans){
            break;
        }
    }
    cout<<a<<"^"<<cnt<<" = "<<ans<<" = "<<t<<" mod "<<n<<"\n";
    long long p=b/cnt;
    long long r=b%cnt;
    long long res=1;
    for(int i=0;i<p;i++){
        res*=t;
    }
    long long val=1;
    for(int i=0;i<r;i++){
        val*=a;
    }
    res*=val;
    cout<<"(a^b) % n = "<<a<<"^"<<b<<" mod "<<n<<" = "<<val<<"*("<<t<<"^"<<p<<")"<<" mod "<<n<<" = "<<res%n;
    return 0;
}