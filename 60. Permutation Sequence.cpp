//https://leetcode.com/problems/permutation-sequence/
int fact(int n)
{
    return (n != 1) ? n * fact(n - 1) : 1;
}

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int tmp;
        for (int i = 1; i <= n; ++i) {
            nums[i - 1] = i;
        }
        string ans = "";
        int f = fact(n);
        for (int i = n; i >= 2; --i) {
            f /= i;
            tmp = (k - 1) / f;
            ans += to_string(nums[tmp]);
            nums.erase(nums.begin() + tmp);
            k = k - tmp*f;
        }
        ans += to_string(nums[0]);
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
