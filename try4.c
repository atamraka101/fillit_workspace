#include <stdio.h>
#include <string.h>

#define O_SHAPE (char[16]) {'#', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define I_SHAPE (char[16]) {'#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.'};
#define IH_SHAPE (char[16]) {'#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define L_SHAPE (char[16]) {'#', '.', '.', '.', '#', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.'};
#define LR_SHAPE (char[16]) {'#', '#', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define LD_SHAPE (char[16]) {'#', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.'};
#define LL_SHAPE (char[16]) {'.', '.', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define J_SHAPE (char[16]) {'.', '#', '.', '.', '.', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.'};
#define JR_SHAPE (char[16]) {'#', '.', '.', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define JD_SHAPE (char[16]) {'#', '#', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.'};
#define JL_SHAPE (char[16]) {'#', '#', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define T_SHAPE (char[16]) {'#', '#', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define TR_SHAPE (char[16]) {'.', '#', '.', '.', '#', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.'};
#define TD_SHAPE (char[16]) {'.', '#', '.', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define TL_SHAPE (char[16]) {'#', '.', '.', '.', '#', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.'};
#define Z_SHAPE (char[16]) {'#', '#', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define ZR_SHAPE (char[16]) {'.', '#', '.', '.', '#', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.'};
#define S_SHAPE (char[16]) {'.', '#', '#', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
#define SR_SHAPE (char[16]) {'#', '.', '.', '.', '#', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.'};


int validate_tetriminos_shape(char *input, int inLen)
{
	int i;
	int j;
	int ndx;
	char sh[16];

	/* Each input shape must  be of size 20 bytes */
	if (inLen != 20)
		return (0);
	i = 0;
	j = 0;
	ndx = 0;
	while (i < inLen)
	{
		if (!(input[i] == '.' || input[i] == '#' || input[i] == '\n'))
		return (0);

		if ((i % 5) == 4)
			if (input[i] != '\n')
				return (0);
			//printf("%d: %02X\n", i, input[i]);
		i++;
	}
	return (1);
}

int parse_input(char *input, int inLen)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		validate_tetriminos_shape(&input[i], 20);
		i += 20;
	}
	return (1);
}

int convert_16bytes_to_4x4_matrix(char matrix[4][4], char *input)
{
	int r;
	int c;
	int ndx;

	r = 0;
	ndx = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (input[ndx] == '\0')
				return (0);
			matrix[r][c] = input[ndx];
			c++;
			ndx++;
		}
		r++;
	}
	return (1);
}

int convert_4x4_matrix_to_16bytes(char matrix[4][4], char *output)
{
	int r;
	int c;
	int ndx;

	r = 0;
	ndx = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			output[ndx] = matrix[r][c];
			ndx++;
			c++;
		}
		r++;
	}
	return (1);
}

void shift_4x4_matrix_row(char matrix[4][4])
{
	char hold[4];
	int r;

	r = 0;
	memcpy(hold, matrix[0], 4);
	while (r < 3)
	{
		memcpy(matrix[r], matrix[r + 1], 4);
		r++;
	}
	memcpy(matrix[3], hold, 4);

}

void shift_4x4_matrix_row_by_k(char matrix[4][4], int k)
{
	int i;

	i = 0;
	while (i < k){
		shift_4x4_matrix_row(matrix);
		i++;
	}
}

void shift_4x4_matrix_column(char matrix[4][4])
{
	int r;
	int c;
	char hold;

	c = 0;
	r = 0;
	while (r < 4)
	{
		c = 0;
		hold = matrix[r][0];
		while(c < 3)
		{
			matrix[r][c] = matrix[r][c+1];
			c++;
		}
		matrix[r][3] = hold;
		r++;
	}

}

void shift_4x4_matrix_column_by_k(char matrix[4][4], int k)
{
	int i;

	i = 0;
	while (i < k){
		shift_4x4_matrix_column(matrix);
		i ++;
	}
}

void display_4x4_matrix(char matrix[4][4])
{
	int r;
	int c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			printf("%c ", matrix[r][c]);
			c++;
		}
		printf("\n");
		r++;
	}
}

int get_starting_row(char matrix[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == '#')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int get_starting_col(char matrix[4][4])
{
	int r;
	int c;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < 4)
		{
			if (matrix[r][c] == '#')
			{
				return (c);
			}
			r++;
		}
		c++;
	}
	return (-1);
}

int shift_matrix_top_left(char matrix[4][4])
{
	int rk;
	int ck;

	rk = get_starting_row(matrix);
	if (rk < 0)
		return (0);
	ck = get_starting_col(matrix);
	if (rk < 0)
		return (0);
	shift_4x4_matrix_row_by_k(matrix, rk);
	shift_4x4_matrix_column_by_k(matrix, ck);
	return (1);
}

int transform_input(char *input, char *output)
{
	char mat[4][4];
	int status;

	if(!convert_16bytes_to_4x4_matrix(mat, input))
		return (0);

	return (0);
}

int main(void)
{
	char input1[20] = "....\n....\n..##\n..##\n";
	parse_input(input1, 20);
	int r, c;

	//char inputx[16] = "..........##.##.";
	//char inputx[16] = "...#...#...#...#";
	char inputx[16] = ".......#...#..##";
	char mat[4][4];

	convert_16bytes_to_4x4_matrix(mat, inputx);
	display_4x4_matrix(mat);

	printf("shift matrix top left\n");
	shift_matrix_top_left(mat);
	display_4x4_matrix(mat);
	return (1);
}
