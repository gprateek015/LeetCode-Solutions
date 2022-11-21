class Solution {
    void helper(vector<vector<char>>& maze, pair<int, int> &curr, queue<pair<int, int>> &q, int &next) {
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};
        for(int i=0; i<4; i++) {
            int a = curr.first + x[i];
            int b = curr.second + y[i];
            if(a >= 0 && a < maze.size() && b>=0 && b<maze[0].size()) {
                if(maze[a][b]=='.') {
                    q.push({a, b});
                    next++;
                    maze[a][b] = '+';
                }
            }
        }
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        queue<pair<int, int>> q;
        q.push({ent[0], ent[1]});
        int curr = 1;
        int next = 0;
        int h=0;
        while(q.size()) {
            pair<int, int> cur = q.front();
            q.pop();
            curr--;
            maze[cur.first][cur.second] = '+';
            if((cur.first == 0 || cur.first == maze.size()-1 || cur.second==0 || cur.second==maze[0].size()-1) && h) {
                return h;
            }
            helper(maze, cur, q, next);
            if(!curr) {
                h++;
                curr = next;
                next = 0;
            }
        }
        return -1;
    }
};