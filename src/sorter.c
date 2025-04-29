#include "sorter.h"


static int	ft_stracasecmp(const char *s1, const char *s2)
{
	size_t	i;

    if (s1[0] == '.')
        s1++;
    if (s1[0] == '.')
        s1++; 
    if (s2[0] == '.')
        s2++;
    if (s2[0] == '.')
        s2++;
	i = 0;
	while (s1[i] == '\0' && s2[i] == '\0')
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]) || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)ft_tolower(s1[i]) - (unsigned char)ft_tolower(s2[i]));
		i++;
	}
    return ((unsigned char)ft_tolower(s1[i]) - (unsigned char)ft_tolower(s2[i]));
}

direntList *getDirentList(DIR *d)
{
    direntList *list = NULL;
    direntList *last = NULL;
    direntList *buffer;
    struct dirent *de;

    while ((de = readdir(d)) != NULL)
    {
        buffer = malloc(sizeof(direntList));
        if (!buffer)
            return NULL; // handle error properly
        buffer->value = malloc(sizeof(struct dirent));
        if (!buffer->value)
            return NULL; // handle error properly
        ft_memcpy(buffer->value, de, sizeof(struct dirent));
        buffer->next = NULL;

        if (!list)
            list = buffer;
        else
            last->next = buffer;
        last = buffer;
    }
    return list;
}


int sortHelpSuperior(direntList *current, const char *dirName)
{
    return ft_stracasecmp(current->next->value->d_name, current->value->d_name) > 0;
}

int sortHelpInferior(direntList *current, const char *dirName)
{
	return ft_stracasecmp(current->next->value->d_name, current->value->d_name) < 0;
}

int sortHelpTime(direntList *current, const char *dirName)
{
    struct stat buf1;
    struct stat buf2;

    if (lstat(current->value->d_name, &buf1) == -1)
        return 0;
    if (lstat(current->next->value->d_name, &buf2) == -1)
        return 0;
    if (buf1.st_mtime == buf2.st_mtime)
        return ft_stracasecmp(current->next->value->d_name, current->value->d_name) < 0;
    return buf1.st_mtime < buf2.st_mtime;
}

void printlist(direntList *list)
{
    direntList *buffer = list;

    while (buffer)
    {
        ft_printf("%s\n", buffer->value->d_name);
        buffer = buffer->next;
    }
    
}

direntList *sortList(direntList *list, int (*f)(direntList *current, const char *dirName), const char *dirName)
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
        next     = cur->next;  // save next
        cur->next = prev;      // reverse pointer
        prev     = cur;        // advance prev
        cur      = next;       // advance cur
    }
    return prev;
}