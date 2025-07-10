#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  system("clear");
  printf("Enter your password: ");
  char pass[50];
  scanf("%s", &pass);
  if (strlen(pass) < 6) {
    printf("password must be at least 6 symbols long!");
    return EXIT_SUCCESS;
  }
  printf("Enter your password again for check: ");
  char check[50];
  scanf("%s", &check);
  if (strcmp(pass, check)) {
    printf("Passwords do not match!");
    return EXIT_SUCCESS;
  } else {
    printf("Passwords match! Yay!");
  }
  return EXIT_SUCCESS;
}
