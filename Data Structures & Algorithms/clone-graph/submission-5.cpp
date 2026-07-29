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

        // map original node -> its clone; one-time cloning
        unordered_map<Node*, Node*> orgToCloned;
        queue<Node*> q; // bfs frontier of original nodes (needs neighbor processing)

        // clone the first node and enqueue original node
        orgToCloned[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* orgNode = q.front();
            q.pop();

            // process through all of original node's neighbors
            for (Node* neighbor : orgNode->neighbors) {
                // only clone new neighbor once; handles cycles
                if (!orgToCloned.count(neighbor)) {
                    orgToCloned[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // append the *cloned* neighbor, not the original
                orgToCloned[orgNode]->neighbors.push_back(orgToCloned[neighbor]);
            }
        }

        return orgToCloned[node];
        }
};
