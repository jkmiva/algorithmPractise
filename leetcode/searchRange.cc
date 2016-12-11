// Copyright [2016] <Huang Jiaming>
/*
 * search a range for a target in a sorted array, return [-1, -1] if doesn't
 * find it.
 */
class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        vector<int> ret(2,-1);
        while (i < j) {
            int mid = i + (j-i)/2;
            if (nums[mid] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        if (nums[i] != target) {    // if no found, return [-1,-1]
            return ret;
        }
        ret[0] = i;
        j = nums.size()-1;    // no need to set i = 0
        while (i < j) {
            int mid = i + (j-i)/2 + 1;    // similar to find left endpoint
            if (nums[mid] <= target) {
                i = mid;
            } else {
                j = mid - 1;
            }
        }
        ret[1] = j;
        return ret;

    }
};
