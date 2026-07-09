class Solution {
public:
    int evalRPN(vector<string>& s) {
        vector<int>v;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == "+"){
                int x = v.back(); v.pop_back();
                int y = v.back(); v.pop_back();
                v.push_back(y+x);
            }
            else if(s[i] == "*"){
                int x = v.back(); v.pop_back();
                int y = v.back(); v.pop_back();
                v.push_back(y*x);
            }
            else if(s[i] == "-"){
                int x = v.back(); v.pop_back();
                int y = v.back(); v.pop_back();
                v.push_back(y-x);
            }
            else if(s[i] == "/"){
                int x = v.back(); v.pop_back();
                int y = v.back(); v.pop_back();
                v.push_back(y/x);
            }
            else{
                v.push_back(stoi(s[i]));
            }
        }
        return v.back();
    }
};
