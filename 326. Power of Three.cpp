//https://leetcode.com/problems/power-of-three/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        while (n % 3 == 0)
            n /= 3;
        return (n == 1);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isPowerOfThree(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}