#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student {
 char lastname[30];
 char firstname[20];
 int group;
} Student_t;

typedef struct link{
     Student_t  student;
     struct link * next;
} Link_t;

void read_file_content(Student_t * array, FILE * file);

/*************   global variables   ****************/

Link_t * first_link = NULL;
int number_of_students = 0;

/********************   main   ********************/
int main(int argc, char*argv[]) {
  // First, we read the content of the file with the list of students
  // check that the user gave a correct number of parameters
  // Usage: ./sum_fscanf file_name
  if(argc!=2)
  {
    printf("Wrong usage: expected ./linked_list file_name");
    return -1;
  }

  // check for the occurence of errors when using fopen and fscanf,
  // display an error message and quit in case of errors.
  FILE * f = fopen(argv[1], "r");
  if (f == NULL)
  {
    printf("Error: could not open file %s, make sure it exists\n", argv[1]);
    return -2;
  }

  Student_t students_array [160];
  read_file_content(students_array, f);

  // visualize the content of students_array using printf
  for(int i =0;i<number_of_students;i++){
    printf("this is the student number %d named %s %s in the group %d \n",i,students_array[i].firstname,students_array[i].lastname,students_array[i].group);
  }

}

void read_file_content(Student_t * array, FILE * file){
  int ret_lec;
  while (ret_lec != EOF ){
    ret_lec = fscanf(file, "%s %s %d", array[number_of_students].firstname, array[number_of_students].lastname, &array[number_of_students].group);
    if (ret_lec == 3)
      number_of_students++;
    else if (ret_lec == EOF){
        return ;
    }
    else
      printf ("Line  %d : error or end of file \n", number_of_students);
  }
  printf("read_file_content: Implemented \n");
  exit(-1);
}