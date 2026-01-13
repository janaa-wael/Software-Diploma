# Structured Binding

### **1️⃣ What are Structured Bindings?**

Structured bindings, introduced in **C++17**, allow you to **decompose objects** like tuples, pairs, structs, or containers directly into individual variables in a single statement.

**Purpose:**

- Simplifies **accessing multiple values at once**.
- Makes code **cleaner, readable, and less error-prone**.

**Example with `std::pair`:**

```cpp
#include <iostream>
#include <utility>  // for std::pair

int main() {
    std::pair<int, std::string> p{1, "Alice"};

    // Structured binding
    auto [id, name] = p;

    std::cout << id << " - " << name << "\n";
}
```

Here, `id` and `name` are automatically assigned from `p.first` and `p.second`.

**Example with `std::tuple`:**

```cpp
#include <tuple>

int main() {
    std::tuple<int, double, char> t{42, 3.14, 'x'};

    auto [i, d, c] = t;  // Structured binding
}
```

**Example with containers (like `map`):**

```cpp
#include <map>
#include <string>

int main() {
    std::map<int, std::string> m{{1, "one"}, {2, "two"}};

    for (const auto& [key, value] : m) {
        std::cout << key << " -> " << value << "\n";
    }
}
```

------

### **2️⃣ Comparison with Traditional Methods**

| Feature             | Traditional Access                                   | Structured Bindings                                    |
| ------------------- | ---------------------------------------------------- | ------------------------------------------------------ |
| **Pairs/Tuples**    | Access via `.first`, `.second` or `std::get<>()`.    | Decompose directly into variables using `auto [a, b]`. |
| **Maps**            | `for (const auto &p : m) { p.first; p.second; }`     | `for (const auto &[key, value] : m) { key; value; }`   |
| **Readability**     | Verbose, harder to read.                             | Clean, readable, self-explanatory.                     |
| **Variable Naming** | Need extra statements to assign to meaningful names. | Assign meaningful names in the same line.              |
| **Error-prone**     | Easy to swap `.first` and `.second` accidentally.    | Reduces such mistakes because names are explicit.      |

**Traditional tuple example:**

```cpp
auto t = std::make_tuple(1, 2, 3);
int a = std::get<0>(t);
int b = std::get<1>(t);
int c = std::get<2>(t);
```

**Structured binding version:**

```cpp
auto [a, b, c] = t;  // Cleaner and less error-prone
```

------

✅ **Key takeaway:**

Structured bindings **save lines of code, improve readability, and allow direct naming of elements**, especially when dealing with tuples, pairs, or iterating over maps.

