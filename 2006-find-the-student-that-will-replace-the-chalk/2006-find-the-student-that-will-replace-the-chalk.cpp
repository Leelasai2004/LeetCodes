class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=accumulate(chalk.begin(),chalk.end(),0LL);
        long long x=k;
        x%=sum;
        int n=chalk.size();
        for(int i=0;i<n;i++){
            x-=chalk[i];
            if(x<0){
                return i;
            }
        }
        return 0;
    }
};