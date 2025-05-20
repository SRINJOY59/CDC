
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int size;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int subtreesz(Node* root){
    if(root == NULL) return 0;
    int left = subtreesz(root->left);
    int right = subtreesz(root->right);
    root->size = left + right + 1;
    return root->size;
}

int solve(Node* root, int &cnt, int k){
    if(root == NULL) return -1;
    int left = solve(root->left, cnt, k);
    if(left != -1) return left;
    cnt++;
    if(cnt == k) return root->val;
    int right = solve(root->right, cnt, k);
    return right;
}

int getKthElement(Node* node, int k)
{
    if(node == NULL || k < 1 || k > node->size) return -1;
    int Lsize = node->left ? node->left->size : 0;
    if(k == Lsize + 1) return node->val;
    else if(k <= Lsize) return getKthElement(node->left, k);
    else return getKthElement(node->right, k - Lsize - 1);
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
        int n,q;
        cin>>n>>q;
        assert(n<=1000000);
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ind = 0;
        Node* tree = getBinaryTree(arr,&ind);
        int nodesz = subtreesz(tree);
        for(int i=0;i<q;i++){
            int k;
            cin>>k;
            cout<<getKthElement(tree,k)<<" ";
        }
        cout<<"\n";

    }
    return 0;
}
