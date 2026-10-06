class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>hold;

        for(auto token : tokens){
            if(token == "+"){
                int x = hold.back();hold.pop_back();
                int y = hold.back();hold.pop_back();
                hold.push_back(y + x);
            }
            else if(token == "-"){
                int x = hold.back();hold.pop_back();
                int y = hold.back();hold.pop_back();
                hold.push_back(y - x);
            }
            else if(token == "*"){
                int x = hold.back();hold.pop_back();
                int y = hold.back();hold.pop_back();
                hold.push_back(y * x);
            }
            else if(token == "/"){
                int x = hold.back();hold.pop_back();
                int y = hold.back();hold.pop_back();
                hold.push_back(y / x);
            }
            else{
                hold.push_back(stoi(token));
            }
        }
        return hold.back();
    }
};
