#pragma once

#include <sys/stat.h>
#include "./42libft/ft_base/libft.h"
#include "parser.h"
#include "list.h"
#include "42libft/ft_str/ft_str.h"

extern t_flags flags;

direntList *getDirentList(DIR *d);
direntList *sortList(direntList *list, int (*f)(direntList *, char *), char *dirName);
direntList *reverseList(direntList *head);
void destroyList(direntList *list);

int sortHelpSuperior(direntList *current, char *dirName);
int sortHelpInferior(direntList *current, char *dirName);
int sortHelpTime(direntList *current, char *dirName);