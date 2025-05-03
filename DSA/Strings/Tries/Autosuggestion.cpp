#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEndOfWord;
    int prefix;
    vector<string> wend;

    TrieNode() {
        isEndOfWord = false;
        prefix = 0;
    }
};

class Trie {
private:
    void dfs(TrieNode* node, vector<string>& topk, int cnt) {
        if ((int)topk.size() >= cnt) return;

        if (node->isEndOfWord) {
            for (const auto& word : node->wend) {
                if ((int)topk.size() >= cnt) break;
                topk.push_back(word);
            }
        }

        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if ((int)topk.size() >= cnt) break;
            dfs(it->second, topk, cnt);
        }
    }

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            node->prefix++;
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        node->wend.push_back(word);
    }

    void Delete(const string& word) {
        TrieNode* node = root;
        stack<TrieNode*> nodes;
        nodes.push(root);
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) return; // Word not found
            node = node->children[ch];
            nodes.push(node);
        }
        if (!node->isEndOfWord) return; // Word not found as complete word

        node->isEndOfWord = false;
        auto it = find(node->wend.begin(), node->wend.end(), word);
        if (it != node->wend.end()) {
            node->wend.erase(it);
        }

        // Decrement prefix counters
        for (int i = (int)word.size(); i >= 0 && !nodes.empty(); --i) {
            TrieNode* nd = nodes.top(); nodes.pop();
            nd->prefix--;
        }
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        return true;
    }

    vector<string> TopKStrings(const string& prefix, int k) {
        TrieNode* node = root;
        vector<string> results;

        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return results; // Prefix not found
            }
            node = node->children[ch];
        }

        dfs(node, results, k);

        return results;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, MaxLen, Q;
    cin >> N >> MaxLen >> Q;
    Trie T;

    for (int i = 0; i < N; i++) {
        int len;
        string str;
        cin >> len >> str;
        T.insert(str);
    }

    while (Q--) {
        int n, k;
        string s;
        cin >> n >> s >> k;

        for (int i = 0; i < n; i++) {
            string sub = s.substr(0, i + 1);
            vector<string> ans = T.TopKStrings(sub, k);
            if (ans.empty()) continue;

            int cnt = 0;
            for (const auto& word : ans) {
                cout << word << " ";
                cnt++;
                if (cnt >= k) break;
            }
            cout << '\n';
        }
    }

    return 0;
}
