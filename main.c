#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#define Tdata human

void menu();

int main() {
	system("chcp 1251");
	system("cls");
	menu();
	
	return 0;
}


void menu() {
	char adress[] = "C:\\111\\bd.bin";
	human aa;
	int choice = 0, cn;
	printf("�������� ��������:\n");
	printf("1 - ���������� ������  � ���� ������\n");
	printf("2 - �������� ������ �� ���� ������\n");
	printf("3 - ����� ������ �� ����\n");
	printf("4 - �������������� ������ � ���� ������\n");
	printf("5 - ���������� ������ � ���� �� ����\n");
	printf("6 - ����� �� ����� ����������� ���� ������\n");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		fcreate(adress);
		break;
	case 2:
		filewrite(adress);
		filedelete(adress);
		filewrite(adress);
		break;
	case 3:
		filewrite(adress);
		filesearch(adress);
		break;
	case 4:
		filewrite(adress);
		fedit(adress);
		break;
	case 5:
		filewrite(adress);
		filesort(adress);
		filewrite(adress);
		break;
	case 6:
		filewrite(adress);
		break;
	}
	printf("������ ����������?\n 1 - ��, 0 - ���\n");
	scanf("%d", &cn);
	if (cn == 1) menu();
}