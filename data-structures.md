[Back](https://github.com/coolinmc6/CS-concepts/blob/master/README.md)

# Data Structures

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

const stack = new Stack();  // create a new Stack
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


## Queue

Queue Implementation: [GeeksforGeeks](https://www.geeksforgeeks.org/implementation-queue-javascript/)

## Linked List


## Tree


## Graph


## Hash Table