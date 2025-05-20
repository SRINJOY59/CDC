
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> getZigzagLevelorderTraversal(Node* root) {
  // Complete the function.
    if(root == NULL) return {};
        map<int, vector<int>>ans;
        queue<pair<int, Node*>>q;
        q.push({0, root});
        int flag = 0;
        while(!q.empty()){
            Node* node = q.front().second;
            int level = q.front().first;
            q.pop();
            ans[level].push_back(node->val);
            if(node->left){
                q.push({level+1, node->left});
            }
            if(node->right){
                q.push({level+1, node->right});
            }

        }
        int level = 0;
        vector<vector<int>>answer;
        
        for(auto it: ans){
            level = it.first;
            if(level&1){
                vector<int>result = it.second;
                reverse(result.begin(), result.end());
                answer.push_back(result);
            }
            else
                answer.push_back(it.second);
        }
        return answer;
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
        vector<vector<int>> ans = getZigzagLevelorderTraversal(tree);
        for(auto u:ans){
            for(auto v:u){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
