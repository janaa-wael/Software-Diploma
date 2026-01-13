# Result Feature 

## **1️⃣ What is `std::result`?**

`std::result` (or `std::expected` in C++23, or a custom equivalent) is a **type that represents either a successful value or an error**.

Think of it as a container that can hold:

- ✅ A valid result (like `int`, `double`, or any type `T`)
- ❌ An error (like a string message, error code, or exception info)

### **Purpose**

- To **handle errors safely** without throwing exceptions.
- To **make error handling explicit**, so the caller must check the result.

### **Example (custom simple version)**

```cpp
#include <iostream>
#include <string>
#include <variant>

template<typename T>
struct Result {
    std::variant<T, std::string> value;  // value or error

    bool is_ok() const { return std::holds_alternative<T>(value); }
    bool is_error() const { return std::holds_alternative<std::string>(value); }

    T unwrap() const { return std::get<T>(value); }
    std::string error() const { return std::get<std::string>(value); }
};

// Usage
Result<int> divide(int a, int b) {
    if (b == 0)
        return Result<int>{std::string("Division by zero")};
    return Result<int>{a / b};
}

int main() {
    auto r = divide(10, 0);
    if (r.is_ok())
        std::cout << r.unwrap() << std::endl;
    else
        std::cout << "Error: " << r.error() << std::endl;
}
```

------

## **2️⃣ Why use `std::result` instead of exceptions?**

| Feature          | `std::result`                          | Exceptions                         |
| ---------------- | -------------------------------------- | ---------------------------------- |
| **Control flow** | Explicit; compiler forces you to check | Implicit; may be ignored           |
| **Performance**  | No stack unwinding, low overhead       | May be expensive (stack unwinding) |
| **Safety**       | Makes errors obvious                   | Can be missed, runtime surprises   |
| **Usage**        | Functional style: `map`, `and_then`    | Traditional try/catch              |

------

## **3️⃣ Comparison with `std::optional`**

| Feature               | `std::result`                     | `std::optional`                          |
| --------------------- | --------------------------------- | ---------------------------------------- |
| **Stores error info** | ✅ Yes (error message or code)     | ❌ No (just missing value)                |
| **For failure cases** | Explicit                          | Only “no value”                          |
| **Use case**          | Functions that can fail with info | Functions that might not return anything |

### Example

```cpp
std::optional<int> find_index(int x) { ... } // just None if not found
Result<int> safe_divide(int a, int b) { ... } // detailed error if b==0
```

So:

- `std::optional` = “maybe a value or nothing”
- `std::result` = “value or error with reason”

------

## ✅ **Key takeaway**

- `std::result` makes **error handling explicit and safe**.
- Safer alternative to exceptions in performance-sensitive or embedded code.
- More informative than `std::optional`.

