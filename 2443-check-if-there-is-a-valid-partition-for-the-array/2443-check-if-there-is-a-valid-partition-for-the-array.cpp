class Solution {
public:
    bool validPartition(vector<int>& n) {
    int size = n.size();
    bool dp[4] = {true, false, false, false};

    if (size < 2) {
        return false;
    }

    if (size >= 2) {
        dp[2] = (n[0] == n[1]);
    }

    for (int i = 2; i < size; ++i) {
        bool twoEqual = false;
        if (n[i] == n[i - 1]) {
            twoEqual = true;
        }

        bool threeEqual = false;
        if (n[i] == n[i - 1] && n[i] == n[i - 2]) {
            threeEqual = true;
        }

        bool threeConsecutive = false;
        if (n[i] - 1 == n[i - 1] && n[i] - 2 == n[i - 2]) {
            threeConsecutive = true;
        }

        bool three = threeEqual || threeConsecutive;

        if (dp[(i - 1) % 4] && twoEqual) {
            dp[(i + 1) % 4] = true;
        } else if (dp[(i - 2) % 4] && three) {
            dp[(i + 1) % 4] = true;
        } else {
            dp[(i + 1) % 4] = false;
        }
    }

    bool result = dp[size % 4];
    return result;
}

};