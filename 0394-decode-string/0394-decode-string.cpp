class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string res="";
                while(st.top()!='['){
                    res=st.top()+res;
                    st.pop();
                }
                st.pop();
                string times="";
                while(!st.empty() && isdigit(st.top()) ){
                    times=st.top()+times;
                    st.pop();
                }
                int k=stoi(times);
                while(k--){
                    int x=0;
                    while(x<res.size()){
                        st.push(res[x]);
                        x++;
                    }
                }
            }
           
        }
         string res="";
            while(!st.empty()){
                res=st.top()+res;
                st.pop();
            }
            return res;
    }
};