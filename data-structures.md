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
- See a [Stack illustrated](https://github.com/coolinmc6/CS-concepts/blob/master/data-structures-illustrated.md#stack)
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
unshift ("add") and pop ("remove")
- See a [Queue illustrated](https://github.com/coolinmc6/CS-concepts/blob/master/data-structures-illustrated.md#queue)
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

- A linked list is an ordered collection of data, with each element containing a link to its successor.

> Although a linked list is similar to an array, it is not restricted to a declared number of elements. Additionally, unlike an array which stores data contiguously in memory or on disk, a linked list can easily insert or remove elements without reallocation or reorganization of the entire structure because the data items need not be stored contiguously
 
- Here are some key terms to know:
  - **Node:** an element in the linked list which contains the data and the reference node
  - **Head:** The first node
  - **Tail:** the last node
  - **Data:** the data that we want to save
  - **Reference:** the reference to the next node
+ Linked lists have *constant time* insertions and deletions because we can just change the pointers
  * Arrays require *linear time* because items must be shifted over when adding or deleting items
+ Linked lists don't have *random access*. We must access nodes sequentially starting from the first one. Therefore, searching for an element is slow
+ There are number of ways to implement linked lists, they all have a number of different methods. The implementation below is from my [AlgoCasts](https://github.com/coolinmc6/AlgoCasts/blob/master/exercises/linkedlist/index.js) repo:

```js
class Node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    // To insert something in the beginning, I need to do two things:
    //   - create a node
    //   - set it to the head WITHOUT deleting everything.
    // so how do I shift everything down? 
    // set the "next" for the new Node to the current this.head
    insertFirst(data) {
        this.head = new Node(data, this.head);
    }

    // Returns the size of the linked list
    // I use a while loop to
    size() {
        let counter = 0;
        let node = this.head;

        while(node) {
            counter++;
            node = node.next;
        }
        return counter;
    }

    getFirst() {
        return this.head;
//             return this.getAt(0); => I can use this later after I implement getAt()
    }

    getLast() {
        let node = this.head;
        let last = null;
        while(node) {
            if(node.next == null) { last = node};
            node = node.next;
        }
        return last;
    }

    clear() {
        this.head = null;
    }

    removeFirst() {
        if(!this.head) {
            return;
        }
        this.head = this.head.next;
    }

    removeLast() {

        // if no head, then just return
        if(!this.head) {
            return;
        }

        // if no head.next, then there's one element; removing last is just clearing the list
        if(!this.head.next) {
            this.head = null;
            return;
        }

        // Now that we can handle cases for lists of lengths 0 and 1, we can handle everything else

        let previous = this.head;
        let node = this.head.next;

        while (node.next){
            previous = node;
            node = node.next;
        }

        previous.next = null;
    }

    insertLast(data) {
        if(!this.head) {
            this.head = new Node(data);
            return;
        }

        let last = this.getLast();
        if(last) {
            last.next = new Node(data);
        }
    }

    // Given an index, return the node at that index
    getAt(index) {
        let counter = 0;
        let node = this.head;

        // This does the work; while the node exists, look at counter....
        // ...if counter matches desired index, return that node...
        // ...if not, increment the counter and move node to the next node
        // if there is no next node, while loop breaks and we return null

        while(node) {
            if(counter === index) {
                return node;
            }

            counter++;
            node = node.next;
        }

        return null;
    }

    removeAt(index) {
        if(!this.head) {
            return;
        }

        if(index === 0) {
            this.head = this.head.next;
            return;
        }

        const previous = this.getAt(index - 1);
        if(!previous || !previous.next) {
            return;
        }
        previous.next = previous.next.next
    }

    insertAt(data, index) {
        if (!this.head) {
          this.head = new Node(data);
          return;
        }

        if (index === 0) {
          this.head = new Node(data, this.head);
          return;
        }

        const previous = this.getAt(index - 1) || this.getLast();
        const node = new Node(data, previous.next);
        previous.next = node;
    }

    // Run a function for each node in the list
    forEach(fn) {
        let node = this.head;
        let counter = 0;
        while (node) {
            fn(node, counter);
            node = node.next;
            counter++;
        }
    }

}
```

- I know that there's a lot there so here's a simplified list of properties/methods that I should know how to implement.

```js
class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class LinkedList() {
  constructor() {
    this.head = null;
  }

  // insert at front of list
  insertFirst(data) {}

  // insert at back of list
  insertLast(data) {}

  // return size of the Linked List
  size(){}

  // return first element
  getFirst(){}

  // return last element
  getLast(){}

  // return node at a particular index
  getAt(index) {}

  // remove first node
  removeFirst() {}

  // remove last node
  removeLast() {}

  // remove a node at a particular index
  removeAt(index) {}

  // insert a node at a particular index
  insertAt(data, index) {}

  // call a function for each node in the list
  forEach(fn) {}
};
```

[back to top](#top)

## Tree

> A Tree is a widely used data structure that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node. A tree data structure can be defined recursively as a collection of nodes (starting at a root node), where each node is a data structure consisting of a value, together with a list of references to nodes (the “children”), with the constraints that no reference is duplicated, and none points to the root node.

- There are many different kinds of trees in terms of data structures but the *tree*, generally, is described as a very useful data structure to know with the Document Object Model (DOM) being the most famous example.
- I've looked at a number of different implementations of a tree and many of them have the following in common:
  + Separate constructors for `Node` and `Tree`
  + Each `Node` typically has the following properties: 
    * **data**: the value of the node
    * **children**: an array of children nodes
    * Major differences:
      - I've seen an implementation where each `Node` has a method to add or remove children
      - Some `Node` have a `parent` property
      - some have nothing else besides *data* and *children*
  + Each `Tree` typically has these two methods:
    * **Breadth-First Traversal** (`traverseBFS`, `traverseBF`)
    * **Depth-First Traversal** (`traverseDFS`, `traverseDF`)
    + those methods often have as an argument a function, `fn`, that is called within the function (recursion)
    + Other methods include: *contains*, *add*, *remove*, *print*, and others
* There are a number of implementations I could show, the one below is the one I can describe.




- Here are the examples of trees I've borrowed from other sources:
  + 

[back to top](#top)

## Graph


[back to top](#top)

## Hash Table


[back to top](#top)


## Resources and Links

- General
    + [Medium: Data Structures in JavaScript](https://medium.com/siliconwat/data-structures-in-javascript-1b9aed0ea17c)
    + [benoitvallon/computer-science-in-javascript](https://github.com/benoitvallon/computer-science-in-javascript)
    + [Data Structures in JavaScript](https://code.tutsplus.com/series/data-structures-in-javascript--cms-772)
- Stack
    + [trekhleb/javascript-algorithms: Stack](https://github.com/trekhleb/javascript-algorithms/tree/master/src/data-structures/stack)
- Queue
    + Queue Implementation: [GeeksforGeeks](https://www.geeksforgeeks.org/implementation-queue-javascript/)
    + [trekhleb/javascript-algorithms: Queue](https://github.com/trekhleb/javascript-algorithms/tree/master/src/data-structures/queue)
- Linked List
  + [JS Data Structures: Linked List](https://codeburst.io/js-data-structures-linked-list-3ed4d63e6571)
  + [Doubly Linked List](https://hackernoon.com/the-little-guide-of-linked-list-in-javascript-9daf89b63b54)
- Tree
  + [Data Structures With JavaScript: Tree](https://code.tutsplus.com/articles/data-structures-with-javascript-tree--cms-23393)
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













