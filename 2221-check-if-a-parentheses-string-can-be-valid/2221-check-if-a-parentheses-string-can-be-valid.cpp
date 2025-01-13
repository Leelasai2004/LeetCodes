class Solution {
public:   
bool canBeValid(string s, string locked) {
    // If the string length is odd, it's impossible to make it valid.
    if (s.size() % 2 != 0) {
        return false;
    }

    // Validate the string for '(' opening balance.
    int openBalance = 0; // Tracks the balance of '('.
    int wildcards = 0;   // Tracks the number of unlocked characters.

    // First pass: Traverse from left to right for '('.
    for (int i = 0; i < s.size(); ++i) {
        if (locked[i] == '1') {
            // If the character is locked:
            if (s[i] == '(') {
                openBalance++; // Increment balance for '('.
            } else {
                openBalance--; // Decrement balance for ')'.
            }
        } else {
            // If the character is unlocked, treat it as a wildcard.
            wildcards++;
        }

        // If openBalance + wildcards is negative, we can't balance up to this point.
        if (openBalance + wildcards < 0) {
            return false;
        }
    }

    // Validate the string for ')' closing balance.
    int closeBalance = 0; // Tracks the balance of ')'.
    wildcards = 0;        // Reset the wildcard count.

    // Second pass: Traverse from right to left for ')'.
    for (int i = s.size() - 1; i >= 0; --i) {
        if (locked[i] == '1') {
            // If the character is locked:
            if (s[i] == ')') {
                closeBalance++; // Increment balance for ')'.
            } else {
                closeBalance--; // Decrement balance for '('.
            }
        } else {
            // If the character is unlocked, treat it as a wildcard.
            wildcards++;
        }

        // If closeBalance + wildcards is negative, we can't balance up to this point.
        if (closeBalance + wildcards < 0) {
            return false;
        }
    }

    // If both passes are valid, the string can be valid.
    return true;
}
};
