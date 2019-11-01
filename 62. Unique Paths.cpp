//https://leetcode.com/problems/unique-paths/
class Solution {
   public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int k = m - 1;
        double res = 1;
        for (int i = 1; i <= k; i++)
            res = res * (N - k + i) / i;
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
