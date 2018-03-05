#include "rbc.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	uint64_t original[] = {0, 0};
	uint64_t key[] = {0, 0};
	printf("Original message:\n");
	print64(original[0]);
	print64(original[1]);
	printf("\nOriginal key:\n");
	print64(key[0]);
	print64(key[1]);
	printf("\nEncrypted message:\n");
	rbc_encrypt(&original[0], &original[1], key[0], key[1]);
	print64(original[0]);
	print64(original[1]);
	printf("\nDecrypted message:\n");
	rbc_decrypt(&original[0], &original[1], key[0], key[1]);
	print64(original[0]);
	print64(original[1]);	
	printf("\n");
	
}

void print64(uint64_t num)
{
	for(int i = 63; i >= 0; i--)
	{
		printf("%d", (num >> i) % 2);
	}
	fflush(stdout);
}