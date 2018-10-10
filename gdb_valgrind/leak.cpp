#include <iostream>

class myClass {
public:
  int myMember;

  myClass() : myMember(0) {
    std::cout << "myClass def constructor" << std::endl;
  }

  myClass(int i) : myMember(i) {
    std::cout << "myClass value constructor" << std::endl;
  }
};

int main() {
  
  myClass *ptr1 = new myClass();
  myClass *ptr2 = new myClass(100);
  
  std::cout << ptr1->myMember << std::endl;
  std::cout << (*ptr2).myMember << std::endl;
  
}
