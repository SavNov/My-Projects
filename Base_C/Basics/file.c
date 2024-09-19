#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char string[100];
  FILE *fptr;

  fptr = fopen("myfile.txt", "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  printf("Enter string (no spaces): ");
  fgets(string, sizeof(string), stdin);

  fprintf(fptr, "%s", string);
  fclose(fptr);
  return 0;
}
