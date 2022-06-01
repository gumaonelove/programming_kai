#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

#include "List.h"
#include "my_functions.h"

using namespace std;

List::List(){
    head = nullptr;
    tail = nullptr;
    Size = 0;
}

List::~List(){
    Node* temp;
    ofstream f("./list.txt");
    if (f.is_open()){
        if (head != nullptr){
            temp = head;
            for (int i = 0; i < Size; i++){
                f << temp->surname + ";" + temp->name + ";" + temp->lastname + ";" + temp->age + ";" + temp->family_status << endl;
                temp = temp->pNext;
            }
            cout << "Данные успешно загружены в файл" << endl;
        } else {
            cout << "Список пуст, нечего записывать" << endl;
            f << "Здесь были бы ваши данные, если бы они в принципе были" << endl;
        }
        f.close();
    } else {
        cout << "Не удалось записать данные в файл" << endl;
    }

    while (Size){ // освобождаем память, очищаем список
        pop_front();
    }
}

void List::Separate(string str, string data[]){ // метод для разделения входящей из файла строки по значениям полей
    int j = 0;
    for (int i = 0; i <= str.size(); i++){
        // Итерируемся по строке и посимвольно записываем данные, при встрече с разделителем (;)
        // начинаем записывать данные в следующую ячейку, так происходит разделение по полям данных
        if (str[i] == ';'){
            j++;
            continue;
        }
        data[j] += str[i];
    }
}

void List::Add_Data(string data[]){ // метод добавления данных в наш список
    Node *add = new Node; // создаём новый элемент-структуру
    add->surname = data[0]; data[0] = "";
    add->name = data[1]; data[1] = "";
    add->lastname = data[2];  data[2] = "";
    add->age = data[3];  data[3] = "";
    add->family_status = data[4];  data[4] = "";

    if (head == nullptr){ // если список пуст, создаём "голову" и замыкаем саму на себя
        head = tail = add;
        add->pNext = head;
    } else { // иначе добавляем элемент в конец, замыкаем его на голову и делаем крайним элементом в списке
        add->pNext = head;
        tail->pNext = add;
        tail = add;
    }
    Size++;
}


void List::Search(){
    string str; // буферная строка, получаемая из консоли
    cout << "Введите строку, для удаления вхождения (пример: Ф;И;О;Возраст;Семейное_положение): " << endl;
    getline(cin, str); // получаем строку из console
    while (str == ""){
        getline(cin, str); // получаем строку из console
    }


    Node* temp;
    temp = head;
    for (int i = 0; i < Size; i++){
        string now_str = temp->surname + ";" + temp->name + ";" + temp->lastname + ";" + temp->age + ";" + temp->family_status;
        if (string_comparison(str, now_str)){
            temp->surname = "";
            temp->name = "";
            temp->lastname = "";
            temp->age = "";
            temp->family_status = "";

            cout << "Удаление произошло успешно" << endl;
            return;
        }
        temp = temp->pNext;
    }
    cout << "Данный элемент не встречается" << endl;
    return;
}


void List:: List_input(){ // метод, объединяющая вспомогательные методы для записи всех элементов из файла в список
    ifstream f("./list.txt");
    if (f.is_open()) {
        string str; // буферная строка, получаемая из файла
        string data[5]; // буферный массив элементов, заполняемый в Separate и используемый в Add_Data
        while (!f.eof()){
            getline(f, str); // получаем строку из файла
            if (str == "") continue; // пропускаем пустые строки

            Separate(str, data); // разделяем строку по полям нашей структуры
            Add_Data(data); // записываем данные в соответствующие поля
        }
        f.close(); // обязательно закрываем файл после работы  с ним
    }
    else {
        cout << "Не удалось загрузить список" << endl;
        exit(-1);
    }
}

void List::Show() {  // метод печати списка в консоль
    if (head != nullptr) {
        Node* temp = head; // временный элемент-структуры для итерации
        cout << "Фамилия" << '\t' << "Имя" << '\t' <<  "Отчество" << '\t' <<  "Возраст" << '\t' <<  "Семейное_положение" << endl;
        for (int i = 0; i < Size; i++) {
            cout << temp->surname << temp->name << temp->lastname << temp->age << temp->family_status << endl;
            temp = temp->pNext;
        }
    } else {
        cout << "Здесь были бы ваши данные, если бы они в принципе были" << endl;
    }
}

