#ifndef HEADER_H
#define HEADER_H
#define Tdata human

typedef struct {
	char name[20];
	char surname[20];
	char fathername[20];
	int number;
	char type[10];
	char country[20];
	char port[20];
}human;



void scanfSet(Tdata* a);
void printSet(Tdata a);
void fcreate(char* adress);
void filewrite(char* adress);
void filedelete(char* adress);
void filesearch(char* adress);
void fedit(char* adress);
Tdata edithuman(Tdata newhuman);



#endif
