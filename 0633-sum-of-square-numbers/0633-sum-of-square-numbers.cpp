class Solution {
public:
    bool judgeSquareSum(int c) {
      
        for(int i=0;i<=sqrt(c);i++){
            int req=c-i*i;
            int s=sqrtl(req);

            if(i*i+s*s==c){
                return true;
            }
        }
        return false;
    }
};