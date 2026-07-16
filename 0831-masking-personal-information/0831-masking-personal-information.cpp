class Solution {
public:
    string maskPII(string s) {
        if(s.find('@') != string :: npos){
             string email= "";

             for(char c : s)
                email +=tolower(c);

            int at = email.find('@');

            return string (1, email[0]) + 
                    "*****" +
                    string (1, email[at-1]) +
                    email.substr(at);
             
        }

        string digits = "";
        for(char c: s){
            if(isdigit(c))
                digits += c;
        }
        int country = digits.size()- 10;

        string ans= "";
        if(country > 0){
            ans += "+";
            ans += string(country, '*');
            ans += "-";
        }
         ans+= "***-***-";
         ans += digits.substr(digits.size()-4);
         
         return ans;
    }
};