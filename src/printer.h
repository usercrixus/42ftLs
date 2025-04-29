#ifndef PRINTER
#define PRINTER

#include <sys/types.h>
#include <dirent.h>
#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"

#include "parser.h"
#include "sorter.h"

static int listDir(char *dirName);
void manageListDir(int argc, char **argv);

#endif