#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class TrieNode{
    public:
        map<char, TrieNode*>children;
        bool isEndOfWord;
        int prefix;
        vector<string>wend;
        TrieNode(){
            isEndOfWord = false;
            prefix = 0;
        }
};


class Trie{
    public:
        TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(auto ch : word){
            node->prefix++;
            if(node->children.find(ch) == node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
        node->wend.push_back(word);
    }

    void Delete(string word){
        TrieNode* node = root;
        for(auto ch: word){
            node->prefix--;
            if(node->children.find(ch) == node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = false;
        auto it = find(node->wend.begin(), node->wend.end(), word);
        if(it != node->wend.end()){
            node->wend.erase(it);
        }
    }

    bool search(string word){
        for(auto ch : word){
            if(node->children.find(ch) == node->children.end())
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startswith(string word){
        for(auto ch : word){
            if(node->children.find(ch) == node->children.end()){
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

};