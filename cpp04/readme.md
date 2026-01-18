# C++ Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

This module introduces advanced Object-Oriented Programming (OOP) concepts in C++98, focusing on polymorphism, abstraction, and interfaces. Below are detailed explanations, ideas, concepts, and implementations for each exercise (ex00, ex01, ex02).

## General Concepts Overview

### Polymorphism
- **Definition**: The ability of objects of different classes to be treated as objects of a common base class, with behavior determined at runtime (its inherete the methods only (const)).
- **Types**:
  - **Compile-time (Static)**: Function overloading, templates.
  - **Runtime (Dynamic)**: Virtual functions, achieved via vtable (virtual table) in C++.
- **Why Important**: Enables flexible, extensible code (e.g., handling different animal types uniformly).
- **Keyword**: `virtual` for methods, `virtual` destructor for proper cleanup.

### Inheritance
- **Definition**: Mechanism where a derived class inherits properties and behaviors from a base class.
- **Types**:
  - **Public**: Derived class can access public/protected members.
  - **Protected/Private**: More restrictive access.
- **Why Used**: Promotes code reuse and hierarchical relationships (e.g., Dog "is-a" Animal).

### Composition
- **Definition**: A class contains objects of other classes as members (has-a relationship).
- **Why Used**: More flexible than inheritance; avoids deep inheritance hierarchies.

### Deep vs. Shallow Copy
- **Shallow Copy**: Copies pointers/references; shared resources lead to bugs (e.g., double deletion).
- **Deep Copy**: Creates independent copies of resources; ensures data integrity.
- **Implementation**: Use copy constructors and assignment operators to allocate new memory.

### Abstract Classes
- **Definition**: Classes that cannot be instantiated; serve as blueprints.
- **How**: Declare at least one pure virtual function (`= 0`).
- **Why Used**: Enforce implementation in derived classes; prevent instantiation of incomplete types.

### Interfaces (Pure Abstract Classes)
- **Definition**: Classes with only pure virtual functions (no data members or implementations).
- **Why Used**: Define contracts without implementation details; enable multiple inheritance for behavior.

### Memory Management in C++
- **RAII (Resource Acquisition Is Initialization)**: Resources allocated in constructors, deallocated in destructors.
- **Heap vs. Stack**: Use `new`/`delete` for dynamic allocation; avoid leaks by pairing them.
- **Virtual Destructors**: Ensure derived destructors are called when deleting via base pointers.

### Orthodox Canonical Form
- **Required for Classes**: Default constructor, copy constructor, assignment operator, destructor.
- **Why**: Ensures classes behave predictably when copied or assigned, especially with dynamic members.

## Exercise 00: Polymorphism

### Overview
Introduces basic polymorphism with virtual functions. `Animal` base class with `Dog` and `Cat` derived classes. Demonstrates runtime polymorphism and the importance of virtual destructors.

### Key Concepts
- **Virtual Functions**: `makeSound()` is virtual in `Animal`, overridden in `Dog`/`Cat`. Calls are resolved at runtime based on actual object type.
- **Why Virtual?**: Without `virtual`, calls via base pointers would use base implementation (static binding).
- **WrongAnimal/WrongCat**: Illustrates lack of polymorphism when base method isn't virtual. `WrongCat` overrides `makeSound()`, but via `WrongAnimal*`, it calls base version.
- **Virtual Destructors**: Ensures proper cleanup when deleting derived objects via base pointers.

### Implementation Notes
- `Animal::makeSound()` provides a default, but derived classes override it.
- Constructors/destructors print messages to trace object lifecycle.
- `getType()` returns the animal's type string.

### Code Structure
- `Animal.hpp/.cpp`: Base class with virtual `makeSound()`.
- `Dog.hpp/.cpp`: Inherits `Animal`, sets `type = "Dog"`, overrides `makeSound()`.
- `Cat.hpp/.cpp`: Similar to `Dog`, `type = "Cat"`.
- `WrongAnimal.hpp/.cpp`: Non-virtual `makeSound()`.
- `WrongCat.hpp/.cpp`: Overrides `makeSound()`, but polymorphism fails.
- `main.cpp`: Tests polymorphism via base pointers.

### Expected Output
- `Dog` and `Cat` make correct sounds via `Animal*`.
- `WrongCat` via `WrongAnimal*` makes `WrongAnimal` sound.

