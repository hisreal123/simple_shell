# Simple Shell

## Description
The Simple Shell is a command-line interpreter that allows users to interact with the operating system by entering commands. This project is a simplified version of the Unix shell, implementing basic shell functionalities.

## Features
- Command execution
- Simple built-in commands (e.g., `ls`, `cd`, `exit`)
- Handling of simple command pipelines
- Reproducing certain commands and system calls
- Redirection of standard input and standard output
<!-- - Background command execution (using `&`) -->

## Getting Started

### Prerequisites
- C compiler (e.g., GCC)
- Unix-like operating system

### Compilation
Compile the Simple Shell source code using the provided Makefile:

<!-- ```bash
make -->
### Present Files
- shell.h: header file
- AUthORS: Authors file generated from script
- 0-shell: contains the main function to direct to either interactive or noninteractive shell
- 1-get_input: calls getline to begin accepting input for the interactive shell
- 2-process_command: in this function, strtok is used to split the command into arrays and funnel out any empty lines
- 3-fork_execute: contains code to screen the passed command for certain specific calls that can be executed before/without forking
- 4-fork_child: code the fork, wait and exit the forked program if error
- 5-non_int: this function will only run if non interactive shell is called, and i had to write the code for its own function processes
- 6-strcomp: is a custom strcmp function
- 7-atoi: is a custom atoi function that doesnt return any output when it encounters negative ints or a letter
- 8-commands: is a function containing all the commands that the shell is allowed to process
- 9-getlin: is a custom getline function
- 10-chdir: is a custom function to change directory effectively
- 11-stlen: is a custom strlen function.
