#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
#ifndef MY_STRUCTS_H
#define MY_STRUCTS_H

#include <string>

struct People{
    People* next;
    People* previous;

    std::string surname;
    std::string name;
    std::string lastname;

    int age;
    std::string family_status;
};


struct DefaultPeople{
    std::string surname;
    std::string name;
    std::string lastname;

    int age;
    std::string family_status;
};


struct Node{
    std::string val;
    Node *next;

    Node(std::string _val) : val(_val), next(nullptr) {};
};


struct List{
    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr) {};

    bool is_empty(){
        return first == nullptr;
    };

    void push_back(std::string _val){
        Node* p = new Node(_val);

        if (is_empty()) {
            first = p;
            last = p;
            return;
        } else {
            last -> next = p;
            last = p;
        }
    };

    void print(){
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            std::cout << p -> val << " ";
            p = p -> next;
        }
        std::cout << std::endl;
    };

    Node* find(std::string _val){
        Node* p = first;
        while (p && p->val != _val) p = p->next;
            return (p && p -> val == _val) ? p : nullptr;
    };

    void remove_first(){
        if (is_empty()) return;

        Node* p = first;
        first->next;
        delete p;
    };

    void remove_last(){
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
    };

    void remove(std::string _val){
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        } else if (last->val == _val){
            remove_last();
            return;
        };

        Node* slow = first;
        Node* fast = first->next;

        while (fast && fast->val != _val){
            fast = fast->next;
            slow = slow->next;
        };

        if (!fast) {
            std::cout << "This element is not exist" << std::endl;
            return;
        };

        slow->next = fast->next;
        delete fast;
    };

    Node* operator[] (const int index){
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++){
            p = p->next;
            if (!p) return nullptr;
        };
        return p;
    }

    void add_element(int index, std::string _val){
        if (is_empty()){
            push_back(_val);
        } else if (index == 1) {
            Node* elem = new Node(_val);
            elem->val = _val;
            elem->next = first;
            first = elem;
        }else {
            Node* elem = new Node(_val);
            Node* elemPrev = Node[index];
            elem->val = _val;
            elem->next = elemPrev->next;
            elemPrev->next = elem;
        };
    };

    void reset_list(){
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            Node[p] = nullptr;
            p = p -> next;
        };
    };
};

#endif //MY_STRUCTS_H
#pragma clang diagnostic pop