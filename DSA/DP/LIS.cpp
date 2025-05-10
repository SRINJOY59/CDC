#include<bits/stdc++.h>
using namespace std;


int memoisation(vector<int>& arr, int index, int prev_index, vector<vector<int>>& dp) {
    if (index == arr.size()) return 0;
    if (dp[index][prev_index + 1] != -1) return dp[index][prev_index + 1];

    int len = memoisation(arr, index + 1, prev_index, dp);
    if (prev_index == -1 || arr[index] > arr[prev_index]) {
        len = max(len, 1 + memoisation(arr, index + 1, index, dp));
    }
    return dp[index][prev_index + 1] = len;
}


vector<int> printLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1), parent(n);
    int lastIndex = 0, maxi = 1;

    for (int index = 0; index < n; index++) {
        parent[index] = index;
        for (int prev_index = 0; prev_index < index; prev_index++) {
            if (arr[index] > arr[prev_index] && dp[prev_index] + 1 > dp[index]) {
                dp[index] = dp[prev_index] + 1;
                parent[index] = prev_index;
            }
        }
        if (dp[index] > maxi) {
            maxi = dp[index];
            lastIndex = index;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (parent[lastIndex] != lastIndex) {
        lastIndex = parent[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}



int tabulation(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--) {
        for (int prev_index = index - 1; prev_index >= -1; prev_index--) {
            int len = dp[index + 1][prev_index + 1];
            if (prev_index == -1 || arr[index] > arr[prev_index]) {
                len = max(len, 1 + dp[index + 1][index + 1]);
            }
            dp[index][prev_index + 1] = len;
        }
    }
    return dp[0][0];
}


int optimal(vector<int>&arr){
    int n = arr.size();
    vector<int>temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1;i<n;i++){
        if(arr[i] > temp.back()){
            len++;
            temp.push_back(arr[i]);
        }
        else{
            int lower = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[lower] = arr[i];
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Memoisation
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << "Memoisation solution: " << memoisation(arr, 0, -1, dp) << endl;

    // Print LIS
    vector<int> lis = printLIS(arr);
    cout << "LIS: ";
    for (int val : lis) {
        cout << val << " ";
    }
    cout << endl;

    // Tabulation
    cout << "Tabulation solution: " << tabulation(arr) << endl;

    // Optimal
    cout << "Optimal solution: " << optimal(arr) << endl;

    return 0;
}
