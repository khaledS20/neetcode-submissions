class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>holder;

        for(int i =0; i<tokens.size(); i++)
        {
            if(tokens[i] == "+"){
                int x = holder.back(); holder.pop_back();
                int y = holder.back(); holder.pop_back();
                holder.push_back(x+y);
            }
            else if(tokens[i] == "-"){
                int x = holder.back(); holder.pop_back();
                int y = holder.back(); holder.pop_back();
                holder.push_back(y-x);
            }
            else if(tokens[i] == "*"){
                int x = holder.back(); holder.pop_back();
                int y = holder.back(); holder.pop_back();
                holder.push_back(x*y);
            }
            else if(tokens[i] == "/"){
                int x = holder.back(); holder.pop_back();
                int y = holder.back(); holder.pop_back();
                holder.push_back(y/x);
            }
            else{
                holder.push_back(stoi(tokens[i]));
            }
        }
        return holder.back();
    }
};
