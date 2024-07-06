class Solution {
public:
    int passThePillow(int n, int time) {
        time%=(n+n-2);
        for(int i=1;i<=n;i++){
            if(time==0){
                return i;
            }
             time--;
        }
        for(int j=n-1;j>=1;j--){
            if(time==0){
                return j;
            }
            time--;

        }
        return 0;
    }
};