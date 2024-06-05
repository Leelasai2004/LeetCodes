class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> f(26,0);
        bool firs=true;
        for(auto s :words){
            vector<int> f2(26,0);
            for(auto c:s){
                f2[c-'a']++;
            }
            if(firs){
                firs=false;
                f=f2;
                continue;
            }
            for(int i=0;i<26;i++){
                f[i]=min(f[i],f2[i]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            while(f[i]){
                string res;
                res+=('a'+i);
                ans.push_back(res);
                f[i]--;
            }
        }
        return ans;
    }
};