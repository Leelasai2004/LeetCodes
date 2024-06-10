class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> c=h;
        sort(c.begin(),c.end());
        int cnt=0;
        for(int i=0;i<c.size();i++){
            if(c[i]!=h[i]){
                cnt++;
            }
        }
        return cnt;
    }
};