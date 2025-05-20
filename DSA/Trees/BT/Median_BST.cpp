#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int size;
    Node *left, *right;
    Node(int x) : val(x), size(1), left(NULL), right(NULL) {}
};

int subtreesz(Node* root) {
    if (!root) return 0;
    int left = subtreesz(root->left);
    int right = subtreesz(root->right);
    root->size = left + right + 1;
    return root->size;
}

int kthElement(Node* root, int k) {
    if (!root || k < 1 || k > root->size) return -1;
    int Lsize = root->left ? root->left->size : 0;
    if (k == Lsize + 1) return root->val;
    else if (k <= Lsize) return kthElement(root->left, k);
    else return kthElement(root->right, k - Lsize - 1);
}

void Inorder(Node* root, vector<int>&answer){
    if(root == NULL) return ;
    Inorder(root->left, answer);
    answer.push_back(root->val);
    Inorder(root->right, answer);
}

int getMedian(Node* root){
    vector<int>temp;
    if(root == NULL) return 0 ;
    Inorder(root, temp) ;
    int n = temp.size() ;
    if(temp.size() % 2 == 0){
        return ((temp[n/2] + temp[(n/2 - 1)])/2);
    }
    else{
        return temp[n/2];
    }
}

Node* getBinaryTree(vector<int>& num, int* ind) {
    if (*ind >= num.size() || num[*ind] == -1) {
        (*ind)++;  // Important: move past the -1
        return NULL;
    }

    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num, ind);
    node->right = getBinaryTree(num, ind);

    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ind = 0;
        Node* root = getBinaryTree(arr, &ind);
        cout << getMedian(root) << "\n";
    }

    return 0;
}
