#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
class Solution{
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) return 0;

    // Two sets for bidirectional search
    unordered_set<string> beginSet, endSet;
    beginSet.insert(beginWord);
    endSet.insert(endWord);

    int steps = 1;
    int wordLen = beginWord.length();

    while (!beginSet.empty() && !endSet.empty()) {
        // Always expand the smaller set to optimize performance
        if (beginSet.size() > endSet.size()) {
            swap(beginSet, endSet);
        }

        unordered_set<string> nextSet;
        for (string word : beginSet) {
            for (int i = 0; i < wordLen; i++) {
                char oldChar = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == oldChar) continue;
                    word[i] = c;

                    // If the sets meet, we found the shortest path
                    if (endSet.count(word)) {
                        return steps + 1;
                    }

                    // If word is in dictionary, add to next layer and remove to avoid cycles
                    if (dict.count(word)) {
                        nextSet.insert(word);
                        dict.erase(word);
                    }
                }
                word[i] = oldChar; // Backtrack
            }
        }
        beginSet = nextSet;
        steps++;
    }

    return 0;
}
};