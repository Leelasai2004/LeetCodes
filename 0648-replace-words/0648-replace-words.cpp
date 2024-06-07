class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_set<string> st;
        for(auto m:d) st.insert(m);
        string res="";
        int n=s.size();
        for(int i=0;i<n;i++){
            string pres="";
            while(s[i]!=' ' && i<n){
                pres+=s[i];
                if(st.find(pres)!=st.end()){
                    break;
                }
                i++;
            }
            while(s[i]!=' ' && i<n){
                i++;
            }
            res+=pres;
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};