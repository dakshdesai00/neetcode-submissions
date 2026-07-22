struct ListNode {
    int val;
    int key;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) : key(x), val(x), prev(nullptr), next(nullptr) {}
    ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int len;
    int cap;
    ListNode* head;
    ListNode* tail;

public:
    LRUCache(int capacity) {
        cap = capacity;
        len = 0;

        head = new ListNode(-1);
        tail = new ListNode(-1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        ListNode* curr = head->next;

        while (curr != tail && curr->key != key)
            curr = curr->next;

        if (curr == tail)
            return -1;

        // Remove from current position
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // Insert after head
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;

        return curr->val;
    }

    void put(int key, int value) {
        // Check if key already exists
        ListNode* curr = head->next;

        while (curr != tail && curr->key != key)
            curr = curr->next;

        if (curr != tail) {
            curr->val = value;

            // Move to front
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            curr->next = head->next;
            curr->prev = head;
            head->next->prev = curr;
            head->next = curr;
            return;
        }

        // Cache full -> remove LRU
        if (len == cap) {
            ListNode* temp = tail->prev;

            temp->prev->next = tail;
            tail->prev = temp->prev;

            delete temp;
            len--;
        }

        // Insert new node
        ListNode* node = new ListNode(key, value);

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        len++;
    }
};