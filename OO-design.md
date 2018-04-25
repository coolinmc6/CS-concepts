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
- Example of User Story formula
As a (_type of user_)
I want (_goal_)
so that (_reason_)

**User Stories and Use Cases**
| User Stories | Use Cases|
| --- | --- |
| short - one index card | long - a document |
| one goal, no details | multiple goals and details |
| informal | casual to (very) formal |
| "placeholder for conversation" | "record of conversation" |


## Domain Modeling (Modeling the App)

## Creating Classes

## Inheritance and Composition

## Advanced Concepts

## Object-Oriented Design Patterns

## Object-Oriented Design Principles

## Conclusion




























