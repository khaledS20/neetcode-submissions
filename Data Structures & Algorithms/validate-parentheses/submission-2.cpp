class Solution {
public:
    bool isValid(string s) {
        stack<char>holder;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                holder.push(s[i]);
            }else{
                if(!holder.empty()){
                    if(holder.top() == '[' && s[i] == ']'){
                        holder.pop();
                    }else if(holder.top() == '{' && s[i] == '}'){
                        holder.pop();
                    }else if(holder.top() == '(' && s[i] == ')'){
                        holder.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return holder.empty();
    }
};
