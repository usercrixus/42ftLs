#include "printer.h"

static void manageRecursivity(char *dirName)
{
    DIR *d = opendir(dirName);
    if (!d)
        return;
    struct dirent *de;
    while ((de = readdir(d)) != NULL)
    {
        if (DT_DIR == de->d_type && ft_strncmp(".", de->d_name, 2) != 0 && ft_strncmp("..", de->d_name, 3) != 0)
        {
            char *tmp = ft_strjoin(dirName, "/");
            char *buff = ft_strjoin(tmp, de->d_name);
            free(tmp);
            ft_printf("\n");
            listDir(buff);
            free(buff);
        }
    }
    closedir(d);
}

static void basicPrint(struct dirent *de)
{
    if (!flags.a && de->d_name[0] == '.')
        return;
    if (DT_DIR == de->d_type)
        ft_printf("\033[34m%s\033[0m  ", de->d_name);
    else if (DT_REG == de->d_type)
        ft_printf("%s  ", de->d_name);
}


static void longPrint()
{
}

static int listDir(char *dirName)
{
    DIR *d = opendir(dirName);
    if (!d)
        return (0);
    direntList *list = getDirentList(d);
    list = sortList(list, sortHelpInferior, dirName);
    if (flags.t)
        list = sortList(list, sortHelpTime, dirName);
    if (flags.r)
        list = reverseList(list);
    if (flags.R)
        ft_printf("%s:\n", dirName);
    while (list)
    {
        if (flags.l)
            longPrint(list->value);
        else
            basicPrint(list->value);
        list = list->next;
    }
    ft_printf("\n");
    closedir(d);
    if (flags.R)
        manageRecursivity(dirName);
    return (1);
}

void manageListDir(int argc, char **argv)
{
    int i;
    int isPrinted;

    isPrinted = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] != '-')
        {
            if (!listDir(argv[i]))
                ft_printf("ls: cannot access '%s': No such file or directory", argv[i]);
            isPrinted = 1;
        }
        i++;
    }
    if (!isPrinted && !listDir("."))
        ft_printf("ls: cannot access '.': No such file or directory");
}
