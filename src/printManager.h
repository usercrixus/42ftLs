#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"

#include "parser.h"
#include "sorter.h"
#include "printer.h"
#include "list.h"

static int listDir(char *dirName);
static direntList *formatList(direntList *list, char *dirName);
static void manageRecursivity(direntList *buffer, char *dirName);

void manageListDir(int argc, char **argv);