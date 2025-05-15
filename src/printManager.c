#include "printManager.h"

direntList *formatList(direntList *list, char *dirName)
{
    list = sortList(list, sortHelpInferior, dirName);
    if (flags.t)
        list = sortList(list, sortHelpTime, dirName);
    if (flags.r)
        list = reverseList(list);
    return list;
}

int listDir(char *dirName)
{
    DIR *d;
    direntList *buffer;
    direntList *list;

    d = opendir(dirName);
    if (!d)
        return (-1);
    list = getDirentList(d);
    if (!list)
        return (closedir(d), -1);
    list = sortList(list, sortHelpInferior, dirName);
    if (flags.t)
        list = sortList(list, sortHelpTime, dirName);
    if (flags.r)
        list = reverseList(list);
    if (flags.l)
        ft_printf("%s:\ntotal %d\n", dirName, getTotalBlockManager(dirName) / 2);
    else if (flags.R)
        ft_printf("%s:\n", dirName, getTotalBlockManager(dirName) / 2);
    buffer = list;
    while (buffer)
    {
        print(dirName, buffer->value);
        buffer = buffer->next;
    }
    if (!flags.l)
        ft_printf("\n");
    if (flags.R)
    {
        buffer = list;
        manageRecursivity(buffer, dirName);
    }
    destroyList(list);
    closedir(d);
    return (1);
}

void manageRecursivity(direntList *buffer, char *dirName)
{
    char *tmp;
    char *buff;

    while (buffer != NULL)
    {
        if (DT_DIR == buffer->value->d_type
            && (flags.a || (!flags.a && buffer->value->d_name[0] != '.'))
            && ft_strncmp(buffer->value->d_name, ".", 2) != 0 && ft_strncmp(buffer->value->d_name, "..", 3) != 0)
        {
            tmp = ft_strjoin(dirName, "/");
            buff = ft_strjoin(tmp, buffer->value->d_name);
            free(tmp);
            ft_printf("\n");
            listDir(buff);
            free(buff);
        }
        buffer = buffer->next;
    }
}

void manageListDir(int argc, char **argv)
{
    int i;
    int isPrinted;
    char *cleanName;

    isPrinted = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] != '-')
        {
            cleanName = ft_strtrim(argv[i], "/");
			if (listDir(cleanName) == -1)
                ft_printf("ls: cannot access '%s': No such file or directory", argv[i]);
            isPrinted = 1;
            free(cleanName);
        }
        i++;
    }
    if (!isPrinted)
    {
        if (listDir(".") == -1)
            ft_printf("ls: cannot access '.': No such file or directory");
    }
}
