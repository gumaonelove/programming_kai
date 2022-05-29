#include <string>

struct People
{
    using namespace std;

    string surname = "";
    string name = "";
    string lastname = "";

    int age = 0;
    string family_status = "";
};


struct Node
{
    using namespace std;

    string val;
    Node *next;

    Node(string _val) : val(_val), next(nullptr) {}
};


struct List
{
    using namespace std;

    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr) {}

    bool is_empty(){
        return first == nullptr;
    }

    void push_back(string _val)
    {
        Node* p = new Node(_val);

        if (is_empty()) 
        {
            first = p;
            last = p;
            return
        } else {
            last -> next = p;
            last = p;
        }
    }

    void print()
    {
        if (is_empty()) return

        while (p) {
            // p != nullptr
            cout << p -> val << " ";
            p = p -> next;
        }
        cout << endl;
    }

    Node* find(string _val)
    {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
            return (p && p -> val == _val) ? p : nullptr;
    }

    void remove_first()
    {
        if (is_empty()) return;

        Node* p = first;
        first->next;
        delete p;
    }

    void remove_last()
    {
        if (is_empty()) return;

        if (first == last){
            remove_first();
            return;
        } else {
            Node* p = first;
            while (p->next != last) p = p->next;
            p->next = nullptr;
            delete last;
            last = p;
        }
    }

    void remove(string _val)
    {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        } else if (last->val == _val){
            remove_last();
            return;
        }

        Node* slow = first;
        Node* fast = first->next;

        while (fast && fast->val != _val){
            fast = fast->next;
            slow = slow->next;
        }

        if (!fast) {
            cout << "This element is not exist" << endl;
            return;
        }

        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index){
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++){
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }

    void add_element(int index, string _val)
    {
        if (is_empty()){
            push_back(_val);
        } else if (index == 1) {
            Node* elem = new Node;
            elem->val = _val;
            elem->next = first;
            first = elem;
        }else {
            Node* elem = new Node;
            elem->val = _val;
            elem->next = elemPrev->next;
            elemPrev->next = elem;
        }
    }

    void reset_list()
    {
        if (is_empty()) return;

        while (p) {
            List[p] = nullptr;
            p = p -> next;
        }
    }

    
};