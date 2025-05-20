
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int>&inorder, vector<int>&postorder, int &postorderIndex, int left, int right){
    if(left > right) return NULL;
    int val = postorder[postorderIndex];
    postorderIndex--;
    Node* root = new Node(val);
    int index = -1;
    for(int i = left; i <= right; i++){
        if(inorder[i] == val){
            index = i;
            break;
        }
    }
    root->right = buildTree(inorder, postorder, postorderIndex, index+1, right);
    root->left = buildTree(inorder, postorder, postorderIndex, left, index-1);
    return root;
}

Node* getBinaryTree(vector<int>&inorder,vector<int>&postorder)
{
  // Complete the function.
  int postorderIndex = postorder.size()-1;
  int left = 0;
  int right = inorder.size()-1;
  return buildTree(inorder, postorder, postorderIndex, left, right);
}

void generateArray(Node* root, vector<int>&ans){
    if(root==NULL){
        ans.push_back(-1);
        return;
      }
    ans.push_back(root->val);
    generateArray(root->left,ans);
    generateArray(root->right,ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        assert(n<=1000000);
        vector<int>arr1(n);
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        vector<int>arr2(n);
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        Node* tree = getBinaryTree(arr1,arr2);
        vector<int>ans;
        generateArray(tree,ans);
        for(auto v:ans)cout<<v<<" ";
        cout<<"\n";
    }
    return 0;
}
