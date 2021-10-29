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
	printf("Выберите действие:\n");
	printf("1 - добавление записи  в базу данных\n");
	printf("2 - удаление записи из базы данных\n");
	printf("3 - поиск записи по полю\n");
	printf("4 - редактирование записи в базе данных\n");
	printf("5 - сортировка данных в базе по полю\n");
	printf("6 - вывод на экран содержимого базы данных\n");
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
	printf("Хотите продолжить?\n 1 - да, 0 - нет\n");
	scanf("%d", &cn);
	if (cn == 1) menu();
}