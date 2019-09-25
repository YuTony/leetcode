//https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int N) {
        if (N <= 1)
            return N;
        else
            return fib(N - 1) + fib(N - 2);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().fib(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}