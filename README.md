✅ Generated README.md for ft_ls:

# ft_ls

`ft_ls` is a custom reimplementation of the Unix `ls` command in C. It lists directory contents and supports several common flags. This project is modular and relies on a custom `libft` library.

## Features

    - Recursively lists files and directories.
    - Supports typical flags (`-l`, `-a`, `-r`, `-t`, etc.).
    - Handles hidden files and subfolders.
    - Custom sorting and formatting logic.
    - Clean modular design with:
      - Parsing
      - Sorting
      - Listing
      - Printing managers

## Project Structure

    ft_ls/
    ├── src/
    │ ├── main.c
    │ ├── parser.*
    │ ├── sorter.*
    │ ├── list.*
    │ ├── printer.*
    │ ├── printManager.*
    │ └── 42libft/ # Custom library dependency
    ├── test/ # Test files and folders
    ├── Makefile
    ├── .gitignore
    └── .vscode/ # Dev settings


## Building the Project

    make

This will compile ft_ls and all required components, including 42libft.
Running the Program

    ./ft_ls [options] [path]

Examples

    ./ft_ls
    ./ft_ls -l
    ./ft_ls -la /etc

Development Notes

    Written in C99.
    Requires a POSIX-compliant system (e.g., Linux, macOS).
    Developed with modular and educational goals in mind.
    Uses custom versions of standard C functions from libft.

Credits

    Built as a project in the 42 school curriculum.
    libft includes submodules for string manipulation, math, get_next_line, and printf.

Happy hacking!
