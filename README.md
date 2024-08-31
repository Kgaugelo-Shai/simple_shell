# simple_shell
# About the Simple Shell Project
The Simple Shell is a Unix command interpreter created for a project at ALX School.

## Introduction
Designed to execute Unix commands, the Simple Shell project is built in stages, with each stage adding more features to the shell, fulfilling various learning objectives.

# List of Project Tasks:

## Task 0: Betty would be proud:
- Code passes the Betty checks

## Task 1: Simple shell 0.1:
Write a UNIX command line interpreter.
- Usage: simple_shell

Your Shell should:
- Display a prompt and wait for the user to type a command. A command line always ends with a new  line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:
- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

## Task 2: Simple shell 0.2
## Task 3: Simple shell 0.3
## Task 4: Simple shell 0.4
## Task 5: Simple shell 1.0
## Task 6: Simple shell 0.1.1 (Advanced)
## Task 7: Simple shell 0.2.1 (Advanced)
## Task 8: Simple shell 0.4.1 (Advanced)
## Task 9: setenv, unsetenv (Advanced)
## Task 10: cd (Advanced)
## Task 11: ; (Advanced)
## Task 12: && and || (Advanced)
## Task 13: alias (Advanced)
## Task 14: Variables (Advanced)
## Task 15: Comments (Advanced)
## Task 16: File as input (Advanced)

## Setup Guide
- To run the Simple Shell on your computer, use the instructions below.

## System Requirements
- Ubuntu 20.04 LTS
- GCC compiler
- Knowledge of Unix and C language

# Compilation
Run this command to compile the shell:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```