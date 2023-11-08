#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    bool isEndOfWord;
    int count = 0;
    TrieNode(){
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieNode *root = new TrieNode(), *curr = nullptr;
        int res = 0;
        string result;
        for(string s : words){
            curr = root;
            int cnt = 0;
            for(char ch : s){
                int ind = ch - 'a';
                if(!curr->children[ind]){
                   curr->children[ind] = new TrieNode();
                }
                curr = curr->children[ind];
                if(curr->isEndOfWord) cnt++;
            }
            cnt++;
            curr->count += cnt;
            curr->isEndOfWord = true;
            if(cnt >= res){
                result = (cnt == res && s.compare(result) > 0) ? result: s;
                res = cnt;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> words = {"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"};
    s.longestWord(words);
    
    return 0;
}