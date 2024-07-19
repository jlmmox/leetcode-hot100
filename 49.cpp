#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;//key是strs中的每一个字符串,value是“strs中每一个字符串”的每一个字母出现的个数
        for(string str:strs) {//遍历strs中的每一个字符串
            int counts[26] = {0};
            for(char c:str) {//遍历字符串中的每一个字母
                counts[c-'a']++;//计数
            }
            string key = "";
            for(int i = 0;i<26;++i) {
                if(counts[i]!=0) {
                    key.push_back(i+'a');
                    key.push_back(counts[i]);
                }
            }
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& p:map) {
            res.push_back(p.second);//res中存的是strs中的字符串
        }
        return res;
    }
};
