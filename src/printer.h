#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "./42libft/ft_printf/ft_printf.h"
#include "./42libft/ft_base/libft.h"
#include "42libft/ft_str/ft_str.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "parser.h"

int print(char *parent, struct dirent *de);