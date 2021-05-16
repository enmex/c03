#include <iostream>
#include "circle_list.h"
using namespace std;

int main() {
    int size = 10;
    circle_list* circle = new circle_list(size);
    for(int i = 0; i < size; i++){
        circle->push(i+1); //в список включаем элементы 1...10
    }
    circle_list::iterator_list* iterator = circle->begin(); //инициализация итератора вот такая через begin
    while(!iterator->finish()){
        cout << iterator->getValue()->value << "->";
        iterator->next();
    }
    cout << endl;
}