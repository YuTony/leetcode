//https://leetcode.com/problems/top-k-frequent-elements/

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> m;
        for (int t : nums) {
            m[t]++;
        }
        vector<int> ans;
        priority_queue<pair<int, int>> tmp;
        for (auto it = m.begin(); it != m.end(); it++) {
            tmp.push(make_pair(it->second, it->first));
            if (tmp.size() > m.size() - k) {
                ans.push_back(tmp.top().second);
                tmp.pop();
            }
        }
        return ans;
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}