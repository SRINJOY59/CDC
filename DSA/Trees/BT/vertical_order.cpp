
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {



public:



vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Map: vertical -> {level -> multiset of node values}
    map<int, map<int, multiset<int>>> nodes;
    queue<tuple<TreeNode*, int, int>> q; // node, vertical, level
    q.push({root, 0, 0});

    while (!q.empty()) {
        auto [node, x, y] = q.front();
        q.pop();
        nodes[x][y].insert(node->data);
        if (node->left) q.push({node->left, x - 1, y + 1});
        if (node->right) q.push({node->right, x + 1, y + 1});
    }

    vector<vector<int>> result;
    for (auto& [x, levels] : nodes) {
        vector<int> col;
        for (auto& [y, vals] : levels) {
            col.insert(col.end(), vals.begin(), vals.end());
        }
        result.push_back(col);
    }
    return result;
}



};


































TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    vector<string> dat;
    string t;
    for (auto c : data)
    {
        if (c == ',')
        {
            dat.push_back(t);
            t.clear();
        }
        else
            t.push_back(c);
    }
    dat.push_back(t);
    int i = 0;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoll(dat[0]));
    q.push(root);
    auto cur = root;
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (dat[i] != "x")
        {
            x->left = new TreeNode(stoll(dat[i]));
            q.push(x->left);
        }
        i++;
        if (dat[i] != "x")
        {
            x->right = new TreeNode(stoll(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}

void solve() {
    string tr;
    cin >> tr;
    Solution sol;
    auto root = deserialize(tr);
    auto ans = sol.verticalTraversal(root);
    for (auto x : ans) {
        for (auto y : x)cout << y << " ";
        cout << endl;
    }
    cout << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