void List::pop_front() { // метод удаления первого элемента из списка
    Node* temp = head;
    head = head->pNext; // переопределяем голову на следующий элемент
    delete temp; // удаляем первый элемент
    Size--; // уменьшаем переменную, отвечающую за размер нашего списка
}

void List::Set_default() { // функция сброса значения всех полей всех элементов списка по умолчанию на Nod Defined (ND)
    Node* temp = head; // временный элемент для итерации
    for (int i = 0; i < Size; i++) { // итерация по списку, переопределние значений на ND
        temp->surname = "ND";
        temp->name = "ND";
        temp->lastname = "ND";
        temp->age = "ND";
        temp->family_status = "ND";
        temp = temp->pNext;
    }
    cout << "Значения сброшены по умолчанию" << endl;
}

void List::Sort_data() { // метод печати данных в отсортированном виде, сам список при этом не сортируется
    short unsigned int how;
    short unsigned int what;
    Node* arr = new Node [Size]; // создаём массив элементов для дальнейшего использования метода сортировки из algorythm
    Node* temp = head;

    for (int i = 0; i < Size; i++){
        arr[i] = *temp;
        temp = temp->pNext;
    }

    // определение характера сортировки - по возрастанию или убыванию, с обработкой ошибок пользовательского ввода
    cout << "Как будем сортировать?" << endl << "1 - по возрастанию" << endl << "2 - по убыванию" << endl << "Ожидание пользовательского ввода: ";
    while (!(cin >> how) and cin.peek() != '\n' || how != 1 and how != 2){
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода, введите 1 или 2: ";
    }

    // определяем, по какому полю будем сортировать, с обработкой ошибок пользовательского ввода
    cout << "Что будем сортировать?" << endl;
    cout << "1 - фамилия" << endl << "2 - имя" << endl << "3 - отчество" << endl << "4 - возраст" << endl << "5 - семейное положение" << endl;
    cout << "Ожидание пользовательского ввода: ";
    while (!(cin >> what) and cin.peek() != '\n' || what != 1 and what != 2 and what != 3 and what != 4 and what != 5){
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода, введите 1 или 2 или 3 или 4 или 5: ";
    }

    switch (what) {
        case 1:
            sort(arr, arr + Size, [](Node & d1, Node & d2) {return d1.surname < d2.surname;});
            break;
        case 2:
            sort(arr, arr + Size, [](Node & d1, Node & d2) {return d1.name < d2.name;});
            break;
        case 3:
            sort(arr, arr + Size, [](Node & d1, Node & d2) {return d1.lastname < d2.lastname;});
            break;
        case 4:
            sort(arr, arr + Size, [](Node & d1, Node & d2) {return stoi(d1.age) < stoi(d2.age) ;});
            break;
        case 5:
            sort(arr, arr + Size, [](Node & d1, Node & d2) {return d1.family_status < d2.family_status;});
            break;
    }

    cout << "Отсортированные данные" << endl; // кастомизация вывода отсортированных данных
    cout << "Фамилия" << '\t' << "Имя" << '\t' << "Отчество" << '\t' << "Возраст" << '\t' << "Семейное положение" << endl;

    if (how == 1) { // если пользователь указал сортировку по возрастанию, выводим значения по возрастанию
        for (int i = 0; i < Size; i++) { // итерируемся по отсортированному массиву и выводим значения
            cout << arr[i].surname << '\t' << arr[i].name << '\t' << arr[i].lastname << '\t' << arr[i].age << '\t' << arr[i].family_status << endl;
        }
    } else { // если пользователь указал сортировку по убыванию, выводим значения по убыванию
        for (int i = Size - 1, j = 1; i >= 0; i--, j++) { // итерируемся по отсортированному массиву и выводим значения
            cout << arr[i].surname << '\t' << arr[i].name << '\t' << arr[i].lastname << '\t' << arr[i].age << '\t' << arr[i].family_status << endl;
        }
    }
    delete [] arr; // освобождаем память после печати всех значений
}