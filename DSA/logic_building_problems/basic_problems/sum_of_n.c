#include <stdio.h>
#include <stdlib.h>

int find_sum(int n) { return n * (n + 1) / 2; }

int main(int argc, char *argv[]) {
  system("clear");
  printf("Enter n: ");
  int n;
  scanf("%d", &n);
  printf("Result: %d", find_sum(n));
  return EXIT_SUCCESS;
}
