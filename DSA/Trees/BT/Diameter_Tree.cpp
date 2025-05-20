#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
int dfs(TreeNode* root, int &maxi){
      if(root == NULL) return 0;
      int lc = dfs(root->left, maxi);
      int rc = dfs(root->right, maxi);
      maxi = max(maxi, lc + rc);
      return max(lc, rc) + 1;
  }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int ans = dfs(root, maxi);
        return maxi;
    }
};