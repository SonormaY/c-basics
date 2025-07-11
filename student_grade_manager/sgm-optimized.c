#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[30];
  unsigned int id;
  int exams[3];
  float average;
  char grade;
};

int get_single_char();
void clear_stream();
void add_student(struct Student **, int *);
void print_all_students(struct Student *, int *);
void print_student(struct Student *);
void search_by_id(struct Student *, int *, int);
void show_top_student(struct Student *, int *);

int main(int argc, char *argv[]) {
  // capacity to track memory alloc
  int capacity = 0;
  // allocating memory for students, but for now with size == 0
  struct Student *students = malloc(sizeof(struct Student) * capacity);
  if (students == NULL) {
    printf("alloc failed bozo");
    exit(EXIT_FAILURE);
  }
  // main menu loop
  while (1) {
    system("clear");
    printf(
        "Student Grade Manager Menu\n1. Add student\n2. Print all students\n3. "
        "Search student by ID\n4. Show top student (highest average)\n5. "
        "Exit\n\nSelect option(1-5): ");
    int choice;
    scanf("%d", &choice);
    clear_stream();

    switch (choice) {
    case 1:
      add_student(&students, &capacity);
      break;
    case 2:
      print_all_students(students, &capacity);
      break;
    case 3:
      system("clear");
      printf("Enter id to search: ");
      int id_to_search;
      scanf("%d", &id_to_search);
      search_by_id(students, &capacity, id_to_search);
      break;
    case 4:
      show_top_student(students, &capacity);
      break;
    case 5:
      exit(EXIT_SUCCESS);
    default:
      continue;
    }
  }
  return EXIT_SUCCESS;
}

// for 'press enter to continue...' message
int get_single_char() {
  int input;

  input = getchar();

  if (input != '\n') {
    clear_stream();
  }

  return input;
}

// stuff that clears stream from average
// idk how it works
void clear_stream() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    continue; // discard extra characters
  }
}

void add_student(struct Student **students, int *capacity) {
  // clear console, increase capacity through dereferencing a pointer and
  // reallocate memory accordingly lol
  system("clear");
  (*capacity)++;
  *students = realloc(*students, sizeof(struct Student) * *capacity);
  if (*students == NULL) {
    printf("Realloc failed gg");
    exit(EXIT_FAILURE);
  }

  // get info from user
  struct Student *current_student = *students + *capacity - 1;
  printf("Student add menu\nEnter student name: ");
  scanf(" %[^\n]", current_student->name);
  current_student->id = *capacity;
  // calculate average from user unput
  int total = 0;
  for (int i = 0; i < 3; i++) {
    printf("Enter exam grade %d: ", i + 1);
    scanf("%d", &current_student->exams[i]);
    total += current_student->exams[i];
  }
  current_student->average = (float)total / 3.0;
  // get char from average
  if (current_student->average >= 90) {
    current_student->grade = 'A';
  } else if (current_student->average >= 80) {
    current_student->grade = 'B';
  } else if (current_student->average >= 70) {
    current_student->grade = 'C';
  } else if (current_student->average >= 60) {
    current_student->grade = 'D';
  } else {
    current_student->grade = 'F';
  }

  clear_stream();
  printf("\nPress Enter to continue...");
  get_single_char();
}

void print_all_students(struct Student *students, int *capacity) {
  system("clear");
  // if db is empty
  if (*capacity == 0) {
    printf("No students in database yet...\n");
    printf("Pre Enter to conyinue...");
    get_single_char();
  }

  for (int i = 0; i < *capacity; i++) {
    print_student(students + i);
    printf("\n");
  }
  printf("\nPress Enter to continue...");
  get_single_char();
}

void print_student(struct Student *student) {
  printf("\nStudent name: %s", student->name);
  printf("\nStudent ID: %d", student->id);
  printf("\nStudent grade: %c", student->grade);
  printf("\nStudent average: %f", student->average);
  for (int i = 0; i < 3; i++) {
    printf("\n%s's exam %d: %d", student->name, i + 1, student->exams[i]);
  }
}

void search_by_id(struct Student *students, int *capacity, int id) {
  bool found = false;
  for (int i = 0; i < *capacity; i++) {
    if ((students + i)->id == id) {
      print_student(students + i);
      found = true;
      break; // break if student was found to not waste computing time
    }
  }

  // if no student with such id
  if (!found) {
    printf("No student matching id %d found :(", id);
  }
  clear_stream();
  printf("\nPress Enter to continue...");
  get_single_char();
}

void show_top_student(struct Student *students, int *capacity) {
  system("clear");
  struct Student *top_student = students;
  for (int i = 1; i < *capacity; i++) {
    if ((students + i)->average > top_student->average) {
      top_student = students + i;
    }
  }
  printf("Top student by average: \n");
  print_student(top_student);
  clear_stream();
  printf("\nPress Enter to continue...");
  get_single_char();
}
