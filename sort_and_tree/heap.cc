/**
 * build-max-heap: O(n)
 * maxHeapify : O(log n)
 * heapSort: O(n log n)
 **/
/**
 * Huang Jiaming
 * saskatoon, canada
 * 2016-7-9
 **/
#include <iostream>
using namespace std;

/**
 * help function
 **/
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * assumes that the binary trees rooted at Left(i) and Right(i)
 * are maxHeaps, but a[i] might violate the max-heap property
 * i >= 1, heapSize = a.size - 1
 **/
void maxHeapify(int a[], int size, int i) {
    int l = 2*i;
    int r = 2*i+1;
    int large;
    if (l <= size-1 && a[l] > a[i]) {
        large = l;
    } else {
        large = i;
    }
    if (r <= size-1 && a[r] > a[large]) {
        large = r;
    }
    if (large != i) {
        swap(a[i], a[large]);
        maxHeapify(a, size, large);
    }
}

/**
 * build from a[len/2] downto 1
 * use the procedure maxHeapify in a bottom-up manner
 **/
void buildMaxHeap(int a[], int size) {
    for (int i = (size-1)/2; i >= 1; i--) {
        maxHeapify(a, size, i);
    }
}

/**
 * first build maxHeap array, then each time switch a[1] with last
 * unsort element, a.length downto 2
 **/
void heapSort(int a[], int size) {
    buildMaxHeap(a, size);
    for (int i = size-1; i >= 2; i--) {
        swap(a[i], a[1]);
        size--;
        maxHeapify(a , size, 1);
    }
}

int main(int argc, char *argv[]) {
    int a[6] = {0, 4, 5, 6, 7, 8};
    buildMaxHeap(a, 6);
    for (int i = 1; i < 6; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;

    int b[6] = {0, 5, 8, 7, 6, 4};
    buildMaxHeap(b, 6);
    //suppose to be 8,6,7,5,4
    for (int i = 1; i < 6; i++) {
        cout << b[i] <<", ";
    }
    cout << endl;

    // test heapSort
    int c[11] = {0, 7, 4, 8, 2, 1, 34, 76, 6, 10, 3};
    heapSort(c, 11);
    for (int i = 1; i < 11; i++) {
        cout << c[i] << ", ";
    }
    cout << endl;
    return 0;
}
