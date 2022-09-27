#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	speaker(void)
{
	printf("I'm child\n");
}

int main()
{
	int *room;

	room = (int *)malloc(5 * sizeof(int));
	memset(room, -1, 5);

	printf("parent's pid: %d\n", getpid());
	for(int i = 0; i < 5; ++i)
	{
		room[i] = fork();
		if (room[i] == 0)
		{
			speaker();
			break;
		}
		else if (room[i] < 0)
			exit(-1);
		else
			printf("child %d's pid : %d\n", i, room[i]);
	}
	if (room[4] > 0)
		printf("parent again!%d\n", getpid());

}