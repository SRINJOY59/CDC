#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> mp;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    void dfs(TrieNode* node, int pos, string& s, int remaining, string& current, vector<string>& results) {
        if (pos == s.length()) {
            if (node->isEndOfWord) {
                results.push_back(current);
            }
            return;
        }

        for (auto& pair : node->mp) {
            char ch = pair.first;
            TrieNode* child = pair.second;
            int newRemaining = remaining;
            if (ch != s[pos]) {
                if (newRemaining == 0) continue;
                newRemaining--;
            }
            current.push_back(ch);
            dfs(child, pos + 1, s, newRemaining, current, results);
            current.pop_back();
        }
    }

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->mp.find(ch) == node->mp.end()) {
                node->mp[ch] = new TrieNode();
            }
            node = node->mp[ch];
        }
        node->isEndOfWord = true;
    }

    vector<string> findStrings(string word, int k) {
        vector<string> results;
        string current = "";
        dfs(root, 0, word, k, current, results);
        return results;
    }
};

int main() {
    int n;
    cin >> n;
    Trie T;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        T.insert(arr[i]);
    }
    string word;
    cin >> word;
    int k;
    cin >> k;
    vector<string> results = T.findStrings(word, k);
    for (string& res : results) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
