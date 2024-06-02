class Solution {
public:
    string clearStars(string s) {
        vector<bool> take(s.size(),true);
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
              pq.push({s[i],-i});
            }
            else{
                take[i]=false;
                take[-pq.top().second]=false;
                pq.pop();
            }
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(take[i]){
                res+=s[i];
            }
        }
        return res;
        
    }
};