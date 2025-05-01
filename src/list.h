#include <sys/types.h>
#include <dirent.h>
#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"

#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

typedef struct s_direntList
{
	struct dirent *value;
	struct s_direntList *next;
} direntList;

static int getTotalBlocks(direntList *list, char *dirname);

int getTotalBlockManager(char *dirName);
void destroyList(direntList *list);
direntList *getDirentList(DIR *d);