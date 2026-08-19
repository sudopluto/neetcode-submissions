class MyLinkedList {

    struct LinkedListNode;

    struct LinkedListNode {
        int val{0};
        LinkedListNode* prev{nullptr};
        LinkedListNode* next{nullptr};

        LinkedListNode(int val, LinkedListNode* prev, LinkedListNode* next)
            : val{val}, prev{prev}, next{next} {}
        
        LinkedListNode(int val)
            : val{val} {}
    };

    size_t sz{0};
    LinkedListNode* head{nullptr};
    LinkedListNode* tail{nullptr};

    LinkedListNode* getNodeAtIdx(int index) {
        if (sz == 0 || index >= sz) {
            return nullptr;
        }
        LinkedListNode* ret = head;
        for (size_t i = 0; i < index; ++i) {
            ret = ret->next;
        }
        return ret;
    }

public:
    MyLinkedList() {}
    
    int get(int index) {
        if(index < 0 || index >= sz) {
            return -1;
        }
        LinkedListNode* nodeAtIdx = getNodeAtIdx(index);
        if (nodeAtIdx == nullptr) {
            return -1;
        } else {
            return getNodeAtIdx(index)->val;
        } 
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
       addAtIndex(sz, val); 
    }
    
    // add val node before current val node at index
    // if index == list sz, append element
    void addAtIndex(int index, int val) {
        if(index > sz) {return;}

        LinkedListNode* node = new LinkedListNode(val);
        if(sz == 0) {
            head = node;
            tail = node;
        } else if (index == sz) {
            node->prev = tail;
            tail->next = node;
            tail = node;
        } else if (index == 0) {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            LinkedListNode* nodeAtIdx = getNodeAtIdx(index);
            node->next = nodeAtIdx;
            node->prev = nodeAtIdx->prev;
            nodeAtIdx->prev->next = node;
            nodeAtIdx->prev = node;
        }
        ++sz;
        
    }
    
    void deleteAtIndex(int index) {
        if (sz == 0 || index >= sz) { return; }
        LinkedListNode* nodeAtIdx = getNodeAtIdx(index);
        if (sz == 1) {
            head = nullptr;
            tail = nullptr;    
        } else if (index == sz - 1) {
            tail = tail->prev;
            tail->next = nullptr;
        } else if (index == 0) {
            head = head->next;
            head->prev = nullptr;
        } else {
            nodeAtIdx->prev->next = nodeAtIdx->next;
            nodeAtIdx->next->prev = nodeAtIdx->prev;
        }
        
        delete nodeAtIdx;
        --sz;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */