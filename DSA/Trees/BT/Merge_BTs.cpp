
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


Node *getMergedTree(Node * t1, Node * t2)
{
    // Complete the function.
    if(t1 == NULL && t2 == NULL) return NULL;
    int val = 0;
    if(t1 != NULL) val += t1->val;
    if(t2 != NULL) val += t2->val;
    Node* root = new Node(val);
    root->left = getMergedTree(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    root->right = getMergedTree(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
    return root;
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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ind = 0;
        Node* tree1 = getBinaryTree(arr,&ind);
        arr.clear();
        cin>>n;
        assert(n<=1000000);
        arr.resize(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ind = 0;
        Node* tree2 = getBinaryTree(arr,&ind);
        Node* mergedTree = getMergedTree(tree1,tree2);
        vector<int>ans;
        generateArray(mergedTree,ans);
        for(auto v:ans)cout<<v<<" ";
        cout<<"\n";
    }
    return 0;
}
