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
void ft_print_ligne(char **line1, char **line2, t_data *img)
{
	int	i;
	static int p1[2] = {START_X, START_Y};
	int p2[2];
	const int gaps[2] = {30, 10};
	int	p3[2];
	int	temp[2];

	i = 0;
	temp[0] = p1[0];
	temp[1] = p1[1];
	while (line1[i])
	{
		p2[0] = p1[0] + gaps[0];
		if (i == 0)
			p2[1] = p1[1] + gaps[1] - ft_atoi(line1[i])*3;
		else 
			p2[1] = p1[1] + gaps[1] - ft_atoi(line1[i])*3 + ft_atoi(line1[i - 1])*3;
		tracersegment(p1, p2, img);
		if(temp[0] != START_X)
		{
			p3[0] = p1[0] + 25;
			p3[1] = p1[1] - 30 + ft_atoi(line1[i])*3;
			printf("i vaut %d\n", i);
			printf("line i vaut %s\n", line1[i]);
			printf("p3 x %d\n", p3[0]);
			printf("p3 y %d\n", p3[1]);
			printf("p1 x %d\n", p1[0]);
			printf("p1 y %d\n", p1[1]);
			printf("-------\n");
			tracersegment(p1, p3, img);
		}

		p1[0] = p2[0];
		p1[1] = p2[1];
		i++;
	}
		printf("HHHHHHHHHHHHHHH\n");

	p1[0] = temp[0] - 25;
	p1[1] = temp[1] + 30;
}