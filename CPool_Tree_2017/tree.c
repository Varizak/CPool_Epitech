/*
** EPITECH PROJECT, 2017
** tree
** File description:
** thomas.foubert@ymail.com
ON UTILISE TOTAL_LINE_SIZE POUR LES ESPACES
*/
int place_trunk(int size, int j, int line_size , int l)
{
	int i = 0;

	if (size % 2 == 1)
		size--;
	i = size - (size / 2);
	if (size == 1)
		for (j; j != (line_size / 2) - l; j++)
			my_putchar(' ');
	else
		for (j; j != (line_size / 2) - l - i; j++)
			my_putchar(' ');
	return (l);
}

int make_trunk(int size, int line_size, int k)
{
	int i;
	int j = 0;
	int l = 0;
	int m = 0;

	if (size % 2 == 0)
		m = size + 1;
	else
		m = size;
	for (i = 0; i != size; i++) {
		l = place_trunk(size, j, line_size, l);
		for (k = 0; k != m; k++)
			my_putchar('|');
		my_putchar('\n');
		j = 0;
		l = 0;
	}
}

int make_line_branch(int total_line_size, int total_star)
{
	for (int j = 0; j < (total_line_size); j++)
		my_putchar(' ');
	for (int k = 0; k < total_star; k++)
		my_putchar('*');
	my_putchar('\n');
}

int make_branch(int branch_number, int total_line_size, int total_star)
{
	int decrement = 2;

	if (branch_number < 3 && branch_number != 0)
		total_star -= 2;
	if (((branch_number - 1) % 2 == 0) && branch_number > 1)
		decrement = branch_number + 1;
	if (((branch_number - 1) % 2 == 1) && branch_number > 1)
		decrement = branch_number;
	if (branch_number > 2)
		total_star -= decrement;
	total_line_size -= (total_star - 1) / 2;
	for (int i = 0; i < (4 + branch_number); i++) {
		make_line_branch(total_line_size, total_star);
		total_line_size--;
		total_star += 2;
	}
	return (total_star - 2);
}

void tree(int size)
{
	int line;
	int full_star = 1;
	int k = 4;

	for (int i = 0; i != size; i++) {
		k += 2;
		line += k;
	}
	for (int i = 0; i < size; i++)
		full_star = make_branch(i, (line / 2) - (size * 2), full_star);
	//make_trunk(size, line, k);
}

int main(void)
{
	tree(8);
	return (0);
}
