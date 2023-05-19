// Majority Search : O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int majo(int arr[],int n){
    int cnt=0;
    int v=arr[n/2];
    for(int i=0;i<n;i++){
        if(arr[i]==v){
            cnt++;
        }
    }
    if(cnt>n/2){
        return v;
    }
    else{
        return -1;
    }
}
void Merge(int *a, int low, int high, int mid)
{
	int i,j,k,temp[high-low+1];
	i = low;
	k = 0;
	j = mid+1;
	while (i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while (i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
	while (j<=high)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for (i=low; i<=high; i++)
	{
		a[i]=temp[i-low];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low<high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
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
    int left[100], right[100];
    for(int i=0;i<n;i++){
        if(i<n/2){
            left[i]=arr[i];
        }
        else{
            right[i-n/2]=arr[i];
        }
    }
    int r;
    if(n%2==0){
        MergeSort(right,0,n/2);
        r=majo(right,n/2);
    }
    else{
        MergeSort(right,0,(n/2)+1);
        r=majo(right,(n/2)+1);
    }
    MergeSort(left,0,n/2);
    int l=majo(left,n/2);
    if(l==-1 && r==-1){
        cout<<"No Majority Element."<<endl;
    }
    else if(l==r){
        cout<<"Majority Element: "<<l<<endl;
    }
    else if(l==-1){
        int cnt=0;
        int v=r;
        for(int i=0;i<n;i++){
            if(arr[i]==v){
                cnt++;
            }
        }
        if(cnt>n/2){
            cout<<"Majority Element = "<<v<<endl;
        }
        else{
            cout<<"No Majority Element Found."<<endl;
        }
    }
    else if(r==-1){
        int cnt=0;
        int v=l;
        for(int i=0;i<n;i++){
            if(arr[i]==v){
                cnt++;
            }
        }
        if(cnt>n/2){
            cout<<"Majority Element = "<<v<<endl;
        }
        else{
            cout<<"No Majority Element Found."<<endl;
        }
    }
    else{
        int cnt=0;
        int v=l;
        for(int i=0;i<n;i++){
            if(arr[i]==v){
                cnt++;
            }
        }
        if(cnt>n/2){
            cout<<"Majority Element = "<<v<<endl;
        }
        else{
            int cnt=0;
            int v=r;
            for(int i=0;i<n;i++){
                if(arr[i]==v){
                    cnt++;
                }
            }
            if(cnt>n/2){
                cout<<"Majority Element = "<<v<<endl;
            }
            else{
                cout<<"No Majority Element Found."<<endl;
            }
        }
    }
}