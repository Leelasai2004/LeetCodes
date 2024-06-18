class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        set<pair<int,int>> st;
        int n=d.size();
        vector<array<int,2>> task;
        for(int i=0;i<n;i++){
            task.push_back({d[i],-p[i]});
        }
        sort(task.begin(),task.end());
        int mn=task[0][1];
        for(int i=0;i<n;i++){
            task[i][1]=min(mn,task[i][1]);
            mn=min(mn,task[i][1]);
        }
        for(int i=0;i<n;i++){
            st.insert({task[i][0],task[i][1]});
        }
        int ans=0;
        for(int i=0;i<w.size();i++){
            auto it=st.upper_bound({w[i],1e9});
            // cout<<it->first<<" "<<it->second<<'\n';
            if(it==st.begin()) continue;
            it--;
            ans-=(it->second);
            // cout<<ans<<'\n';
        }
        return ans;
    }
};