class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        string b = "";

        for(int i = 0; i<s.size(); i++){
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    a+=tolower(s[i]);
                }else{
                    a+=s[i];
                }
            }
        }

        b = a;
        reverse(a.begin(), a.end());

        return a == b;
    }
};
