/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* recClone(Node* node, unordered_map<Node*, Node*>& cloneMap) 
    {
        if(cloneMap.find(node) != cloneMap.end())
            return cloneMap[node];

        Node* clone = new Node(node->val);
        cloneMap[node] = clone;

        for(auto neighbor : node->neighbors)
            clone->neighbors.push_back(recClone(neighbor, cloneMap));

        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> cloneMap;
        return recClone(node, cloneMap);
    }
};