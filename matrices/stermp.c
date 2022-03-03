#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "stermp.h"

void gotoxy(int x, int y) {
  printf("\033[%d;%dH", y, x); 	/* Put cursor in X, Y */
}

void clear_buffer() {
    int fdflags;
    fdflags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fdflags | O_NONBLOCK);
    while (getchar()!=EOF);
    fcntl(STDIN_FILENO, F_SETFL, fdflags);
}

