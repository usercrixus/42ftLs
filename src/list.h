#pragma once

#include <dirent.h>
#include <sys/stat.h>
#include "42libft/ft_base/libft.h"
#include "parser.h"
#include "42libft/ft_str/ft_str.h"

typedef struct s_direntList
{
	struct dirent *value;
	struct s_direntList *next;
} direntList;


int getTotalBlockManager(char *dirName);
void destroyList(direntList *list);
direntList *getDirentList(DIR *d);
