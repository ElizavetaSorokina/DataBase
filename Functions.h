#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define N 20
Tdata edithuman(Tdata newhuman);

void scanfSet(Tdata* a) {
	printf("\n���: ");
	gets(&a->name);
	printf("\n�������: ");
	gets(&a->surname);
	printf("\n��������: ");
	scanf("%s", &a->fathername);
	printf("\n����� �����:");
	scanf("%d", &a->number);
	printf("\n��� �����: ");
	getchar();
	gets(&a->type);
	printf("\n������ ����������: ");
	gets(&a->country);
	printf("\n���� ����������: ");
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
	printf("������� ���-�� �������, ������� �� ������ �������� � ���� ������: ");
	scanf("%d", &n);
	getchar();
	if ((f = fopen(adress, "a b")) != NULL) {
		for (i = 0; i < n; i++) {
			scanfSet(&a);
			fwrite(&a, sizeof(Tdata), 1, f);
		}
		fclose(f);
	}
	else printf("������");
}

void filewrite(char* adress) {
	FILE* f;
	int k = 1;
	Tdata a;
	printf("\n � ����� %s:\n", adress);
	if ((f = fopen(adress, "rb")) != NULL) {
		printf("  ���		       �������              ��������     ����� ����� ��� ����� ������ ����������   ���� ��������\n");
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
	else printf("���� �� ��� ������");
}
void filedelete(char* adress) {
	FILE* f;
	int i = -1, numb = -1, del, now;
	//char surn[20];
	Tdata a;
	printf("������� ����� ����� ���������, �������� ������ ������� ");
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
			else printf("���� �� ��� ������ ��� ������.");
		}
		else printf("������ ������ ����� �� ����������.\n");
	}
	else printf("���� �� ��� ������");
}

void filesearch(char* adress) {
	FILE* f;
	int s;
	int i = 0;

	Tdata a;
	printf("������� ����, �� �������� ���� ������� �����:\n");
	printf("1 - ���, 2 - �������, 3 - ��������, 4 - ����� �����, 5 - ��� �����, 6 - ������ ����������, 7 - ���� ����������\n");
	scanf("%d", &s);
	switch (s) {
	case 1:
		i = 0;
		char pname[20];
		printf("������� ���:\n");
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
			if (i == 0) printf("������ ����� ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
	case 2:
		i = 0;
		char psur[20];
		printf("������� �������:\n");
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
			if (i == 0) printf("����� ������� ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
		break;
	case 3:
		i = 0;
		char pfname[20];
		printf("������� ��������:\n");
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
			if (i == 0) printf("������ �������� ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
	case 4:
		i = 0;
		int pnum;
		printf("������� ����� �����:\n");
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
			if (i == 0) printf("������ ������ ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
	case 5:
		i = 0;
		char ptype[10];
		printf("������� ��� �����:\n");
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
			if (i == 0) printf("������ ���� ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
	case 6:
		i = 0;
		char pcountry[20];
		printf("������� ������ ����������:\n");
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
			if (i == 0) printf("����� ������ ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
	case 7:
		i = 0;
		char pport[20];
		printf("������� ���� ����������:\n");
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
			if (i == 0) printf("������ ����� ���\n");
			fclose(f);
		}
		else printf("���� �� ��� ������");
		break;
	}
}



void fedit(char* adress) {
	FILE* f;
	Tdata a;
	int num = -1, i = -1, s, choise, now;
	Tdata newhuman;
	printf("������� ����� ����� ���������,���� �������� �� ������ ���������������\n");
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
			else printf("���� �� ��� ������ ��� ������.");
		}
		else printf("������ ������ ����� �� ����������.\n");
	}
	else printf("���� �� ��� ������");
}

Tdata edithuman(Tdata newhuman) {
	int s, k;
	char str[20];
	printf("������� ����� ����, ������� ������ ��������������� \n");
	printf("1 - ���, 2 - �������, 3 - ��������, 4 - ����� �����, 5 - ��� �����, 6 - ������ ����������, 7 - ���� ����������\n");
	scanf("%d", &s);
	getchar();
	switch (s) {
	case 1:
		printf("������� ����� ���: ");
		gets(str);
		strcpy(newhuman.name, str);
		break;
	case 2:
		printf("������� ����� �������: ");
		gets(str);
		strcpy(newhuman.surname, str);
		break;
	case 3:
		printf("������� ����� ��������: ");
		gets(str);
		strcpy(newhuman.fathername, str);
		break;
	case 4:
		printf("������� ����� ����� �����: ");
		scanf("%d", &k);
		newhuman.number = k;
		break;
	case 5:
		printf("������� ����� ��� �����: ");
		gets(str);
		strcpy(newhuman.type, str);
		break;
	case 6:
		printf("������� ����� ������ ����������: ");
		gets(str);
		strcpy(newhuman.country, str);
		break;
	case 7:
		printf("������� ����� ���� ��������: ");
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
	printf("������� ����� ���� ��� ����������:\n");
	printf("1 - ���, 2 - �������, 3 - ��������, 4 - ����� �����, 5 - ��� �����, 6 - ������ ����������, 7 - ���� ����������\n");
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
