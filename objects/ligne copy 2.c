#include "test.h"

static int	ft_contain_nl(char* str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	strstrlen(char** strstr)
{
	int	i;

	i = 0;
	while (!ft_contain_nl(strstr[i]))
	{
		i++;
	}
	return (i);
}

void ft_print_ligne(char **line1, char **line2, t_data *img, int color)
{
	int	i;
	static int p1[2] = {200, 100};
	int p2[2];
	const int gaps[2] = {30, 10};
	static char* temp = malloc(strstrlen(line1) * sizeof(char *));

	i = 0;
	p2[0] = p1[0] + gaps[0];
	p2[1] = p1[1] + gaps[1];
	while (!ft_contain_nl(line1[i]))
	{
		// printf("%d %d %d %d\n", p1[0], p2[0], p1[1], p2[1]);
		printf("\np1 avant %d\n", p1[0]);
		tracersegment(p1, p2, 0x00FF0000+(i * 100), img);
		printf("\np1 après %d\n\n", p1[0]);
		p1[0] = p2[0];
		p1[1] = p2[1];
		p2[0] = p2[0] + gaps[0];
		p2[1] = p2[1] + gaps[1];
		i++;
	}

 }