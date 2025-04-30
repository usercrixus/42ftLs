#ifndef SORTER
#define SORTER

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#include "./42libft/ft_base/libft.h"
#include "./42libft/ft_printf/ft_printf.h"

typedef struct s_direntList
{
	struct dirent *value;
	struct s_direntList *next;
} direntList;

direntList *getDirentList(DIR *d);
direntList *sortList(direntList *list, int (*f)(direntList *current));

int sortHelpSuperior(direntList *current);
int sortHelpInferior(direntList *current);
int sortHelpTime(direntList *current);
direntList *reverseList(direntList *head);

#endif