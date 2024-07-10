#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    vector<int>dp(prices.size(),0);//前i天中获得的最大利润
     int mi=prices[0];
     for(int i=1;i<prices.size();i++)
     {
        mi=min(mi,prices[i]);//记录前i个元素中的最小值
        dp[i]=max(dp[i-1],prices[i]-mi);//状态转移方程
     }
    
     return dp[prices.size()-1];
    }
};
int main()
{   vector<int> p={7,1,5,3,6,4};
    Solution a;
    int b=a.maxProfit(p);
    cout<<b<<endl;
    return 0;
}
