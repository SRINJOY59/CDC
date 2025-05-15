#include<bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};


UndirectedGraphNode* cloneDFS(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& visited) {
    if (!node) return nullptr;

    if (visited.find(node) != visited.end()) {
        return visited[node];
    }

    UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
    visited[node] = clone;

    for (UndirectedGraphNode* neighbor : node->neighbors) {
        clone->neighbors.push_back(cloneDFS(neighbor, visited));
    }

    return clone;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    return cloneDFS(node, visited);
}

