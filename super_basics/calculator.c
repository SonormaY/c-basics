#include <stdio.h>
#include <stdlib.h>

void addition(void);
void substraction(void);
void multiplication(void);
void division(void);

int main(int argc, char *argv[]) {
  while (1) {
    printf("Calculator menu\n1. Addition\n2. Substraction\n3. "
           "Multiplication\n4. Division\nEnter your choice(1-4): ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      addition();
      break;
    case 2:
      substraction();
      break;
    case 3:
      multiplication();
      break;
    case 4:
      division();
      break;
    default:
      printf("Wrong number");
    }
  }
  return EXIT_SUCCESS;
}

void addition(void) {
  printf("Enter first number: ");
  int a;
  scanf("%d", &a);
  printf("Enter second number: ");
  int b;
  scanf("%d", &b);
  printf("Result: %d\n", a + b);
}

void substraction(void) {
  printf("Enter first number: ");
  int a;
  scanf("%d", &a);
  printf("Enter second number: ");
  int b;
  scanf("%d", &b);
  printf("Result: %d\n", a - b);
}

void multiplication(void) {
  printf("Enter first number: ");
  int a;
  scanf("%d", &a);
  printf("Enter second number: ");
  int b;
  scanf("%d", &b);
  printf("Result: %d\n", a * b);
}

void division(void) {
  printf("Enter first number: ");
  int a;
  scanf("%d", &a);
  printf("Enter second number: ");
  int b;
  scanf("%d", &b);
  if (b == 0) {
    printf("Can't divide by 0\n");
    return;
  }
  printf("Result: %d\n", a / b);
}
