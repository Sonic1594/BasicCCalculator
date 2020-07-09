#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double calc(int x, int y, char order){
  double result;
  if (order == '+'){
    result = x+y;
  } else if (order == '-'){
    result = x-y;
  } else if (order == '/'){
    result = x/y;
  } else if (order == '*'){
    result = x*y;
  } else {
    result = pow(x,y);
  }

  return result;
}

int main() {
/*
this is a comment
*/
  double num1;
  double num2;
  char op;
  double result;
  int acceptableOp = 0;
  const char *validOps = "+-*/^";

  /*Creating a pointer variable*/
  char *pOp;

  printf("Hello, give me any two numbers and an operator I will do the math for you \nEnter your first number: ");
  scanf("%lf", &num1);
  printf("Now enter your second number: ");
  scanf("%lf", &num2);
  fflush(stdin);
  printf("Now");

  /* checks to make sure user have a valid operator */
  while (acceptableOp == 0){
    printf(" enter the operator");
    scanf("%c", &op);
    pOp = &op; /*setting pointer to be the memory address of op*/

    /*runs as long as there is something at that memory address
   which in this case is as long as there is a nextchar for op*/
    while (*pOp){
      /*strchr searches through the first string for the the char
      given, in this case validOps is being searched for *pOp
      (when adding a * to a pointer it returns what is at that
      address rather than the address itself)*/
      if (strchr(validOps, *pOp)){
        acceptableOp = 1;
      } else {
        printf("Sorry! I can't accept that\n");
        fflush(stdin);
        printf("Please");
      }
      /*moves to the next memory address*/
      pOp++;
    }
  }
  result = calc(num1, num2, op);



  printf("%.2f %c %.2f is %.2f\n", num1, op, num2, result);

  return 0;
}
