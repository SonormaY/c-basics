#include <stdio.h>

int get_single_char(void);
void clear_stream(void);

int main(void) {
  int choice;
  char name[100];

  printf("Enter name: ");
  scanf("%99s", name);
  clear_stream();

  printf("Play a game, %s (y/n)? ", name);
  choice = get_single_char();

  if (choice == 'y') {
    printf("Press ENTER to continue:");
    get_single_char();
  } else {
    puts("That was uninspiring!");
  }

  puts("bye");
  return 0;
}

int get_single_char(void) {
  int input;

  input = getchar();

  if (input != '\n') {
    clear_stream();
  }

  return input;
}

void clear_stream(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    continue; // discard extra characters
  }
}
