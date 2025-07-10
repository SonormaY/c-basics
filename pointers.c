#include <stdio.h>
#include <stdlib.h>

void swap_if_bigger(int *a, int *b);
int sum(int a, int b);

int main(int argc, char *argv[]) {
  printf("Enter number a: ");
  int a;
  scanf("%d", &a);
  printf("Enter number b: ");
  int b;
  scanf("%d", &b);
  swap_if_bigger(&a, &b);
  printf("Sum: %d. a: %d. b: %d", sum(a, b), a, b);

  return EXIT_SUCCESS;
}

void swap_if_bigger(int *a, int *b) {
  if (*a > *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
}

int sum(int a, int b) { return a + b; }
