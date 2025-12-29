#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_map<string, vector<char>> transitions;
    unordered_set<string> memo;

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string& s : allowed) {
            transitions[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom, "");
    }

private:
    bool dfs(string current, string next) {
        if (current.length() == 1) return true;

        if (next.length() == current.length() - 1) {
            if (memo.count(next)) return false;
            if (dfs(next, "")) return true;
            memo.insert(next);
            return false;
        }

        int idx = next.length();
        string base = current.substr(idx, 2);

        if (transitions.count(base)) {
            for (char top : transitions[base]) {
                if (dfs(current, next + top)) return true;
            }
        }

        return false;
    }
};