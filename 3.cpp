#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxnum=1;
        
       if(s=="")
       return 0;
        char a[s.length()];
        for(int i=0;i<s.length();i++)
        {   int m=0;
            int newmax=0;
            a[m]=s[i];
            newmax+=1;
           
            for(int j=1;j<s.length()-i;j++)
            {      int c=0;
                for(int b=0;b<=m;b++)
                {
                if(s[i+j]==a[b])
                {
                    maxnum=std::max(maxnum,newmax);
                    c=1;
                    break;
                }
                }
                   if(c==1)
                   break;
                    newmax+=1;
                    m+=1;
                    a[m]=s[i+j];
                
                if(j==s.length()-i-1)
                {
                    maxnum=std::max(maxnum,newmax);
                }
                
               
            }
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