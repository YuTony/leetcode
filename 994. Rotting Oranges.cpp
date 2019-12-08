//https://leetcode.com/problems/rotting-oranges/

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int counter = 0, res = -1;
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] > 0) counter++;
            }
        }
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                vector<int> cur = q.front();
                counter--;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = cur[0] + dir[i][0], y = cur[1] + dir[i][1];
                    if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        if (counter == 0) return res == -1 ? 0 : res;
        return -1;
    }

   private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};