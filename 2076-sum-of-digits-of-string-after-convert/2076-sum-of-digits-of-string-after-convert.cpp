class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character to its corresponding position value in string
        string ans;
        for(auto c : s) {
            ans += to_string(c - 'a' + 1);
        }

        // Perform the transformation k times
        while(k--) {
            int sum = 0;
            for(auto a : ans) {
                sum += a - '0';
            }
            ans = to_string(sum);
        }
        
        return stoi(ans);
    }
};
