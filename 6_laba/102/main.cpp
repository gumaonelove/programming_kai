#include <iostream>

#include "my_structs.h"
#include "functions.h"

int main()
{
    using namespace std;
    get_navigation();

    List* list(nullptr);

    while (true){
        switch (getIndex()){
            case 1:
                case_1(list);
                continue;
            case 2:
                case_2(list);
                continue;
            case 3:
                case_3(list);
                continue;
            default:
                cout << "Указан неверный номер, повтороите попытку" << endl;
                continue;
        }
    }
    if (unloadingList(DEFAULT_NAME_FILE_IN_OUT, list)){
        cout << "Список выгружен и удален из оперативной памяти" << endl;
    }
    return 0;
}