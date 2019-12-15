//https://leetcode.com/problems/rectangle-area/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F);
        if (A >= G || C <= E || D <= F || B >= H)
            return s1 + s2;
        int s3 = (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
        return s1 - s3 + s2;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int A = stringToInteger(line);
        getline(cin, line);
        int B = stringToInteger(line);
        getline(cin, line);
        int C = stringToInteger(line);
        getline(cin, line);
        int D = stringToInteger(line);
        getline(cin, line);
        int E = stringToInteger(line);
        getline(cin, line);
        int F = stringToInteger(line);
        getline(cin, line);
        int G = stringToInteger(line);
        getline(cin, line);
        int H = stringToInteger(line);

        int ret = Solution().computeArea(A, B, C, D, E, F, G, H);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}