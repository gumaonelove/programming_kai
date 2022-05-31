#ifndef _LIST_H_
#define _LIST_H_

#include <string>

using namespace std;

struct Node{
    string surname{};
    string name{};
    string lastname{};
    string age{};
    string family_status{};
    Node* pNext{};

    Node(string surname = "ND", string name = "ND", string lastname = "ND", string age = "ND", string family_status = "ND", Node* pNext = nullptr) {
        surname = this->surname;
        name = this->name;
        lastname = this->lastname;
        age = this->age;
        family_status = this->family_status;
        pNext = this->pNext;
    }
};

struct List{
    List();
    ~List();
    void List_input();
    void Separate(string str, string data[]);
    void Add_Data(string data[]);
    void Show();
    void pop_front();
    void Set_default();
    void Sort_data();
    void Search();
    Node* Move(int index);
    Node* head;
    Node* tail;
    int Size;
};

#endif
