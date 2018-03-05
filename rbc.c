#include <stdint.h>
#include <stdio.h>
#include "rbc.h"


void rbc_enc_round(uint64_t *pt1, uint64_t *pt2, uint64_t k1, uint64_t k2)
{
	uint64_t p1 = *pt1;
	uint64_t p2 = *pt2;

	//First half-round
	p1 = p1 ^ p2;
	p1 = ROTR(p1, 3);
	p1 = p1 ^ k1;
	*pt1 = p1;

	//Second half-round
	p2 = p2 ^ p1;
	p2 = ROTL(p2, 5);
	p2 = p2 ^ k2;
	*pt2 = p2;
}

void rbc_dec_round(uint64_t *ct1, uint64_t *ct2, uint64_t k1, uint64_t k2)
{
	uint64_t c1 = *ct1;
	uint64_t c2 = *ct2;

	c2 = c2 ^ k2;
	c2 = ROTR(c2, 5);
	c2 = c2 ^ c1;
	*ct2 = c2;

	c1 = c1 ^ k1;
	c1 = ROTL(c1, 3);
	c1 = c1 ^ c2;
	*ct1 = c1;
}

void rbc_encrypt(uint64_t *pt1, uint64_t *pt2, uint64_t k1, uint64_t k2)
{
	uint64_t dest[2 * ROUNDS];
	rbc_expand_key(dest, k1, k2);
	for(int i = 0; i < ROUNDS; i++)
	{
		rbc_enc_round(pt1, pt2, dest[2*i], dest[2*i + 1]);
	}
}

void rbc_decrypt(uint64_t *ct1, uint64_t *ct2, uint64_t k1, uint64_t k2)
{
	uint64_t dest[2 * ROUNDS];
	rbc_expand_key(dest, k1, k2);
	for(int i = ROUNDS - 1; i >= 0; i--)
	{ 
		rbc_dec_round(ct1, ct2, dest[2*i], dest[2*i + 1]);
	}
}

void rbc_expand_key(uint64_t *dest, uint64_t k1, uint64_t k2)
{
	for(int i = 0; i < ROUNDS; i++)
	{
		//First 'half-expansion'
		k1 = ROTR(k1, 3);
		k2 = ROTL(k2, 5);
		k1 += constP;
		k2 += constQ;
		k1 = k1 ^ k2;

		k2 = ROTR(k2, 3);
		k2 = k2 + k1;
		k2 = k2 ^ ROTL((uint64_t)(constP ^ constQ), (uint64_t)(2*i));
		dest[2*i] = k2;

		k1 = ROTR(k1, 3);
		k2 = ROTL(k2, 5);
		k1 += constP;
		k2 += constQ;
		k1 = k1 ^ k2;

		k2 = ROTR(k2, 3);
		k2 = k2 + k1;
		k2 = k2 ^ ROTL((uint64_t)(constP ^ constQ), (uint64_t)(2*i + 1));
		dest[2*i + 1] = k2;
	}
}