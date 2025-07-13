#include <stdio.h>
#include <stdlib.h>

void print_table(int n) {
  for (int i = 1; i <= 10; i++) {
    printf("%d * %d = %d\n", n, i, n * i);
  }
}

int main(int argc, char *argv[]) {
  system("clear");
  printf("Enter number: ");
  int n;
  scanf("%d", &n);
  print_table(n);
  return EXIT_SUCCESS;
}
