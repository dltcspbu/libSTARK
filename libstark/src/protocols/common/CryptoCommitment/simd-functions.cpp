#ifndef _MY_SIMD_FUNCTIONS_
#define _MY_SIMD_FUNCTIONS_

#include <iostream>

inline void _My_shuffle_pd(uint64_t* a, uint64_t* b, int imm8, uint64_t* dst) {
	dst[0] = ((imm8 & 1) == 0) ? a[0] : a[1];
	dst[1] = ((imm8 & 2) == 0) ? b[0] : b[1];
}

inline void _My_slli_epi64(uint64_t* a, int imm8, uint64_t* dst) {
	dst[0] = ((imm8 > 63) ? 0 : (a[0] << imm8));
	dst[1] = ((imm8 > 63) ? 0 : (a[1] << imm8));
}

inline void _My_srli_epi64(uint64_t* a, int imm8, uint64_t* dst) {
	dst[0] = ((imm8 > 63) ? 0 : (a[0] >> imm8));
	dst[1] = ((imm8 > 63) ? 0 : (a[1] >> imm8));
}

inline void _My_xor_si128(uint64_t* a, uint64_t* b, uint64_t* dst) {
	dst[0] = a[0] xor b[0];
	dst[1] = a[1] xor b[1];
}

inline void _My_shuffle_epi8(uint8_t* a, uint8_t* b, uint8_t* dst) {
	for (int j = 0; j < 16; ++j) {
		dst[j] = ((b[j] & 128) > 0 ? 0 : a[15 & b[j]]);
	}
}

inline void _My_shuffle_epi32(uint32_t* a, int imm8, uint32_t* dst) {
	dst[0] = a[imm8 & 3];
	dst[1] = a[(imm8 >> 2) & 3];
	dst[2] = a[(imm8 >> 4) & 3];
	dst[3] = a[(imm8 >> 6) & 3];
}

inline void _My_slli_si128(uint8_t* a, int imm8, uint8_t* dst) {
	if (imm8 > 15) {
		imm8 = 16;
	}

	for (int i = 0; i < 16; ++i) {
		dst[(i + imm8) % 16] = a[i];
	}
}

#endif