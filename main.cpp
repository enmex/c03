#include <iostream>
#include "RingedList.h"
using namespace std;

int main() {
   RingedList<int> a;
   a.init();
   RingedList<int>::iterator_list it(a);
   int size = 0;
   cout << "Введите размер списка" << endl;
   cin >> size;
   int x = 0;
   cout << "Вводите список" << endl;
   it.start();
   for(int i = 0; i < size; i++){
      cin >> x;
      a.push(it, x);
      it.next();
   }
   it.start();
}
