class Solution {
public:
    bool isValid(string s) {
        stack<char>holder;

        for(int i =0; i<s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                holder.push(s[i]);
            }else{
                if(holder.empty())return false;
                else{
                    if(s[i] == ']' && holder.top() == '[')holder.pop();
                    else if(s[i] == ')' && holder.top() == '(')holder.pop();
                    else if(s[i] == '}' && holder.top() == '{')holder.pop();
                    else return false;
                }
            }
        }
        return holder.empty();
    }
};
