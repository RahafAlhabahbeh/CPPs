The Orthodox Canonical Class Form
Default Constructor: Initializes a "blank" object.
Copy Constructor: Creates a new object as a copy of an existing one.
Copy Assignment Operator: Sets an existing object's values to match another.
Destructor: Cleans up when the object is destroyed.

1. What is other?
the name of the parameter. It represents the existing object that you want to copy from.

Using a reference (&) allows the function to look at the original memory of the existing object directly, avoiding an infinite loop when he compiler would need to call the Copy Constructor to pass into the function.

Operator Resolution
To understand why the << operator must be outside the class: The object on the left is always the one that "owns" the function.