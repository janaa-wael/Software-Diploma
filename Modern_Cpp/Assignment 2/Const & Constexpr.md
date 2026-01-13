# Const & Constexpr

### **1️⃣ Difference between `constexpr` and `const`**

| Feature             | `const`                                                      | `constexpr`                                                  |
| ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Meaning**         | Declares a variable or object whose value cannot be changed after initialization. | Declares that a variable, function, or object can (and should) be evaluated at **compile-time** if possible. |
| **Evaluation time** | Can be initialized at runtime or compile-time.               | Must be **compile-time evaluable** (for variables) or able to produce a compile-time result (for functions). |
| **Variables**       | `const int x = 5;` → `x` cannot change, but initialization can be runtime. | `constexpr int x = 5;` → `x` is **guaranteed** to be evaluated at compile-time. |
| **Functions**       | `const` doesn’t apply to functions directly.                 | `constexpr` functions can be executed at compile-time if called with compile-time constants. |
| **Usage**           | Read-only data.                                              | Compile-time constants, template arguments, array sizes, and optimization opportunities. |

**Example:**

```cpp
const int a = 5;        // OK, a is read-only
int x;
const int b = x;        // OK if x known at runtime

constexpr int c = 5;    // OK, evaluated at compile-time
int y;
constexpr int d = y;    // ❌ Error: y not known at compile-time
```

------

### **2️⃣ Significance of `constexpr` in functions and variables**

**a) For variables:**

- Guarantees **compile-time evaluation**.
- Can be used for:
  - Array sizes.
  - Template parameters.
  - `switch` cases.
- Helps compiler optimize and catch errors earlier.

```cpp
constexpr int size = 10;
int arr[size];  // OK, size is compile-time constant
```

**b) For functions:**

- Tells the compiler that the function **can be evaluated at compile-time** if arguments are compile-time constants.
- Enables:
  - Compile-time computations.
  - Use in `constexpr` variables and template arguments.
- Must contain **only statements that can be evaluated at compile-time** (simple arithmetic, return expressions, other `constexpr` functions).

```cpp
constexpr int square(int x) {
    return x * x;
}

constexpr int s = square(5);  // Evaluated at compile-time
int arr[s];                   // OK
```

**Key points:**

- `constexpr` functions **can also be used at runtime** with runtime values.
- Helps **performance** by moving computation from runtime to compile-time.
- Encourages **safer and more predictable code**.