[Back to Main Page](https://github.com/coolinmc6/CS-concepts)

# Object-Oriented Design

## Introduction
- "Object-Oriented": Analysis, Designn, Programming
- Analysis - understand
- Design - plan
- Programming - build
- waterfall approach => distinct linear plan wherein you complete each distinct step and then move on
- this approach doesn't work because you are constantly learning more about what works and what doesn't.
- Agile development is more iterative

## Core Concepts
- as programs got larger, one long procedure no longer became feasible
- programs started getting broken up into smaller objects
- **What is an Object?**
	+ one object might contain other objects
	+ objects have attributes (i.e. on/off, green/red/blue/etc, large/small, etc)
	+ objects also have behaviors (i.e. a plane can fly but telephones and apples cannot)
	+ Identity, Attributes, Behavior
	+ Is it a noun? Can you put "the" in front of object?
		* the bank account; the apple
- A class is a blueprint for an object. It is not the object itself
- The class comes first and that's what we create
- Creating a class:
	+ what is it? (name, type)
	+ what describes it? attributes (properties, data)
	+ what can it do? behavior (operations)
		* functions that belong to a class
- each object is an instance of a class; creating an object is instantiation
- Many languages are have existing classes like strings, dates, collections, etc.
- Four key terms / concepts to know in object-oriented programming:
	+ abstraction
	+ polymorphism
	+ inheritance
	+ encapsulation
- you can remember them with the acronym: APIE or "a pie"
- **What is abstraction?**
	+ abstraction means that we focus on the essential qualities of something rather than one specific example
	+ abstraction means that we don't create a separate class for Joe's bank account and a separate class for
	Sally's bank account - we make one class for what a bank account should be
	+ The main goal of abstraction is to handle complexity by hiding unnecessary details from the user. 
	That enables the user to implement more complex logic on top of the provided abstraction without
	understanding or even thinking about all the hidden complexity.
- **What is encapsulation?**
	+ an object should not reveal anything about itself except what is absolutely necessary for other parts of
	the application to work
	- we close off parts of the object and make just the things you want public
	- it's not about being secretive it's about reducing the dependencies between different parts of 
	the application
- **What is inheritance?**
	+ We can create a new class and then instead of writing it from scratch, we can base it on an existing class
	+ Inheritance lets programmers create new classes that share some of the attributes of existing classes.
	This lets us build on previous work without reinventing the wheel
- **What is polymorphism?**
	+ polymorphism means "many forms"
	+ we can inherit when useful but override the super class's method/attribute when needed
	+ polypmorphism adds flexibility

## Object-Oriented Analysis and Design
- Here are the most common 5 steps to figure what classes you need and what they will do:
	+ Gather Requirements
	+ Describe the app
	+ Identify the main objects
	+ Describe the Interactions
	+ Create a Class Diagram
- **Gather Requirements**
	+ what problem are you trying to solve
	+ WRITE IT DOWN
- **Describe the app**
	+ build a simple narrative in plain, conversational language
	+ use cases and user stories
	+ here, you may create a wireframe or mock-up
- **Identify the main objects**
	+ use the stories to pick out the most important objects/classes
- **Describe the Interactions**
	+ describe the interactions between those objects
	+ Ex: a "Customer" needs to open a "BankAccount"
	+ Ex: a "Spaceship" must explode when it hits an "Asteroid"
- **Create a Class Diagram**
	+ a visual representation of the classes you'll need
- in an iterative development process, you'll complete these five steps multiple times over many iterations
- **Creating Requirements**
- Functional Requirements: what does it do?
	+ features/capabilities
- Non-Functional Requirements: what else?
	+ help
	+ legal
	+ performance
	+ security
	+ support
- Functional Requirements (examples):
	+ "System must...."
	+ "Application must..."
	+ "Program must..."
- NonFunctional Requirements
	- "System must respond to searches within 2 seconds"
	- "Comply with all relevant HPIAA"
- FURPS / FURPS+
	+ Functional requirements
	+ Usability requirements
	+ reliability requirements
	+ Performance requirements
	+ Supportability requirements
- **FURPS+**
	+ those 5 plus:
	+ Design requirements
	+ Implementation
	+ Interface requirements
	+ physical requirements
- You need to come away with the minimum requirements - not the answer for every single item
- **Goal:** we must come away with SOMETHING written down that describes what the app is doing (and answers
these other requirements) before we start programming
- UML = Unified Modeling Language

## Utilitizing Use Cases
- Use Cases
	+ Title: what is the goal?
	+ Actor: who desires it?
	+ Scenario: how is it accomplished?
- Title:
	+ short phrase, active verb
	+ examples:
		* "register new member"
		* "transfer funds"
		* "purchase items"
		* etc
- Actor
	+ Who? User, Customer, Member, Administrator, etc.
		* could be a computer system (i.e. ACMESystem)
- Scenario (as paragraph)
	+ in a paragraph is common
	+ series of steps
	+ you can also add additional details
		* Extensions: "describe steps for out-of-stock situations"
		* Precondition
		* Postcondition
		* Stakeholders
		* Technology list...
	+ be careful => requiring this level of formality can kill productivity
	+ casual write-ups are fine
- Actors are anything with behavior that lives outside of your system but has a goal they want to
accomplish within it
**Identifying Actors**
	+ External Systems / Organizations
		* external data sources, web services, corporate apps, tax reporting, backup systems
	+ Roles / Security Groups
	+ Job Titles / Departments
	+ the primary actor is who initiates the request / work - that doesn't mean that they will always do
	the most work

**Identifying Scenarios**
+ User focused goals are: purchase items, create new document, etc.
+ Logging in is not an adequate scenario
+ we are shooting for readability and ease of use
+ use active voice and shorter sentences, be concise
+ Focus on the intention - not "customer clicks the buy now button"
+ Use Case Prompts
	* Who performs system administration tasks?
	* Who manages users and security?
	* What happens if the system fails?
	* Is anyone looking at performance metrics or logs?
**Diagramming Use Cases**
- see lecture for image
**User Story**
- Example of User Story formula:

As a (_type of user_)

I want (_goal_)

so that (_reason_)

**User Stories and Use Cases**

| User Stories | Use Cases|
| :------------: | :--------: |
| short - one index card | long - a document |
| one goal, no details | multiple goals and details |
| informal | casual to (very) formal |
| "placeholder for conversation" | "record of conversation" |


## Domain Modeling (Modeling the App)
- we need to create a conceptual model of our system
- It simply means identifying the most important objects in the application
- don't worry about imperfection, you are trying to get the main ones

**Identifying Objects**
- go through your Use Cases and just underline the nouns
- combine some of the duplicates (i.e. "sale" and "order" probably refer to the same thing) 
and split whichever ones you think need to be broken out
- You'll also notice that some of these nouns are really properties of some larger parent objects
- see lecture for diagram
- It's a series of boxes that represent the objects with lines (with accompanying verb) to represent
the relationships between these objects

**Identifying Responsibilities**
- highlight the verbs
- Avoid Global Master Objects
- responsibilities should be distributed amongst your objects, there shouldn't be an overarching "System"
object that holds the miscellaneous methods
- CRC Cards:
	+ **C**lass Name
	+ **R**esponsibilities => the things it needs to take care of
	+ **C**ollaborators => the other classes it interacts with

## Creating Classes (Section #5)

**Creating Class Diagrams**

| Class Diagram  |
|:----:|
|  |
| Class Name |
| Attributes |
| Operations |

Example:

| Product |
|:----|
| - name: String<br>- isActive: Boolean<br>- launchDate: Date<br>- itemNumber: Integer |
| + getName(): String<br>+ setActive(Boolean)<br>+ getProductDetails(): String<br>+ displayProduct()<br>- formatProductDetails(): String |

- we give the type of variable for the attributes
- we provide the type the arguments (if any) for the various methods
- we also show the visibility as denoted by the "-" or "+"; so "-" means private
- Avoid building plain data structures

**Instantiation**
- The `new` keyword is often responsible for creating an object. In the background, the computer 
is allocating a little bit of memory for your new object, and then initializing all the variables in 
it and returning a reference to that object.
- a constructor is a special method that exists to construct the object
- in UML, if you see a method with the same name as the class, that is the constructor

**Using Static / Shared Members**
- Interest rate => an example of a property that applies to all savings accounts but is the same
- That's where the "static" keyword comes in
- We can make a static property to say that there is only ONE of these (not a separate property on each
instance of our class) and applies to all accounts
- There are also static methods

## Inheritance and Composition
- Inheritance describes an "is a" relationship
- A car **is a** vehicle
- A bus **is a** vehicle
- If BankAccount is the parent class or super class, CheckingAccount, SavingsAccount, and InvestmentAccount
could be the child classes or sub-classes that inherit from it
- You always inheriting from some other class, for example, the base Object class
- sometimes calling a method in the subclass that is from the parent class, you might need "super"
	+ i.e. `super.doSomething()`
- Abstract classes are objects that are never instantiated. A great example is the BankAccount class. The
BankAccount class is a great parent object for CheckingAccount, SavingsAccount, InvestmentAccount but it
will never be instantiated itself
- an interface is similar to a class but with no actual functionality
- it will just have method signatures that all classes that "implement" that interface must create
- aggregation is often referred to as a "Has A" relationship
	+ a customer **has a** address
	+ a car **has a** engine
	+ a bank **has many** bank accounts
	+ a university **has many** students
- Composition is a more specific form of Aggregation and implies ownership
- filled in diamond implies that the associated objects would be destroyed. So a Document class **has many**
Pages but if the Document is destroyed, those pages are destroyed
- This would not be the case with a Classroom: if a Classroom is destroyed, the associated Student objects
would not be

## Advanced Concepts
- Sequence diagrams (UML)
	+ only sketch out the scenarios that are not completely clear
- UML Diagrams
	+ there are a list of 14 diagrams


## Object-Oriented Design Patterns
- design patterns are best practices to keep in mind
- Design Patterns book by the "Gang of Four"
- Types of Patterns
	+ creational
	+ structural
	+ behavioral
- Singleton
	+ we want to ensure a class only has one instance
	+ we want one way of accessing it
	+ private constructor but public static method that checks a private property that looks at whether
	an instance exists - if it does, return that; if not, create new
- Memento Design Pattern
	+ this is a way of managing change, basically a way to undo a change to an object, but doing it in
	a way that does not violate encapsulation



## Object-Oriented Design Principles

**General Development Principles**
- DRY: Don't Repeat Yourself
	+ there should be a single source of truth
- YAGNI: You Ain't Gonna Need It
- Code Smells
	+ long methods
	+ very short (or long) identifiers
	+ pointless comments
	+ God object
	+ Feature envy
		* if one class does very little except use all the methods of another class

**SOLID**
- S: Single Responsibility Principle
- O: Open / Closed Principle
- L: Liskov Substitution Principle
- I: Interface Segregation Principle
- D: Dependecy Inversion Principle

**S: Single Responsibility Principle**
- an object should have one reason to exist, one reason to change - one primary responsibility
- don't create God objects

**O: Open / Closed Principle**
- Open for extension, closed for modification
- after you've written some working code, and then your requirements change, if you 
need to add additional behavior, you do it by writing new code, not by changing all code that 
already works.

**L: Liskov Substitution Principle**
- Derived classes must be substitutable for their base classes

**I: Interface Segregation Principle**
- many specific interfaces are better than one general interface

**D: Dependecy Inversion Principle**
- depend on abstraction, not on concretions

**SOLID Conclusion**
- SOLID can be used as a checklist

**GRASP**
- GRASP = General Responsibility Assignment Software Patterns
- GRASP has 9 ideas:
	+ Creator
	+ Controller
	+ Pure Fabrication
	+ Information Expert
	+ High Cohesion
	+ Indirection
	+ Low Coupling
	+ Polymorphism
	+ Protected Variations
+ Expert / Information Expert
	* assign the responsibility to the class that has the information needed to fulfill it
+ Creator
	* Who is responsible for creating an object/
* Low Coupling / High Cohesion
	- Coupling: the level dependencies between object
	- Cohesion: the level that a class contains focused, relative behaviors
	- The aiming is LOW COUPLING and HIGH COHESION
- Controller
	+ Don't connect UI elements directly to business objects
	+ i.e. MVC
+ Pure Fabricaiton
	* what the behavior does not belong anywhere else, create a new class
* Indirection
	- to reduce coupling, introduce an intermediate object
- Polymorphism
	+ automatically correct bahvior based on type
		* as opposed to: conditional logic that checks for particular types
* Protected Variations
	- protect the system from changes and variations
		+ identify the most likely points of change
		+ use multiple techniques: encapsulation, LSP, OCP

## Conclusion

**Resources**
- Software Requirements by Karl Wiegers
- Writing Effective Use Cases by Alistair Cockburn's
- User Stories Applied by Mike Cohn
- UML Distilled by Martin Fowler
- Refactoring by Martin Fowler
- Head First Design Patterns












