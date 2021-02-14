#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define max_int (1 << 16) - 1


int main (int argc, char * argv[], char ** envp) {

   int input;
   unsigned short value;
   while  ( ! feof(stdin) ) {
     scanf("%d", &input);
     if (input > max_int) {
       fprintf(stderr, "Error in input!\n");
       exit(1);
     }
     value = (unsigned short) input;
     write(1, &value, sizeof(unsigned short));
  }
}
