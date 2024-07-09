#include <vector>
#include <string>
#include <array>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        std::array<int, 26> p_count{0};
        std::array<int, 26> s_count{0};
        
        for (char c : p) {
            p_count[c - 'a']++;//计算p中元素出现的个数
        }
        
        int left = 0, right = 0;
        while (right < s.length()) {
            s_count[s[right] - 'a']++;//计算s中元素出现的个数，如果滑动窗口长度不够则一直添加，如果够了则一次只添加最右边新加入的元素
            
            if (right - left + 1 == p.length())//此时滑动窗口的大小为p的长度 
            {
                if (s_count == p_count)//s和p中元素出现的个数相等时
                 {
                    result.push_back(left);//存入左指针的位置
                }
                s_count[s[left] - 'a']--;//去除left所在的元素
                left++;
            }
            right++;
        }
        
        return result;
    }
};

