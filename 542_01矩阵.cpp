/*
    给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。 
    两个相邻元素间的距离为 1 。
    给定矩阵的元素个数不超过 10000。
    给定矩阵中至少有一个元素是 0。
    矩阵中的元素只在四个方向上相邻: 上、下、左、右。
*/

/*
    BFS
    pair每个0元素的坐标并入队，并将矩阵中的1置为INT_MAX，
    如果0附近的值能通过0+1变小的话，说明这个附近的值计算出了到0的最近距离
    同理，这个附近的值 的 附近的值也可以通过此方法进行更新
    那么，这个附近的值的坐标也要入队
*/
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
                    q.push(make_pair(i,j)); //pair将两个数据合成一组数据
                else
                    matrix[i][j]=INT_MAX; //int的最大值
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
