# Object-Oriented JavaScript

[Home](https://github.com/coolinmc6/CS-concepts/blob/master/README.md)


```js
// Create a new class
function Vehicle(color, weight) {
    this.color = color;
    this.weight = weight;
}

// Add a class method to the class
Vehicle.prototype.drive = function() {
    console.log('The ' + this.color + ' vehicle is now driving!')
}

Vehicle.prototype.honk = function() {
    console.log('Honk!')
}

// Instantiate a new instance of the class
var stuff = new Vehicle('red', '2000lbs');
stuff.drive()
stuff.honk();

// Create child class
function Car(color, weight, doors) {
    // instantiate a new instance of Vehicle within the Car class
    Vehicle.call(this, color, weight);
    this.doors = doors;
}

// Inherit the methods, etc. of the Vehicle
Car.prototype = Object.create(Vehicle.prototype);

var nissan = new Car('silver', '2200lbs', 4);
nissan.drive()

console.log(nissan)
```