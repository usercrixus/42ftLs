#pragma once

#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"

#include "parser.h"
#include "sorter.h"
#include "printer.h"
#include "list.h"

direntList *formatList(direntList *list, char *dirName);
int listDir(char *dirName);
void manageRecursivity(direntList *buffer, char *dirName);
void manageListDir(int argc, char **argv);