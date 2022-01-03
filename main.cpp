#include <iostream>
#include "list.cpp"

typedef int DataType;
void test1(List<DataType>&);
void test2(List<DataType>&);

int main() {
    LinkedList<DataType> linkedList;
    ArrayList<DataType, 10> arrayList;

    test1(linkedList);
   // test2(linkedList);
    return 0;
}

void test1(List<DataType> &list) {
    for(int i = 0; i < 10; i++) {
        list.add((i * 3 + 9) / 2);
    }
    for(int i = 0; i < list.getSize(); i++) {
        std::cout << "Element" << i << " - " << list[i] << std::endl;
    }

    std::cout << "Pop element - " << list.pop() << std::endl;

    for(int i = 0; i < list.getSize(); i++) {
        std::cout << "Element" << i << " - " << list[i] << std::endl;
    }

    std::cout << "Adding to Begin..." << std::endl;
    list.addToBegin(999);

    for(int i = 0; i < list.getSize(); i++) {
        std::cout << "Element" << i << " - " << list[i] << std::endl;
    }

    std::cout << "Pop from Begin..." << list.popFromStart() << std::endl;

    for(int i = 0; i < list.getSize(); i++) {
        std::cout << "Element" << i << " - " << list[i] << std::endl;
    }

    std::cout << "Is empty ? " << std::boolalpha << list.isEmpty() << std::endl;
}
