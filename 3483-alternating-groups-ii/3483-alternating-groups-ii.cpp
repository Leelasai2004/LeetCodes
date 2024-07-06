class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        vector<int> prefixIndex(n, 0);
        prefixIndex[0] = 0;
        for (int i = 1; i < n; i++) {
            if (colors[i - 1] != colors[i]) {
                prefixIndex[i] = prefixIndex[i - 1];
            } else {
                prefixIndex[i] = i;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i - prefixIndex[i] + 1 >= k) {
                count++;
            }
        }
        return count;
    }
};
