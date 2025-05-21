#include <bits/stdc++.h>
using namespace std;

vector<int> binaryPalindromes;

int createPalindrome(int n, bool oddLength) {
    int res = n;
    if (oddLength) n /= 2;
    while (n > 0) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}

void generateBinaryPalindromes(int limit) {
    for (int i = 1; ; i++) {
        int p1 = createPalindrome(i, false);
        int p2 = createPalindrome(i, true);
        if (p1 > limit && p2 > limit) break;
        if (p1 <= limit) binaryPalindromes.push_back(p1);
        if (p2 <= limit) binaryPalindromes.push_back(p2);
    }
    sort(binaryPalindromes.begin(), binaryPalindromes.end());
}

int minOpsToBinaryPalindrome(int n) {
    auto it = lower_bound(binaryPalindromes.begin(), binaryPalindromes.end(), n);
    int ans = INT_MAX;
    if (it != binaryPalindromes.end())
        ans = min(ans, abs(*it - n));
    if (it != binaryPalindromes.begin())
        ans = min(ans, abs(*prev(it) - n));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generateBinaryPalindromes(1e9 + 1000);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << minOpsToBinaryPalindrome(n) << '\n';
    }

    return 0;
}