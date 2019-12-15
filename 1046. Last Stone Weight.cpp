//https://leetcode.com/problems/last-stone-weight/

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeight(vector<int> &stones) {
        multiset<int> s(stones.begin(), stones.end());
        while (s.size() > 1) {
            int x = *prev(s.end());
            s.erase(prev(s.end()));
            int y = *prev(s.end());
            s.erase(prev(s.end()));
            if (x != y) {
                s.insert(x - y);
            }
        }
        return s.empty() ? 0 : *(prev(s.end()));
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> stones = stringToIntegerVector(line);

        int ret = Solution().lastStoneWeight(stones);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}