class Solution {
private:
    /* ===================== TRIE NODE ===================== */
    struct TrieNode {
        TrieNode* children[26];  // pointers to next letters (a → z)
        string word;             // stores full word if this node ends a word

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };

    TrieNode* root;              // root of the Trie
    vector<string> result;       // final answer
    int rows, cols;              // board dimensions

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        /* --------- Step 1: Build Trie from words --------- */
        for (string& w : words) {
            insertWord(w);
        }

        rows = board.size();
        cols = board[0].size();

        /* --------- Step 2: DFS from each board cell --------- */
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return result;
    }

private:
    /* ===================== INSERT WORD INTO TRIE ===================== */
    void insertWord(string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            // Create node if path doesn't exist
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            // Move to next character
            node = node->children[idx];
        }

        // Store full word at last character node
        node->word = word;
    }

    /* ===================== DFS SEARCH ===================== */
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        /* --------- Boundary / Pruning Checks --------- */
        if (ch == '#') return;                     // already visited
        if (!node->children[ch - 'a']) return;     // no word with this prefix

        // Move Trie pointer forward
        node = node->children[ch - 'a'];

        /* --------- Word Found --------- */
        if (!node->word.empty()) {
            result.push_back(node->word);  // add word to result
            node->word.clear();             // prevent duplicates
        }

        /* --------- Mark cell as visited --------- */
        board[r][c] = '#';

        /* --------- Explore neighbors --------- */
        if (r > 0) dfs(board, r - 1, c, node);
        if (c > 0) dfs(board, r, c - 1, node);
        if (r < rows - 1) dfs(board, r + 1, c, node);
        if (c < cols - 1) dfs(board, r, c + 1, node);

        /* --------- Backtrack --------- */
        board[r][c] = ch;
    }
};
