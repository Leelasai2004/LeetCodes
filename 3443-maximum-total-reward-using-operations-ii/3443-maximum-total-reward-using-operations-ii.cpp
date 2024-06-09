class Solution {
public:
    int maxTotalReward(vector<int>& v) {
       bitset<100001> possible,mask;
       sort(v.begin(),v.end());
       possible[0]=1;
       int low=0;
       for(int i=0;i<v.size();i++){
            while(low<v[i]){
                mask[low]=1;
                low++;
            }
            possible=possible | ((possible & mask)<<v[i]);
       }
       for(int i=(int)1e5;i>=0;i--){
        if(possible[i]){
            return i;
        }
       }
       return 0;
    }
};