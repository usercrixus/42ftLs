#include "sorter.h"

static char *correctedSortName(char *name)
{
    if (ft_strncmp(name, ".", 2) != 0 && ft_strncmp(name, "..", 3) != 0)
    {
        if (name[0] == '.')
            name++;
    }
    return (name);
}

int sortHelpSuperior(direntList *current, char *dirName)
{
    return ft_stracasecmp(correctedSortName(current->next->value->d_name), correctedSortName(current->value->d_name)) > 0;
}

int sortHelpInferior(direntList *current, char *dirName)
{
	return ft_stracasecmp(correctedSortName(current->next->value->d_name), correctedSortName(current->value->d_name)) < 0;
}

int sortHelpTime(direntList *current, char *dirName)
{
    struct stat buf1;
    struct stat buf2;
    char* path;
    char* pathBuffer;

    pathBuffer = ft_strjoin(dirName, "/");
    path = ft_strjoin(pathBuffer, current->value->d_name);
    if (lstat(path, &buf1) == -1)
        return 0;
    free(pathBuffer);
    free(path);
    pathBuffer = ft_strjoin(dirName, "/");
    path = ft_strjoin(pathBuffer, current->next->value->d_name);
    if (lstat(path, &buf2) == -1)
        return 0;
    free(pathBuffer);
    free(path);    
    if (buf1.st_mtime == buf2.st_mtime) {
        if (buf1.st_mtim.tv_nsec == buf2.st_mtim.tv_nsec) {
            return ft_stracasecmp(correctedSortName(current->value->d_name), correctedSortName(current->next->value->d_name)) > 0;
        }
        return buf1.st_mtim.tv_nsec < buf2.st_mtim.tv_nsec;
    }
    return buf1.st_mtime < buf2.st_mtime;
    
}

void printlist(direntList *list)
{
    while (list)
    {
        printf(" %s ", list->value->d_name);
        list = list->next;
    }
    printf("end\n");
}

direntList *sortList(direntList *list, int (*f)(direntList *, char *), char *dirName)
{
    int isSorted;
    direntList *current;
    direntList *previous;
    direntList *buffer;

    if (!list)
        return NULL;
    isSorted = 0;
    while (!isSorted)
    {
        isSorted = 1;
        previous = NULL;
        current = list;
        while (current && current->next)
        {
            if (f(current, dirName))
            {
                buffer = current->next;
                current->next = buffer->next;
                buffer->next = current;

                if (previous)
                    previous->next = buffer;
                else
                    list = buffer;

                previous = buffer;
                current = buffer->next;
				isSorted = 0;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }
    return list;
}

direntList *reverseList(direntList *head)
{
    direntList *prev = NULL;
    direntList *cur  = head;
    direntList *next;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur; 
        cur = next;
    }
    return prev;
}
