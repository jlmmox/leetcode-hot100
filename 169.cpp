#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement_baoli(vector<int>& nums) //暴力解
    {
        unordered_map<int,int> num;
        for(int c:nums)
        {
            num[c]++;
            if(num[c]>nums.size()/2)
                return c;
        }
    }
       
    int majorityElement(vector<int>& nums) //中位数
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    

};
