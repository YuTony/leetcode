//https://leetcode.com/problems/course-schedule/

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> v(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, g, v))
                return false;
        }
        return true;
    }

   private:
    typedef vector<vector<int>> graph;
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for (vector<int> t : prerequisites) {
            g[t[0]].push_back(t[1]);
        }
        return g;
    }
    bool dfs(int i, graph& g, vector<int>& v) {
        if (v[i] == -1)
            return false;
        if (v[i] == 1)
            return true;
        v[i] = -1;
        for (int i : g[i]) {
            if (!dfs(i, g, v))
                return false;
        }
        v[i] = 1;
        return true;
    }
};
