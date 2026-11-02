class LRUCache {
public:
    struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k, int l): key(k), value(l), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, Node*> mpp; 
    int capacity;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    LRUCache(int capacity) {
        this->capacity=capacity;
        mpp.clear();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* node=mpp[key];
        deletenode(node);
        insertnode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            deletenode(node);
            insertnode(node);
            node->value=value;
        }
        else{
            if(mpp.size()==capacity){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deletenode(node);
            }
            Node* newnode=new Node(key, value);
            mpp[key]=newnode;
            insertnode(newnode);
        }
    }
    void deletenode(Node* node){
    Node* next=node->next;
    Node* prev=node->prev;
    prev->next=next;
    next->prev=prev;
    }
void insertnode(Node* node){
    Node* next=head->next;
    head->next=node;
    node->prev=head;
    node->next=next;
    next->prev=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */