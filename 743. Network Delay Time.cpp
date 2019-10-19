//https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distances(N + 1, __INT_MAX__);
        distances[K] = 0;
        for (int i = 0; i < N; i++) {
            for (auto t : times)
            {
                int u = t[0], v = t[1], w = t[2];
                if (distances[u] != __INT_MAX__ && distances[v] > distances[u] + w) {
                    distances[v] = distances[u] + w;
                }
            }
        }
        int max = 0;
        for (int i = 1; i <= N; i++) {
            max = max < distances[i] ? distances[i] : max;
        }
        return max != __INT_MAX__ ? max : -1;
    }
};
