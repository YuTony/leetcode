//https://leetcode.com/problems/ugly-number-ii/

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> ans(n);
        int i1 = 0, i2 = 0, i3 = 0;
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = min(ans[i1] * 2, min(ans[i2] * 3, ans[i3] * 5));
            if (ans[i] == ans[i1] * 2) i1++;
            if (ans[i] == ans[i2] * 3) i2++;
            if (ans[i] == ans[i3] * 5) i3++;
        }
        return ans[n - 1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().nthUglyNumber(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}