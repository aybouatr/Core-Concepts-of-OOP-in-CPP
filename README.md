# 🚀 C++ Programming Modules (cpp00-cpp09)

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C++98](https://img.shields.io/badge/Standard-C%2B%2B98-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)

**A complete C++ learning path (42 curriculum style) from fundamentals to advanced OOP + STL**

[Overview](#-overview) • [Modules](#-modules) • [Installation](#-installation) • [Usage](#-usage) • [Key Concepts](#-key-concepts)

</div>

---

## 📖 Overview

This repository contains a progressive series of C++ modules (**cpp00 → cpp09**) designed to teach Object-Oriented Programming and modern C++ thinking using the **C++98 standard** and strict compilation flags.

Each module introduces new concepts while building upon previous ones: memory management, canonical form, inheritance, polymorphism, exceptions, templates, containers, iterators, algorithms, and real-world problem solving.

### 🎯 Learning Objectives

- Master **memory management** (stack vs heap, ownership, deep copy)
- Learn **OOP pillars** (encapsulation, inheritance, polymorphism)
- Use **abstract classes** + **interfaces** properly
- Handle errors using **exceptions**
- Understand **templates** (generic programming)
- Become comfortable with **STL containers/iterators/algorithms**
- Write **robust, leak-free, maintainable C++ code**

---

## 📂 Repository Structure

```
cpp/
├── cpp00/          # Intro: classes, encapsulation, I/O basics
├── cpp01/          # Memory allocation, pointers, references, file I/O
├── cpp02/          # Operator overloading, canonical form
├── cpp03/          # Inheritance, constructor chaining
├── cpp04/          # Polymorphism, virtual, abstract classes
├── cpp05/          # Exceptions, RAII, bureaucrat/forms system
├── cpp06/          # Type conversion, serialization, RTTI
├── cpp07/          # Templates (functions/classes), generic programming
├── cpp08/          # STL containers/iterators/algorithms
└── cpp09/          # Advanced STL + real parsing problems (data processing)
```

---

## 📚 Modules

## ✅ Module 00: Introduction to C++
**Goal:** Learn the basics of classes and C++ syntax while staying disciplined.

**Topics covered:**
- Namespaces, classes, member functions
- Encapsulation (private/public)
- `std::cout`, `std::cin`, basic formatting
- Initialization basics

---

## ✅ Module 01: Memory & References
<details>
<summary>Click to expand</summary>

**Goal:** Understand how memory works and how design changes depending on ownership.

**Topics covered:**
- **Stack vs Heap allocation** (`new` / `delete`)
- **Pointers vs References**
- **Dynamic arrays** (`new[]` / `delete[]`)
- **File I/O** (`std::ifstream`, `std::ofstream`)
- Member function pointers (callbacks-style patterns)

**Typical exercises:**
- Zombies (stack/heap)
- Zombie Horde (arrays)
- HumanA vs HumanB (reference vs pointer)
- Replace tool (file parsing)

</details>

---

## ✅ Module 02: Operator Overloading
<details>
<summary>Click to expand</summary>

**Goal:** Write classes that behave like real C++ types.

**Topics covered:**
- **Orthodox Canonical Form**
- Copy constructor vs assignment
- Operator overloading (`+ - * /`, comparisons, `<<`)
- Fixed-point number logic (common in this module)

**Why it matters:**
Operator overloading teaches you how to design clean APIs and how copying should behave.

</details>

---

## ✅ Module 03: Inheritance
<details>
<summary>Click to expand</summary>

**Goal:** Build inheritance hierarchies correctly and understand constructor/destructor order.

**Topics covered:**
- Basic inheritance: `class Derived : public Base`
- Protected vs private members
- Constructor chaining and destruction order
- Reuse and extension patterns

**Typical exercises:**
- ClapTrap / ScavTrap / FragTrap style hierarchy

</details>

---

## ✅ Module 04: Polymorphism
<details>
<summary>Click to expand</summary>

**Goal:** Learn runtime polymorphism and why virtual destructors are mandatory.

**Topics covered:**
- Virtual functions and dynamic dispatch
- Virtual destructors
- Abstract classes + pure virtual methods
- Deep copy problems (Brain example is classic)
- Wrong polymorphism example (non-virtual pitfalls)

**Example:**
```cpp
class Animal {
protected:
    std::string type;
public:
    virtual ~Animal() {}
    virtual void makeSound() const = 0;
};
```

</details>

---

## ✅ Module 05: Exceptions
<details>
<summary>Click to expand</summary>

**Goal:** Write safe code that fails correctly and predictably.

**Topics covered:**
- try/catch/throw
- Custom exceptions inheriting `std::exception`
- `what()` implementation
- Exception propagation
- RAII mindset: resource safety even on failure

**Example:**
```cpp
class GradeTooHighException : public std::exception {
public:
    const char* what() const throw() { return "Grade too high!"; }
};
```

</details>

---

## ✅ Module 06: Casting, Serialization & RTTI
<details>
<summary>Click to expand</summary>

**Goal:** Understand how C++ converts types and how runtime type identification works.

**Topics covered:**
- Scalar conversions (`char`, `int`, `float`, `double`)
- `static_cast`, `reinterpret_cast`, `dynamic_cast`
- **Serialization** basics (convert pointer/data into raw representation safely)
- **RTTI** (Run-Time Type Information) and polymorphic type detection

**Why it matters:**
This module teaches what’s happening “under the hood” in C++ and helps avoid dangerous casts.

**Common tasks you might see:**
- Convert string input into multiple scalar representations
- Serialize/deserialize pointers (`uintptr_t`)
- Identify derived type from base pointer/reference

</details>

---

## ✅ Module 07: Templates (Generic Programming)
<details>
<summary>Click to expand</summary>

**Goal:** Write code that works with *any type* safely.

**Topics covered:**
- Function templates
- Class templates
- Template instantiation
- Working with unknown types (constraints-by-design in C++98 style)

**Why it matters:**
Templates are the foundation of STL and modern C++ design.

**Typical examples:**
- `swap`, `min`, `max` templates
- A small templated container/array with bounds checking

</details>

---

## ✅ Module 08: STL Containers, Iterators & Algorithms
<details>
<summary>Click to expand</summary>

**Goal:** Become productive with real C++ tools: containers + algorithms.

**Topics covered:**
- STL containers (often `vector`, `list`, `deque`, `map`, etc.)
- Iterators (begin/end, iterator categories)
- Algorithms (`find`, `for_each`, etc.)
- Writing generic utilities that operate on containers
- Handling errors/exceptions with STL usage

**Why it matters:**
In real projects, most work is manipulating data with STL.

**Typical tasks you might see:**
- Find/search inside a container
- “Easy find” helper
- Spans / ranges (min/max distance logic)
- MutantStack-style iterator access to stack-like container

</details>

---

## ✅ Module 09: Advanced STL + Data Processing Problems
<details>
<summary>Click to expand</summary>

**Goal:** Use STL to solve more realistic problems: parsing, validation, performance, and clean design.

**Topics covered:**
- Input parsing and validation
- Working with time/sequence data
- Algorithmic thinking (efficiency matters)
- Using multiple containers strategically (map, vector, deque)
- Clean error handling and reporting

**Common 42-style projects in this module:**
- **BitcoinExchange**: parse CSV database + input file, compute values by date
- **RPN**: Reverse Polish Notation calculator using stack logic
- **PmergeMe**: sorting with performance constraints (merge-insert approach)

**Why it matters:**
This module is where everything comes together: STL + OOP + robustness + edge cases.

</details>

---

## 🛠️ Installation

### Prerequisites
- C++ compiler with **C++98** support (`g++` / `clang++`)
- `make`

### Clone
```bash
git clone https://github.com/aybouatr/cpp.git
cd cpp
```

---

## 🚀 Usage

Each exercise usually has its own Makefile:

```bash
# Example:
cd cpp04/ex00
make
./your_program

# Cleanup
make fclean
```

### Makefile Commands
| Command | Description |
|--------:|-------------|
| `make` | Compile |
| `make clean` | Remove object files |
| `make fclean` | Remove objects + binaries |
| `make re` | Rebuild everything |

---

## 🔑 Key Concepts

### 1) Memory Management (Stack vs Heap)
```cpp
Zombie z("Foo");          // stack (auto cleanup)

Zombie* p = new Zombie("Bar"); // heap (manual cleanup)
delete p;

Zombie* horde = new Zombie[10];
delete[] horde;
```

### 2) References vs Pointers
| Feature | Reference | Pointer |
|--------|-----------|---------|
| Null | ❌ | ✅ |
| Reassign | ❌ | ✅ |
| Syntax | `T&` | `T*` |
| Must init | ✅ | ❌ |

### 3) Virtual Functions = Runtime Polymorphism
```cpp
class Base { public: virtual ~Base() {} virtual void f() {} };
class Derived : public Base { public: void f() {} };

Base* b = new Derived();
b->f();
delete b; // OK because destructor is virtual
```

### 4) Canonical Form (Rule of 3)
```cpp
class MyClass {
public:
    MyClass();
    MyClass(const MyClass&);
    MyClass& operator=(const MyClass&);
    ~MyClass();
};
```

### 5) Exceptions
```cpp
try {
    // code that may throw
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

---

## 📊 Compilation Flags

```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

---

## 🐛 Testing

Memory leak check:
```bash
valgrind --leak-check=full ./your_program
```

---

## 🤝 Contributing

Educational repo — contributions are welcome:
- Bug reports / improvements
- Better explanations
- Extra tests / edge cases

---

## 📚 Resources

- https://en.cppreference.com/
- https://www.learncpp.com/
- https://isocpp.github.io/CppCoreGuidelines/
- Scott Meyers — Effective C++

---

## 👤 Author

**aybouatr**  
GitHub: https://github.com/aybouatr

---

<div align="center">

**Made as part of the 42 School curriculum**

</div>
