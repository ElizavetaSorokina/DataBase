#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define N 20
Tdata edithuman(Tdata newhuman);

void scanfSet(Tdata* a) {
	printf("\nИмя: ");
	gets(&a->name);
	printf("\nФамилия: ");
	gets(&a->surname);
	printf("\nОтчество: ");
	scanf("%s", &a->fathername);
	printf("\nНомер каюты:");
	scanf("%d", &a->number);
	printf("\nТип каюты: ");
	getchar();
	gets(&a->type);
	printf("\nСтрана проживания: ");
	gets(&a->country);
	printf("\nПорт назначения: ");
	gets(&a->port);
}
void printSet(Tdata a) {

	printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
	printf("\n");
}



void fcreate(char* adress) {
	FILE* f;
	int i, n;
	Tdata a;
	printf("Введите кол-во записей, которые вы хотите добавить в базу данных: ");
	scanf("%d", &n);
	getchar();
	if ((f = fopen(adress, "a b")) != NULL) {
		for (i = 0; i < n; i++) {
			scanfSet(&a);
			fwrite(&a, sizeof(Tdata), 1, f);
		}
		fclose(f);
	}
	else printf("Ошибка");
}

void filewrite(char* adress) {
	FILE* f;
	int k = 1;
	Tdata a;
	printf("\n В файле %s:\n", adress);
	if ((f = fopen(adress, "rb")) != NULL) {
		printf("  Имя		       Фамилия              Отчество     Номер каюты Тип каюты Страна проживания   Порт прибытия\n");
		while (!feof(f)) {
			fread(&a, sizeof(Tdata), 1, f);
			if (!feof(f)) {
				printf("%d)", k);
				printSet(a);
				k++;
			}
		}
		fclose(f);
		printf("\n");
	}
	else printf("Файл не был открыт");
}
void filedelete(char* adress) {
	FILE* f;
	int i = -1, numb = -1, del, now;
	//char surn[20];
	Tdata a;
	printf("Введите номер каюты пассажира, которого хотите удалить ");
	scanf("%d", &del);
	if ((f = fopen(adress, "rb")) != NULL) {
		while (!feof(f)) {
			fread(&a, sizeof(Tdata), 1, f);
			if (!feof(f)) {
				i++;
				if (del == a.number) numb = i;
			}
		}
		fclose(f);
		if (numb != -1) {
			if ((f = fopen(adress, "r+b")) != NULL) {
				now = numb;
				for (int j = numb; j < i; j++) {
					fseek(f, (now + 1) * sizeof(Tdata), SEEK_SET);
					fread(&a, sizeof(Tdata), 1, f);
					fseek(f, now * sizeof(Tdata), SEEK_SET);
					fflush(f);
					fwrite(&a, sizeof(Tdata), 1, f);
					now++;
				}
				chsize(_fileno(f), i * sizeof(Tdata));
				fclose(f);
			}
			else printf("Файл не был открыт для записи.");
		}
		else printf("Такого номера каюты не существует.\n");
	}
	else printf("Файл не был открыт");
}

void filesearch(char* adress) {
	FILE* f;
	int s;
	int i = 0;

	Tdata a;
	printf("Введите поле, по которому надо сделать поиск:\n");
	printf("1 - Имя, 2 - Фамилия, 3 - Отчество, 4 - Номер каюты, 5 - Тип каюты, 6 - Страна проживания, 7 - Порт назначения\n");
	scanf("%d", &s);
	switch (s) {
	case 1:
		i = 0;
		char pname[20];
		printf("Введите имя:\n");
		getchar();
		gets(pname);
		//printf("%s", pname);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (!strcmp(pname, a.name)) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такого имени нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
	case 2:
		i = 0;
		char psur[20];
		printf("Введите фамилию:\n");
		getchar();
		gets(psur);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (!strcmp(psur, a.surname)) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такой фамилии нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
		break;
	case 3:
		i = 0;
		char pfname[20];
		printf("Введите отчество:\n");
		getchar();
		gets(pfname);
		//printf("%s", pname);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (!strcmp(pfname, a.fathername)) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такого отчества нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
	case 4:
		i = 0;
		int pnum;
		printf("Введите номер каюты:\n");
		scanf("%d", &pnum);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (pnum == a.number) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такого номера нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
	case 5:
		i = 0;
		char ptype[10];
		printf("Введите тип каюты:\n");
		getchar();
		gets(ptype);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (!strcmp(ptype, a.type)) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такого типа нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
	case 6:
		i = 0;
		char pcountry[20];
		printf("Введите страну проживания:\n");
		getchar();
		gets(pcountry);
		//printf("%s", pname);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (!strcmp(pcountry, a.country)) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такой страны нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
	case 7:
		i = 0;
		char pport[20];
		printf("Введите порт назначения:\n");
		getchar();
		gets(pport);
		//printf("%s", pname);
		if ((f = fopen(adress, "rb")) != NULL) {
			while (!feof(f)) {
				fread(&a, sizeof(Tdata), 1, f);
				if (!feof(f)) {
					if (!strcmp(pport, a.port)) {
						i++;
						printf("%-20s %-20s %-20s %-4d %-10s %-20s %-20s", a.name, a.surname, a.fathername, a.number, a.type, a.country, a.port);
					}
				}
			}
			if (i == 0) printf("Такого порта нет\n");
			fclose(f);
		}
		else printf("Файл не был открыт");
		break;
	}
}



