#pragma once
#include <iostream>
#include <exception>

enum ExceptionType {
    WRONG_SIZE,
    EMPTY_LIST,
    ITERATOR_OUT_OF_RANGE,
    FULL_LIST
};

/*
    тут класс исключений для списка
*/

class ListException{
private:
    ExceptionType exception;
public:
    ListException(ExceptionType exception) : exception(exception) {}
    const char* getError() noexcept { return parseString(exception).c_str(); }

    const std::string parseString(ExceptionType exception){
        switch(exception) {
            case WRONG_SIZE:
                return "Неверно передано значение размера списка";
                break;
            case EMPTY_LIST:
                return "Невозможно проделать операцию - список пуст";
                break;
            case ITERATOR_OUT_OF_RANGE:
                return "Выход итератора за границы списка";
                break;
            case FULL_LIST:
                return "Список переполнен";
                break;
            default:
                break;
        }

    }

};