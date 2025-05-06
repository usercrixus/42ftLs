#include "printer.h"

static void printPermissions(struct stat *sb)
{
    char perms[11] = "----------";

    if (S_ISDIR(sb->st_mode))
        perms[0] = 'd';
    else if (S_ISLNK(sb->st_mode))
        perms[0] = 'l';
    else if (S_ISCHR(sb->st_mode))
        perms[0] = 'c';
    else if (S_ISBLK(sb->st_mode))
        perms[0] = 'b';
    else if (S_ISFIFO(sb->st_mode))
        perms[0] = 'p';
    else if (S_ISSOCK(sb->st_mode))
        perms[0] = 's';
    if (sb->st_mode & S_IRUSR)
        perms[1] = 'r';
    if (sb->st_mode & S_IWUSR)
        perms[2] = 'w';
    if (sb->st_mode & S_IXUSR)
        perms[3] = 'x';
    if (sb->st_mode & S_IRGRP)
        perms[4] = 'r';
    if (sb->st_mode & S_IWGRP)
        perms[5] = 'w';
    if (sb->st_mode & S_IXGRP)
        perms[6] = 'x';
    if (sb->st_mode & S_IROTH)
        perms[7] = 'r';
    if (sb->st_mode & S_IWOTH)
        perms[8] = 'w';
    if (sb->st_mode & S_IXOTH)
        perms[9] = 'x';
    ft_printf("%s ", perms);
}

static void printOwnerAndGroup(struct stat *sb)
{
    struct passwd *pw = getpwuid(sb->st_uid);
    struct group *gr = getgrgid(sb->st_gid);
    ft_printf("%s %s ", pw ? pw->pw_name : "?", gr ? gr->gr_name : "?");
}

static void printModificationTime(struct stat *sb)
{
    time_t t = sb->st_mtime;
    char *ts = ctime(&t);
    char *formated = ft_substr(ts, 4, 12);
    ft_printf("%s ", formated);
    free(formated);
}

static void printName(struct stat *sb, struct dirent *de, char *fullpath)
{
    ft_printf("%s", de->d_name);
    if (S_ISLNK(sb->st_mode))
    {
        char target[PATH_MAX];
        ssize_t len = readlink(fullpath, target, sizeof(target) - 1);
        if (len > 0)
        {
            target[len] = '\0';
            ft_printf(" -> %s", target);
        }
    }
}

static void printSize(struct stat *sb)
{
    off_t offset = sb->st_size;
    if (offset <= 0)
        offset = 1;
    while (offset < 9999999)
    {
        ft_printf(" ");
        offset *= 10;
    }
    ft_printf("%d ", (long long)sb->st_size);
}

int print(char *parent, struct dirent *de)
{
    struct stat sb;
    char *bufferPath;
    t_str *path;

    if (!flags.a && de->d_name[0] == '.')
        return (0);
    if (!flags.l)
        ft_printf("%s  ", de->d_name);
    else
    {
        path = ft_str_create();
        ft_str_multiple_push(path, 3, parent, "/", de->d_name);
        bufferPath = ft_str_get_char_array(path, path->size);
        if (lstat(bufferPath, &sb) == -1)
            return (0);
        printPermissions(&sb);
        ft_printf("%u ", (unsigned long)sb.st_nlink);
        printOwnerAndGroup(&sb);
        printSize(&sb);
        printModificationTime(&sb);
        printName(&sb, de, bufferPath);
        free(bufferPath);
        ft_str_free(path);
        ft_printf("\n");
    }
    return (1);
}