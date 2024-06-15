class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v(profits.size());
        for(int i=0;i<profits.size();i++){
            v[i]={capital[i],profits[i]};
        }
        sort(v.begin(),v.end());
        int idx=0;
        int n=v.size();
        multiset<int> feasible;
        while(k--){
            for(;idx<n;){
                if(v[idx].first<=w){
                    feasible.insert(v[idx].second);
                    idx++;
                }
                else{
                    break;
                }
            }
            if(feasible.empty()){
                break;
            }
            auto it=feasible.end();
            it--;
            w+=*it;
            feasible.erase(it);
        }
        return w;
    }
};