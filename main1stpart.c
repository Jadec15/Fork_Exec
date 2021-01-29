
#include <stdio.h>
#include <unistd.h>

int ForkExec(char *temp[]);

void main(int argc, char *argv[])
{
 int temp;
 temp = ForkExec(argv);
 printf("\nForkExec returned %d\n", temp);
}

int ForkExec(char *temp[])
{
	int id = fork();

	if ( id == 0 ) 
	{

		execvp(temp[1], temp+1);

	}

	wait( 2);
	printf("parent finished excution");
	return id;
}


