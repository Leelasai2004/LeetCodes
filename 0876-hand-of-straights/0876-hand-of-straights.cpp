
class Solution {
public:

// void __print(int x) { cout << x; }
// void __print(long x) { cout<< x; }
// void __print(long long x) { cout << x; }
// void __print(unsigned x) { cerr << x; }
// void __print(unsigned long x) { cerr << x; }
// void __print(unsigned long long x) { cerr << x; }
// void __print(float x) { cerr << x; }
// void __print(double x) { cerr << x; }
// void __print(long double x) { cerr << x; }
// void __print(char x) { cerr << '\'' << x << '\''; }
// void __print(const char *x) { cerr << '\"' << x << '\"'; }
// void __print(const string &x) { cerr << '\"' << x << '\"'; }
// void __print(bool x) { cerr << (x ? "true" : "false"); }
// template <typename T, typename V>
// void __print(const pair<T, V> &x){cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
// template <typename T>
// void __print(const T &x){int f = 0;cerr << '{';for (auto &i : x)cout << (f++ ? "," : ""), __print(i);cout << "}";}
// void _print() { cerr << "]\n"; }
// template <typename T, typename... V>
// void _print(T t, V... v)
// {__print(t);if (sizeof...(v))cout << ", ";_print(v...);}

// #define dbg(x...)               \
//   cout << "[" << #x << "] = ["; \
//   _print(x)


    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        int n=hand.size();
        multiset<int> st(hand.begin(),hand.end());
            // dbg(1);
        for(int i=0;i<n;i++){
            if(st.find(hand[i])==st.end()){
                continue;
            }
            int m=groupSize;
            m--;
            int j=1;
            int x=hand[i];
            while(m--){
            if(st.find(x+j)==st.end()){
                return false;
            }
            st.erase(st.find(x+j));

            j++;
            //dbg(st);
        }
        st.erase(st.find(hand[i]));
         
        }
        return true;
    }
};