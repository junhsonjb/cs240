#include <iostream>

class myClass {
public:
  int myMember;
  
  myClass() : myMember(0) { }
};

int main() {
  
  myClass *ptr = (myClass *)0x1;

  std::cout << "before std::nullptr" << std::endl;
  ptr = nullptr;
  std::cout << "after std::nullptr" << std::endl;
  
  std::cout << "crashing: " << ptr->myMember << std::endl;

  return 0;
}
