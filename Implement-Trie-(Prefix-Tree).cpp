class Node{
public:
    Node* links[26];
    bool flag;

    bool contains(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};


class Trie {
    Node* root;
public:

    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto& ch : word){
            if(!node->contains(ch)){
                node->put(ch, new Node());
            }
            node=node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(auto& ch: word){
            if(!node->contains(ch)) return false;
            node=node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(auto& ch: prefix){
            if(!node->contains(ch)) return false;
            node=node->get(ch);
        }
        return true;
    }
};