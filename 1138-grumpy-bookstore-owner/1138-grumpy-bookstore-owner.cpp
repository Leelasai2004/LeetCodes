class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int now=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(!grumpy[i]) now+=customers[i];
        }
        int mx=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]) mx+=customers[i];
        }
        int l=0,r=minutes;
        int mxi=mx;
        // cout<<now<<'\n';
        while(r<n){
            // cout<<mxi<<" "<<l<<" "<<r<<'\n';
            if(grumpy[r]){
                mx+=customers[r];
            }
            if(grumpy[l]){
                mx-=customers[l];
                l++;
            }
            else{
                l++;
            }
            mxi=max(mxi,mx);
            r++;
        }
        return now+mxi;
    }
};