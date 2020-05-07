#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	char name[40];
	char number[40];
}
info;


info people[4];
char rwa[10];
char ans[10];
char password[8];

int main(void)
{
	printf("Do you want to find, read or append?\n");
	scanf("%s", rwa);

	if (strcmp(rwa, "append") == 0)
	{
	printf("Please enter the password to access edit the database.\n");
	scanf("%s", password);

		if (strcmp(password, "imcool") == 0)
		{
			printf("Access granted.\n");

			for (int i = 0; i < 4; i++)
			{
				printf("Please enter a name.\n");
				scanf("%s", people[i].name);
				printf("Please enter the person's number.\n");
				scanf("%s", people[i].number);
			}
		}
		else
		{
			printf("access denied");
		}		
	}

	if (strcmp(rwa, "read") == 0)
	{
		FILE* myfile;
		myfile = fopen("test.txt", "r");
		char readingLines[150];
		
		while (!feof(myfile))
		{
			fgets(readingLines, 150, myfile);
			puts(readingLines);
		}
		fclose(myfile);
		return 0;
	}
	
	if (strcmp(rwa, "find") == 0)
	{
		
		printf("Which individual do you want to find?\n");
		scanf("%s", ans);
		FILE* f = fopen("database.csv", "rb");
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		fseek(f, 0, SEEK_SET);  

		char string[100];
		fread(string, 1, fsize, f);
		fclose(f);

		string[fsize] = 0;
	
	}

	FILE* myfile;
	myfile = fopen("database.csv", "a");
	fprintf(myfile, " %s  %s  %s  %s ", people[0].name, people[1].name, people[2].name, people[3].name);
	fprintf(myfile, "\n %s  %s  %s  %s ", people[0].number, people[1].number, people[2].number, people[3].number);
	fclose(myfile);
	
}