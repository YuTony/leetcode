//https://leetcode.com/problems/find-the-town-judge/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust_to(N + 1, 0), trust_from(N + 1, 0);
        for (auto t : trust) {
            trust_from[t[0]]++;
            trust_to[t[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (trust_to[i] == N - 1 && trust_from[i] == 0)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << s.findJudge(n, trust);
}