#include<bits/stdc++.h>
using namespace std;
void f(int a[100],int start,int end, int n,float matrix[100][100]){
    if(start>=end){
        return;
    }
    else{
        int pivot=start+rand()%n;
        for(int i=start;i<=end;i++){
            for(int j=start;j<=end;j++){
                if((i==pivot||j==pivot)&&i!=j)
                    matrix[i][j]+=1;
            }
        }
        f(a,start,pivot-1,pivot-start,matrix);
        f(a,pivot+1,end,end-pivot,matrix);
    }
}
int main(){
    float mat[100][100];
    int n;
    cout<<"Enter value of n i.e. number of elements:";
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    int iterations=1000000; //10 lakhs
    for(int i=0;i<iterations;i++){
        f(arr,0,n-1,n,mat);
    }
    cout<<"Total Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    float avgmatrix[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            avgmatrix[i][j]=mat[i][j]/iterations;
        }
    }
    cout<<"\nProbability of comparison between ith and jth element:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<fixed<<setprecision(3);
            cout<<ceil(avgmatrix[i][j]*1000)/1000<<" ";
        }
        cout<<endl;
    }
    return 0;
}