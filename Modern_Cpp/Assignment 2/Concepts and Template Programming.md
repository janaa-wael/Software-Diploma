# Concepts and Template Programming

------

## a) Theory

### 1. What are concepts, and how do they improve template programming?

**Concepts** (introduced in **C++20**) are a language feature that allows you to **specify constraints on template parameters**.

They improve template programming by:

- **Providing clear compile-time errors** instead of long, unreadable template errors.
- **Making template requirements explicit**, improving readability.
- **Preventing invalid template instantiations early**.
- Acting as **documentation** for what a template expects.

👉 In short:
**Concepts = constraints + clarity + better diagnostics**

------

### 2. Difference between `requires` clauses and predefined concepts

| Aspect      | `requires` clause                           | Predefined concepts                   |
| ----------- | ------------------------------------------- | ------------------------------------- |
| Definition  | Custom constraint written by the programmer | Ready-made concepts from `<concepts>` |
| Usage       | Used to define specific requirements        | Used for common type categories       |
| Flexibility | Very flexible                               | Limited to standard definitions       |
| Example     | `requires (T a) { a.begin(); }`             | `std::integral<T>`                    |

**Example:**

```cpp
template<typename T>
requires std::integral<T>
void func(T value);
```

👉 `std::integral`, `std::floating_point`, etc. are **predefined concepts**, while `requires` allows you to define **custom rules**.

------

## b) Practice

### 1. Template function using `requires` (integral only)

```cpp
#include <iostream>
#include <type_traits>

template<typename T>
requires std::is_integral_v<T>
void printType(T)
{
    std::cout << "Integral Type\n";
}
```

✅ Works only for integral types
❌ Fails at compile time for non-integral types

------

### 2. Custom concept for a type with `begin`, `end`, and `size`

```cpp
#include <concepts>

template<typename T>
concept Container = requires(T a)
{
    a.begin();
    a.end();
    a.size();
};
```

**Usage example:**

```cpp
template<Container T>
void processContainer(const T& c)
{
    // Works only for container-like types
}
```

👉 This ensures the type behaves like a **container**, without inheritance or base classes.

------

> 