class Solution {
public:
    bool isValid(string s) {
        stack<char>hold;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                hold.push(s[i]);
            }else{
                if(!hold.empty()){
                    if(hold.top() == '(' && s[i] == ')') hold.pop();
                    else if(hold.top() == '{' && s[i] == '}') hold.pop();
                    else if(hold.top() == '[' && s[i] == ']') hold.pop();
                    else return false;
                }else return false;
            }
        }
        return hold.empty();
    }
};
