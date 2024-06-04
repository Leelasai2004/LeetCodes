class Solution {
public:
    bool is_char(char c){
        if(c>='a' && c<='z'){
            return true;
        }
        if(c>='A' && c<='Z'){
            return true;
        }
        if(c>='0' && c<='9'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(is_char(s[i])){
                if(s[i]>='A' && s[i]<='Z'){
                    int x=s[i]-'A';
                    res+=('a'+x);
                }
                else{
                    res+=s[i];
                }
            }
        }
        string b=res;
        reverse(b.begin(),b.end());
        return b==res;
    }
};