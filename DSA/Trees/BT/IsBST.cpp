
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> check(Node* root, bool &isBST) {
    if (root == NULL) {
        return {1e9, -1e9}; // min, max
    }

    pair<int, int> Left = check(root->left, isBST);
    pair<int, int> Right = check(root->right, isBST);

    // Check BST property
    if (root->val >= Right.first) isBST = false;
    if (root->val <= Left.second) isBST = false;

    // Return updated min and max in this subtree
    return {min(root->val, Left.first), max(root->val, Right.second)};
}


bool isBst(Node* root) {
    //Complete the function
    bool isBST = true;
    pair<int, int>ans = check(root, isBST);
    return isBST;
}

Node* getBinaryTree(vector<int> &num, int*ind) {
    if(num[*ind] == -1)
        return NULL;
    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num,ind);
    (*ind)++;
    node->right = getBinaryTree(num,ind);
    return node;
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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ind = 0;
        Node* tree = getBinaryTree(arr,&ind);
        if(isBst(tree)){
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
    }
    return 0;
}
