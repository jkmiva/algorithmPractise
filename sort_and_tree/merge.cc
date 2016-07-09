#include <iostream>
using namespace std;

void merge(int arr[], int help[], int low, int mid, int high){
	for(int k=low; k<=high; k++){
		help[k] = arr[k];
	}
	int i = low, j = mid + 1;
	int z = low;
	while(i<=mid && j<=high){
		if(help[i] <= help[j]){
			arr[z++] = help[i++];
		}
		else{
			arr[z++] = help[j++];
		}
	} 
// no need to copy the right half array, because the right half is already there. 
	int remain = mid - i; 
	for(int l=0; l<=remain; l++){
		arr[z+l] = help[i+l];
	}
}

void mergeSort(int arr[], int help[], int low, int high){
	if(low < high){
		int mid = (high + low)/2;
		mergeSort(arr, help, low, mid);
		mergeSort(arr, help, mid+1, high);
		merge(arr, help, low, mid, high);
	}
}

void mergeSort(int p[], int len){
	int helpArr[len];
	mergeSort(p, helpArr, 0, len-1);
}


int main(){
	int a[10] = {1,7,9,3,5,2,3,0,10,4};
	mergeSort(a, 10);
	for(int i: a){
		cout<<i<<",";
	}
	cout<<endl;
	return 0;
}
