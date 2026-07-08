class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    /* ================= ADD WORD ================= */
    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            // Create node if it doesn't exist
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        // Mark end of word
        node->isEnd = true;
    }

    /* ================= SEARCH WORD ================= */
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    /* ================= DFS HELPER ================= */
    bool dfs(const string& word, int index, TrieNode* node) {
        // If we've processed all characters
        if (index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];

        // Case 1: Normal character
        if (c != '.') {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            return dfs(word, index + 1, node->children[idx]);
        }

        // Case 2: Wildcard '.'
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
        }

        return false;
    }
};
