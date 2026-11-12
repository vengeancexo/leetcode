class Trie {
public:
    class Node{
    public:
        Node* alphas[26];
        bool stringover;
        Node(){
            for(int i=0;i<26;i++){
                alphas[i] = nullptr;
            }
            stringover = false;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr->alphas[index] == nullptr) {
                curr->alphas[index] = new Node();
            }
            curr = curr->alphas[index];
        }
        curr->stringover = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char ch:word){
            int index = ch - 'a';
            if(curr->alphas[index] == nullptr){
                return false;
            }
            curr = curr->alphas[index];
        }
        if(curr->stringover){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(curr->alphas[index] == nullptr)
                return false;
            curr = curr->alphas[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
