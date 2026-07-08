class Solution {
private:
    vector<vector<int>> result; // store all valid combinations
    vector<int> path;           // current combination

    void dfs(vector<int>& candidates, int target, int start) {
        // Base case: target is 0 → valid combination
        if (target == 0) {
            result.push_back(path);
            return;
        }

        // Explore candidates starting from 'start'
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Prune: stop if number exceeds target
            if (candidates[i] > target) break;

            // Choose the number
            path.push_back(candidates[i]);

            // Recurse with next index (i+1), because number can only be used once
            dfs(candidates, target - candidates[i], i + 1);

            // Backtrack
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        dfs(candidates, target, 0);
        return result;
    }
};
