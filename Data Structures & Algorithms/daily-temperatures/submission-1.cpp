// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int>hold;
//         vector<int>result(temperatures.size(), 0);

//         for(int i = temperatures.size() - 1; i>= 0; i--){
//             while(!hold.empty() && temperatures[i] > temperatures[hold.top()]){
//                 hold.pop();
//             }

//             if(!hold.empty()){
//                 result[i] = hold.top() - i;
//             }

//             hold.push(i);
//         }
//         return result;
//     }
// };
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> hold;
        vector<int> result(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!hold.empty() &&
                   temperatures[i] >= temperatures[hold.top()]) {
                hold.pop();
            }

            if (!hold.empty()) {
                result[i] = hold.top() - i;
            }

            hold.push(i);
        }

        return result;
    }
};