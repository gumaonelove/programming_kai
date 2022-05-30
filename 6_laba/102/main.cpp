#include <iostream>

#include "my_structs.h"
#include "my_functions.h"
#include "my_constants.h"

int main(){
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
                std::cout << "Указан неверный номер, повтороите попытку" << std::endl;
                continue;
        }
    }
    if (unloadingList(DEFAULT_NAME_FILE_IN_OUT, list)){
        std::cout << "Список выгружен и удален из оперативной памяти" << std::endl;
    }
    return 0;
}