# CS50 - Intro to Computer Science

**Lectures**

- [Week 0](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-0)
- [Week 1](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-1)
- [Week 2](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-2)



# Homework

|Week|Homework|Submitted|See the code|
|:---:|:---|:---:|:---|
|0|*none*|*n/a*||
|1|Mario|yes|[https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset1/mario_less.c](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset1/mario_less.c)|
| |Cash|yes|[https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset1/cash.c](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset1/cash.c)|
| |Caesar|yes|[https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset2/caesar.c](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset2/caesar.c)|
| |Vigenere|yes|[https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset2/vigenere.c](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/pset2/vigenere.c)|
|2||||
|3||||
|4||||
|5||||
|6||||
|7||||
|8||||
|9||||
|10||||

# Week 0

**Lecture:** [https://www.youtube.com/watch?v=y62zj9ozPOM&list=PLhQjrBD2T3828ZVcVzEIhsHVgjANGZveu](https://www.youtube.com/watch?v=y62zj9ozPOM&list=PLhQjrBD2T3828ZVcVzEIhsHVgjANGZveu)

- phone book problem => keep splitting in half until you find Mike Smith

# Week 1

source code needs to be converted to machine code for the computer to read it
source code => compiler => machine code
IDE = Integrated Development Environment

`clang hello.c` => compile the code

`./a.out` => execute the code

```c
#include <stdio.h>

int main(void) 
{
	printf("hello, world\n");
}
```

- `clang -o hello hello.c` => compile the file and output a file called "hello"
- with C, you need to specify the kind of data you are creating (i.e. string, int, float, etc.)
- library => collection of functions
- if checking one character in C, you use single quotes; strings use double quotes

```c
#include <stdio.h>

// C is now made aware of the square function
int square(int n);

int main(void)
{
	// get_int is not from the C library
	int x = get_int("x: ");
	// printf("%i\n", x * x)
	printf("%i\n", square(x))
}

int square(int n)
{
	return n * n;
}
```

```c
int main(void)

int main(int argc, string argv[])
// argc => integer
// argv => array of strings

```

# Week 2

# Week 3

# Week 4

