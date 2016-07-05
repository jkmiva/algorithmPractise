#include <iostream>
using namespace std;

void quickSort(int *, int, int);
int partition(int *, int, int);

int main(){
	int a[10] = {7,12,3,9,5,20,1,4,9,0};
	quickSort(a, 0, 9);
	for(int i : a){
		cout << i << ", ";
	}
	cout << endl;
	return 0;
}

void quickSort(int a[], int left, int right){
	int index = partition(a, left, right);
	if(left < index-1){
		quickSort(a, left, index-1);
	}
	if(right > index){
		quickSort(a, index, right);
	}
}

int partition(int a[], int left, int right){
	int pivot = a[(left + right)/2];
	int i = left, j = right;
	int temp;
	while(i <= j){
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
		if(i <= j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	return i;
}
