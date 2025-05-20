#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void solve(Node* root, Node** head, Node** prev){
        if(root == NULL) return;
        solve(root->left, head, prev);
        if(*prev == NULL) *head = root;
        else{
            (*prev)->right = root;
            root->left = *prev;
        }
        *prev = root;
        solve(root->right, head, prev);
    }
    Node* bToDLL(Node* root) {
        // code here
        Node* head = NULL;
        Node* prev = NULL;
        solve(root, &head, &prev);
        return head;
    }
};