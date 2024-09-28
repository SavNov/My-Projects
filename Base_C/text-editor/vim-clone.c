#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

typedef struct line {
  unsigned char *l_text;
  struct line *next;
  struct line *prev;
} line_T;

typedef struct buffer {
  unsigned char *b_fname; // File name
  unsigned char *b_ffname; // Full file name
  line_T *first_line;
  line_T *last_line;
  int line_count;
  int b_changed; // Is the buffer modified?


} buf_T;

buf_T create_buffer(const char *);
void destroy_buffer(buf_T *);
void newline(buf_T *, const char *);
void remove_line(buf_T *, line_T *);
void ncurses_init_fill(buf_T *);
buf_T create_buffer(const char *filename) {
  buf_T *buf = malloc(sizeof(buf_T));
  buf->b_fname = (unsigned char *) strdup(filename);
  buf->b_ffname = buf->b_fname;
  buf->line_count = 0;
  buf->b_changed = false;
  buf->first_line = NULL;
  buf->last_line = NULL;
  
  return *buf;
}

void destroy_buffer(buf_T *buf) {
  line_T *current_line = buf->first_line;

  while (current_line->next != NULL) {
    remove_line(buf, current_line);
  }

}
void newline(buf_T *buf, const char *line_text) {
  line_T *new_line = malloc(sizeof(line_T));
  new_line->l_text = (unsigned char *) strdup(line_text);
  new_line->next = NULL;

  if (buf->last_line == NULL) {
    // This is the first line in the buffer.
    new_line->prev = NULL;
    buf->first_line = new_line;
  } else {
    // There are already lines in the buffer.
    new_line->prev = buf->last_line;
    buf->last_line->next = new_line;
  }
  buf->last_line = new_line;
  buf->line_count++;
}

void remove_line(buf_T *buf, line_T *line) {
  if (line->prev != NULL) {
    line->prev->next = line->next; //Unlink from the previous line.
  } else {
    buf->first_line = line->next; // Update the head if it's the first line.
  }

  if (line->next != NULL) {
    line->next->prev = line->prev;
  } else {
    buf->last_line = line->prev;
  }

  free(line->l_text);
  free(line);
  buf->line_count--;
}

buf_T start(FILE *fptr, char *fname) {
  char line[200];
  if ((fopen(fname, "r") != NULL)) {
    buf_T buf = create_buffer(fname);
    while (fgets(line, sizeof(line), fptr) != NULL) {
      newline(&buf,line);
    }
    return buf;
  } else {
    buf_T buf;
    line = "Hello!";
    newline(&buf, line);
    return buf;
  }
}

void ncurses_init_fill(buf_T *buf) {
  line_T *current_line = buf->first_line;
  int focused_line = 0;
  while (current_line->next != NULL && focused_line < 24) {
    move(focused_line,0);
    printw("%s", current_line->l_text);
    focused_line++;
  }
  sleep(5);
}
int main(int argc, char **argv) {
  if (argc == 1) {
    printf("%s", argv[0]);
  }
  FILE *fptr;
  char *fname = argv[1];
  initscr();
  printw("Hello! This is my vim clone!");
  refresh();
  sleep(5);
  clrtobot();
  buf_T buf = start(fptr, fname);
  ncurses_init_fill(&buf);
  destroy_buffer(&buf);
  endwin();
  
  return 0;
} 
