#pragma once

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

void initFlags();
void manageSetFlags(int argc, char **argv);