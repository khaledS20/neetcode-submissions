class Solution {
private:
    vector<vector<int>> result;  // stores all valid combinations
    vector<int> path;            // current combination

    void dfs(vector<int>& candidates, int target, int start, int sum) {
        // Base case: sum equals target
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // Explore further candidates
        for (int i = start; i < candidates.size(); i++) {
            int num = candidates[i];

            // Prune: skip if sum would exceed target
            if (sum + num > target) continue;

            // Choose num
            path.push_back(num);

            // Recurse with same i (number can be used unlimited times)
            dfs(candidates, target, i, sum + num);

            // Backtrack: remove last number
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0); // start DFS from index 0
        return result;
    }
};
