#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "parser.h"

static void printPermissions(struct stat *sb);
static void printSize(struct stat *sb);
static void printName(struct stat *sb, struct dirent *de, char *fullpath);
static void printModificationTime(struct stat *sb);
static void printOwnerAndGroup(struct stat *sb);

int print(char *parent, struct dirent *de);