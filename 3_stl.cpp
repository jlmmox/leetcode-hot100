#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
class Solution {
public:
int lengthOfLongestSubstring(string s) {
    if(s.empty())
    return 0;
    int maxnum=1;
    vector<int> char_list;
    for(char c:s)
    {
        if(find(char_list.begin(),char_list.end(),c)!=char_list.end())//字符在char_list中已经存在
        {
            char_list.erase(char_list.begin(), find(char_list.begin(), char_list.end(), c) + 1);//删除char_list中的字符
        }
        char_list.push_back(c);//将字符c放入char_list中
        maxnum = max(maxnum, (int)(char_list.size()));
    }
    return maxnum;
}
};

int main()
{
    string s="pwwkew";
    Solution *a=new Solution();
    int b=a->lengthOfLongestSubstring(s);
    cout<<b;
    return 0;

}