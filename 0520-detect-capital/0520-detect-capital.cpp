class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0, lower = 0;

        for(char ch : word){
            if(isupper(ch))
                upper ++;
            else
                lower ++;
        }
        int n= word.size();
        if(upper == n) return true;
        if(lower == n) return true;
        if(isupper(word[0]) && lower == n-1)
            return true;

        return false;
    }
};