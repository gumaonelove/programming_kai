#ifdef CONSTANS_H
#define CONSTANS_H
#include "my_functions.h"
#include <string>

const std::string DEFAULT_NAME_FILE_IN_OUT("list.txt");

enum class EMPLOYEE_FIELD {
    SURNAME = 0;
    NAME = 0;
    LASTNAME = 0;
    AGE = 0;
    FAMILY_STATUS = 0;
};

enum class PRINT {
    NEXT,
    PREVIOS
};

const DefaultList DEFAULT_LIST{
    "Тестов",
    "Тест",
    "Тестович",
    19,
    "Встречается"
}