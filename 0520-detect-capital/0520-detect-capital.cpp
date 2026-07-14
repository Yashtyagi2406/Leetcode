class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        if(n == 1) return true;

        bool shouldBeUpper = isupper(word[0]) && isupper(word[1]);

        for(int i= 1; i< n; i++){
            if((bool)isupper(word[i]) != shouldBeUpper)
                 return false;
        }
        return true;
    }
};