### Why This Design?
- Teaches dynamic binding vs. static binding.
- Shows polymorphism enables uniform handling of different types.

## Exercise 01: I don’t want to set the world on fire

### Overview
Adds composition and deep copying. `Dog` and `Cat` now have a `Brain` (array of 100 ideas). Ensures deep copies to prevent shared state. Tests memory leaks via polymorphic deletion.

### Key Concepts
- **Composition**: `Brain* brain` in `Dog`/`Cat`; animals "have" brains.
- **Deep Copying**: Copy constructors/assignment operators allocate new `Brain` objects. Prevents one animal's idea changes affecting another's.
- **Memory Management**: `new Brain()` in constructors, `delete brain` in destructors. Virtual destructors ensure cleanup via base pointers.
- **Polymorphic Deletion**: Array of `Animal*` (mixed `Dog`/`Cat`) deleted as `Animal*`; correct destructors called due to virtual `~Animal()`.
- **Testing Leaks**: No `Animal` instantiation; focus on derived objects.

### Implementation Notes
- `Brain` class: Array of `std::string`, with `setIdea()`/`getIdea()` for access.
- `Dog`/`Cat` constructors: `brain = new Brain()`.
- Copy Constructor: `brain = new Brain(*other.brain)` (deep copy).
- Assignment Operator: `delete brain; brain = new Brain(*other.brain)`.
- Destructor: `delete brain`.
- `main.cpp`: Tests deep copy by modifying ideas independently.

### Expected Output
- Constructor/destructor messages show proper order (derived first, then base).
- Deep copy test: Dog1 and Dog2 have different ideas after modification.
- No memory leaks (verify with `valgrind`).

### Why This Design?
- Reinforces RAII and deep copying for dynamic members.
- Demonstrates composition over inheritance for "has-a" relationships.
- Ensures safe polymorphic operations.

## Exercise 02: Abstract Class

### Overview
Makes `Animal` abstract by declaring `makeSound()` pure virtual (`= 0`). Prevents instantiation of `Animal` directly, as it "makes no sound."

### Key Concepts
- **Abstract Classes**: Cannot be instantiated; force derived classes to implement pure virtual functions.
- **Pure Virtual Functions**: Declared with `= 0`; no implementation in base class.
- **Why Abstract?**: `Animal` is incomplete without specific sound behavior. Prevents misuse (e.g., no generic `Animal` objects).
- **Polymorphism Unchanged**: Derived classes still work via base pointers.

### Implementation Notes
- `Animal.hpp`: `virtual void makeSound() const = 0;`
- `Animal.cpp`: Removes `makeSound()` implementation.
- `Dog`/`Cat`: Must implement `makeSound()` or remain abstract.
- `main.cpp`: No `new Animal()`; only derived objects.

### Expected Output
- Same as ex01, but `Animal` cannot be instantiated (compile error if attempted).
- Polymorphism works as before.

### Why This Design?
- Enforces design intent: base classes should be abstract if they represent incomplete concepts.
- Promotes better OOP by requiring concrete implementations in derived classes.

## Summary of Concepts Across Exercises

| Concept | ex00 | ex01 | ex02 |
|---------|------|------|------|
| Polymorphism | Virtual `makeSound()` | Virtual destructors for cleanup | Pure virtual enforces implementation |
| Inheritance | `Dog`/`Cat` inherit `Animal` | Same, with composition | Same, abstract base |
| Composition | N/A | `Brain*` in `Dog`/`Cat` | Same |
| Deep Copy | N/A | Copy constructors/assignment for `Brain` | Same |
| Memory Mgmt | Virtual destructors | RAII with `new`/`delete` | Same |
| Abstract Classes | N/A | N/A | `Animal` with pure virtual |

### Compilation and Testing
- Compile with: `c++ -Wall -Wextra -Werror -std=c++98 *.cpp`
- Run: `./a.out`
- Check leaks: `valgrind ./a.out` (if available)
- Each exercise builds on the previous; ex02 is ex01 with abstract `Animal`.

### Final Thoughts
- This module emphasizes safe, polymorphic C++ code.
- Key Idea: Use virtual for runtime behavior, abstract for contracts, composition for flexibility.
- Avoid common pitfalls: shallow copies, non-virtual destructors, memory leaks.