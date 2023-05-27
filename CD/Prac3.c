#include <ctype.h>
#include <stdio.h>
#include <string.h>

void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);

int count, n = 0; //the number of symbols in the First set of nt

char calc_first[10][100];
char calc_follow[10][100];
int m = 0; //the number of symbols in the Follow set of nt

char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main(int argc, char** argv)
{
	int jm = 0;
	int km = 0;
	int i, choice;
	char c, ch;
	count = 7; //the number of production rules in the grammar

	strcpy(production[0], "A=SB");
	strcpy(production[1], "A=B");
	strcpy(production[2], "S=a");
	strcpy(production[3], "S=Bc");
	strcpy(production[4], "S=#");
	strcpy(production[5], "B=b");
	strcpy(production[6], "B=d");

	int a1;
	char done[count];
	int ptr = -1;

	for (k = 0; k < count; k++) {
		for (a1 = 0; a1 < 100; a1++) {
			calc_first[k][a1] = '!';
		}
	}
	int point1 = 0, point2, xxx;

	for (k = 0; k < count; k++) {
		c = production[k][0];
		point2 = 0;
		xxx = 0;
		for (a1 = 0; a1 <= ptr; a1++)
			if (c == done[a1])
				xxx = 1;

		if (xxx == 1)
			continue;

		findfirst(c, 0, 0); // This function takes three arguments: the non-terminal symbol to calculate the First set for, a starting index for the production rule to consider, and a starting index for the current symbol in the production rule.
		ptr += 1;

		done[ptr] = c;
		printf("\n First(%c) = { ", c);
		calc_first[point1][point2++] = c;

		// Print first sets 
		for (i = 0 + jm; i < n; i++) {
			int a2 = 0, chk = 0;

			for (a2 = 0; a2 < point2; a2++) {

				if (first[i] == calc_first[point1][a2]) {
					chk = 1;
					break;
				}
			}
			if (chk == 0) {
				printf("%c, ", first[i]);
				calc_first[point1][point2++] = first[i];
			}
		}
		printf("}\n");
		jm = n;
		point1++;
	}
	printf("\n");
	char donee[count];
	ptr = -1;

	for (k = 0; k < count; k++) {
		for (a1 = 0; a1 < 100; a1++) {
			calc_follow[k][a1] = '!';
		}
	}
	point1 = 0;
	int land = 0;
	for (e = 0; e < count; e++) {
		ck = production[e][0];
		point2 = 0;
		xxx = 0;

		for (a1 = 0; a1 <= ptr; a1++)
			if (ck == donee[a1])
				xxx = 1;

		if (xxx == 1)
			continue;
		land += 1;

		
		follow(ck);
		ptr += 1;

		donee[ptr] = ck;
		printf(" Follow(%c) = { ", ck);
		calc_follow[point1][point2++] = ck;

		// Print follow 
		for (i = 0 + km; i < m; i++) {
			int a2 = 0, chk = 0;
			for (a2 = 0; a2 < point2; a2++) {
				if (f[i] == calc_follow[point1][a2]) {
					chk = 1;
					break;
				}
			}
			if (chk == 0) {
				printf("%c, ", f[i]);
				calc_follow[point1][point2++] = f[i];
			}
		}
		printf(" }\n\n");
		km = m;
		point1++;
	}
	char ter[10];
	for(k=0;k<10;k++){
		ter[k] = '!';
	}
	int ap,vp,sid = 0;
	for(k=0;k<count;k++){
		for(a1=0;a1<count;a1++){
			if(!isupper(production[k][a1]) && production[k][a1]!= '#' && production[k][a1] != '=' && production[k][a1] != '\0'){
				vp = 0;
				for(ap = 0;ap < sid; ap++){
					if(production[k][a1] == ter[ap]){
						vp = 1;
						break;
					}
				}
				if(vp == 0){
					ter[sid] = production[k][a1];
					sid ++;
				}
			}
		}
	}
	
	ter[sid] = '$';
	sid++;
	printf("\n\t\t\t\t\t\t\t  LL(1) Parsing Table :-");
	printf("\n\t\t\t\t|\t");
	for(ap = 0;ap < sid; ap++){
		printf("%c\t\t",ter[ap]);
	}
	printf("\n\t\t\t---------------------------------------------------------------------------------------------------------------------\n");
	char first_prod[count][sid];
	for(ap=0;ap<count;ap++){
		int d1 = 0;
		k = 2;
		int ct = 0;
		char tem[100];
		while(production[ap][k] != '\0'){
			if(!isupper(production[ap][k])){
				tem[ct++] = production[ap][k];
				tem[ct++] = '_';
				tem[ct++] = '\0';
				k++;
				break;
			}
			else{
				int a3=0;
				int a4 = 0;
				for(a3=0;a3<count;a3++){
					if(calc_first[a3][0] == production[ap][k]){
						for(a4=1;a4<100;a4++){
							if(calc_first[a3][a4] != '!'){
								tem[ct++] = calc_first[a3][a4];
							}
							else
								break;
						}
					break;
					}
				}
				tem[ct++] = '_';
			}
			k++;
		}
		int a3 = 0,a4;		
		for(a4 = 0;a4<ct;a4++){
			if(tem[a4] == '#'){
				a3 = 1;
			}
			else if(tem[a4] == '_'){
				if(a3 == 1){
					a3 = 0;
				}
				else
					break;
			}
			else{
				first_prod[ap][d1++] = tem[a4];
			}
		}
	}
	char table[land][sid+1];
	ptr = -1;
	for(ap = 0; ap < land ; ap++){
		for(a1 = 0; a1 < (sid + 1) ; a1++){
			table[ap][a1] = '!';
		}
	}
	for(ap = 0; ap < count ; ap++){
		ck = production[ap][0];
		xxx = 0;
		for(a1 = 0; a1 <= ptr; a1++)
			if(ck == table[a1][0])
				xxx = 1;
		if (xxx == 1)
			continue;
		else{
			ptr = ptr + 1;
			table[ptr][0] = ck;
		}
	}
	for(ap = 0; ap < count ; ap++){
		int a4 = 0;
		while(first_prod[ap][a4] != '\0'){
			int to,ni=0;
			for(to=0;to<sid;to++){
				if(first_prod[ap][a4] == ter[to]){
					ni = 1;
				}
			}
			if(ni == 1){
				char xz = production[ap][0];
				int cz=0;
				while(table[cz][0] != xz){
					cz = cz + 1;
				}
				int vz=0;
				while(ter[vz] != first_prod[ap][a4]){
					vz = vz + 1;
				}
				table[cz][vz+1] = (char)(ap + 65);
			}
			a4++;
		}
	}
	for(k=0;k<sid;k++){
		for(a1=0;a1<100;a1++){
			if(calc_first[k][a1] == '!'){
				break;
			}
			else if(calc_first[k][a1] == '#'){
				int fz = 1;
				while(calc_follow[k][fz] != '!'){
					char xz = production[k][0];
					int cz=0;
					while(table[cz][0] != xz){
						cz = cz + 1;
					}
					int vz=0;
					while(ter[vz] != calc_follow[k][fz]){
						vz = vz + 1;
					}
					table[k][vz+1] = '#';
					fz++;	
				}
				break;
			}
		}
	}
	for(ap = 0; ap < land ; ap++){
		printf("\t\t\t   %c\t|\t",table[ap][0]);
		for(a1 = 1; a1 < (sid + 1) ; a1++){
			if(table[ap][a1] == '!')
				printf("\t\t");
			else if(table[ap][a1] == '#')
				printf("%c=#\t\t",table[ap][0]);
			else{
				int mum = (int)(table[ap][a1]);
				mum -= 65;
				printf("%s\t\t",production[mum]);
			}
		}
		printf("\n");
		printf("\t\t\t---------------------------------------------------------------------------------------------------------------------");
		printf("\n");
	}
}

