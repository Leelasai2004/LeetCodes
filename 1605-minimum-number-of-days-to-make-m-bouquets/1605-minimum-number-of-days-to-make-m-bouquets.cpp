class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int l=0,r=*max_element(b.begin(),b.end());
        int ans=-1;
        while(l<=r){
            int mid=l-(l-r)/2;
            int res=0,cnt=0;
            for(auto n:b ){
                if(n<=mid){
                    cnt++;
                }
                else
                {
                    res+=(cnt/k);
                    cnt=0;
                }
            }
            res+=(cnt/k);
            // cout<<mid<<" "<<l<<" "<<r<<" "<<res<<'\n';
            if(res>=m){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }

        }
        return ans;
    }
};