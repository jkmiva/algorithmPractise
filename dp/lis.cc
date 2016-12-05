// Copyright [2016] <Huang Jiaming>
/**
 * longest increasing subsequence
 * lis[i] = max(lis[i-1], lis[j]+1),
 *   -->  arr[j] is the leftmost data which is smaller than arr[i].
 *        if such arr[j] doesn't exist, lis[i] = lis[i-1]
 */

#include <iostream>

class Lis {
public:
    static int lis(int arr[], int n) {
        int *lis = new int[n];
        for (int i = 0; i < n; i++) {
            lis[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (arr[j] < arr[i]) {
                    lis[i] = lis[j]+1 > lis[i-1]? lis[j] + 1 : lis[i-1];
                    break;
                }
            }
            // if arr[i] is less than all elements before it
            // lis[i] = lis[i-1]
            if (lis[i] == 1) {
                lis[i] = lis[i-1];
            }
        }
        int ret = lis[n-1];
        delete lis;
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = 9;
    int ret = Lis::lis(arr, 9);
    std::cout << "get "<< ret << ", expected 6."<< std::endl;

    int arr1[] = {0, 8, 2, 3, 7, 9};
    int ret1 = Lis::lis(arr1, 6);
    std::cout << "get "<< ret1 << ", expected 5."<< std::endl;

    int arr2[] = {0, 8, 2, 2, 3, 3, 7, 9};
    int ret2 = Lis::lis(arr2, 8);
    std::cout << "get "<< ret2 << ", expected 5."<< std::endl;


    return 0;
}
