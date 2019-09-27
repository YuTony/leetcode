//https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {

        string prod(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                int tmp = (num1[i] - '0') * (num2[j] - '0');
                int idx = i + j + 1;
                while (tmp > 0) {
                    tmp += prod[idx] - '0';
                    prod[idx] = tmp % 10 + '0';
                    idx -= 1;
                    tmp /= 10;
                }
            }
        }
        size_t start = prod.find_first_not_of("0");
        if (start != string::npos) {
            return prod.substr(start);
        } else {
            return "0";
        }
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
