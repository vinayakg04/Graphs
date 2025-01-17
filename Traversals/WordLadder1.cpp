class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // If endWord is not in the wordList, there's no valid sequence
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        // BFS initialization
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // {current word, current level}

        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();

            // Try transforming each character of currentWord
            for (int i = 0; i < currentWord.size(); i++) {
                string tempWord = currentWord;

                for (char c = 'a'; c <= 'z'; c++) {
                    tempWord[i] = c;

                    // If the transformed word is the endWord, return the path length
                    if (tempWord == endWord) {
                        return level + 1;
                    }

                    // If the transformed word is in the wordSet, enqueue it and remove it from the set
                    if (wordSet.find(tempWord) != wordSet.end()) {
                        q.push({tempWord, level + 1});
                        wordSet.erase(tempWord); // Remove to avoid revisiting
                    }
                }
            }
        }

        return 0; // No valid transformation sequence
    }
};
