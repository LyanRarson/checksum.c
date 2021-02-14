/********************************/
/* Program Name: checksum.c     */
/* Author: Ryan Larson          */
/* Date: 2/14/21                */
/********************************/
/* Description:                 */
/* Validation Checks: must be   */
/*     passed at least 10 bytes */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

#define checksum_index 5

int main (int argc, char * argv[], char ** envp) {

	int count = 10;
	int sum = 0;   
	byte checksum; 
	byte complement;
	byte *buffer = malloc(sizeof(byte[count])); // allocate buffer

	if(read(0, (void*)buffer, count) < count) {
		fprintf(stderr, "Error: input must be at least %i bytes!\n", count);
		return 2;
	}

	for(int i = 0; i < count; i++) {
		if(i == checksum_index) {
			checksum = buffer[i];
			buffer[i] = 0;
		}
		else {
			sum += buffer[i];
			if(sum > max_int)
			{
				sum = sum % (max_int + 1);
				sum++; // will always carry 1
			}
		}
	}
	
	complement = max_int - sum;

	fprintf(stdout, "Stored Checksum: %u, Computed Checksum: %u\n", checksum, complement);
	if (checksum != complement) {
		fprintf(stderr, "Error Detected!\n"); 
		return 1;
	}
	return 0;
}
