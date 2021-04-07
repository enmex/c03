#include <iostream>
#include "RingedList.h"
using namespace std;

int main() {
    RingedList* list = new RingedList();
    RingedList::iterator_list it(list);
    for(int i = 0; i < 10; i++){
        list->push(it, it.getPos());
        it.next();
    }
    it.start();
    while(!it.finish()){
        cout << it.getValue() << " ";
        it.next();
    }
    cout << it.getValue() << endl;

    it.start();
    RingedList::iterator_list res = list->find(6);
    cout << "position for 6: " << res.getPos() << endl;

    cout << "checking delete of 6" << endl;
    cout << "size before is " << list->length() << endl;
    list->del(res); //удаляем 6
    cout << "size after is " << list->length() << endl;
    cout << "List after delete: ";
    while(!it.finish()){
        cout << it.getValue() << " ";
        it.next();
    }
    cout << it.getValue() << endl;
}
