//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int n) {
        double x = 1;
        for (;;) {
	        double nx = (x + n / x) / 2;
	        if (abs (x - nx) < 0.000001)  break;
	        x = nx;
        }
        return x;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
