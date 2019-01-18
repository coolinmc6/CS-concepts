[Back](https://github.com/coolinmc6/CS-concepts/blob/master/README.md)
<a name="top"></a>

# Data Structures

### Table of Contents

- [Stack](#stack)
- [Queue](#queue)
- [Linked List](#linked-list)
- [Tree](#tree)
- [Graph](#graph)
- [Hash Table](#hash-table)
- [Resources & Links](#resources-and-links)
- [Questions and Answers](#questions-and-answers)


## Stack

- A stack is pretty similar to a queue in that it is an ordered list of items (like an array)
- Stacks are FILO (First-In-Last-Out) or LIFO (Last-In-First-Out)
- There are two main methods on the Stack data structure: **push** and **pop**
	+ **push**: add a record to the top of the stack
	+ **pop**: Remove the "top" record in the stack
	+ *Another method that you could be asked to create is the "peek()" method which shows the top item on the stack*
- Here's an example of an implementation of a Stack:

```js
class Stack {

	constructor() {
		this.data = [];
	}

	push(record) {
		this.data.unshift(record);
	}

	pop() {
		return this.data.shift();
	}

	peek() {
		return this.data[0];
	}
}
```

- Here's that implementation with an explanation:

```js
class Stack {
	// need a constructor to instantiate the Stack and create the array
    constructor() {
        this.data = [];
    }

    // add to top of stack (or front of array)
    push(record) {
        return this.data.unshift(record);
    }
    
    // remove from top of stack (or front of array)
    pop() {
        return this.data.shift();
    }
    
    // view the item on top of the stack (or first item in array)
    peek() {
        return this.data[0]
    }
}

const stack = new Stack();  	// create a new Stack
stack.push("apples"); 		// add an item to the stack
stack.push('oranges');
stack.push('grapefruits');

console.log(stack); 		// Stack {data: Array(3)}
stack.pop(); 				// remove an item from Stack
console.log(stack); 		// Stack {data: Array(2)}
```

- when you log out the stack, you pretty much see that it's jsut an object with one property, *data*, that holds an array.
- on the prototype of the object, you see that there are the four methods you created

- Here's an implementation from [GeeksforGeeks](https://www.geeksforgeeks.org/implementation-stack-javascript/):

```js
// Stack class 
class Stack { 
  
    // Array is used to implement stack 
    constructor() { 
        this.items = []; 
    } 

    push(element) { 
        // push element into the items 
        this.items.push(element); 
    }

    pop() { 
        // return top most element in the stack and removes it from the stack 
        // Underflow if stack is empty 
        if (this.items.length == 0) 
            return "Underflow"; 
        return this.items.pop(); 
    } 

    peek() { 
        // return the top most element from the stack but doesn't delete it. 
        return this.items[this.items.length - 1]; 
    }
    
    // =======================
    // Helper Functions

    // isEmpty function: Returns true if the stack is empty
    isEmpty() { 
        // return true if stack is empty 
        return this.items.length == 0; 
    }
    
    printStack() { 
        var str = ""; 
        for (var i = 0; i < this.items.length; i++) 
            str += this.items[i] + " "; 
        return str; 
    }
}
```

- an interesting part about the above implementation is the "Underflow" error for pop. The first implementation didn't have that.

[back to top](#top)

## Queue

- A queue can be seen as a container of records; the data enters in one part (front/top) and then exits another part (back/bottom)
- Think of a queue like a line at a store. If you are the first one in the line, you'll be the first to checkout. Queues are "fair" while stacks, if implemented as lines at a store, are "unfair"
- adding a record = enqueuing
- removing a record = dequeuing
- Queues follow FIFO => First In, First Out

| Queue       | Array Equivalent |
| ------------|:-----------------:|
| Add to Queue| `array.unshift(data)`  |
| Remove from queue| `array.pop()` |

- whenever we make a Queue class, we essentially initialize an array and block the other methods besides
unshift ("add") and pop ("remove");
- This first implementation adds everything to the front and removes items from the back:

```js
class Queue {
    constructor() {
        this.items = [];
    }

    enqueue(data) {
        return this.items.unshift(data);
    }

    dequeue() {
        return this.items.pop();
    }
}
```

- This second implementation adds everything to the back and removes them from the front:

```js
class Queue {
   constructor() {
      this.items = []
   }

   enqueue(element) {
       return this.items.push(element)
   }

   dequeue() {
       if(this.isEmpty()) {
           return "No elements in queue";
       }
       return this.items.shift();
   }
    
   // if queue is empty, returns true
   isEmpty() {
       return this.items.length == 0;
   }

   front() {
       if(this.isEmpty()) {
           return "No elements in queue";
       }
       return this.items[0];
   }
}
```

[back to top](#top)

## Linked List


[back to top](#top)

## Tree


[back to top](#top)

## Graph


[back to top](#top)

## Hash Table


[back to top](#top)


## Resources and Links

- General
    + [Medium: Data Structures in JavaScript](https://medium.com/siliconwat/data-structures-in-javascript-1b9aed0ea17c)
- Stack
- Queue
    + Queue Implementation: [GeeksforGeeks](https://www.geeksforgeeks.org/implementation-queue-javascript/)
- Linked List
- Tree
- Graph
- Hash Table


## Questions and Answers

**What is the difference between a *Stack* and a *Queue*?**

A **stack** and a **queue** are very similar. They are both lists or containers of items like an array. They differ in the order that they are added and removed from the list / container. 


**Stacks** are LIFO (Last-in-First-out) meaning that the last item that was added to the stack is the first item that's taken out. Think of it stacking books in a box. If you stack 10 books on top of each other, you can't immediately grab the first one you put in - you have to remove the first 9 books you placed on top of it. 


**Queues** are FIFO (First-in-First-out) meaning that the first item added to the queue is the first item removed. Queues are like lines at a store (or anywhere, really); they are "fair". If you are the first person in line, you are the first people to be helped / checked out / etc.


Both stacks and queues typically have only two methods: one to add an item and one to remove an item. Here is a comparison of the two data structures:


||**Stack**|**Queue**|
|:---:|:---:|:---:|
|**Order**|LIFO|FIFO|
|**JavaScript Constructor**|`this.items = []`|`this.items = []`|
|**Add an item**|`stack.push("apples")`<br>adds item to the front of the stack|`queue.enqueue("apples")`<br>adds item to the back of the queue|
|**Remove an item**|`stack.pop()`<br>removes the most recently added item|`queue.dequeue()`<br>removes the first item in the queue|













