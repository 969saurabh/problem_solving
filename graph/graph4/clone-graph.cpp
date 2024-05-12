//https://leetcode.com/problems/clone-graph/submissions/
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
  map<int,Node*> vis;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;
        int n=node->neighbors.size();
         Node* root=new Node(node->val);
         vis[node->val]=root;
         for(int i=0;i<n;i++)
         {
            if(vis.find(node->neighbors[i]->val)==vis.end())
             root->neighbors.push_back(cloneGraph(node->neighbors[i]));
             else
             {
                root->neighbors.push_back(vis[node->neighbors[i]->val]);
             }
         }
         return root;


    }
};