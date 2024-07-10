class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yanghui(numRows);//5行
        for(int i=0;i<numRows;++i)
        {
            yanghui[i].resize(i+1);//创建i+1列,[i]不能忘
            yanghui[i][0]=yanghui[i][i]=1;
            for(int j=1;j<i;++j)
                yanghui[i][j]=yanghui[i-1][j]+yanghui[i-1][j-1];
        }
        return yanghui;
    }
};
