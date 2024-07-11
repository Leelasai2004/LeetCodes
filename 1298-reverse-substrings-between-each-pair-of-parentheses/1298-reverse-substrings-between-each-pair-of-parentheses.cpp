class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n=s.size();
        vector<int> portal(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j=st.top();
                st.pop();
                portal[i]=j;
                portal[j]=i;
            }
        }
        int x=1;
        string res="";
        for(int i=0;i<n;i+=x){
            if(s[i]=='(' || s[i]==')'){
                i=portal[i];
                x=-x;
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};