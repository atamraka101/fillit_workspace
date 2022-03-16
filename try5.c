#include "libft/libft.h" // remove lifbt.a from libft file
#include <string.h>
#include <stdio.h>

#define SZ_4x4_MATRIX	16
#define ROWS_4X4	4
#define COLS_4X4	4

typedef struct tetriminos_piece
{
	int coordinates[8];
	char letter;
}			tet_item;

void get_coordinates(char *input, int inSize, int *output, int *outSize)
{

}

void get_cordinates(char *input, int size)
{
	int row;
	int column;
	int ndx;

	row = 0;
	ndx = 0;
	while (ndx < size)
	{
		column = 0;
		while (column < 4)
		{
			if (input[ndx] == '#')
			{
				printf("%d", row);
				printf("%d", column);
				printf("\t");
			}
			else {
				printf(".\t");
			}
			column++;
			ndx++;
		}
		printf("\n");
		row++;
	}
}
void display_coordinates(int *coordinates, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d:: %d\n", i, coordinates[i]);
		i++;
	}
}
int main(void)
{
	char input1[16] = ".......#...#..##";
	get_cordinates(input1, 16);

	int output[8];
	int outLen;
	get_coordinates(input1, SZ_4x4, output, &outLen);
	display_coordinates(output, outLen);
	//parse_input(input1, 20);
	//int r, c;

	//char inputx[16] = "..........##.##.";
	//char inputx[16] = "...#...#...#...#";
	/*char inputx[16] = ".......#...#..##";
	char mat[4][4];

	convert_16bytes_to_4x4_matrix(mat, inputx);
	display_4x4_matrix(mat);

	printf("shift matrix top left\n");
	shift_matrix_top_left(mat);
	display_4x4_matrix(mat);*/

	return (1);
}
