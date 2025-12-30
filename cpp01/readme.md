The :: symbol is called the Scope Resolution Operator.
Class MemberZombie::announce()Find announce inside the Zombie class.Namespacestd::stringFind string inside the std namespace.Global Scope::my_func()Find my_func in the global space (not in a class).

The this keyword is a special pointer available inside any non-static member function. It points directly to the specific object (the "instance") currently executing that function

Stack Allocation: Memory is managed automatically. When a variable goes out of scope (like the end of a function), it is destroyed immediately

Heap Allocation: You manually request memory using the new keyword. This memory persists until you explicitly use delete

The Destructor: A special member function (denoted by a ~ followed by the class name) that is called automatically when an object is destroyed. It’s perfect for cleanup or, in this case, debugging.

The Dot Operator (.) — Direct Access
You use the dot operator when you have a direct instance of an object. This is usually the case for objects created on the Stack.
The Arrow Operator (->) — Indirect Access
You use the arrow operator when you have a pointer to an object. This is almost always the case for objects created on the Heap using new.

Zombie::Zombie(std::string name) : _name(name) {}
This is called a Member Initializer List.
create the _name variable and set its value to name at the exact moment
How it works: First, the compiler creates _name and gives it a default value (an empty string). Then, it enters the curly braces {} and overwrites that empty string with the new name.

ex01
array->heap

ex02
Pointer (string*): It is its own variable that holds the memory address of another variable. You use the & operator to get the address. It can be changed to point to something else later.

Reference (string&): It is an alias (a nickname) for an existing variable. It is not a separate entity in memory in the same way a pointer is. Once initialized, it can never point to anything else.

ex03
Feature,HumanA (Reference),HumanB (Pointer)
Exists from start?,Yes (Mandatory),No (Optional)
Can be NULL?,No,Yes
Can change weapon?,No (Linked for life),Yes (Can swap pointers)

{} define a Local Scope (also called a block scope).
used in main.cpp to control the lifetime of the objects created inside them