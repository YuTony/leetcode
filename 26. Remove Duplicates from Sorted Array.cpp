//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int> &nums) {
        int s = nums.size();
        if (!s) return 0;
        auto i = nums.begin() + 1;
        while (i != nums.end()) {
            if (*i == *(i - 1)) {
                i = nums.erase(i);
            } else
                i++;
        }
        return nums.size();
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

        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}