<a name='top'></a>
# CS50 - Intro to Computer Science

**Lectures**

- [Week 0](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-0)
- [Week 1](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-1)
- [Week 2](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-2)
- [Week 3](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-3)
- [Week 4](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-4)
- [Week 5](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-5)
- [Week 6](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-6)
- [Week 7](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-7)
- [Week 8](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-8)
- [Week 9](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-9)
- [Week 10](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-10)
- [Week 11](https://github.com/coolinmc6/CS-concepts/blob/master/CS50-Intro-to-CS/CS50-Notes.md#week-11)


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

## Music Homework Notes
- white keys are the non-sharp keys
- accidentals
	+ sharp = #
	+ flat = b
- C# = Db
- the piano is divided into octaves. The middle octave is Octave 4
- D4 = the D key in the 4th Octave
- C starts the Octaves so it would go from C4-D4-E4-F4-G4-A4-B4-C5
- **bday**
	+ using the sheet music
	+ figure out which notes are being played
	+ write down the ASCII representation in the bday.txt
	+ C4@1/8 => C, fourth octave, eighth note
	+ C#4@1/8 => C#, fourth octave, eighth note
	+ blank line means a resst for 1/8th note
- **helpers.c**
	+ Write three functions:
		* is_reset
		* duration
		* frequency
	+ is_rest
	+ duration
		* `int duration(string fraction)`
		* takes in a fraction as a string and output a whole number representing how many eight notes
		* 1/8 => 1
		* 1/4 => 2
		* 3/8 => 3
		* 1/2 => 4
	+ frequency
		* * `int frequency(string note)`
		* parse the string into a note and its octave => A#4 -> separate into A# and Octave 4
		* calculate the frequency of the note in the given octave
		* return the frequency
		* Frequencies 
			* A4 = 440 Hz
			* Every semitone up => frequency * 2 ^ 1/12
			* Every semitone down => frequency / 2 ^ 1/12
			* if moving two up => f * 2 ^ **2**/12
			* sounds like I will essentially just need to figure out out how many semitones away from A4 I am
			+ A5 = 880 Hz = 440 * 2 ^ 12/12 = 440 * 2 ^ 1 = 440 * 2

## Computational Complexity
- when we talk about about the complexity of an algorithm, we generally reger to the worst-case scenario
	+ this is **Big O**
- best case scenario is **Big Omega**
- We can measure how much it takes up (in resources) in terms of time or memory. This measure is *f(n)*
- Computation Complexity

|Big O|Time|Description
|O(1)|constant time|Always takes a single operation in the worst case|
|O(log n)|logarithmic time|Always takes *n* operations in the worst case|
|O(n)|linear time||
|O(n log n|linearithmic time||
|O(n^2|quadratic time||
|O(n ^C|polynomial time||
|O(c^n|exponential time||
|O(n!)|factorial time||
|O(infinity)|infinite time||

## Selection Sort
- Find the smallest unsorted element and add it to the end of a sorted list
- In pseudocode (repeat this until sorted):
	+ Search the unsorted part of the data to find the smallest value
	+ swap the smallest found value with the first element of the unsorted part
- Worst-case scenario: iterate over each of the n elements (to find the smallest unsorted element) and we must repeat this process *n* times, since only one element gets sorted on each pass
- Best-case scenario: exactly the same! There's no way to guarantee the array is sorted until we go through
the process for all of the elements
- Worst Case: O(n^2)
- Best Case: Omega (n^2)



# Week 3

[back to top](#top)

# Week 4

[back to top](#top)

# Week 5

[back to top](#top)

# Week 6

[back to top](#top)

# Week 7

[back to top](#top)

# Week 8

[back to top](#top)

# Week 9

[back to top](#top)

# Week 10

[back to top](#top)

# Week 11

[back to top](#top)