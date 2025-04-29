#include "parser.h"

t_flags flags;

void initFlags()
{
	ft_memset(&flags, 0, sizeof(flags));
}

static void setFlags(char *s)
{
	if (ft_strchr(s, 'l'))
		flags.l = 1;
	if (ft_strchr(s, 'R'))
		flags.R = 1;
	if (ft_strchr(s, 'a'))
		flags.a = 1;
	if (ft_strchr(s, 'r'))
		flags.r = 1;
	if (ft_strchr(s, 't'))
		flags.t = 1;
}

void manageSetFlags(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			setFlags(argv[i]);
		i++;
	}
}