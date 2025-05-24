#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    double val = static_cast<double>(a) / b;

    int x = static_cast<int>(floor(val));
    int y = static_cast<int>(ceil(val));

    if (abs(x - val) < abs(y - val)) {
        cout << x << endl;
    } else {
        cout << y << endl;
    }

    return 0;
}
