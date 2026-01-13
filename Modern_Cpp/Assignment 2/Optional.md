# Optional

### **1️⃣ Purpose of `std::optional`**

`std::optional` (introduced in **C++17**) is a **wrapper type that may or may not contain a value**. It represents **optional/nullable values** in a **type-safe** way.

**Purpose:**

- To indicate that a function **might not return a meaningful value**.
- To **avoid using raw pointers or sentinel values** (like `-1`, `nullptr`, or `0`) for "no value".

**Example:**

```cpp
#include <optional>
#include <iostream>

std::optional<int> find_even(int x) {
    if (x % 2 == 0)
        return x;        // has a value
    else
        return {};       // empty optional
}

int main() {
    auto result = find_even(3);
    if (result) {
        std::cout << "Even number: " << *result << "\n";
    } else {
        std::cout << "No even number found\n";
    }
}
```

**Advantages over pointers or sentinel values:**

| Aspect             | Pointer                             | Sentinel Value                 | `std::optional`                                      |
| ------------------ | ----------------------------------- | ------------------------------ | ---------------------------------------------------- |
| **Expressiveness** | `nullptr` signals no value          | `-1` or `0` signals no value   | Clearly represents “maybe a value”                   |
| **Type safety**    | Can point to wrong type             | Must pick a sentinel carefully | Fully type-safe, avoids invalid values               |
| **Ownership**      | Raw pointers need manual management | N/A                            | Automatically managed; no dangling references        |
| **Readability**    | Less clear for reader               | Magic numbers are unclear      | Self-explanatory (`optional<int>` means "maybe int") |

------

### **2️⃣ Limitations of `std::optional`**

1. **Not suitable for large objects frequently copied**
   - Copying or moving large objects repeatedly can be expensive.
2. **Does not replace all pointers**
   - Cannot express shared ownership like `std::shared_ptr`.
3. **Cannot hold references directly**
   - Use `std::optional<std::reference_wrapper<T>>` if you need optional references.
4. **No default "null value" for complex types**
   - You still need to check `if(opt)` or `opt.has_value()` before using it.
5. **Slight memory overhead**
   - `std::optional<T>` typically adds a flag to indicate whether a value is present.

------

✅ **Key takeaway:**

`std::optional` is a **clean, safe way to represent values that might not exist**, replacing raw pointers or sentinel values, but it’s **not a replacement for all pointer or ownership semantics**, and may incur minor overhead for large objects.

------

### **`std::nullopt` in `std::optional`**

`std::nullopt` is a **special constant** that represents **“no value”** for an `std::optional`.

- It makes your code **explicit** when you want an optional to be empty.
- Preferred over `{}` because it is **self-documenting**.

**Example:**

```cpp
#include <optional>
#include <iostream>

std::optional<int> divide(int a, int b) {
    if (b == 0)
        return std::nullopt;  // explicitly return "no value"
    return a / b;
}

int main() {
    auto result = divide(10, 0);
    if (result.has_value()) {
        std::cout << "Result: " << *result << "\n";
    } else {
        std::cout << "Division by zero, no result.\n";
    }
}
```

**Key points about `std::nullopt`:**

1. Type-safe: you **cannot accidentally assign it to a non-optional type**.
2. Improves **readability**: anyone reading the code sees the intent “optional is empty”.
3. Can be used with **assignment**:

```cpp
std::optional<int> opt = 42;
opt = std::nullopt;  // now opt has no value
```

1. Preferred in **function return statements** when signaling failure, instead of using pointers or magic numbers.

------

✅ **Memory & Behavior Notes:**

- `std::optional<T>` uses **1 extra flag internally** to track if it contains a value or `nullopt`.
- `std::nullopt` does **not occupy extra memory**; it just sets the flag to “empty”.

