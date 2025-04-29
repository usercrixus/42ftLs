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
direntList *sortList(direntList *list, int (*f)(direntList *current, const char *dirName), const char *dirName);

int sortHelpSuperior(direntList *current, const char *dirName);
int sortHelpInferior(direntList *current, const char *dirName);
int sortHelpTime(direntList *current, const char *dirName);
direntList *reverseList(direntList *head);

#endif