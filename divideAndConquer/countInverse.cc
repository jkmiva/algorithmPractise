// copyright [2016] <Huang Jiaming>
#include <iostream>

class countInverse {
  public:
    static int ci(int arr[], int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int leftCount = ci(arr, left, mid);
        int rightCount = ci(arr, mid+1, right);
        int merge = 0;
        for (int i = left; i <= mid; i++) {
            for (int j = mid + 1; j <= right; j++) {
                if (arr[i] > arr[j]) {
                    merge++;
                }
            }
        }
        return leftCount + rightCount + merge;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = {1, 20, 6, 4, 5};
    int c = countInverse::ci(arr, 0, 4);
    std::cout << c << std::endl;
    return 0;
}
