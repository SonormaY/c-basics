#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_odd(int n) {
  if ((n & 1) == 0) {
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  system("clear");
  printf("Enter number to check: ");
  int n;
  scanf("%d", &n);
  if (is_odd(n)) {
    printf("Number is odd.");
    return EXIT_SUCCESS;
  }
  printf("Number is even.");
  return EXIT_SUCCESS;
}
