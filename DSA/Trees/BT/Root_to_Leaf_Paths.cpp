#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void solve(Node* root, vector<int> arr, vector<vector<int>>& paths) {
        if (root == NULL) return;

        arr.push_back(root->data);

        if (root->left == NULL && root->right == NULL) {
            paths.push_back(arr);
            return;
        }

        solve(root->left, arr, paths);
        solve(root->right, arr, paths);
        arr.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<int> arr;
        vector<vector<int>> paths;
        solve(root, arr, paths);
        return paths;
    }
};

void printPaths(const vector<vector<int>>& paths) {
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6

    Expected Output:
    1 2 4
    1 2 5
    1 3 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    cout << "Root-to-Leaf Paths:" << endl;
    printPaths(paths);

    return 0;
}
