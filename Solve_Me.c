#include <stdio.h>

struct dictionary {
	int  key;
	char txt[2];
	int  enc;
};

struct dictionary dic[] = {
	{0,"_"},{1,"A"},{2,"B"},{3,"C"},{4,"D"},
	{5,"E"},{6,"F"},{7,"G"},{8,"H"},{9,"I"},
	{10,"J"},{11,"K"},{12,"L"},{13,"M"},{14,"N"},
	{15,"O"},{16,"P"},{17,"Q"},{18,"R"},{19,"S"},
	{20,"T"},{21,"U"},{22,"V"},{23,"W"},{24,"X"},
	{25,"Y"},{26,"Z"}
};

int enc[] = {
	24,21,00,19,02,
	26,14,01,13,19,
	18,16,10,20,17,
	19,26,10,00,19,
	02,01,10,26,01
};

void printCipher() {
	int p = 0;
	printf("\x1b[36m===Solve Me===\x1b[39m\n");
	for(int i = 0; i < sizeof(enc)/sizeof(enc[0]); i++) {
		p+=1;
		printf("\x1b[31m%02d \x1b[39m", enc[i]);
		if(p%5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

void dicEncode() {
	int a = 7;
	int b = 19;
	int p = 0;
	printf("\x1b[36m==============Dictionary==============\x1b[39m\n");
	for(int i = 0; i < sizeof(dic)/sizeof(dic[0]); i++) {
		p+=1;
		dic[i].enc = (a * dic[i].key + b)%27;
		printf("\x1b[32m%02d\x1b[39m:%s:\x1b[31m%02d\x1b[39m ", dic[i].key, dic[i].txt, dic[i].enc);
		if(p%5 == 0) {
			printf("\n");
		}
	}
	printf("\n\n");
}

void decode() {
	printf("\x1b[36m>Decode<\x1b[39m\n");
	for(int i = 0; i < sizeof(enc)/sizeof(enc[0]); i++) {
		for(int p = 0; p < 27; p++) {
			if(enc[i] == dic[p].enc) {
				printf("\x1b[32m%s\x1b[39m", dic[p].txt);
				break;
			}
		}
	}
	printf("\n\n");
}

void main() {
	printCipher();
	dicEncode();
	decode();
}

