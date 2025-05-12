#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int year = 2025;
  int age = 20;

  printf("It is %d currently, and you are %d years old\n", year, age);

  char grade = 'B';
  printf("Ypur grade is %c\n", grade);

  char name[] = "Sonorma";
  printf("Hello, %s\n", name);

  bool isTuesday = true;
  if (isTuesday) {
    printf("Today is tuesday\n");
  }

  return EXIT_SUCCESS;
}
