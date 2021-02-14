/********************************/
/* Program Name: checksum.c     */
/* Author: Ryan Larson          */
/* Date: 2/14/21                */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte (char)

int main (int argc, char * argv[], char ** envp) {

	int count = 10;
	int sum = 0;   
	byte checksum; 
	byte complement;
	byte *buffer = malloc(sizeof(byte[10])); // allocate buffer

	if(read(int fildes, void *buf, size_t nbyte) != 10) {
		fprintf(stdout, "Error: input must equal 10 bytes!\n");
		return 2;
	}

	for(int i = 0; i < 10; i++) {
		
	}

	fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
	if (checksum != complement ) {
		fprintf(stderr, "Error Detected!\n"); 
		return 1;
	}
	return 0;
}
