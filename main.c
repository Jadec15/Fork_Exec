#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int ForkExec(char *temp[]);

void main(int argc, char *argv[])
{
 int temp;  
 int curr = 1;
 int prev = 1;
 while(argv[curr] != NULL)
{
	if (strcmp(argv[curr], ":")==0)
	{
		argv[curr] = NULL;
		int i;
	        for( i = prev; i < curr; i++ )
			{
				printf("%s ",argv[i]);
			}
		printf("\n");
		temp = ForkExec(&argv[prev]);
		prev = curr + 1;
		
	}
	curr++;
 	
}
	printf("fork returned\n");
}

int ForkExec(char *temp[])
{
	int id = fork();

	if ( id == 0 ) 
	{

		execvp(temp[0], temp);
		return 0; 
	}

	wait(NULL);
	return id;
}


