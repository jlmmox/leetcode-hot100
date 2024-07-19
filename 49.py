import collections


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        hashmap = collections.defaultdict(list)
        for i in strs:
            key = ''.join(sorted(i))
            hashmap[key].append(i)
        return list(hashmap.values())
    
a=["eat","tea","tan","ate","nat","bat"]#待传入的参数

solution=Solution()#创建solution类的实例

result=solution.groupAnagrams(a)
print(result) #要加括号
