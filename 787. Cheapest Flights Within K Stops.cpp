//https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> g;
        for (const auto& e : flights)
            g[e[0]].emplace_back(e[1], e[2]);
        int ans = INT_MAX;
        vector<int> visited(n, 0);
        dfs(g, visited, src, dst, K + 1, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

   private:
    void dfs(unordered_map<int, vector<pair<int, int>>>& g, vector<int>& visited, int src, int dst, int k, int price, int& ans) {
        if (src == dst) {
            ans = price;
            return;
        }
        if (k == 0) return;
        visited[src] = 1;
        for (const auto& x : g[src]) {
            if (visited[x.first] == 0 && price + x.second <= ans) {
                dfs(g, visited, x.first, dst, k - 1, price + x.second, ans);
            }
        }
        visited[src] = 0;
    }
};