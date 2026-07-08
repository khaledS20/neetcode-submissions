// class Solution {
// public:
//     bool isPalindrome(string s) {
        
//         int left = 0;
//         int right = s.size() -1;

//         while(left < right){
//             while(left <right && !isalnum(s[left]))left++;
//             while(left <right && !isalnum(s[right]))right--;

//             if(tolower(s[left]) != tolower(s[right])) return false;

//             left++;
//             right--;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isPalindrome(string s) {
        string str1 = "";

        for(int i = 0; i<s.size(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                if((s[i] >= 'A' && s[i] <= 'Z')){
                    str1+=tolower(s[i]);
                }else{
                    str1+=s[i];
                }
            }
        }

        string str2 = str1;
        reverse(str1.begin(), str1.end());

        return str1 == str2;
    }
};
