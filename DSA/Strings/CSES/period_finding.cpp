#include<bits/stdc++.h>
using namespace std;

void FastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}

vector<int> zFunction(const string &s) {
  const int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  FastIO();

  string s;
  cin >> s;

  const int n = s.size();
  const auto z = zFunction(s);

  for (int i = 1; i < n; ++i) {
    if (z[i] + i == n) {
      cout << i << " ";
    }
  }
  cout << n << "\n";

  return 0;
}