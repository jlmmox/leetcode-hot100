#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int num=nums.size();
      sort(nums.begin(),nums.end());
      vector<int> result{};
      result.resize(queries.size(),0);
      for(int i=0;i<queries.size();i++)
      {
      int sum=0;
      for(int j=0;j<nums.size();j++)
      {     sum+=nums[j];
        if(sum<=queries[i])
            {
                
                result[i]++;
            }
      
      }
      }
return result;
    }
};
int main()
{
   vector<int> nums={4,5,2,1};
   vector<int> quer={3,10,21};
   vector<int> m;
   Solution *b=new Solution();
   m=b->answerQueries(nums,quer);
cout<<m[2];
   
}
//