#include <iostream>

int main() 
{
    using namespace std;
    string name;
    int age;

    cout << "- Hello! Whats is your name?" << endl;
    cerr << "> ";
    cin >> name;
    cout << "- I am glad to see you, " << name << "!" << endl << "- What is your age?" << endl;
    cerr << "> ";
    cin >> age;
    cout << "- I thought you are " << age + 1 << " year old. You look younger!" << endl;

    return 0;
}