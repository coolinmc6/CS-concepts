# C Language Notes

- to run a program in the Cloud9 IDE:

```sh
make hello		# make was written by CS50 to compile the hello.c file
```
- printing variables:

```c
printf("%c", character);
printf("%d", digit);
printf("%s", string);
printf("%i", integer);

```
- Random code:

```c
// Header files
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

// Random Bites

// checks for ending "integer" that indicates end of a string in C
while(s[b] != '\0) 

```

## Functions

- declare functions are the top of the file BUT your main function is the first actual function. For example:

```c
// function declarations
void set_array(int array[4]);
void set_int(int x);

// main function
int main(void)
{
    // CODE
}

// other functions
void set_array(int array[4])
{
    // CODE
}

void set_int(int x)
{
    // CODE
}
```



## Arrays

- an array is a giant block of contiguous memory
- Array declarations
  - type name[size]
  - `int student_grades[40]`

```c
// instantiation syntax
bool truthtable[3] = { false, true, true };

// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

- Arrays can also have multiple dimensions

```c
bool battleship[10][10];
```
- in memory, it's really just a 100-element array
- we cannot assign one array to another array; we'd have to copy one array into the other

```c
int foo[5] = {1, 2, 3, 4, 5};
int bar[5];

for(int j = 0; j < 5; j++)
{
    bar[j] = foo[j];
}
```
- to pass something by value means we are copying the variable
- Arrays are passed by reference. The callee receives the actual array, **NOT** a copy of it

## Magic Numbers

- this allows you to declare, essentially, a global variable that can't be changed.
- when the code is compiled, it goes through the program and replaces all instances of that
constant with the number, string, etc.
- if `#include` is similar to copy/paste, `#define` is analagous to find/replace

```c
// define NAME REPLACEMENT(value)
#define PI 3.14159265
#define DECK_SIZE 52
#define COURSE "CS50"
```