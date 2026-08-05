class Node {
public: 
    Node* prev = nullptr;
    Node* next = nullptr;
    int key;
    int value;

    Node(int k, int v) : key(k), value(v) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> keyToNode;
    int cap;
    Node* left = new Node(0,0);
    Node* right = new Node(0,0);


    LRUCache(int capacity) {
        cap = capacity;
        left->next = right;
        right->prev = left;
    }

    void insert(Node* node) {
        // always insert at right
        Node* oldMRU = right->prev;
        right->prev = node;
        oldMRU->next = node;
        node->prev = oldMRU;
        node->next = right;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
    
    int get(int key) {
        if (!keyToNode.count(key)) {
            return -1;
        }

        // since we touched it, we want to reorder
        // remove from linked list
        Node* node = keyToNode[key];
        remove(node);
        // insert to linked list
        insert(node);

        return node->value;
    }
    
    void put(int key, int value) {
        // if we already have the key, we need to update
        if (keyToNode.count(key)) {
            // remove existing
            remove(keyToNode[key]);
        }
        // insert to linked list
        Node* node = new Node(key, value);
        insert(node);
        keyToNode[key] = node;

        // if we reach cap, remove lru
        if (keyToNode.size() > cap) {
            // remove lru
            Node* lru = left->next;
            remove(lru);
            keyToNode.erase(lru->key);

        }
        
    }
};
