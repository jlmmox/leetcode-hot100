#include<cstring>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        
        //如果s的长度是奇数，不可能是有效的括号，直接返回false
       
       if(s.size() % 2 != 0)
            return false;
            
        
        //创建一个哈希表，用来存储每个右括号对应的左括号
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        //创建一个栈用于存储左括号
        stack<char> stk;
        //遍历字符串s的每一个字符，并将其存储为char类型
        for(char c : s){
            //判断当前字符是否是右括号，如果是则进行下一步判断
            //如果不是就将左括号放入栈顶进行下一轮循环判断
            //通过count函数来判断哈希表中的键，也就是所有右括号
            if(map.count(c)){
                //map.count()不是0则表示是右括号，继续进行下一步判断
                //首先判断栈是否为空，如果栈为空，则表示第一个字符是右括号，不可能是有效的括号
                //如果栈不是空，代表有左括号，继续判断栈顶的左括号和哈希表中的当前右括号的左括号是否相等
                //不相等直接返回false
                if(stk.empty() || stk.top() != map[c]){
                    return false;
                }
                //走到这一步说明左括号匹配，将左括号弹出栈顶，继续进行下一轮的匹配
                stk.pop();
            }else{
                //右括号匹配，左括号直接入栈
                //首先走到这一步表示，在s的遍历过程中，第一个字符不是右括号,而是左括号
                //再将左括号添加到栈顶，方便下一轮循环的时候与哈希表的右括号的左括号进行比对
                stk.push(c);
            }
        }
        //遍历完所有字符后，如果栈为空则说明所有括号都成功匹配，返回true
        //否则说明有未被匹配的左括号，返回false
        return stk.empty();
    }
};
