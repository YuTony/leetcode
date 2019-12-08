//https://leetcode.com/problems/word-ladder-ii/

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        graph g;
        vector<vector<string>> paths;
        vector<string> path = {beginWord};
        if (buildGraph(g, beginWord, endWord, dict)) {
            findPaths(g, beginWord, endWord, path, paths);
        }
        return paths;
    }

   private:
    typedef unordered_map<string, vector<string>> graph;

    bool buildGraph(graph& g, string beginWord, string endWord, unordered_set<string>& dict) {
        unordered_set<string> todo;
        todo.insert(beginWord);
        while (!todo.empty()) {
            if (todo.find(endWord) != todo.end()) {
                return true;
            }
            for (string t : todo) {
                dict.erase(t);
            }
            unordered_set<string> temp;
            for (string w : todo) {
                string current = w;
                for (int i = 0; i < w.size(); i++) {
                    char c = w[i];
                    for (w[i] = 'a'; w[i] < 'z'; w[i]++) {
                        if (dict.find(w) != dict.end()) {
                            temp.insert(w);
                            g[current].push_back(w);
                        }
                    }
                    w[i] = c;
                }
            }
            swap(todo, temp);
        }
        return false;
    }

    void findPaths(graph& g, string beginWord, string endWord, vector<string>& path, vector<vector<string>>& paths) {
        if (beginWord == endWord) {
            paths.push_back(path);
        } else {
            for (string child : g[beginWord]) {
                path.push_back(child);
                findPaths(g, child, endWord, path, paths);
                path.pop_back();
            }
        }
    }
};