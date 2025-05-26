#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_STUDENTS 100

struct Student {
  char name[30];
  u_int32_t id;
  int exams[3];
  float average;
  char grade;
};

struct Student search_student_by_id(int, struct Student[MAX_STUDENTS]);
void print_student(struct Student);
int get_single_char();
void clear_stream();

int main(void) {
  struct Student students[MAX_STUDENTS];
  int last_added = 0;
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
      fflush(stdout);
      system("clear");
      printf("Student add menu\nEnter student name: ");
      scanf("%[^\n]s", &students[last_added].name);
      printf("Enter your studentID: ");
      scanf("%d", &students[last_added].id);
      for (int i = 0; i < 3; i++) {
        printf("Enter exam %d grade: ", i + 1);
        scanf("%d", &students[last_added].exams[i]);
      }
      clear_stream();
      float average;
      for (int i = 0; i < 3; i++) {
        average += students[last_added].exams[i];
      }
      average /= 3;
      students[last_added].average = average;
      if (average >= 90) {
        students[last_added].grade = 'A';
      } else if (average >= 80) {
        students[last_added].grade = 'B';
      } else if (average >= 70) {
        students[last_added].grade = 'C';
      } else if (average >= 60) {
        students[last_added].grade = 'D';
      } else {
        students[last_added].grade = 'F';
      }
      last_added++;
      printf("Press Enter to continue...");
      get_single_char();
      break;

    case 2:
      system("clear");
      if (last_added == 0) {
        printf("No students in DB!\n");
      }
      for (int i = 0; i < last_added; i++) {
        printf("Student %d\n", i + 1);
        print_student(students[i]);
        printf("\n");
      }
      printf("Press Enter to continue...");
      get_single_char();
      break;

    case 3:
      printf("Enter student id to search: ");
      int id;
      scanf("%d", &id);
      clear_stream();
      struct Student result = search_student_by_id(id, students);
      system("clear");
      print_student(result);
      printf("Press Enter to continue...");
      get_single_char();
      break;

    case 4:
      break;

    default:
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}

void print_student(struct Student student) {
  printf("Name: %s\nID: %d\nAverage: %.2f\nGrade: %c\n", student.name,
         student.id, student.average, student.grade);
  for (int i = 0; i < 3; i++) {
    printf("Exam %d: %d\n", i + 1, student.exams[i]);
  }
}

struct Student search_student_by_id(int id,
                                    struct Student students[MAX_STUDENTS]) {
  for (int i = 0; i < MAX_STUDENTS; i++) {
    if (students[i].id == id) {
      return students[i];
    }
  }
  struct Student null;
  null.grade = 'N';
  return null;
}

int get_single_char() {
  int input;

  input = getchar();

  if (input != '\n') {
    clear_stream();
  }

  return input;
}

void clear_stream() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    continue; // discard extra characters
  }
}
