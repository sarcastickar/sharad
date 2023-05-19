#include<bits/stdc++.h>
using namespace std;
int rec(vector<int> v){
    cout<<"Current Vector: ";
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
    if(v.size()==1){
        return v[0];
    }
    else if(v.size()==0){
        return -1;
    }
    else{
        vector<int> v1;
        for(int i=0;i<v.size();i+=2){
            if(i+1<v.size()){
            if(v[i]==v[i+1]){
                v1.push_back(v[i]);
            }
            }
            else{
                v1.push_back(v[i]);
            }
        }
        int a=rec(v1);
        return a;
    }
}
int main(){
    vector <int> l;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int inp;
    for(int i=0;i<n;i++){
        cout<<"Enter element no. "<<i+1<<": ";
        cin>>inp;
        l.push_back(inp);
    }
    int ans=rec(l);
    if(ans==-1){
        cout<<"No majority element found"<<endl;
    }
    else{
        int cnt=0;
        for(int i=0;i<l.size();i++){
            if(l[i]==ans){
                cnt++;
            }
        }
        if(cnt>l.size()/2){
            cout<<"Majority element = "<<ans<<endl;
        }
        else{
            cout<<"No majority element found"<<endl;
        }
    }
}