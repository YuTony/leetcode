//https://leetcode.com/problems/word-ladder/

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int counter = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return counter;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (word[j] = 'a'; word[j] < 'z'; word[j]++) {
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            counter++;
        }
        return 0;
    }
};