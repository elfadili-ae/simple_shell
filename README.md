# Simple SHELL

This is a simple shell project written in C that provides basic shell functionalities.
It can handle the following built-in commands: **exit**, **env**, **setenv**, **unsetenv**, **cd**, and **alias**.
Additionally, it supports the following separators and operators: command separator **;**,
logical AND **&&**, and logical OR **||**.

## Usage
To compile the project use this command:
```
gcc -o simple_shell shell.c
```

To run the simple shell, execute the compiled binary:
```
./simple_shell
```
The shell will display a prompt where you can enter commands.

## Command-Line Arguments
You can also provide a file containing commands as an argument to the simple shell.
This will execute the commands from the file. The usage is as follows:
```
./simple_shell [filename]
```

## Built-in Functionalities

### Exit
To exit the simple shell, use the **exit** command:
```
exit
```

### Environment Manipulation
The simple shell supports the following environment manipulation commands:

- **env**: Display the current environment variables.
- **setenv** **[variable]** **[value]**: Set the value of an environment variable.
- **unsetenv** **[variable]**: Unset an environment variable.

## Change Directory
To change the current working directory, use the **cd** command:
```
cd [directory]
```
Replace **[directory]** with the path to the directory you want to change to.

## Alias
The **alias** command allows you to define aliases for other commands. The usage is as follows:
```
alias [alias_name]=[command]
```
Replace **[alias_name]** with the name you want to assign to the alias, and **[command]** with
the command you want to associate with the alias.

## Command Separators and Operators
The shell supports the following separators and operators to control command execution:

- Command separator **;**: Use **;** to separate multiple commands on a single line. They will be
executed sequentially.
- Logical AND **&&**: Use **&&** to execute the next command only if the previous command
succeeds (returns exit status 0).
- Logical OR **||**: Use **||** to execute the next command only if the previous command fails
(returns a non-zero exit status).
