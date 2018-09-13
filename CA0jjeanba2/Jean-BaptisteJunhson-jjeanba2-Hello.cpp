#include <iostream>
#include <stdlib.h>
#include "Hello_Class.h"

using namespace std;

// class Hello_Class {
//    public:
//       Hello_Class(int i) {
//          if (i == 0) {
//             output_string = "Hello C++ Data Structures, from Junhson!!";
//          } else {
//             output_string = "Hello Data Structures!";
//          }
//       }
//       void print_hello() {
//          cout << output_string << endl;
//       }
//    private:
//       string output_string;
// };

int main(int argc, char *argv[])
{
   Hello_Class *my_hello_ptr = new Hello_Class(0);

   my_hello_ptr->print_hello();
   delete(my_hello_ptr);

   Hello_Class my_hello(1);
   my_hello.print_hello();
}


