//https://leetcode.com/problems/course-schedule-ii/

#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> order;
        vector<bool> gone(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !no_cycle(g, gone, done, i, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }

   private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }

    bool no_cycle(graph& g, vector<bool>& gone, vector<bool>& done, int node, vector<int>& order) {
        if (gone[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        gone[node] = done[node] = true;
        for (int p : g[node]) {
            if (!no_cycle(g, gone, done, p, order)) {
                return false;
            }
        }
        order.push_back(node);
        gone[node] = false;
        return true;
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> d = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {1, 3}};
    vector<int> ans = s.findOrder(4, d);
    return 0;
}