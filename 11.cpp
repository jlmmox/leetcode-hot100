#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sizeh=height.size();
        int l=0;
        int r=sizeh-1;
        int capacity=(r-l)*min(height[r],height[l]);//初始值
        while(l<r)
        {height[l]>height[r]?r=r-1:l=l+1;
        capacity= max(capacity,(r-l)*min(height[r],height[l]));
        }
        return capacity;
    }
};
