// JH.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "jh_ref.h"
#include <string.h> 
#include <assert.h>
#include <stdlib.h> 
#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <string>
#include "time.h"

using namespace std;

void printBits(size_t const size, void const * const ptr, FILE *write)
{
	unsigned char *b = (unsigned char*)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			byte = b[i] & (1 << j);
			byte >>= j;
			fprintf(write,"%u", byte);
		}
	}
	puts("");
}

static unsigned char gethex(const char *s, char **endptr) {
	assert(s);
	while (isspace(*s)) s++;
	assert(*s);
	return strtoul(s, endptr, 16);
}

unsigned char *convert(const char *s, int *length) {
	unsigned char *answer = (unsigned char*)malloc((strlen(s) + 1) / 3);
	unsigned char *p;
	for (p = answer; *s; p++)
		*p = gethex(s, (char **)&s);
	*length = p - answer;
	return answer;
}

double get_CPU_time_usage(clock_t clock1, clock_t clock2){
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
}

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t begin = clock();
	char *bin = "010011111111010000000000";
	char *a = bin;
	int num = 0;
	do {
		int b = *a == '1' ? 1 : 0;
		num = (num << 1) | b;
		a++;
	} while (*a);

	unsigned char plaintext[3] =
	{ 0x4F,0xF4,0x00 };

	unsigned char salida[512];
	int tam =17;
	DataLength tamano = tam;
	int hashbitlen = 512;
	//printf("Bits: ");
	//printBits(sizeof(plaintext), &plaintext);
	//printf("Hex: ");
	/*for (int i = 0; i < 3; i++) {
		printf("%x ", plaintext[i]);
	}*/
	//printf("\n");
	Hash(hashbitlen, plaintext, tamano, salida);
	/*for (int i = 0; i <= hashbitlen/8; i++) {
		printf("%x", salida[i]);
	}*/
	printf("\n ------------------\n");

	FILE *out1;
	out1 = fopen("out1.txt","w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i],out1);
	}

	//-------------------
	
	unsigned char plaintext2[3] =
	{ 0xCF, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
		printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext2, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
		printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out2;
	out2 = fopen("out2.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out2);
	}

	//--------------------------
	unsigned char plaintext3[3] =
	{ 0x8F, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext3, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out3;
	out3 = fopen("out3.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out3);
	}
	
	//--------------------------
	unsigned char plaintext4[3] =
	{ 0xAF, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext4, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out4;
	out4 = fopen("out4.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out4);
	}

	//--------------------------
	unsigned char plaintext5[3] =
	{ 0xB7, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext5, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out5;
	out5 = fopen("out5.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out5);
	}

	//--------------------------
	unsigned char plaintext6[3] =
	{ 0xB3, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext6, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out6;
	out6 = fopen("out6.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out6);
	}


	//--------------------------
	unsigned char plaintext7[3] =
	{ 0xB1, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext7, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out7;
	out7 = fopen("out7.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out7);
	}

	//--------------------------
	unsigned char plaintext8[3] =
	{ 0xB0, 0xF4, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext8, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out8;
	out8 = fopen("out8.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out8);
	}

	//--------------------------
	unsigned char plaintext9[3] =
	{ 0xB0, 0x74, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext9, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out9;
	out9 = fopen("out9.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out9);
	}

	//--------------------------
	unsigned char plaintext10[3] =
	{ 0xB0, 0x34, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext10, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out10;
	out10 = fopen("out10.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out10);
	}


	//--------------------------
	unsigned char plaintext11[3] =
	{ 0xB0, 0x14, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext11, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out11;
	out11 = fopen("out11.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out11);
	}

	//--------------------------
	unsigned char plaintext12[3] =
	{ 0xB0, 0x04, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext12, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out12;
	out12 = fopen("out12.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out12);
	}

	//--------------------------
	unsigned char plaintext13[3] =
	{ 0xB0, 0x0C, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext13, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out13;
	out13 = fopen("out13.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out13);
	}


	//--------------------------
	unsigned char plaintext14[3] =
	{ 0xB0, 0x8C, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext14, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out14;
	out14 = fopen("out14.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out14);
	}


	//--------------------------
	unsigned char plaintext15[3] =
	{ 0xB0, 0x0A, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext15, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out15;
	out15 = fopen("out15.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out15);
	}

	//--------------------------
	unsigned char plaintext16[3] =
	{ 0xB0, 0x0B, 0x00 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext16, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out16;
	out16 = fopen("out16.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out16);
	}

	//--------------------------
	unsigned char plaintext17[3] =
	{ 0xB0, 0x0B, 0x80 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext17, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out17;
	out17 = fopen("out17.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out17);
	}

	//--------------------------
	unsigned char plaintext18[3] =
	{ 0xB0, 0x0B, 0xC0 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext18, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out18;
	out18 = fopen("out18.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out18);
	}


	//--------------------------
	unsigned char plaintext19[3] =
	{ 0xB0, 0x0B, 0xE0 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext19, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out19;
	out19 = fopen("out19.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out19);
	}


	//--------------------------
	unsigned char plaintext20[3] =
	{ 0xB0, 0x0B, 0xF0 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext20, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out20;
	out20 = fopen("out20.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out20);
	}


	//--------------------------
	unsigned char plaintext21[3] =
	{ 0xB0, 0x0B, 0xF8 };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext21, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out21;
	out21 = fopen("out21.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out21);
	}

	//--------------------------
	unsigned char plaintext22[3] =
	{ 0xB0, 0x0B, 0xFC };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext22, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out22;
	out22 = fopen("out22.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out22);
	}

	//--------------------------
	unsigned char plaintext23[3] =
	{ 0xB0, 0x0B, 0xFE };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext23, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out23;
	out23 = fopen("out23.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out23);
	}


	//--------------------------
	unsigned char plaintext24[3] =
	{ 0xB0, 0x0B, 0xFF };

	salida[512];

	//printf("Bits: ");
	//printBits(sizeof(plaintext2), &plaintext);
	/*printf("Hex: ");
	for (int i = 0; i < 3; i++) {
	printf("%x ", plaintext2[i]);
	}
	printf("\n");*/
	Hash(hashbitlen, plaintext24, tamano, salida);
	/*for (int i = 0; i <= hashbitlen / 8; i++) {
	printf("%x", salida[i]);
	}
	printf("\n ------------------\n");
	*/
	FILE *out24;
	out24 = fopen("out24.txt", "w+");
	for (int i = 0; i <= hashbitlen / 8; i++) {
		printBits(4, &salida[i], out24);
	}

	clock_t end = clock();

	printf("inicial: %f", begin);
	printf("final: %f", end);

	printf("Tiempo tardado: %f", get_CPU_time_usage(end, begin));
	return 0;
}

