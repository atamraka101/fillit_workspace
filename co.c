#include <stdio.h>

int main(void)
{
	int row;
	int column;
	int ndx;

	row = 0;
	ndx = 0;
	while (ndx < 20)
	{
		column = 0;
		while (column < 4)
		{
			printf("%d", row);
			printf("%d", column);
			column++;
			printf("\t");
		}
		printf("\n");
		row++;
		ndx = ndx + 5;
		//printf("ndx: %d", ndx);
	}
	return (1);
}
