#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Enter number of elements: ");
  int number;
  scanf("%d", &number);
  int *array = malloc(number * sizeof(int));
  if (array == NULL) {
    return EXIT_FAILURE;
  }
  for (int i = 0; i < number; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &array[i]);
  }
  printf("Do you want to extend array? (y/n): ");
  char choice;
  scanf(" %c", &choice);
  int number_extend = 0;
  if (choice == 'y') {
    printf("\nEnter number of elements to add: ");
    scanf("%d", &number_extend);
    array = realloc(array, (number + number_extend) * sizeof(int));
    for (int i = number; i < number + number_extend; i++) {
      printf("Enter element %d: ", i + 1);
      scanf("%d", &array[i]);
    }
  }
  for (int i = 0; i < number + number_extend; i++) {
    printf("Element %d: %d\n", i + 1, array[i]);
  }

  free(array);
  array = NULL;
  return EXIT_SUCCESS;
}