void follow(char c)
{
	int i, j;

	if (production[0][0] == c) {
		f[m++] = '$';
	}
	for (i = 0; i < 10; i++) {
		for (j = 2; j < 10; j++) {
			if (production[i][j] == c) {
				if (production[i][j + 1] != '\0') {
					followfirst(production[i][j + 1], i,
								(j + 2));
				}

				if (production[i][j + 1] == '\0'
					&& c != production[i][0]) {
					follow(production[i][0]);
				}
			}
		}
	}
}

void findfirst(char c, int q1, int q2)
{
	int j;

	if (!(isupper(c))) {
		first[n++] = c;
	}
	for (j = 0; j < count; j++) {
		if (production[j][0] == c) {
			if (production[j][2] == '#') {
				if (production[q1][q2] == '\0')
					first[n++] = '#';
				else if (production[q1][q2] != '\0'
						&& (q1 != 0 || q2 != 0)) {
	
					findfirst(production[q1][q2], q1,
							(q2 + 1));
				}
				else
					first[n++] = '#';
			}
			else if (!isupper(production[j][2])) {
				first[n++] = production[j][2];
			}
			else {
				findfirst(production[j][2], j, 3);
			}
		}
	}
}

void followfirst(char c, int c1, int c2)
{
	int k;

	if (!(isupper(c)))
		f[m++] = c;
	else {
		int i = 0, j = 1;
		for (i = 0; i < count; i++) {
			if (calc_first[i][0] == c)
				break;
		}

		while (calc_first[i][j] != '!') {
			if (calc_first[i][j] != '#') {
				f[m++] = calc_first[i][j];
			}
			else {
				if (production[c1][c2] == '\0') {
					follow(production[c1][0]);
				}
				else {
					followfirst(production[c1][c2], c1,
								c2 + 1);
				}
			}
			j++;
		}
	}
}

