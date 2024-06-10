class Solution {
public:
    void heapify(vector<int> &v,int n,int i){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && v[left]<v[smallest])
        {
            smallest=left;
        }
        if(right<n && v[right]<v[smallest])
        {
            smallest=right;
        }
        if(smallest!=i){
            swap(v[i],v[smallest]);
            heapify(v,n,smallest);
        }
    }
    void heapsort(vector<int> &arr){
        int n=arr.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
        reverse(arr.begin(),arr.end());
    }
    int heightChecker(vector<int>& h) {
        vector<int> c=h;
        heapsort(c);
        int cnt=0;
        for(int i=0;i<c.size();i++){
            if(c[i]!=h[i]){
                cnt++;
            }
        }
        return cnt;
    }
};