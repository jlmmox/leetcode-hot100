#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right =  nums.size() - 1;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;//二分法,(right-left)>>1相当于（right-left)/2,mid=(r+l)/2,防止加法溢出和提高运算速度
                if(target==nums[mid])
                return mid;
                else if (target < nums[mid]) {
                    right=mid-1;//target在mid左边，right要减小
                } 
                else {
                left=mid+1;
                }
        }
        return left;
    }
};
