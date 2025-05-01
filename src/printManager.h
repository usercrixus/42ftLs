#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"


#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "sorter.h"
#include "printer.h"

static int listDir(char *dirName);
static direntList *formatList(direntList *list, char *dirName);
static void manageRecursivity(direntList *buffer, char *dirName);

void manageListDir(int argc, char **argv);