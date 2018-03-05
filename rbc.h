#ifndef __RBC_H__
#define __RBC_H__

#include <stdint.h>
#define ROUNDS 12
#define constP 0xB7E151628AED2A6B
#define constQ 0x9E3779B97F4A7C15
#define ROTR(a, b) (((a) >> (b)) | (a << (64 - (b))))
#define ROTL(a, b) (((a) << (b)) | (a >> (64 - (b))))

void rbc_enc_round(uint64_t *pt1, uint64_t *pt2, uint64_t k1, uint64_t k2);
void rbc_dec_round(uint64_t *ct1, uint64_t *ct2, uint64_t k1, uint64_t k2);
void rbc_encrypt(uint64_t *pt1, uint64_t *pt2, uint64_t k1, uint64_t k2);
void rbc_decrypt(uint64_t *ct1, uint64_t *ct2, uint64_t k1, uint64_t k2);
void rbc_expand_key(uint64_t *dest, uint64_t k1, uint64_t k2);
void print64(uint64_t num);

#endif