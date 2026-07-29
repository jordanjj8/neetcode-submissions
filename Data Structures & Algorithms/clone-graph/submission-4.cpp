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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        // bfs to clone each node
        // use a hashmap to register one time cloning
        unordered_map<Node*, Node*> orgToCloned;
        queue<Node*> q; // enqueue original nodes
        orgToCloned[node] = new Node(node->val); //clone the first node
        q.push(node); // enqueue the first node to loop through the neighbors

        // iterative BFS to find all the neighbors
        while (!q.empty()){
            Node* orgNode = q.front();
            q.pop();
            // loop through all the neighbors of original
            for (Node* neighbor: orgNode->neighbors) {
                // check if we've already cloned it
                // to handle cycles
                if (!orgToCloned.count(neighbor)) {
                    orgToCloned[neighbor] = new Node(neighbor->val); // create clone
                    q.push(neighbor); // need to populate clone's neighbor list
                }
                // update cur's neighbor list
                orgToCloned[orgNode]->neighbors.push_back(orgToCloned[neighbor]);
            }

        }
        return orgToCloned[node];
    }
};
