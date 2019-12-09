class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    q.push(make_pair(i,j));
                else
                    matrix[i][j]=INT_MAX;
            }
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            for(auto dir:dirs)
            {
                int x=temp.first+dir[0];
                int y=temp.second+dir[1];
                if(x<0||x>=m||y<0||y>=n||(matrix[temp.first][temp.second]+1>=matrix[x][y]))
                    continue;
                matrix[x][y]=matrix[temp.first][temp.second]+1;
                q.push(make_pair(x,y));
            }
        }
        return matrix;
    }
};
