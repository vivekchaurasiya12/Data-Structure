class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

    // 1,000 to 999,999 -> 1 comma
    if (n >= 1000) {
        ans += min(n, 999999LL) - 1000 + 1;
    }

    // 1,000,000 to 999,999,999 -> 2 commas
    if (n >= 1000000) {
        ans += 2LL * (min(n, 999999999LL) - 1000000 + 1);
    }

    // 1,000,000,000 to 999,999,999,999 -> 3 commas
    if (n >= 1000000000LL) {
        ans += 3LL * (min(n, 999999999999LL) - 1000000000LL + 1);
    }

    // 1,000,000,000,000 to 999,999,999,999,999 -> 4 commas
    if (n >= 1000000000000LL) {
        ans += 4LL * (min(n, 999999999999999LL)
                      - 1000000000000LL + 1);
    }

    // 1,000,000,000,000,000 -> 5 commas
    if (n >= 1000000000000000LL) {
        ans += 5;
    }

    return ans;
    }
};