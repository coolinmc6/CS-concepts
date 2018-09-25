# Miscellaneous Notes

## Command Line

| Command | Comments |
| :---: | :---|
| `ls` | list items in the directory | 
| `cd` | change directory |
| `cd ..` | go up one level / directory |
| `pwd` | print working directory |
| `mkdir` | make directory |
| `cp hello.txt hi.txt` | copy the file *hello.txt* as new file *hi.txt* |
| `cp -r [folder]` | copy **recursively** a directory |
| `rm hi.txt` | delete the hi.txt file |
| `rm -rf [folder]` | delete the folder; the *-f* is a flag that wants to double check I really want to delete the file |
| `mv nmae.txt name.txt` | rename the file *nmae.txt* to *name.txt* |

## Data Types

- in C, we need to declare the variable's data type

| Type | Comments |
| :---: | :---|
| **int** | 32 bits worth of information (8 bits in a byte); -2 ^ 31 to 2 ^ 31 |
| *unsigned* **int** |- removes the negative values and doubles the number of potential values you can have<br>- upper bound is around 4 billion |
| **char** | - characters take up one byte of memory |
| **floating point** | - floating point numbers take up 32 bits |
| **double** | - are like floating point numbers but have double the space; 64 bits |
| **void** | - *void* is not a data type but it does exist.<br> - a function with a *void* return type doesn't return a value <br> `printf` is an example of a function that doesn't return anything|

- C doesn't have a built-in Boolean or String data type (unlike other programming languages) but the CS50 instructors have created a library with those types
- here are some simple variable declarations:

```c
int number; char letter;
```
