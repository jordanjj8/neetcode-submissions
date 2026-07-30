/*
Design Story:
1. Requirements:
   - get(key) and put(key, value) both O(1)
   - fixed capacity; when full, remove the LRU entry
 
2. Two main jobs:
   a. Fast lookup by key        -> unordered_map (O(1) average lookup)
   b. Track "last used" order   -> need an ordered container
 
3. Picking the ordered container:
   - Queue: can't promote a middle key to the back in O(1).
   - Singly linked list: each node only points forward. To remove a middle node
        the prev is needed, but the list only points away from the previous node,
        which requries scanning from the head. 
   - Array/vector: move-to-front needs shifting, and finding the LRU needs
     a scan, so O(n).
   - Doubly linked list: prev + next let us detach and re-attach a known
     node at either end in O(1).
 
4. Why we pair it with a hash map:
   - The list gives recency ordering, but it cannot locate a key in O(1).
   - unordered_map<int, Node*> maps key -> node pointer for O(1) lookup.
   - The node stores {key, value, prev, next}; keeping key in the node
     lets us erase the evicted key from the map.
 
5. Ordering looks like:
   - List is ordered MRU ... LRU.
   - Head / left  = MRU (insert / promote here)
   - Tail / right = LRU (evict from here)
 
6. get(key):
   - not in map -> return -1
   - in map     -> move node to MRU end and return value
 
7. put(key, value):
   - key exists -> update value, move node to MRU
   - key new    -> create node at MRU; if size > capacity, remove LRU tail
     and erase that key from the map
 
8. Complexity:
   - unordered_map lookup is O(1) average
   - list splice/erase is O(1)
   - overall O(1) get/put, O(capacity) space
 
9. Edge cases to flag:
   - capacity == 0
   - updating an existing key does NOT change the size or trigger eviction
 
10. C++ implementation note:
    - Raw Node* with sentinel head_/tail_ gives full control.
    - Alternatively, std::list with unordered_map<key, list<Node>::iterator>
      works because list::splice is O(1) and handles node lifetime for you.
*/

class Node {
public:
    int key;
    int val;
    Node* prev = nullptr;
    Node* next = nullptr;

    // constructor
    Node(int k, int v) : key(k), val(v) {}
};


class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left = nullptr;
    Node* right = nullptr;

    void remove(Node* node) {
        //Remove node from the list
        // prev - node - next
        //    prev - next
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        //Inserts node to the front (MRU pointer)
        // prev - right 
        //     node
        // prev->next = node
        // node->prev = prev
        // right->prev = node
        // node->next = right
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        right->prev = node;
        node->next = right;
        
    }

    LRUCache(int capacity) {
        // when cache is initialized
        cap = capacity;
        cache.clear(); // clear the map in case
        // make the doubly linked list
        left = new Node(0,0);
        right = new Node(0,0);
        //make them connected
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        // returns the value corresponding to key
        // if key doesn't exist, return -1
        if (!cache.count(key)) {
            return -1;
        }
        // get the value from cache
        Node* node = cache[key];
        // update the ordering 
        // remove node from list
        remove(node);
        // insert node to list
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            // remove node from list
            remove(cache[key]);
        }
        // create new node and add to cache
        cache[key] = new Node(key, value);
        // insert node to list
        insert(cache[key]);
        // Check Capacity
        if (cache.size() > cap) {
        // if capacity reached, then 
        // remove the lru from list
        // remove key from cache
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }

    }
};
