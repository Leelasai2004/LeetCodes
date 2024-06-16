class FenwickTree{
    public:
    vector<int> bit;
    int n;
    FenwickTree(int n){
        this->n=n;
        bit.resize(n+1,0);
    }
    void add(int i,int val){
        while(i<=n){
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int sum(int i){
        int ans=0;
        while(i>0){
            ans+=bit[i];
            i-=(i&-i);
        } 
        return ans;  
    }
    int sum(int l,int r){
        if(r-l<=1){
            return 0;
        }
        return sum(r-1)-sum(l);
    }
    void check(int i,vector<int>& v){
        if(i>=1 && i<v.size()-1){
            if(v[i]>v[i-1] && v[i]>v[i+1] && sum(i+1)-sum(i)==0){
               add(i+1,1);
            }
            else if((v[i]<=v[i-1] ||  v[i]<=v[i+1] )&& sum(i+1)-sum(i)!=0){
                add(i+1,-1);
            }
        }
    }
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        FenwickTree F(n);
        for(int i=1;i<n-1;i++){
             if(v[i]>v[i-1] && v[i]>v[i+1]){
                // cout<<v[i]<<" "<<i<<'\n';
               F.add(i+1,1);
             }
        }
        vector<int> res;
        for(int i=0;i<q.size();i++){
            if(q[i][0]==1){
                // cout<<q[i][1]+1<<" "<<q[i][2]+1<<'\n';
                res.push_back(F.sum(q[i][1]+1,q[i][2]+1));
            }
            else{
                //  for(int i=1;i<=n;i++){
                //     cout<<F.sum(i)-F.sum(i-1)<<" ";
                // }
                v[q[i][1]]=q[i][2];

                F.check(q[i][1]+1,v);
                F.check(q[i][1],v);
                F.check(q[i][1]-1,v);
                // cout<<"\n";
                // for(int i=1;i<=n;i++){
                //     cout<<F.sum(i)-F.sum(i-1)<<" ";
                // }
                // cout<<'\n';

            }
        }
        return res;
    }
};