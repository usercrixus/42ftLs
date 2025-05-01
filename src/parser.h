#ifndef PARSER
#define PARSER

#include "42libft/ft_base/libft.h"

typedef struct flags
{
	int l;
	int R;
	int a;
	int r;
	int t;
} t_flags;

extern t_flags flags;

static void setFlags(char *s);

void initFlags();
void manageSetFlags(int argc, char **argv);

#endif