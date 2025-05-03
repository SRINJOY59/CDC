#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
vector<T> sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

struct manacher {
    vector<int> p;

    void run_manacher(string s) {
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++) {
            p[i] = max(0, min(r - i, p[l + r - i]));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    void build(string s) {
        string t = "#";
        for (auto v : s) {
            t += v;
            t += "#";
        }
        run_manacher(t);
    }

    string longest_pallindromic_substring(string original) {
        int max_length = -1, center = -1;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] > max_length) {
                max_length = p[i];
                center = i;
            }
        }
        int start = (center - max_length + 1) / 2;
        return original.substr(start, max_length - 1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        manacher m;
        m.build(str);
        cout << m.longest_pallindromic_substring(str) << endl;
    }
    return 0;
}
