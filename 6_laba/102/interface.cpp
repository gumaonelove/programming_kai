#include <iostream>
#include <limits>

void get_navigation()
{
    using namespace std;
    
    cout << "Функционал:" << endl;
    cout << "1) Добавить новый элемент" << endl;
    cout << "2) Печать всех элементов в отсортированном виде" << endl;
    cout << "3) Сброс значений всех элементов" << endl;
}


int getIndex() 
{
    using namespace std; 

    while (true)
    {
        int a;
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
}