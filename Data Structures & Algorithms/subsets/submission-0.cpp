class Solution {
private:
    vector<vector<int>> result; // stores all subsets
    vector<int> path;           // current subset being built

    // DFS helper function
    void dfs(vector<int>& nums, int start) {
        // Save the current subset
        result.push_back(path);

        // Explore further elements
        for (int i = start; i < nums.size(); i++) {
            // Choose nums[i]
            path.push_back(nums[i]);

            // Explore subsets including nums[i]
            dfs(nums, i + 1);

            // Backtrack: remove nums[i] to explore subsets without it
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0); // start DFS from index 0
        return result;
    }
};
