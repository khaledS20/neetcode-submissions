class Solution {
public:
    string multiply(string num1, string num2) {
        

        if(num1 == "0" || num2 == "0") return "0";

        int a1 = num1.size();
        int a2 = num2.size();

        vector<int>hold(a1 + a2, 0);

        for(int i = a1 - 1; i>=0; i--){
            for(int j = a2 - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + hold[j + i + 1];

                hold[i + j + 1] = sum%10;
                hold[i + j] +=sum/10;
            }
        }

        string s = "";
        for(int i = 0; i<hold.size(); i++){
            if(!(s.empty() && hold[i] == 0)){
                s.push_back(hold[i] + '0');
            }
        }
        return s;
    }
};
