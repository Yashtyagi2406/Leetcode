class Solution {
public:
    string maskPII(string s) {
      bool isEmail = false;

      for(char c : s){
        if(c == '@'){
            isEmail= true;
            break;
        }
      }  

      if(isEmail){
         string temp = "";

        //  lowercase me convert
        for(char c : s)
            temp += tolower(c);

        int at = 0;
        while(temp[at] != '@')
            at++;
        
        string ans = "";

        ans = ans + temp[0];
        for(int i = 0; i< 5; i++)
            ans = ans + '*';
         ans = ans + temp[at-1];

        for(int i = at; i< temp.size(); i++)
            ans += temp[i];
        
        return ans;

      }

      vector<char> digits;

      for(char c : s){
        if(isdigit(c))
            digits.push_back(c);
      }

      int country = digits.size() -10;

      string ans = "";

      if(country > 0){
        ans += '+';

        while(country--)
            ans += '*';
        ans +='-';
      }

      ans += "***-***-";
      for(int i= digits.size() - 4; i < digits.size(); i++)
         ans += digits[i];

      return ans;
    }
};