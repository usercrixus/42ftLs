#include "list.h"

static int getTotalBlocks(direntList *list, char *dirname)
{
    int totalBlocks = 0;
    struct stat st;
    char *path;
    char *bufferPath;

    while (list)
    {
        if (flags.a || (!flags.a && list->value->d_name[0] != '.'))
        {
            bufferPath = ft_strjoin(dirname, "/");
            path = ft_strjoin(bufferPath, list->value->d_name);
			free(bufferPath);
			if (lstat(path, &st) == 0)
			{
				totalBlocks += st.st_blocks;
			}
			free(path);
			list = list->next;
		}
		else
			list = list->next;
    }

    return totalBlocks;
}

int getTotalBlockManager(char *dirName)
{
	DIR *d;
    direntList *list;
	int total;

	d = opendir(dirName);
	if (!d)
		return (0);
	list = getDirentList(d);
	total = getTotalBlocks(list, dirName);
	closedir(d);
	destroyList(list);
	return (total);
}

void destroyList(direntList *list)
{
    direntList *buffer;

    while (list)
    {
        buffer = list->next;
        free(list->value);
        free(list);
        list = buffer;
    }
}

direntList *getDirentList(DIR *d)
{
    direntList *list = NULL;
    direntList *last = NULL;
    direntList *buffer;
    struct dirent *de;

    while ((de = readdir(d)) != NULL)
    {
        buffer = malloc(sizeof(*buffer));
        if (!buffer)
            return NULL;
        buffer->value = malloc(sizeof(*(buffer->value)));
        if (!buffer->value)
            return NULL;
        ft_memcpy(buffer->value, de, sizeof(*(buffer->value)));
        buffer->next = NULL;
        if (!list)
            list = buffer;
        else
            last->next = buffer;
        last = buffer;
    }
    return list;
}