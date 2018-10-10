#include <iostream>
using namespace std;
#include <string>

#include "Fraction.h"

int main ( ) {

   Fraction f1, f2(4,5); 

   Fraction f3(f2);
   cout << f3 << endl;
   exit(0);


   string userInput;

   while (1) {
      cout << endl << "Enter the 1st fraction: ";
      cin >> f1;
      cout << "Enter 2nd fraction: ";
      cin >> f2;
      cout << "1st Fraction is: " << f1 << endl;
      cout << "2nd Fraction is: " << f2 << endl;

      cout << "What would you like to do with these two Fractions?!" << endl;
      cout << "Choose from [\"Add\" \"Sub\" \"Compare\" \"Quit\"]" << endl; 
      cout << "--> "; 

      cin >> userInput; 

      if (userInput == "Quit") break;

      if (userInput == "Add")
         cout << "The sum is " << (f1 + f2) << endl;
      else if (userInput == "Sub")
         cout << "The difference is " << (f1 - f2) << endl;
      else if (userInput == "Compare") {
         cout << f1 << " and " << f2 << " are "; 
         if (f1 == f2) {} else cout << "not "; 
         cout << "equal." << endl;  
      } else 
         cout << "Command not recognized. Please try again." << endl; 
   }
}

