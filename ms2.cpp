// Majority Search : O(nlogn)
#include<bits/stdc++.h>
using namespace std;
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
    MergeSort(arr,0,n-1);
    int cnt=0;
    int v=arr[n/2];
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