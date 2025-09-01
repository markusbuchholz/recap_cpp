## Modern C++


---

# 🔹 1. Smart Pointers 

No more manual `new/delete` in most cases.

```cpp
#include <iostream>
#include <memory>

int main() {
    auto up = std::make_unique<int>(42);      // unique ownership
    auto sp = std::make_shared<int>(99);      // shared ownership

    std::cout << *up << " " << *sp << "\n";   // 42 99
}
```

---

# 🔹 2. `auto` Type Deduction

Let the compiler infer the type.

```cpp
auto x = 10;        // int
auto y = 3.14;      // double
auto z = "hello";   // const char*
```

---

# 🔹 3. Range-based for Loop

Clean iteration over containers.

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1,2,3,4};
    for (auto n : v) {
        std::cout << n << " ";
    }
}
```

Output: `1 2 3 4`

---

# 🔹 4. Lambda Functions

Anonymous inline functions.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1,2,3,4};
    std::for_each(v.begin(), v.end(), [](int n){ std::cout << n*2 << " "; });
}
```

Output: `2 4 6 8`

---

# 🔹 5. Move Semantics (`std::move`)

Avoid unnecessary copies → efficiency.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello";
    std::string s2 = std::move(s1); // transfer ownership
    std::cout << "s2 = " << s2 << "\n";  // Hello
    std::cout << "s1 = " << s1 << "\n";  // empty/unspecified
}
```

---

# 🔹 6. `constexpr` (Compile-time Evaluation)

Functions/values computed at compile time.

```cpp
constexpr int square(int x) { return x * x; }

int main() {
    int arr[square(3)]; // size known at compile-time
    std::cout << "Array size = " << sizeof(arr)/sizeof(arr[0]) << "\n";
}
```

Output: `Array size = 9`

---

# 🔹 7. `nullptr` (instead of `NULL` or `0`)

```cpp
int* p = nullptr;
if (!p) std::cout << "Pointer is null\n";
```

---

# 🔹 8. `std::tuple` and `std::pair`

Return multiple values from a function.

```cpp
#include <tuple>
#include <iostream>

std::tuple<int, double, std::string> getData() {
    return {1, 3.14, "robot"};
}

int main() {
    auto [id, val, name] = getData(); // structured binding (C++17)
    std::cout << id << " " << val << " " << name << "\n";
}
```

Output: `1 3.14 robot`

---

# 🔹 9. `std::optional` (C++17)

Represents a value that may or may not exist.

```cpp
#include <optional>
#include <iostream>

std::optional<int> findValue(bool ok) {
    if (ok) return 42;
    return std::nullopt;
}

int main() {
    auto v = findValue(true);
    if (v) std::cout << "Found: " << *v << "\n";
}
```

---

# 🔹 10. Structured Bindings (C++17)

Unpack pairs/tuples cleanly.

```cpp
#include <map>
#include <iostream>

int main() {
    std::map<int, std::string> robots = {{1,"Alpha"},{2,"Beta"}};
    for (auto [id, name] : robots) {
        std::cout << id << " => " << name << "\n";
    }
}
```

 Output:

```
1 => Alpha
2 => Beta
```

---


---


