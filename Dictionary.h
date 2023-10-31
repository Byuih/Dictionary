#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

    void insertRecursive(TrieNode* node, const string& word, int index) {
        if (index == word.length()) {
            node->isEndOfWord = true;
            return;
        }

        char currentChar = word[index];
        if (node->children.find(currentChar) == node->children.end()) {
            node->children[currentChar] = new TrieNode();
        }

        insertRecursive(node->children[currentChar], word, index + 1);
    }

    void findWordsWithPrefixRecursive(TrieNode* node, const string& prefix, string currentWord, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix + currentWord);
        }

        for (const auto& entry : node->children) {
            findWordsWithPrefixRecursive(entry.second, prefix, currentWord + entry.first, suggestions);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        insertRecursive(root, word, 0);
    }

    vector<string> findWordsWithPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return vector<string>();
            }
            node = node->children[c];
        }

        vector<string> suggestions;
        findWordsWithPrefixRecursive(node, prefix, "", suggestions);
        return suggestions;
    }
};
