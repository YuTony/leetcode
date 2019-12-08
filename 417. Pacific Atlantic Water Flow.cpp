//https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                bool reachP = false, reachA = false;
                DFS(res, matrix, i, j, m, n, reachP, reachA);
                if (reachP && reachA) res.push_back({i, j});
            }
        return res;
    }

    void DFS(vector<vector<int>>& res, vector<vector<int>>& matrix, int r, int c, int m, int n, bool& reachP, bool& reachA) {
        if (matrix[r][c] == -1 || reachP && reachA) return;
        int temp = matrix[r][c];
        matrix[r][c] = -1;
        for (int i = 0; i < 4; i++) {
            int R = r + dir[i].first, C = c + dir[i].second;
            if (R == -1 || C == -1)
                reachP = true;
            else if (R == m || C == n)
                reachA = true;
            else if (matrix[R][C] <= temp)
                DFS(res, matrix, R, C, m, n, reachP, reachA);
        }
        matrix[r][c] = temp;
    }

   private:
    vector<pair<int, int>> dir;
};