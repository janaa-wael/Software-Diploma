# Variant Feature

## **1️⃣ What is `std::variant`?**

`std::variant` (introduced in **C++17**) is a **type-safe union**. It can **hold one value out of a fixed set of types** at a time.

**Key points:**

- Think of it as a **container for multiple alternative types**.
- Only **one of the types is active at any time**.
- Type-safe: the compiler knows the possible types.

**Example:**

```cpp
#include <variant>
#include <iostream>
#include <string>

int main() {
    std::variant<int, double, std::string> v;

    v = 42;          // holds int
    v = 3.14;        // now holds double
    v = "Hello";     // now holds string
}
```

------

### **Difference between `std::variant` and `std::any`**

| Feature         | `std::variant`                                             | `std::any`                                             |
| --------------- | ---------------------------------------------------------- | ------------------------------------------------------ |
| **Type set**    | Fixed set of types known at compile-time                   | Any type, unknown at compile-time                      |
| **Type safety** | Checked at compile-time                                    | Type safety only at runtime (you need `std::any_cast`) |
| **Access**      | `std::get<T>(v)` or visitation                             | `std::any_cast<T>(a)`                                  |
| **Use case**    | When alternatives are **known and limited**                | When you need a **truly dynamic type container**       |
| **Performance** | Faster and safer (no dynamic checks if using correct type) | Slower, runtime type checks, can throw `bad_any_cast`  |

✅ **Rule of thumb:** Use `std::variant` when **possible types are known**, use `std::any` when **types are unknown or completely dynamic**.

------

## **2️⃣ Concept of visitation with `std::visit`**

Since `std::variant` can hold multiple types, you often want to **perform different actions depending on which type it currently holds**. This is done using **`std::visit`**, which takes a **visitor function (or lambda)** and the variant.

**Example:**

```cpp
#include <variant>
#include <iostream>
#include <string>

int main() {
    std::variant<int, double, std::string> v = 42;

    // Visitor using lambda
    std::visit([](auto&& val){
        std::cout << "Value is: " << val << "\n";
    }, v);

    v = "Hello";

    std::visit([](auto&& val){
        std::cout << "Value is: " << val << "\n";
    }, v);
}
```

- The lambda **automatically deduces the type** currently stored in the variant.
- You can also provide **overloaded lambdas** for different types:

```cpp
struct Overloaded {
    void operator()(int i) { std::cout << "int: " << i << "\n"; }
    void operator()(double d) { std::cout << "double: " << d << "\n"; }
    void operator()(const std::string& s) { std::cout << "string: " << s << "\n"; }
};

std::visit(Overloaded{}, v);
```

✅ **Key points about `std::visit`:**

- Ensures **type-safe handling** of the active type in a variant.
- Prevents runtime errors from **wrong type access**.
- Central to using `std::variant` effectively.