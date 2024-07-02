class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum=0,mx=INT_MIN;
        for(int i=0;i<v.size();i++){
            mx=max(mx,v[i]+sum);
            sum=max(0,sum+v[i]);
        }
        return mx;
    }
};