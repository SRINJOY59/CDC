#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
TreeNode* solve(vector<int>&arr, int start, int end){
    if(start > end) return NULL;
    int mid = start + (end - start)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = solve(arr, start, mid-1);
    root->right = solve(arr, mid+1, end);
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int>arr;
    ListNode* temp = A;
    while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    int n = arr.size();
    return solve(arr, 0, n-1);
}
