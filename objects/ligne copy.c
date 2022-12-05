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

void ft_print_ligne(char **line1, char **line2, t_data *img, int color)
{
	int	i;
	static int p1[2] = {200, 100};
	int p2[2] = {250, 110};
	int	p3[2];
	int temp[2];

	i = 0;
	p2[0] = p1[0] + 50;
	p2[1] = p1[1] + 10 - (ft_atoi(line2[i])) * 2;
	temp[0] = p1[0] - 25;
	temp[1] = p1[1] + 25 - (ft_atoi(line2[i])) * 2;
	while (!ft_contain_nl(line1[i]))
	{
		// printf("%d %d %d %d\n", p1[0], p2[0], p1[1], p2[1]);
		printf("\np1 avant %d\n", p1[0]);
		tracersegment(p1, p2, 0x00FF0000, img);
		printf("\np1 après %d\n\n", p1[0]);
		p3[0] = p1[0] - 25;
		p3[1] = p1[1] + 25 - ((ft_atoi(line2[i])) * 2);
		tracersegment(p1, p3, 0x00FF0000, img);
		p1[0] = p2[0];
		p1[1] = p2[1];
		p2[0]+= 50;
		p2[1]+= 10 - (ft_atoi(line2[i])) * 2;
		i++;
	}
	p3[0] = p1[0] - 25 ;
	p3[1] = p1[1] + 25 - (ft_atoi(line2[i])) * 2;
	tracersegment(p1, p3, 0x00FF0000, img);
	p1[0] = temp[0];
	p1[1] = temp[1];
 }