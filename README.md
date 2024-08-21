# Simple Shell Project

This project is a custom implementation of a simple shell in C, adhering to the Betty coding style and the constraints of the GNU89 standard. It supports basic shell functionalities such as executing commands, handling built-ins, and managing processes.

## Functionality :

The `simple_shell` project supports the following features:

- `Command Execution`: Executes commands entered by the user, including absolute and relative paths.
- `Built-ins`: Implements basic built-in commands like exit, env, and cd.
- `Environment Handling`: Supports environment variables and their manipulation.
- `Error Handling`: Provides basic error messages for invalid commands or syntax errors.

## Files :

- `shell.h`: Header file containing function declarations and necessary includes.
- `README.md`: Description of the project.
- `AUTHORS`: List of authors contributing to the Simple Shell project.
- `cd.c`: File containing the function to use the cd command to change directories.
- `env.c`: File for print environment.
- `executor.c`: File that manages the execution of the command.
- `input.c`: File for manage user reading.
- `main.c`: File containing the main function and the main code of the program.
- `parser.c`: File for séparate input in command or argument.
- `path.c`: File for search command in PATH.
- `prompt.c`: File that manages the display of the prompt.
- `man_1_simple_shell`: Man file for the project.

## Compilation/Installation :

To install the function, just clone the repository:

```sh
git clone https://github.com/lowbacc/holbertonschool-simple_shell.git
```

and compile the Simple Shell function with this command:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

This command will compile all .c files in the current directory into an executable named `simple_shell`.

## Requirements :

- GCC compiler (version 4.8.4 or later).
- Ubuntu 20.04 LTS or a similar Unix-like operating system.
- Allowed editors : vi, vim, emacs -> we use vim here
- To have the Betty style

## Examples :

Here are some examples of how to use the `simple_shell`:

```sh
#include "shell.h"

/**
 * change_directory - Changes the current working directory
 * @args: Array of arguments where args[1] is the target directory
 */
void change_directory(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
```

## Running the Shell :

To run the `simple_shell`, simply execute the following steps in your terminal:

1. Create a main.c file or change it and include your test cases.
2. Compile the code with the following command in your terminal:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

3. Run the `simple_shell` with the following command in your terminal:

```sh
./hsh
```

## Using Built-ins :

To exit the shell:

```sh
exit
```

To print environment variables:

```sh
env
```

To change directory:

```sh
cd /path/to/directory
```

## Manual Page :

To access the manual page for `simple_shell`:

1. Copy the manual page to the appropriate directory:

```sh
sudo cp man_1_simple_shell /usr/share/man/man3/
```

2. Activate the manual page with:

```sh
mandb
```

3. Restart your shell:

```sh
source ~/.bashrc
```

4. Open the manual page using:

```sh
man man_1_simple_shell
```

## AUTHORS :

- **Matthis SKALSKI** - [@Matthis SKALSKI](https://github.com/lowbacc)
- **Lucas NIEL** - [@Lucas NIEL](https://github.com/HSHKZ)
- **Quentin Lepoutre** - [@Quentin LEPOUTRE](https://github.com/MrKay12)
