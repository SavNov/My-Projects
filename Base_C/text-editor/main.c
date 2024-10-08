#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_CHARS 80
typedef struct {
  char line[MAX_CHARS + 1];
  int is_new_line;
} Line;

typedef struct {
  char **lines;
  int length;
  int capacity;
} buffer;

void start(buffer *buf) {
  buf->capacity = 2;
  buf->length = 0;
  buf->lines = malloc(buf->capacity * sizeof(char *));
  if (buf->lines == NULL) {
    endwin();
    perror("Failed to allocate memory for lines.");
    exit(1);
  }
}

void resize(buffer *buf) {
  buf->capacity *= 2;
  buf->lines = realloc(buf->lines, buf->capacity * sizeof(char *));

  if (buf->lines == NULL) {
    endwin();
    perror("Failed to reallocate memory for lines.");
    exit(1);
  }
}

void newline(buffer *buf, const char *input) {

  if (buf->length == buf->capacity) {
    resize(buf);
  }

  buf->lines[buf->length] = malloc((80 + 1) * sizeof(char));

  if (buf->lines[buf->length] == NULL) {
    endwin();
    perror("Failed to allocate memory for a new line.");
    exit(1);
  }

  strncpy(buf->lines[buf->length], input, 80);
  buf->lines[buf->length][80] = '\0';

  buf->length++;
}

void free_buf(buffer *buf) {

  for (int i = 0; i < buf->length; i++) {
    free(buf->lines[i]);
  }

  free(buf->lines);
}
void end(void) {
  clrtobot();
  sleep(1);
  endwin();
}
int main(int argc, char **argv) {
  char *file = argv[1];
  printf("%s\n", file);
  FILE *fptr;
  if ((fptr = fopen(file, "r")) != NULL) {
    buffer buf;
    start(&buf);
    char line[150];
    while (fgets(line, sizeof(line), fptr) != NULL) {
      buf.newline(line);
    }
  }
  initscr();

  move(5, 10);
  printw("Welcome to my text editor!\n");
  refresh();
  sleep(3);

  move(10, 10);
  printw("This was written in Ncurses!\n");
  refresh();

  move(0,0);
  printw("Press q to exit: Pressing anything else will begin the program.");
  refresh();
  char user = getch();
  if (user == 'q') {
    end();
    fclose(fptr);
    return 0;
  }
  getch();
  endwin();
  fclose(fptr);
  fptr = fopen(file, "a");
  for (int i = 0; i < buf.length; i++) {
    fprintf(fptr, "%s\n", buf.lines[i]);
  }
  free_buf(&buf);

  fclose(fptr);
  return 0;
}
