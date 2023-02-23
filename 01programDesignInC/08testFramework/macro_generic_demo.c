// C program to illustrate macro function.
// https://www.geeksforgeeks.org/_generic-keyword-c/

#include <stdio.h>

#define geeks(T) _Generic( (T), char: 1, int: 2, long: 3, default: 0)

int main(void) {
    // char returns ASCII value which is int type. 
    printf("%d\n", geeks('A')); 
   
    // Here A is a string.
    printf("%d",geeks("A"));
      
    return 0;
}



int addFunction(int num1, int num2) {
  int sum;
  sum = num1 + num2;
  return sum;
}

// int main() {
  // Error example for "expected primary-expression before 'char'"
  // int result = addFunction(int 20, int 30);
// }

