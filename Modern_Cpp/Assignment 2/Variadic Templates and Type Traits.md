# Variadic Templates & Type Traits

### **1. Variadic Templates**

**Definition:**
Variadic templates are templates that can take **any number of template parameters** (including zero). They were introduced in **C++11**.

**Syntax Example:**

```cpp
template<typename... Args>
void printAll(Args... args) {
    (std::cout << ... << args) << '\n'; // fold expression in C++17
}

int main() {
    printAll(1, " hello ", 3.14); // prints: 1 hello 3.14
}
```

**How they improve traditional templates:**

- Traditional templates required you to **define multiple overloads** to handle different numbers of arguments.
- Variadic templates allow **arbitrary-length argument lists** in a single definition.
- They are **type-safe**, unlike old-style C variadic functions (`printf`) which rely on manual type handling.

------

### **2. Type Traits**

**Definition:**
Type traits are **compile-time templates** that provide information about types. They allow you to **inspect or modify types at compile time**.

**Examples:**

```cpp
#include <type_traits>

static_assert(std::is_integral<int>::value, "int is integral");
static_assert(std::is_floating_point<double>::value, "double is floating point");
```

**Role in template metaprogramming:**

- Enable **compile-time decisions** based on type properties.
- Allow writing **generic code** that adapts to types.
- Useful for **SFINAE** (Substitution Failure Is Not An Error) techniques.

------

### **3. `std::enable_if` and `std::conditional`**

**a) `std::enable_if`**

- Used to **enable or disable a template or function** based on a condition.
- Helps implement **SFINAE**, making code safer and more flexible.

**Example:**

```cpp
#include <type_traits>
#include <iostream>

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
printIfIntegral(T value) {
    std::cout << "Integral: " << value << "\n";
}

int main() {
    printIfIntegral(42);    // Works
    // printIfIntegral(3.14); // Error: double not integral
}
```

**b) `std::conditional`**

- Chooses **one type or another** based on a compile-time boolean condition.

**Example:**

```cpp
#include <type_traits>

using MyType = std::conditional<sizeof(int) > 4, long, int>::type;
```

- If `sizeof(int) > 4`, `MyType` is `long`, otherwise it’s `int`.
- Useful for **type selection and optimization** at compile time.

------

### **Summary Table**

| Feature            | Purpose                                                      |
| ------------------ | ------------------------------------------------------------ |
| Variadic templates | Handle arbitrary number of template parameters               |
| Type traits        | Inspect or modify types at compile time                      |
| `std::enable_if`   | Enable/disable templates based on a condition (SFINAE)       |
| `std::conditional` | Choose one type or another based on a compile-time condition |