void fedit(char* adress) {
	FILE* f;
	Tdata a;
	int num = -1, i = -1, s, choise, now;
	Tdata newhuman;
	printf("Введите номер каюты пассажира,поле которого вы хотите отредактировать\n");
	scanf("%d", &s);
	if ((f = fopen(adress, "rb")) != NULL) {
		while (!feof(f)) {
			fread(&a, sizeof(Tdata), 1, f);
			if (!feof(f)) {
				i++;
				if (s == a.number) num = i;
			}
		}
		fclose(f);
		if (num != -1) {
			if ((f = fopen(adress, "r+b")) != NULL) {
				fseek(f, num * sizeof(Tdata), SEEK_SET);
				fread(&newhuman, sizeof(Tdata), 1, f);
				newhuman = edithuman(newhuman);
				fflush(f);
				fseek(f, num * sizeof(Tdata), SEEK_SET);
				fwrite(&newhuman, sizeof(Tdata), 1, f);
				fclose(f);
			}
			else printf("Файл не был открыт для записи.");
		}
		else printf("Такого номера каюты не существует.\n");
	}
	else printf("Файл не был открыт");
}

Tdata edithuman(Tdata newhuman) {
	int s, k;
	char str[20];
	printf("Введите номер поля, которое хотите отредактировать \n");
	printf("1 - Имя, 2 - Фамилия, 3 - Отчество, 4 - Номер каюты, 5 - Тип каюты, 6 - Страна проживания, 7 - Порт назначения\n");
	scanf("%d", &s);
	getchar();
	switch (s) {
	case 1:
		printf("Введите новое имя: ");
		gets(str);
		strcpy(newhuman.name, str);
		break;
	case 2:
		printf("Введите новую фамилию: ");
		gets(str);
		strcpy(newhuman.surname, str);
		break;
	case 3:
		printf("Введите новое отчество: ");
		gets(str);
		strcpy(newhuman.fathername, str);
		break;
	case 4:
		printf("Введите новый номер каюты: ");
		scanf("%d", &k);
		newhuman.number = k;
		break;
	case 5:
		printf("Введите новый тип каюты: ");
		gets(str);
		strcpy(newhuman.type, str);
		break;
	case 6:
		printf("Введите новую страну проживания: ");
		gets(str);
		strcpy(newhuman.country, str);
		break;
	case 7:
		printf("Введите новый порт прибытия: ");
		gets(str);
		strcpy(newhuman.port, str);
		break;

	}
	return newhuman;
}




void filesort(adress) {
	FILE* f;
	Tdata a;
	Tdata humans[N], c;
	int s;
	int i = -1, n = 0;
	if ((f = fopen(adress, "rb")) != NULL) {
		while (!feof(f)) {
			fread(&a, sizeof(Tdata), 1, f);
			if (!feof(f)) {
				n++;
			}
		}
		fclose(f);
	}
	else printf("File didn't open.");
	if ((f = fopen(adress, "rb")) != NULL) {
		while (!feof(f)) {
			i++;
			fread(&a, sizeof(Tdata), 1, f);
			if (!feof(f)) {
				humans[i] = a;
			}
		}
		fclose(f);

	}
	else printf("File didn't open.");
	printf("Введите номер поля для сортировки:\n");
	printf("1 - Имя, 2 - Фамилия, 3 - Отчество, 4 - Номер каюты, 5 - Тип каюты, 6 - Страна проживания, 7 - Порт назначения\n");
	scanf("%d", &s);
	getchar();
	switch (s) {
	case 1:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (strcmp(humans[k].name, humans[k + 1].name) > 0) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (strcmp(humans[k].surname, humans[k + 1].surname) > 0) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (strcmp(humans[k].fathername, humans[k + 1].fathername) > 0) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	case 4:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (humans[k].number > humans[k + 1].number) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	case 5:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (strcmp(humans[k].type, humans[k + 1].type) > 0) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	case 6:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (strcmp(humans[k].country, humans[k + 1].country) > 0) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	case 7:
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (strcmp(humans[k].port, humans[k + 1].port) > 0) {
					c = humans[k + 1];
					humans[k + 1] = humans[k];
					humans[k] = c;


				}
			}
		}
		if ((f = fopen(adress, "wb")) != NULL) {
			for (i = 0; i < n; i++) fwrite(&humans[i], sizeof(Tdata), 1, f);
			fclose(f);
		}
		else printf("File didn't open.");
		break;
	}
}

#endif
