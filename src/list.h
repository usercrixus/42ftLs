#ifndef LIST
#define LIST

#include <dirent.h>
#include <sys/stat.h>
#include "42libft/ft_base/libft.h"
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

#endif