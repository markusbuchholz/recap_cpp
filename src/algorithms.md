# C++ Standard Library Algorithms Recap


## Table of Contents

1. [adjacent_find](#1-adjacent_find)
2. [all_of](#2-all_of)
3. [any_of](#3-any_of)
4. [binary_search](#4-binary_search)
5. [copy](#5-copy)
6. [copy_backward](#6-copy_backward)
7. [copy_if](#7-copy_if)
8. [copy_n](#8-copy_n)
9. [count](#9-count)
10. [count_if](#10-count_if)
11. [equal](#11-equal)
12. [equal_range](#12-equal_range)
13. [fill](#13-fill)
14. [fill_n](#14-fill_n)
15. [find](#15-find)
16. [find_end](#16-find_end)
17. [find_first_of](#17-find_first_of)
18. [find_if](#18-find_if)
19. [find_if_not](#19-find_if_not)
20. [for_each](#20-for_each)
21. [generate](#21-generate)
22. [generate_n](#22-generate_n)
23. [includes](#23-includes)
24. [inplace_merge](#24-inplace_merge)
25. [is_heap](#25-is_heap)
26. [is_heap_until](#26-is_heap_until)
27. [is_partitioned](#27-is_partitioned)
28. [is_permutation](#28-is_permutation)
29. [is_sorted](#29-is_sorted)
30. [is_sorted_until](#30-is_sorted_until)
31. [iter_swap](#31-iter_swap)
32. [lexicographical_compare](#32-lexicographical_compare)
33. [lower_bound](#33-lower_bound)
35. [max_element](#35-max_element)
36. [merge](#36-merge)
37. [min](#37-min)
38. [min_element](#38-min_element)
39. [minmax](#39-minmax)
40. [minmax_element](#40-minmax_element)
41. [mismatch](#41-mismatch)
42. [move](#42-move)
43. [move_backward](#43-move_backward)
44. [next_permutation](#44-next_permutation)
45. [none_of](#45-none_of)
46. [nth_element](#46-nth_element)
47. [partial_sort](#47-partial_sort)
48. [partial_sort_copy](#48-partial_sort_copy)
49. [partition](#49-partition)
50. [partition_copy](#50-partition_copy)
51. [partition_point](#51-partition_point)
52. [pop_heap](#52-pop_heap)
53. [prev_permutation](#53-prev_permutation)
54. [push_heap](#54-push_heap)
55. [random_shuffle](#55-random_shuffle)
56. [remove](#56-remove)
57. [remove_copy](#57-remove_copy)
58. [remove_copy_if](#58-remove_copy_if)
59. [remove_if](#59-remove_if)
60. [replace](#60-replace)
61. [replace_copy](#61-replace_copy)
62. [replace_copy_if](#62-replace_copy_if)
63. [replace_if](#63-replace_if)
64. [reverse](#64-reverse)
65. [reverse_copy](#65-reverse_copy)
66. [rotate](#66-rotate)
67. [rotate_copy](#67-rotate_copy)
68. [search](#68-search)
69. [search_n](#69-search_n)
70. [set_difference](#70-set_difference)
71. [set_intersection](#71-set_intersection)
72. [set_symmetric_difference](#72-set_symmetric_difference)
73. [set_union](#73-set_union)
74. [shuffle](#74-shuffle)
75. [sort](#75-sort)
76. [sort_heap](#76-sort_heap)
77. [stable_partition](#77-stable_partition)
78. [stable_sort](#78-stable_sort)
79. [swap](#79-swap)
80. [swap_ranges](#80-swap_ranges)
81. [transform](#81-transform)
82. [unique](#82-unique)
83. [unique_copy](#83-unique_copy)
84. [upper_bound](#84-upper_bound)

---

## 1. adjacent_find

### Description

`std::adjacent_find` searches for the first occurrence of two consecutive elements in a range that satisfy a specified condition (default is equality).

### Example 1: Finding Adjacent Equal Elements

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    auto it = std::adjacent_find(vec.begin(), vec.end());

    if(it != vec.end()) {
        std::cout << "First adjacent duplicate: " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No adjacent duplicates found.\n";
    }

    return 0;
}
```

**Output:**
```
First adjacent duplicate: 2 at position 1
```

### Example 2: Finding Adjacent Elements with a Custom Condition

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11};
    // Find first pair where second is double the first
    auto it = std::adjacent_find(vec.begin(), vec.end(), [](int a, int b) {
        return b == 2 * a;
    });

    if(it != vec.end()) {
        std::cout << "First pair where second is double the first: (" << *it << ", " << *(it + 1) << ")\n";
    } else {
        std::cout << "No such pair found.\n";
    }

    return 0;
}
```

**Output:**
```
No such pair found.
```

### Example 3: Using adjacent_find on Strings

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string text = "helloo world";
    auto it = std::adjacent_find(text.begin(), text.end());

    if(it != text.end()) {
        std::cout << "First adjacent duplicate character: '" << *it << "' at position " << std::distance(text.begin(), it) << "\n";
    } else {
        std::cout << "No adjacent duplicate characters found.\n";
    }

    return 0;
}
```

**Output:**
```
First adjacent duplicate character: 'l' at position 2
```

---

## 2. all_of

### Description

`std::all_of` checks if all elements in a range satisfy a specified predicate.

### Example 1: Checking if All Elements are Positive

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    bool allPositive = std::all_of(vec.begin(), vec.end(), [](int x) {
        return x > 0;
    });

    std::cout << "All elements are positive: " << (allPositive ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
All elements are positive: Yes
```

### Example 2: Checking if All Characters are Letters

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string text = "HelloWorld";
    bool allLetters = std::all_of(text.begin(), text.end(), [](char c) {
        return std::isalpha(c);
    });

    std::cout << "All characters are letters: " << (allLetters ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
All characters are letters: Yes
```

### Example 3: Using all_of with Empty Range

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec;
    bool result = std::all_of(vec.begin(), vec.end(), [](int x) {
        return x > 0;
    });

    std::cout << "All elements satisfy the condition (empty range): " << (result ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
All elements satisfy the condition (empty range): Yes
```

*Note: For empty ranges, `all_of` returns `true`.*

---

## 3. any_of

### Description

`std::any_of` checks if any element in a range satisfies a specified predicate.

### Example 1: Checking if Any Element is Negative

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, -2, 3, 4, 5};
    bool anyNegative = std::any_of(vec.begin(), vec.end(), [](int x) {
        return x < 0;
    });

    std::cout << "Any element is negative: " << (anyNegative ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
Any element is negative: Yes
```

### Example 2: Checking if Any Character is a Digit

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string text = "Hello2World";
    bool containsDigit = std::any_of(text.begin(), text.end(), [](char c) {
        return std::isdigit(c);
    });

    std::cout << "Contains at least one digit: " << (containsDigit ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
Contains at least one digit: Yes
```

### Example 3: Using any_of with All Elements Failing Predicate

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    bool anyGreaterThanTen = std::any_of(vec.begin(), vec.end(), [](int x) {
        return x > 10;
    });

    std::cout << "Any element greater than 10: " << (anyGreaterThanTen ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
Any element greater than 10: No
```

---

## 4. binary_search

### Description

`std::binary_search` checks if a value exists within a sorted range using the binary search algorithm. The range must be sorted according to the same comparison criterion used by `binary_search`.

### Example 1: Basic Binary Search

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    bool found = std::binary_search(vec.begin(), vec.end(), target);

    std::cout << "Element " << target << (found ? " found.\n" : " not found.\n");

    return 0;
}
```

**Output:**
```
Element 7 found.
```

### Example 2: Binary Search with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "date", "fig"};
    std::string target = "Cherry";

    // Case-insensitive comparison
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        return std::lexicographical_compare(a.begin(), a.end(),
                                            b.begin(), b.end(),
                                            [](char a, char b) {
                                                return tolower(a) < tolower(b);
                                            });
    };

    // Sort the vector using the comparator
    std::sort(vec.begin(), vec.end(), cmp);

    bool found = std::binary_search(vec.begin(), vec.end(), target, cmp);

    std::cout << "Element \"" << target << "\"" << (found ? " found.\n" : " not found.\n");

    return 0;
}
```

**Output:**
```
Element "Cherry" found.
```

### Example 3: Binary Search on Empty Range

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec;
    int target = 10;

    bool found = std::binary_search(vec.begin(), vec.end(), target);

    std::cout << "Element " << target << (found ? " found.\n" : " not found.\n");

    return 0;
}
```

**Output:**
```
Element 10 not found.
```

*Note: Binary search on an empty range always returns `false`.*

---

## 5. copy

### Description

`std::copy` copies elements from one range to another. It requires that the destination range has enough space to accommodate the copied elements.

### Example 1: Copying Elements Between Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {10, 20, 30, 40, 50};
    std::vector<int> destination(5);

    std::copy(source.begin(), source.end(), destination.begin());

    std::cout << "Destination Vector: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Destination Vector: 10 20 30 40 50 
```

### Example 2: Copying into an Array

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<char> source = {'a', 'b', 'c', 'd'};
    char destination[4];

    std::copy(source.begin(), source.end(), destination);

    std::cout << "Destination Array: ";
    for(auto c : destination)
        std::cout << c << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Destination Array: a b c d 
```

### Example 3: Overlapping Ranges (Using copy_backward)

*Note: Directly using `std::copy` with overlapping ranges may lead to undefined behavior. For overlapping ranges, `std::copy_backward` is preferred.*

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Shift elements to the right by one position
    std::copy(vec.begin(), vec.begin() + 4, vec.begin() + 1);
    
    std::cout << "Vector after copy (overlapping): ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after copy (overlapping): 1 1 2 3 4 
```

*Note: For overlapping copies where the destination is after the source, use `std::copy_backward` to avoid data corruption.*

---

## 6. copy_backward

### Description

`std::copy_backward` copies elements from one range to another in reverse order. It is useful when the source and destination ranges overlap, and the destination is positioned after the source.

### Example 1: Using copy_backward with Overlapping Ranges

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    // Shift elements to the right by two positions
    std::copy_backward(vec.begin(), vec.begin() + 4, vec.end());
    
    std::cout << "Vector after copy_backward: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after copy_backward: 1 2 1 2 3 4 
```

### Example 2: Copying Elements from Array to Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int source[] = {100, 200, 300, 400};
    std::vector<int> destination(4);

    std::copy_backward(source, source + 4, destination.end());

    std::cout << "Destination Vector: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Destination Vector: 100 200 300 400 
```

### Example 3: Avoiding Overlap with copy_backward

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<char> vec = {'a', 'b', 'c', 'd', 'e'};
    
    // Attempt to copy first three elements to last three positions using copy_backward
    std::copy_backward(vec.begin(), vec.begin() + 3, vec.end());
    
    std::cout << "Vector after copy_backward: ";
    for(auto c : vec)
        std::cout << c << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after copy_backward: a b a b c 
```

*Note: `std::copy_backward` handles overlapping ranges by copying from the end to the beginning, preventing data corruption.*

---

## 7. copy_if

### Description

`std::copy_if` copies elements from a source range to a destination only if they satisfy a specified predicate.

### Example 1: Copying Even Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5, 6};
    std::vector<int> destination;

    std::copy_if(source.begin(), source.end(), std::back_inserter(destination), [](int x) {
        return x % 2 == 0;
    });

    std::cout << "Even Numbers: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Even Numbers: 2 4 6 
```

### Example 2: Copying Words Longer Than 4 Characters

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> source = {"apple", "bat", "carrot", "dog", "elephant"};
    std::vector<std::string> destination;

    std::copy_if(source.begin(), source.end(), std::back_inserter(destination), [](const std::string &s) {
        return s.length() > 4;
    });

    std::cout << "Words longer than 4 characters: ";
    for(auto &word : destination)
        std::cout << word << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Words longer than 4 characters: apple carrot elephant 
```

### Example 3: Copying Non-Negative Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {-5, 3, -1, 7, 0, -2};
    std::vector<int> destination;

    std::copy_if(source.begin(), source.end(), std::back_inserter(destination), [](int x) {
        return x >= 0;
    });

    std::cout << "Non-negative Numbers: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Non-negative Numbers: 3 7 0 
```

---

## 8. copy_n

### Description

`std::copy_n` copies a specified number of elements from a source range to a destination.

### Example 1: Copying First Three Elements

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {10, 20, 30, 40, 50};
    std::vector<int> destination(3);

    std::copy_n(source.begin(), 3, destination.begin());

    std::cout << "Destination Vector: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Destination Vector: 10 20 30 
```

### Example 2: Copying Elements to an Array

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<char> source = {'x', 'y', 'z'};
    char destination[3];

    std::copy_n(source.begin(), 3, destination);

    std::cout << "Destination Array: ";
    for(auto c : destination)
        std::cout << c << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Destination Array: x y z 
```

### Example 3: Handling copy_n with Insufficient Elements

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {1, 2};
    std::vector<int> destination(5, 0);

    try {
        std::copy_n(source.begin(), 5, destination.begin());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    std::cout << "Destination Vector: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Exception: copy_n cannot copy more elements than available
Destination Vector: 1 2 0 0 0 
```

*Note: Attempting to copy more elements than available results in undefined behavior. Proper checks should be in place.*

---

## 9. count

### Description

`std::count` counts the number of elements in a range that are equal to a specified value.

### Example 1: Counting Occurrences of a Number

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int target = 2;

    int count = std::count(vec.begin(), vec.end(), target);

    std::cout << "Number " << target << " appears " << count << " times.\n";

    return 0;
}
```

**Output:**
```
Number 2 appears 3 times.
```

### Example 2: Counting Specific Characters in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string text = "hello world";
    char target = 'l';

    int count = std::count(text.begin(), text.end(), target);

    std::cout << "Character '" << target << "' appears " << count << " times.\n";

    return 0;
}
```

**Output:**
```
Character 'l' appears 3 times.
```

### Example 3: Counting Elements in an Array

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 5, 5, 5, 5};
    int target = 5;

    int count = std::count(std::begin(arr), std::end(arr), target);

    std::cout << "Number " << target << " appears " << count << " times in the array.\n";

    return 0;
}
```

**Output:**
```
Number 5 appears 5 times in the array.
```

---

## 10. count_if

### Description

`std::count_if` counts the number of elements in a range that satisfy a specified predicate.

### Example 1: Counting Even Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    int count = std::count_if(vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    });
    
    std::cout << "Number of even elements: " << count << "\n";
    
    return 0;
}
```

**Output:**
```
Number of even elements: 3
```

### Example 2: Counting Words Longer Than 4 Characters

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "bat", "carrot", "dog", "elephant"};
    
    int count = std::count_if(words.begin(), words.end(), [](const std::string &s) {
        return s.length() > 4;
    });
    
    std::cout << "Number of words longer than 4 characters: " << count << "\n";
    
    return 0;
}
```

**Output:**
```
Number of words longer than 4 characters: 3
```

### Example 3: Counting Negative Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = { -1, 2, -3, 4, -5, 6 };
    
    int count = std::count_if(vec.begin(), vec.end(), [](int x) {
        return x < 0;
    });
    
    std::cout << "Number of negative elements: " << count << "\n";
    
    return 0;
}
```

**Output:**
```
Number of negative elements: 3
```

---

## 11. equal

### Description

`std::equal` checks if two ranges are equal, meaning they have the same size and corresponding elements compare equal.

### Example 1: Comparing Two Vectors for Equality

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3, 4};
    std::vector<int> vec3 = {1, 2, 4, 3};
    
    bool isEqual1 = std::equal(vec1.begin(), vec1.end(), vec2.begin());
    bool isEqual2 = std::equal(vec1.begin(), vec1.end(), vec3.begin());
    
    std::cout << "vec1 and vec2 are " << (isEqual1 ? "equal.\n" : "not equal.\n");
    std::cout << "vec1 and vec3 are " << (isEqual2 ? "equal.\n" : "not equal.\n");
    
    return 0;
}
```

**Output:**
```
vec1 and vec2 are equal.
vec1 and vec3 are not equal.
```

### Example 2: Comparing Subranges with a Predicate

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

int main() {
    std::string s1 = "Hello";
    std::string s2 = "hello";
    
    bool isEqual = std::equal(s1.begin(), s1.end(), s2.begin(), [](char a, char b) {
        return std::tolower(a) == std::tolower(b);
    });
    
    std::cout << "s1 and s2 are " << (isEqual ? "equal (case-insensitive).\n" : "not equal.\n");
    
    return 0;
}
```

**Output:**
```
s1 and s2 are equal (case-insensitive).
```

### Example 3: Comparing Arrays

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr1[] = {10, 20, 30};
    int arr2[] = {10, 20, 30};
    int arr3[] = {10, 25, 30};
    
    bool isEqual1 = std::equal(std::begin(arr1), std::end(arr1), std::begin(arr2));
    bool isEqual2 = std::equal(std::begin(arr1), std::end(arr1), std::begin(arr3));
    
    std::cout << "arr1 and arr2 are " << (isEqual1 ? "equal.\n" : "not equal.\n");
    std::cout << "arr1 and arr3 are " << (isEqual2 ? "equal.\n" : "not equal.\n");
    
    return 0;
}
```

**Output:**
```
arr1 and arr2 are equal.
arr1 and arr3 are not equal.
```

---

## 12. equal_range

### Description

`std::equal_range` finds the subrange of elements equivalent to a given value in a sorted range. It returns a pair of iterators defining the lower and upper bounds of the range.

### Example 1: Finding Equal Range in a Sorted Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    auto range = std::equal_range(vec.begin(), vec.end(), target);

    int count = std::distance(range.first, range.second);

    std::cout << "Number " << target << " appears " << count << " times.\n";
    std::cout << "Positions: ";
    for(auto it = range.first; it != range.second; ++it)
        std::cout << std::distance(vec.begin(), it) << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Number 2 appears 3 times.
Positions: 1 2 3 
```

### Example 2: Using equal_range with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"Apple", "Banana", "Cherry", "Date", "Fig", "Grape"};
    std::string target = "cherry";

    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        return std::lexicographical_compare(a.begin(), a.end(),
                                            b.begin(), b.end(),
                                            [](char a, char b) {
                                                return tolower(a) < tolower(b);
                                            });
    };

    // Ensure the vector is sorted with the comparator
    std::sort(vec.begin(), vec.end(), cmp);

    auto range = std::equal_range(vec.begin(), vec.end(), target, cmp);

    if(range.first != range.second) {
        std::cout << "\"" << target << "\" found " << std::distance(range.first, range.second) << " times.\n";
    } else {
        std::cout << "\"" << target << "\" not found.\n";
    }

    return 0;
}
```

**Output:**
```
"cherry" found 1 times.
```

### Example 3: Finding Range in an Empty Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec;
    int target = 10;

    auto range = std::equal_range(vec.begin(), vec.end(), target);

    if(range.first == vec.end()) {
        std::cout << "No elements found in the empty vector.\n";
    }

    return 0;
}
```

**Output:**
```
No elements found in the empty vector.
```

*Note: For empty ranges, `equal_range` returns a pair of end iterators.*

---

## 13. fill

### Description

`std::fill` assigns a specified value to all elements in a range.

### Example 1: Filling a Vector with a Specific Value

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec(5);
    
    std::fill(vec.begin(), vec.end(), 42);
    
    std::cout << "Vector after fill: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after fill: 42 42 42 42 42 
```

### Example 2: Filling a Part of a Container

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Fill the middle three elements with 0
    std::fill(vec.begin() + 1, vec.begin() + 4, 0);
    
    std::cout << "Vector after partial fill: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after partial fill: 1 0 0 0 5 
```

### Example 3: Using fill with Arrays

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    
    std::fill(arr, arr + 6, -1);
    
    std::cout << "Array after fill: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Array after fill: -1 -1 -1 -1 -1 -1 
```

---

## 14. fill_n

### Description

`std::fill_n` assigns a specified value to the first `n` elements in a range, starting from a given iterator.

### Example 1: Filling First Three Elements of a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::fill_n(vec.begin(), 3, 99);
    
    std::cout << "Vector after fill_n: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after fill_n: 99 99 99 4 5 
```

### Example 2: Filling Elements in an Array

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    std::fill_n(arr + 2, 2, 0);
    
    std::cout << "Array after fill_n: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Array after fill_n: 10 20 0 0 50 
```

### Example 3: Using fill_n with Output Iterator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec(10, 1);
    
    // Fill first five elements with 5
    std::fill_n(vec.begin(), 5, 5);
    
    std::cout << "Vector after fill_n: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after fill_n: 5 5 5 5 5 1 1 1 1 1 
```

---

## 15. find

### Description

`std::find` searches for the first occurrence of a value in a range and returns an iterator to it. If the value is not found, it returns the end iterator.

### Example 1: Finding an Element in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    int target = 30;

    auto it = std::find(vec.begin(), vec.end(), target);

    if(it != vec.end()) {
        std::cout << "Element " << target << " found at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "Element " << target << " not found.\n";
    }

    return 0;
}
```

**Output:**
```
Element 30 found at position 2
```

### Example 2: Finding a Character in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string text = "Hello World";
    char target = 'W';

    auto it = std::find(text.begin(), text.end(), target);

    if(it != text.end()) {
        std::cout << "Character '" << target << "' found at position " << std::distance(text.begin(), it) << "\n";
    } else {
        std::cout << "Character '" << target << "' not found.\n";
    }

    return 0;
}
```

**Output:**
```
Character 'W' found at position 6
```

### Example 3: Finding an Element in an Array

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int target = 15;

    auto it = std::find(std::begin(arr), std::end(arr), target);

    if(it != std::end(arr)) {
        std::cout << "Element " << target << " found at index " << std::distance(std::begin(arr), it) << "\n";
    } else {
        std::cout << "Element " << target << " not found in the array.\n";
    }

    return 0;
}
```

**Output:**
```
Element 15 found at index 2
```

---

## 16. find_end

### Description

`std::find_end` searches for the last occurrence of a subrange within a larger range.

### Example 1: Finding the Last Subrange in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 1, 2, 3, 4};
    std::vector<int> sub = {1, 2, 3};

    auto it = std::find_end(vec.begin(), vec.end(), sub.begin(), sub.end());

    if(it != vec.end()) {
        std::cout << "Subrange found starting at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "Subrange not found.\n";
    }

    return 0;
}
```

**Output:**
```
Subrange found starting at position 3
```

### Example 2: Finding the Last Occurrence of a String Substring

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string text = "abcXYZabcXYZabc";
    std::string sub = "XYZabc";

    auto it = std::find_end(text.begin(), text.end(), sub.begin(), sub.end());

    if(it != text.end()) {
        std::cout << "Subrange \"" << sub << "\" found starting at position " << std::distance(text.begin(), it) << "\n";
    } else {
        std::cout << "Subrange \"" << sub << "\" not found.\n";
    }

    return 0;
}
```

**Output:**
```
Subrange "XYZabc" found starting at position 9
```

### Example 3: Finding the Last Single Element

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {4, 5, 6, 5, 4};
    int target = 5;

    auto it = std::find_end(vec.begin(), vec.end(), &target, &target + 1);

    if(it != vec.end()) {
        std::cout << "Last occurrence of " << target << " found at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "Element " << target << " not found.\n";
    }

    return 0;
}
```

**Output:**
```
Last occurrence of 5 found at position 3
```

---

## 17. find_first_of

### Description

`std::find_first_of` searches for the first element in the first range that matches any element in the second range.

### Example 1: Finding the First Common Element Between Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {10, 20, 30, 40, 50};
    std::vector<int> vec2 = {5, 15, 25, 35, 45, 30};

    auto it = std::find_first_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());

    if(it != vec1.end()) {
        std::cout << "First common element: " << *it << " at position " << std::distance(vec1.begin(), it) << "\n";
    } else {
        std::cout << "No common elements found.\n";
    }

    return 0;
}
```

**Output:**
```
First common element: 30 at position 2
```

### Example 2: Finding First Vowel in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
    std::string text = "rhythm education";
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    auto it = std::find_first_of(text.begin(), text.end(), vowels.begin(), vowels.end());

    if(it != text.end()) {
        std::cout << "First vowel '" << *it << "' found at position " << std::distance(text.begin(), it) << "\n";
    } else {
        std::cout << "No vowels found.\n";
    }

    return 0;
}
```

**Output:**
```
First vowel 'e' found at position 7
```

### Example 3: Finding Any Matching Character in Arrays

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<char, 5> arr1 = {'x', 'y', 'z', 'a', 'b'};
    std::array<char, 3> arr2 = {'a', 'b', 'c'};

    auto it = std::find_first_of(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());

    if(it != arr1.end()) {
        std::cout << "First matching character: '" << *it << "' at position " << std::distance(arr1.begin(), it) << "\n";
    } else {
        std::cout << "No matching characters found.\n";
    }

    return 0;
}
```

**Output:**
```
First matching character: 'a' at position 3
```

---

## 18. find_if

### Description

`std::find_if` searches for the first element in a range that satisfies a specified predicate.

### Example 1: Finding the First Odd Number

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {2, 4, 6, 7, 8, 10};
    
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) {
        return x % 2 != 0;
    });
    
    if(it != vec.end()) {
        std::cout << "First odd number: " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No odd numbers found.\n";
    }

    return 0;
}
```

**Output:**
```
First odd number: 7 at position 3
```

### Example 2: Finding the First Vowel in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string text = "bcdfghjklmnpqrstvwxyzAEIOU";
    
    auto it = std::find_if(text.begin(), text.end(), [](char c) {
        return std::isalpha(c) && std::strchr("AEIOUaeiou", c);
    });
    
    if(it != text.end()) {
        std::cout << "First vowel: '" << *it << "' at position " << std::distance(text.begin(), it) << "\n";
    } else {
        std::cout << "No vowels found.\n";
    }

    return 0;
}
```

**Output:**
```
First vowel: 'A' at position 21
```

### Example 3: Finding the First String Longer Than Three Characters

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"hi", "hello", "hey", "hola"};
    
    auto it = std::find_if(words.begin(), words.end(), [](const std::string &s) {
        return s.length() > 3;
    });
    
    if(it != words.end()) {
        std::cout << "First word longer than three characters: " << *it << "\n";
    } else {
        std::cout << "No words longer than three characters found.\n";
    }

    return 0;
}
```

**Output:**
```
First word longer than three characters: hello
```

---

## 19. find_if_not

### Description

`std::find_if_not` searches for the first element in a range that does **not** satisfy a specified predicate.

### Example 1: Finding the First Non-Even Number

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {2, 4, 6, 8, 9, 10};
    
    auto it = std::find_if_not(vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    });
    
    if(it != vec.end()) {
        std::cout << "First non-even number: " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "All numbers are even.\n";
    }

    return 0;
}
```

**Output:**
```
First non-even number: 9 at position 4
```

### Example 2: Finding the First Character That is Not a Digit

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string text = "12345abc678";
    
    auto it = std::find_if_not(text.begin(), text.end(), [](char c) {
        return std::isdigit(c);
    });
    
    if(it != text.end()) {
        std::cout << "First non-digit character: '" << *it << "' at position " << std::distance(text.begin(), it) << "\n";
    } else {
        std::cout << "All characters are digits.\n";
    }

    return 0;
}
```

**Output:**
```
First non-digit character: 'a' at position 5
```

### Example 3: Finding the First String Not Starting with 'A'

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names = {"Alice", "Aaron", "Bob", "Amanda", "Charlie"};
    
    auto it = std::find_if_not(names.begin(), names.end(), [](const std::string &s) {
        return !s.empty() && s[0] == 'A';
    });
    
    if(it != names.end()) {
        std::cout << "First name not starting with 'A': " << *it << "\n";
    } else {
        std::cout << "All names start with 'A'.\n";
    }

    return 0;
}
```

**Output:**
```
First name not starting with 'A': Bob
```

---

## 20. for_each

### Description

`std::for_each` applies a specified function to each element in a range.

### Example 1: Printing Elements of a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    std::cout << "Vector elements: ";
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector elements: 10 20 30 40 50 
```

### Example 2: Modifying Elements In-Place

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::for_each(vec.begin(), vec.end(), [](int &x) {
        x *= 2;
    });
    
    std::cout << "Vector after doubling: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after doubling: 2 4 6 8 10 
```

### Example 3: Applying a Function to a List

```cpp
#include <iostream>
#include <algorithm>
#include <list>

int main() {
    std::list<std::string> names = {"Alice", "Bob", "Charlie"};
    
    std::cout << "Names in uppercase: ";
    std::for_each(names.begin(), names.end(), [](std::string &s) {
        for(auto &c : s)
            c = toupper(c);
        std::cout << s << " ";
    });
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Names in uppercase: ALICE BOB CHARLIE 
```

---

## 21. generate

### Description

`std::generate` assigns values to elements in a range by invoking a generator function for each element.

### Example 1: Filling a Vector with Random Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<int> vec(5);
    std::srand(std::time(0)); // Seed for randomness

    std::generate(vec.begin(), vec.end(), []() -> int {
        return std::rand() % 100;
    });

    std::cout << "Random Numbers: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Random Numbers: 83 86 77 15 93 
```

*Note: The actual numbers will vary each run.*

### Example 2: Generating a Sequence of Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec(5);
    int current = 1;

    std::generate(vec.begin(), vec.end(), [&current]() -> int {
        return current++;
    });

    std::cout << "Sequential Numbers: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Sequential Numbers: 1 2 3 4 5 
```

### Example 3: Generating Fibonacci Sequence

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> fib(10);
    int a = 0, b = 1;

    std::generate(fib.begin(), fib.end(), [&a, &b]() -> int {
        int next = a + b;
        a = b;
        b = next;
        return a;
    });

    std::cout << "Fibonacci Sequence: ";
    for(auto num : fib)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Fibonacci Sequence: 1 1 2 3 5 8 13 21 34 55 
```

---

## 22. generate_n

### Description

`std::generate_n` assigns values to the first `n` elements in a range by invoking a generator function.

### Example 1: Generating First Five Even Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec(5);
    int current = 2;

    std::generate_n(vec.begin(), 5, [&current]() -> int {
        int val = current;
        current += 2;
        return val;
    });

    std::cout << "First Five Even Numbers: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
First Five Even Numbers: 2 4 6 8 10 
```

### Example 2: Generating Random Characters

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<char> vec(5);
    std::srand(std::time(0)); // Seed for randomness

    std::generate_n(vec.begin(), 5, []() -> char {
        return 'A' + (std::rand() % 26);
    });

    std::cout << "Random Characters: ";
    for(auto c : vec)
        std::cout << c << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Random Characters: G Q M B Z 
```

*Note: The actual characters will vary each run.*

### Example 3: Filling an Array with Incrementing Values

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr[5];
    int current = 10;

    std::generate_n(arr, 5, [&current]() -> int {
        return current += 5;
    });

    std::cout << "Array after generate_n: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Array after generate_n: 15 20 25 30 35 
```

---

## 23. includes

### Description

`std::includes` checks if all elements of one sorted range are contained within another sorted range.

### Example 1: Checking Subset in Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> large = {1, 2, 3, 4, 5, 6};
    std::vector<int> small = {2, 4, 6};

    bool isIncluded = std::includes(large.begin(), large.end(), small.begin(), small.end());

    std::cout << "All elements of small are in large: " << (isIncluded ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
All elements of small are in large: Yes
```

### Example 2: Using Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> large = {"Apple", "Banana", "Cherry", "Date"};
    std::vector<std::string> small = {"apple", "banana"};

    // Case-insensitive comparison
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a;
        std::string lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };

    // Sort both vectors with the comparator
    std::sort(large.begin(), large.end(), cmp);
    std::sort(small.begin(), small.end(), cmp);

    bool isIncluded = std::includes(large.begin(), large.end(), small.begin(), small.end(), cmp);

    std::cout << "All elements of small are in large (case-insensitive): " << (isIncluded ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
All elements of small are in large (case-insensitive): Yes
```

### Example 3: Checking Subset with Non-Included Elements

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> large = {10, 20, 30, 40, 50};
    std::vector<int> small = {20, 60};

    bool isIncluded = std::includes(large.begin(), large.end(), small.begin(), small.end());

    std::cout << "All elements of small are in large: " << (isIncluded ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
All elements of small are in large: No
```

---

## 24. inplace_merge

### Description

`std::inplace_merge` merges two consecutive sorted ranges into a single sorted range in-place.

### Example 1: Merging Two Sorted Halves of a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 2, 4, 6, 8};
    
    // Merge the first half and the second half
    std::inplace_merge(vec.begin(), vec.begin() + 4, vec.end());
    
    std::cout << "Vector after inplace_merge: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after inplace_merge: 1 2 3 4 5 6 7 8 
```

### Example 2: Merging Two Sorted Subarrays in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {1, 4, 5, 2, 3, 6};
    
    // Merge first three and last three elements
    std::inplace_merge(arr.begin(), arr.begin() + 3, arr.end());
    
    std::cout << "Array after inplace_merge: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Array after inplace_merge: 1 2 3 4 5 6 
```

### Example 3: Merging with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"Apple", "Cherry", "Date", "banana", "fig", "grape"};
    
    // Sort first and second halves
    std::sort(vec.begin(), vec.begin() + 3, [](const std::string &a, const std::string &b) {
        return a < b;
    });
    std::sort(vec.begin() + 3, vec.end(), [](const std::string &a, const std::string &b) {
        return a < b;
    });
    
    // Merge with case-insensitive comparator
    std::inplace_merge(vec.begin(), vec.begin() + 3, vec.end(), [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a;
        std::string lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    });
    
    std::cout << "Vector after inplace_merge: ";
    for(auto &s : vec)
        std::cout << s << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Vector after inplace_merge: Apple banana Cherry Date fig grape 
```

*Note: The custom comparator ensures case-insensitive merging.*

---

## 25. is_heap

### Description

`std::is_heap` checks if a range satisfies the heap property, meaning each parent node is greater than or equal to its child nodes (max-heap).

### Example 1: Checking a Max-Heap in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap = {50, 30, 40, 10, 20};
    
    bool result = std::is_heap(heap.begin(), heap.end());
    
    std::cout << "The vector is " << (result ? "a heap.\n" : "not a heap.\n");
    
    return 0;
}
```

**Output:**
```
The vector is a heap.
```

### Example 2: Checking a Non-Heap Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    bool result = std::is_heap(vec.begin(), vec.end());
    
    std::cout << "The vector is " << (result ? "a heap.\n" : "not a heap.\n");
    
    return 0;
}
```

**Output:**
```
The vector is not a heap.
```

### Example 3: Using Custom Comparator for Heap Check

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> heap = {"delta", "beta", "gamma", "alpha"};
    
    // Max-heap based on string length
    bool result = std::is_heap(heap.begin(), heap.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length(); // Greater lengths have higher priority
    });
    
    std::cout << "The vector is " << (result ? "a heap based on string length.\n" : "not a heap based on string length.\n");
    
    return 0;
}
```

**Output:**
```
The vector is a heap based on string length.
```

---

## 26. is_heap_until

### Description

`std::is_heap_until` returns an iterator to the first element in the range that violates the heap property.

### Example 1: Finding the Violation Point in a Heap

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap = {50, 30, 40, 10, 20};
    
    auto it = std::is_heap_until(heap.begin(), heap.end());
    
    if(it == heap.end()) {
        std::cout << "The entire range is a heap.\n";
    } else {
        std::cout << "Heap property violated at position " << std::distance(heap.begin(), it) << ", value: " << *it << "\n";
    }

    // Introduce a violation
    heap[3] = 60;
    
    it = std::is_heap_until(heap.begin(), heap.end());
    
    if(it == heap.end()) {
        std::cout << "The entire range is a heap.\n";
    } else {
        std::cout << "Heap property violated at position " << std::distance(heap.begin(), it) << ", value: " << *it << "\n";
    }

    return 0;
}
```

**Output:**
```
The entire range is a heap.
Heap property violated at position 3, value: 60
```

### Example 2: Using Custom Comparator with is_heap_until

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> heap = {"delta", "beta", "gamma", "alpha"};
    
    // Max-heap based on string length
    auto it = std::is_heap_until(heap.begin(), heap.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length();
    });
    
    if(it == heap.end()) {
        std::cout << "The entire range is a heap based on string length.\n";
    } else {
        std::cout << "Heap property violated at position " << std::distance(heap.begin(), it) << ", value: " << *it << "\n";
    }

    // Introduce a violation
    heap[2] = "a";
    
    it = std::is_heap_until(heap.begin(), heap.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length();
    });
    
    if(it == heap.end()) {
        std::cout << "The entire range is a heap based on string length.\n";
    } else {
        std::cout << "Heap property violated at position " << std::distance(heap.begin(), it) << ", value: " << *it << "\n";
    }

    return 0;
}
```

**Output:**
```
The entire range is a heap based on string length.
Heap property violated at position 2, value: a
```

### Example 3: Checking Heap Property in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {100, 50, 70, 20, 30, 60};
    
    auto it = std::is_heap_until(arr.begin(), arr.end());
    
    if(it == arr.end()) {
        std::cout << "The entire array is a heap.\n";
    } else {
        std::cout << "Heap property violated at index " << std::distance(arr.begin(), it) << ", value: " << *it << "\n";
    }
    
    return 0;
}
```

**Output:**
```
Heap property violated at index 4, value: 30
```

*Explanation: In the array `{100, 50, 70, 20, 30, 60}`, the heap property is violated at index 4 where `30` is less than its parent `50`.*

---

## 27. is_partitioned

### Description

`std::is_partitioned` checks if a range is partitioned based on a predicate, meaning all elements satisfying the predicate come before those that do not.

### Example 1: Checking if Vector is Partitioned by Even Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {2, 4, 6, 1, 3, 5};
    std::vector<int> vec2 = {2, 4, 6, 8, 10};
    
    auto isEven = [](int x) -> bool {
        return x % 2 == 0;
    };
    
    bool partitioned1 = std::is_partitioned(vec1.begin(), vec1.end(), isEven);
    bool partitioned2 = std::is_partitioned(vec2.begin(), vec2.end(), isEven);
    
    std::cout << "vec1 is " << (partitioned1 ? "partitioned." : "not partitioned.") << "\n";
    std::cout << "vec2 is " << (partitioned2 ? "partitioned." : "not partitioned.") << "\n";
    
    return 0;
}
```

**Output:**
```
vec1 is not partitioned.
vec2 is partitioned.
```

### Example 2: Checking if Strings are Partitioned by Length

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec1 = {"short", "tiny", "longer", "lengthy"};
    std::vector<std::string> vec2 = {"short", "longer", "tiny", "lengthy"};
    
    auto isShort = [](const std::string &s) -> bool {
        return s.length() <= 5;
    };
    
    bool partitioned1 = std::is_partitioned(vec1.begin(), vec1.end(), isShort);
    bool partitioned2 = std::is_partitioned(vec2.begin(), vec2.end(), isShort);
    
    std::cout << "vec1 is " << (partitioned1 ? "partitioned." : "not partitioned.") << "\n";
    std::cout << "vec2 is " << (partitioned2 ? "partitioned." : "not partitioned.") << "\n";
    
    return 0;
}
```

**Output:**
```
vec1 is partitioned.
vec2 is not partitioned.
```

### Example 3: Checking if Array is Partitioned by Greater Than 10

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 7> arr1 = {15, 20, 25, 5, 10, 30, 35};
    std::array<int, 7> arr2 = {15, 5, 20, 25, 10, 30, 35};
    
    auto greaterThanTen = [](int x) -> bool {
        return x > 10;
    };
    
    bool partitioned1 = std::is_partitioned(arr1.begin(), arr1.end(), greaterThanTen);
    bool partitioned2 = std::is_partitioned(arr2.begin(), arr2.end(), greaterThanTen);
    
    std::cout << "arr1 is " << (partitioned1 ? "partitioned." : "not partitioned.") << "\n";
    std::cout << "arr2 is " << (partitioned2 ? "partitioned." : "not partitioned.") << "\n";
    
    return 0;
}
```

**Output:**
```
arr1 is partitioned.
arr2 is not partitioned.
```

---

## 28. is_permutation

### Description

`std::is_permutation` checks if two ranges are permutations of each other, meaning they contain the same elements with the same frequencies, possibly in different orders.

### Example 1: Checking if Two Vectors are Permutations

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 4, 3, 2, 1};
    std::vector<int> vec3 = {1, 2, 2, 4, 5};
    
    bool perm1 = std::is_permutation(vec1.begin(), vec1.end(), vec2.begin());
    bool perm2 = std::is_permutation(vec1.begin(), vec1.end(), vec3.begin());
    
    std::cout << "vec1 and vec2 are " << (perm1 ? "permutations.\n" : "not permutations.\n");
    std::cout << "vec1 and vec3 are " << (perm2 ? "permutations.\n" : "not permutations.\n");
    
    return 0;
}
```

**Output:**
```
vec1 and vec2 are permutations.
vec1 and vec3 are not permutations.
```

### Example 2: Permutation Check with Different Sizes

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<char> vec1 = {'a', 'b', 'c'};
    std::vector<char> vec2 = {'c', 'b', 'a', 'd'};
    
    bool perm = std::is_permutation(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    
    std::cout << "vec1 and vec2 are " << (perm ? "permutations.\n" : "not permutations.\n");
    
    return 0;
}
```

**Output:**
```
vec1 and vec2 are not permutations.
```

### Example 3: Checking Permutation with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::string s1 = "Listen";
    std::string s2 = "Silent";
    
    // Case-insensitive comparison
    auto cmp = [](char a, char b) -> bool {
        return tolower(a) == tolower(b);
    };
    
    bool perm = std::is_permutation(s1.begin(), s1.end(), s2.begin(), s2.end(), cmp);
    
    std::cout << "\"" << s1 << "\" and \"" << s2 << "\" are " << (perm ? "" : "not ") << "permutations (case-insensitive).\n";
    
    return 0;
}
```

**Output:**
```
"Listen" and "Silent" are permutations (case-insensitive).
```

---

## 29. is_sorted

### Description

`std::is_sorted` checks if a range is sorted in non-descending order (default) or according to a specified comparator.

### Example 1: Checking if a Vector is Sorted in Ascending Order

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 3, 2, 4, 5};
    
    bool sorted1 = std::is_sorted(vec1.begin(), vec1.end());
    bool sorted2 = std::is_sorted(vec2.begin(), vec2.end());
    
    std::cout << "vec1 is " << (sorted1 ? "sorted.\n" : "not sorted.\n");
    std::cout << "vec2 is " << (sorted2 ? "sorted.\n" : "not sorted.\n");
    
    return 0;
}
```

**Output:**
```
vec1 is sorted.
vec2 is not sorted.
```

### Example 2: Checking if a List is Sorted in Descending Order

```cpp
#include <iostream>
#include <algorithm>
#include <list>

int main() {
    std::list<int> lst1 = {5, 4, 3, 2, 1};
    std::list<int> lst2 = {5, 3, 4, 2, 1};
    
    bool sorted1 = std::is_sorted(lst1.begin(), lst1.end(), std::greater<int>());
    bool sorted2 = std::is_sorted(lst2.begin(), lst2.end(), std::greater<int>());
    
    std::cout << "lst1 is " << (sorted1 ? "sorted in descending order.\n" : "not sorted in descending order.\n");
    std::cout << "lst2 is " << (sorted2 ? "sorted in descending order.\n" : "not sorted in descending order.\n");
    
    return 0;
}
```

**Output:**
```
lst1 is sorted in descending order.
lst2 is not sorted in descending order.
```

### Example 3: Checking if an Array is Sorted with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

int main() {
    std::array<std::string, 4> arr = {"apple", "banana", "Cherry", "date"};
    
    // Case-insensitive ascending order
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    bool sorted = std::is_sorted(arr.begin(), arr.end(), cmp);
    
    std::cout << "Array is " << (sorted ? "" : "not ") << "sorted (case-insensitive ascending).\n";
    
    return 0;
}
```

**Output:**
```
Array is sorted (case-insensitive ascending).
```

---

## 30. is_sorted_until

### Description

`std::is_sorted_until` finds the first position in a range where the sorting property is violated and returns an iterator to that position.

### Example 1: Finding the Point Where a Vector Stops Being Sorted

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 5, 4, 6, 7};
    
    auto it = std::is_sorted_until(vec.begin(), vec.end());
    
    if(it != vec.end()) {
        std::cout << "Vector stops being sorted at position " << std::distance(vec.begin(), it) << ", value: " << *it << "\n";
    } else {
        std::cout << "The entire vector is sorted.\n";
    }

    return 0;
}
```

**Output:**
```
Vector stops being sorted at position 4, value: 4
```

### Example 2: Using is_sorted_until with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"Apple", "banana", "Cherry", "date", "Elderberry", "fig"};
    
    // Case-insensitive ascending order
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    auto it = std::is_sorted_until(vec.begin(), vec.end(), cmp);
    
    if(it != vec.end()) {
        std::cout << "Vector stops being sorted at position " << std::distance(vec.begin(), it) << ", value: " << *it << "\n";
    } else {
        std::cout << "The entire vector is sorted (case-insensitive).\n";
    }

    return 0;
}
```

**Output:**
```
Vector stops being sorted at position 3, value: date
```

### Example 3: Checking if an Array is Fully Sorted

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 3, 2, 4, 5};
    
    auto it1 = std::is_sorted_until(arr1.begin(), arr1.end());
    auto it2 = std::is_sorted_until(arr2.begin(), arr2.end());
    
    std::cout << "arr1 is " << ((it1 == arr1.end()) ? "" : "not ") << "fully sorted.\n";
    std::cout << "arr2 is " << ((it2 == arr2.end()) ? "" : "not ") << "fully sorted.\n";
    
    return 0;
}
```

**Output:**
```
arr1 is fully sorted.
arr2 is not fully sorted.
```

---

## 31. iter_swap

### Description

`std::iter_swap` swaps the values pointed to by two iterators.

### Example 1: Swapping Elements in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::cout << "Before iter_swap: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    std::iter_swap(vec.begin(), vec.begin() + 4); // Swap first and last elements
    
    std::cout << "After iter_swap: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Before iter_swap: 1 2 3 4 5 
After iter_swap: 5 2 3 4 1 
```

### Example 2: Swapping Characters in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string text = "abcdef";
    
    std::cout << "Before iter_swap: " << text << "\n";
    
    std::iter_swap(text.begin() + 1, text.begin() + 4); // Swap 'b' and 'e'
    
    std::cout << "After iter_swap: " << text << "\n";

    return 0;
}
```

**Output:**
```
Before iter_swap: abcdef
After iter_swap: aebcdf
```

### Example 3: Swapping Elements in Arrays

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 3> arr1 = {10, 20, 30};
    std::array<int, 3> arr2 = {40, 50, 60};
    
    std::cout << "Before iter_swap:\n";
    std::cout << "arr1: ";
    for(auto num : arr1)
        std::cout << num << " ";
    std::cout << "\narr2: ";
    for(auto num : arr2)
        std::cout << num << " ";
    std::cout << "\n";
    
    std::iter_swap(arr1.begin() + 1, arr2.begin() + 2); // Swap 20 and 60
    
    std::cout << "After iter_swap:\n";
    std::cout << "arr1: ";
    for(auto num : arr1)
        std::cout << num << " ";
    std::cout << "\narr2: ";
    for(auto num : arr2)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Before iter_swap:
arr1: 10 20 30 
arr2: 40 50 60 
After iter_swap:
arr1: 10 60 30 
arr2: 40 50 20 
```

---

## 32. lexicographical_compare

### Description

`std::lexicographical_compare` compares two ranges lexicographically (dictionary order). It returns `true` if the first range is lexicographically less than the second.

### Example 1: Comparing Two Strings

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s1 = "apple";
    std::string s2 = "banana";
    
    bool result = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
    
    std::cout << "\"" << s1 << "\" is " << (result ? "less than" : "not less than") << " \"" << s2 << "\".\n";
    
    return 0;
}
```

**Output:**
```
"apple" is less than "banana".
```

### Example 2: Comparing Numerical Ranges

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3, 5};
    
    bool result = std::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    
    std::cout << "vec1 is " << (result ? "lexicographically less than" : "not lexicographically less than") << " vec2.\n";
    
    return 0;
}
```

**Output:**
```
vec1 is lexicographically less than vec2.
```

### Example 3: Using Custom Comparator for Reverse Order

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {5, 4, 3};
    std::vector<int> vec2 = {5, 4, 2};
    
    // Compare in reverse order
    bool result = std::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
                                               [](int a, int b) -> bool {
                                                   return a > b; // Reverse comparison
                                               });
    
    std::cout << "vec1 is " << (result ? "lexicographically greater than" : "not lexicographically greater than") << " vec2.\n";
    
    return 0;
}
```

**Output:**
```
vec1 is lexicographically greater than vec2.
```

---

## 33. lower_bound

### Description

`std::lower_bound` finds the first position in a sorted range where a value can be inserted without violating the order. It returns an iterator to the first element not less than the target.

### Example 1: Finding Insertion Point in a Sorted Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    int target = 35;

    auto it = std::lower_bound(vec.begin(), vec.end(), target);

    if(it != vec.end()) {
        std::cout << "Lower bound for " << target << " is " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No lower bound found; " << target << " is greater than all elements.\n";
    }

    return 0;
}
```

**Output:**
```
Lower bound for 35 is 40 at position 3
```

### Example 2: Using Custom Comparator with lower_bound

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "date"};
    std::string target = "blueberry";
    
    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    auto it = std::lower_bound(vec.begin(), vec.end(), target, cmp);
    
    if(it != vec.end()) {
        std::cout << "Lower bound for \"" << target << "\" is \"" << *it << "\" at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No lower bound found for \"" << target << "\".\n";
    }

    return 0;
}
```

**Output:**
```
Lower bound for "blueberry" is "banana" at position 1
```

### Example 3: Finding Lower Bound in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 5> arr = {5, 10, 15, 20, 25};
    int target = 15;

    auto it = std::lower_bound(arr.begin(), arr.end(), target);

    if(it != arr.end()) {
        std::cout << "Lower bound for " << target << " is " << *it << " at index " << std::distance(arr.begin(), it) << "\n";
    } else {
        std::cout << "No lower bound found; " << target << " is greater than all elements.\n";
    }

    return 0;
}
```

**Output:**
```
Lower bound for 15 is 15 at index 2
```

*Note: If the target exists, `lower_bound` points to its first occurrence.*





## 35. max_element

### Description

`std::max_element` finds the largest element in a range. It returns an iterator to the first occurrence of the maximum element.

### Example 1: Finding the Maximum Element in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    auto it = std::max_element(vec.begin(), vec.end());
    
    if(it != vec.end()) {
        std::cout << "Maximum element: " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Maximum element: 50 at position 4
```

### Example 2: Using Custom Comparator to Find Minimum Element

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 5, 50};
    
    // Using std::max_element with a comparator to find the minimum element
    auto it = std::max_element(vec.begin(), vec.end(), [](int a, int b) -> bool {
        return a < b; // Reverse logic to find minimum
    });
    
    if(it != vec.end()) {
        std::cout << "Minimum element: " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Minimum element: 5 at position 3
```

### Example 3: Finding Maximum Element in an Array of Strings by Length

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

int main() {
    std::array<std::string, 5> arr = {"apple", "banana", "cherry", "date", "elderberry"};
    
    auto it = std::max_element(arr.begin(), arr.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length();
    });
    
    if(it != arr.end()) {
        std::cout << "Longest string: " << *it << " with length " << it->length() << "\n";
    } else {
        std::cout << "Array is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Longest string: elderberry with length 10
```

---

## 36. merge

### Description

`std::merge` combines two sorted ranges into a single sorted range. The resulting range is sorted according to the same comparison used for the input ranges.

### Example 1: Merging Two Sorted Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8};
    std::vector<int> merged(vec1.size() + vec2.size());
    
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin());
    
    std::cout << "Merged Vector: ";
    for(auto num : merged)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Merged Vector: 1 2 3 4 5 6 7 8 
```

### Example 2: Merging with Custom Comparator (Descending Order)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {10, 8, 6, 4};
    std::vector<int> vec2 = {9, 7, 5, 3};
    std::vector<int> merged(vec1.size() + vec2.size());
    
    // Merging in descending order
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin(), [](int a, int b) -> bool {
        return a > b;
    });
    
    std::cout << "Merged Vector (Descending): ";
    for(auto num : merged)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Merged Vector (Descending): 10 9 8 7 6 5 4 3 
```

### Example 3: Merging Strings Alphabetically

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec1 = {"apple", "banana", "cherry"};
    std::vector<std::string> vec2 = {"avocado", "blueberry", "citrus"};
    std::vector<std::string> merged(vec1.size() + vec2.size());
    
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin());
    
    std::cout << "Merged Strings: ";
    for(auto &s : merged)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Merged Strings: apple avocado banana blueberry cherry citrus 
```

---

## 37. min

### Description

`std::min` returns the smaller of two given values. It can also be used with a custom comparator.

### Example 1: Finding Minimum of Two Integers

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int a = 10;
    int b = 20;
    
    int minimum = std::min(a, b);
    
    std::cout << "Minimum between " << a << " and " << b << " is " << minimum << "\n";
    
    return 0;
}
```

**Output:**
```
Minimum between 10 and 20 is 10
```

### Example 2: Finding Minimum with Custom Comparator (Absolute Value)

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    int a = -15;
    int b = 10;
    
    // Compare based on absolute values
    int minimum = std::min(a, b, [](int x, int y) -> bool {
        return std::abs(x) < std::abs(y);
    });
    
    std::cout << "Minimum based on absolute values between " << a << " and " << b << " is " << minimum << "\n";
    
    return 0;
}
```

**Output:**
```
Minimum based on absolute values between -15 and 10 is 10
```

### Example 3: Finding Minimum of Two Strings Lexicographically

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s1 = "apple";
    std::string s2 = "banana";
    
    std::string minimum = std::min(s1, s2);
    
    std::cout << "Lexicographical minimum between \"" << s1 << "\" and \"" << s2 << "\" is \"" << minimum << "\".\n";
    
    return 0;
}
```

**Output:**
```
Lexicographical minimum between "apple" and "banana" is "apple".
```

---

## 38. min_element

### Description

`std::min_element` finds the smallest element in a range. It returns an iterator to the first occurrence of the minimum element.

### Example 1: Finding the Minimum Element in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {50, 20, 30, 10, 40};
    
    auto it = std::min_element(vec.begin(), vec.end());
    
    if(it != vec.end()) {
        std::cout << "Minimum element: " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Minimum element: 10 at position 3
```

### Example 2: Finding Minimum Element with Custom Comparator (String Length)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "kiwi", "banana", "fig", "cherry"};
    
    auto it = std::min_element(vec.begin(), vec.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length();
    });
    
    if(it != vec.end()) {
        std::cout << "Shortest string: " << *it << " with length " << it->length() << "\n";
    } else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Shortest string: fig with length 3
```

### Example 3: Finding Minimum Element in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {15, 22, 8, 19, 8, 30};
    
    auto it = std::min_element(arr.begin(), arr.end());
    
    if(it != arr.end()) {
        std::cout << "Minimum element: " << *it << " at index " << std::distance(arr.begin(), it) << "\n";
    } else {
        std::cout << "Array is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Minimum element: 8 at index 2
```

---

## 39. minmax

### Description

`std::minmax` returns a `std::pair` containing the smaller and larger of two given values. It can also be used with a custom comparator.

### Example 1: Finding Minimum and Maximum of Two Integers

```cpp
#include <iostream>
#include <algorithm>
#include <utility>

int main() {
    int a = 25;
    int b = 15;
    
    auto result = std::minmax(a, b);
    
    std::cout << "Minimum: " << result.first << ", Maximum: " << result.second << "\n";
    
    return 0;
}
```

**Output:**
```
Minimum: 15, Maximum: 25
```

### Example 2: Using Custom Comparator to Find Maximum Based on Absolute Value

```cpp
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

int main() {
    int a = -20;
    int b = 15;
    
    auto result = std::minmax(a, b, [](int x, int y) -> bool {
        return std::abs(x) < std::abs(y);
    });
    
    std::cout << "Minimum based on absolute value: " << result.first 
              << ", Maximum based on absolute value: " << result.second << "\n";
    
    return 0;
}
```

**Output:**
```
Minimum based on absolute value: 15, Maximum based on absolute value: -20
```

### Example 3: Finding min and max of Two Strings Lexicographically

```cpp
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

int main() {
    std::string s1 = "apple";
    std::string s2 = "banana";
    
    auto result = std::minmax(s1, s2);
    
    std::cout << "Lexicographical Minimum: " << result.first 
              << ", Lexicographical Maximum: " << result.second << "\n";
    
    return 0;
}
```

**Output:**
```
Lexicographical Minimum: apple, Lexicographical Maximum: banana
```

---

## 40. minmax_element

### Description

`std::minmax_element` finds both the smallest and largest elements in a range. It returns a `std::pair` of iterators to the minimum and maximum elements.

### Example 1: Finding Minimum and Maximum Elements in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {40, 10, 30, 20, 50};
    
    auto result = std::minmax_element(vec.begin(), vec.end());
    
    if(result.first != vec.end() && result.second != vec.end()) {
        std::cout << "Minimum element: " << *result.first << " at position " << std::distance(vec.begin(), result.first) << "\n";
        std::cout << "Maximum element: " << *result.second << " at position " << std::distance(vec.begin(), result.second) << "\n";
    } else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Minimum element: 10 at position 1
Maximum element: 50 at position 4
```

### Example 2: Using Custom Comparator to Find min and max by String Length

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "kiwi", "banana", "fig", "cherry"};
    
    auto result = std::minmax_element(vec.begin(), vec.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length();
    });
    
    if(result.first != vec.end() && result.second != vec.end()) {
        std::cout << "Shortest string: " << *result.first << " with length " << result.first->length() << "\n";
        std::cout << "Longest string: " << *result.second << " with length " << result.second->length() << "\n";
    } else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Shortest string: fig with length 3
Longest string: banana with length 6
```

### Example 3: Finding min and max in an Array of Doubles

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<double, 6> arr = {3.14, 2.71, 1.41, 1.73, 2.58, 3.00};
    
    auto result = std::minmax_element(arr.begin(), arr.end());
    
    if(result.first != arr.end() && result.second != arr.end()) {
        std::cout << "Minimum element: " << *result.first << " at index " << std::distance(arr.begin(), result.first) << "\n";
        std::cout << "Maximum element: " << *result.second << " at index " << std::distance(arr.begin(), result.second) << "\n";
    } else {
        std::cout << "Array is empty.\n";
    }

    return 0;
}
```

**Output:**
```
Minimum element: 1.41 at index 2
Maximum element: 3.14 at index 0
```

---

## 41. mismatch

### Description

`std::mismatch` compares two ranges and finds the first position where the elements differ. It returns a pair of iterators to the mismatching elements.

### Example 1: Finding Mismatch Between Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 4, 4, 5};
    
    auto result = std::mismatch(vec1.begin(), vec1.end(), vec2.begin());
    
    if(result.first != vec1.end()) {
        std::cout << "Mismatch at position " << std::distance(vec1.begin(), result.first) 
                  << ": " << *result.first << " vs " << *result.second << "\n";
    } else {
        std::cout << "No mismatches found. The ranges are identical.\n";
    }

    return 0;
}
```

**Output:**
```
Mismatch at position 2: 3 vs 4
```

### Example 2: Using Custom Comparator to Find Mismatch Case-Insensitive

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::string s1 = "HelloWorld";
    std::string s2 = "helloworld";
    
    auto result = std::mismatch(s1.begin(), s1.end(), s2.begin(), [](char a, char b) -> bool {
        return std::tolower(a) == std::tolower(b);
    });
    
    if(result.first != s1.end()) {
        std::cout << "Mismatch at position " << std::distance(s1.begin(), result.first) 
                  << ": '" << *result.first << "' vs '" << *result.second << "'\n";
    } else {
        std::cout << "No mismatches found (case-insensitive).\n";
    }

    return 0;
}
```

**Output:**
```
No mismatches found (case-insensitive).
```

### Example 3: Finding Mismatch in Arrays

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<char, 5> arr1 = {'a', 'b', 'c', 'd', 'e'};
    std::array<char, 5> arr2 = {'a', 'b', 'x', 'd', 'e'};
    
    auto result = std::mismatch(arr1.begin(), arr1.end(), arr2.begin());
    
    if(result.first != arr1.end()) {
        std::cout << "Mismatch at index " << std::distance(arr1.begin(), result.first) 
                  << ": '" << *result.first << "' vs '" << *result.second << "'\n";
    } else {
        std::cout << "No mismatches found. The arrays are identical.\n";
    }

    return 0;
}
```

**Output:**
```
Mismatch at index 2: 'c' vs 'x'
```

---

## 42. move

### Description

`std::move` moves elements from one range to another using move semantics. It efficiently transfers resources from source to destination without copying.

### Example 1: Moving Elements Between Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::vector<std::string> source = {"apple", "banana", "cherry"};
    std::vector<std::string> destination;
    
    std::move(source.begin(), source.end(), std::back_inserter(destination));
    
    std::cout << "Source Vector after move: ";
    for(auto &s : source)
        std::cout << "\"" << s << "\" ";
    std::cout << "\nDestination Vector: ";
    for(auto &s : destination)
        std::cout << "\"" << s << "\" ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Source Vector after move: "" "" "" 
Destination Vector: "apple" "banana" "cherry" 
```

*Note: After moving, the source elements are in a valid but unspecified state (often empty for standard containers).*

### Example 2: Moving Elements into an Array

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

int main() {
    std::vector<std::string> source = {"dog", "cat", "bird"};
    std::array<std::string, 3> destination;
    
    std::move(source.begin(), source.end(), destination.begin());
    
    std::cout << "Source Vector after move: ";
    for(auto &s : source)
        std::cout << "\"" << s << "\" ";
    std::cout << "\nDestination Array: ";
    for(auto &s : destination)
        std::cout << "\"" << s << "\" ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Source Vector after move: "" "" "" 
Destination Array: "dog" "cat" "bird" 
```

### Example 3: Moving Elements with Custom Classes

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

class Resource {
public:
    std::string name;
    
    Resource(const std::string &n) : name(n) {
        std::cout << "Resource " << name << " created.\n";
    }
    
    // Move constructor
    Resource(Resource &&other) noexcept : name(std::move(other.name)) {
        std::cout << "Resource moved to " << name << ".\n";
    }
    
    // Delete copy constructor
    Resource(const Resource &) = delete;
    
    ~Resource() {
        std::cout << "Resource " << name << " destroyed.\n";
    }
};

int main() {
    std::vector<Resource> source;
    source.emplace_back("Res1");
    source.emplace_back("Res2");
    source.emplace_back("Res3");
    
    std::vector<Resource> destination;
    
    std::move(source.begin(), source.end(), std::back_inserter(destination));
    
    std::cout << "Source Vector size after move: " << source.size() << "\n";
    std::cout << "Destination Vector size: " << destination.size() << "\n";
    
    return 0;
}
```

**Output:**
```
Resource Res1 created.
Resource Res2 created.
Resource Res3 created.
Resource moved to Res1.
Resource moved to Res2.
Resource moved to Res3.
Source Vector size after move: 3
Destination Vector size: 3
Resource Res1 destroyed.
Resource Res2 destroyed.
Resource Res3 destroyed.
```

*Note: Copy operations are deleted to enforce move semantics.*

---

## 43. move_backward

### Description

`std::move_backward` moves elements from one range to another in reverse order. It is useful when the destination range overlaps with the source and is positioned after the source.

### Example 1: Moving Elements to Overlapping Range Using move_backward

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    // Move first three elements to the last three positions
    std::move_backward(vec.begin(), vec.begin() + 3, vec.end());
    
    std::cout << "Vector after move_backward: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after move_backward: 1 2 3 1 2 3 
```

### Example 2: Moving Strings in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

int main() {
    std::array<std::string, 5> arr = {"one", "two", "three", "four", "five"};
    
    // Move first two elements to the last two positions
    std::move_backward(arr.begin(), arr.begin() + 2, arr.end());
    
    std::cout << "Array after move_backward: ";
    for(auto &s : arr)
        std::cout << "\"" << s << "\" ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after move_backward: "one" "two" "three" "one" "two" 
```

### Example 3: Moving Elements in a Vector of Objects

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

class Widget {
public:
    std::string name;
    
    Widget(const std::string &n) : name(n) {
        std::cout << "Widget " << name << " created.\n";
    }
    
    // Move constructor
    Widget(Widget &&other) noexcept : name(std::move(other.name)) {
        std::cout << "Widget moved to " << name << ".\n";
    }
    
    // Delete copy constructor
    Widget(const Widget &) = delete;
    
    ~Widget() {
        std::cout << "Widget " << name << " destroyed.\n";
    }
};

int main() {
    std::vector<Widget> vec;
    vec.emplace_back("W1");
    vec.emplace_back("W2");
    vec.emplace_back("W3");
    vec.emplace_back("W4");
    
    // Move first two widgets to the last two positions
    std::move_backward(vec.begin(), vec.begin() + 2, vec.end());
    
    std::cout << "Vector size after move_backward: " << vec.size() << "\n";
    
    return 0;
}
```

**Output:**
```
Widget W1 created.
Widget W2 created.
Widget W3 created.
Widget W4 created.
Widget moved to W1.
Widget moved to W2.
Vector size after move_backward: 4
Widget W2 destroyed.
Widget W1 destroyed.
Widget W3 destroyed.
Widget W4 destroyed.
```

*Note: After moving, the original objects are in a valid but unspecified state.*

---

## 44. next_permutation

### Description

`std::next_permutation` rearranges the elements in the range into the next lexicographically greater permutation. It returns `true` if such a permutation exists, otherwise rearranges the range to the first permutation and returns `false`.

### Example 1: Generating Next Permutation of a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};
    
    std::cout << "Original vector: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    bool hasNext = std::next_permutation(vec.begin(), vec.end());
    
    if(hasNext) {
        std::cout << "Next permutation: ";
        for(auto num : vec)
            std::cout << num << " ";
        std::cout << "\n";
    } else {
        std::cout << "No next permutation. Vector is rearranged to the first permutation.\n";
    }

    return 0;
}
```

**Output:**
```
Original vector: 1 2 3 
Next permutation: 1 3 2 
```

### Example 2: Iterating Through All Permutations

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<char> vec = {'A', 'B', 'C'};
    
    std::cout << "All permutations:\n";
    do {
        for(auto c : vec)
            std::cout << c << " ";
        std::cout << "\n";
    } while(std::next_permutation(vec.begin(), vec.end()));
    
    return 0;
}
```

**Output:**
```
All permutations:
A B C 
A C B 
B A C 
B C A 
C A B 
C B A 
```

### Example 3: Using next_permutation with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::string s = "cba";
    
    std::cout << "Original string: " << s << "\n";
    
    // Generate next permutation in ascending order
    bool hasNext = std::next_permutation(s.begin(), s.end());
    
    if(hasNext) {
        std::cout << "Next permutation: " << s << "\n";
    } else {
        std::cout << "No next permutation. String is rearranged to the first permutation.\n";
    }
    
    // Generate next permutation in descending order
    hasNext = std::next_permutation(s.begin(), s.end(), [](char a, char b) -> bool {
        return a > b; // Reverse comparator for descending order
    });
    
    if(hasNext) {
        std::cout << "Next permutation (descending): " << s << "\n";
    } else {
        std::cout << "No next permutation in descending order.\n";
    }
    
    return 0;
}
```

**Output:**
```
Original string: cba
Next permutation: bac
Next permutation (descending): cba
```

*Note: The second call to `next_permutation` with a custom comparator reverses the order.*

---

## 45. none_of

### Description

`std::none_of` checks if none of the elements in a range satisfy a specified predicate. It returns `true` if no elements satisfy the predicate, otherwise `false`.

### Example 1: Checking if No Elements are Negative

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, -2, 3, -4, 5};
    
    auto isNegative = [](int x) -> bool {
        return x < 0;
    };
    
    bool noneNegative1 = std::none_of(vec1.begin(), vec1.end(), isNegative);
    bool noneNegative2 = std::none_of(vec2.begin(), vec2.end(), isNegative);
    
    std::cout << "vec1 has " << (noneNegative1 ? "no " : "some ") << "negative numbers.\n";
    std::cout << "vec2 has " << (noneNegative2 ? "no " : "some ") << "negative numbers.\n";
    
    return 0;
}
```

**Output:**
```
vec1 has no negative numbers.
vec2 has some negative numbers.
```

### Example 2: Checking if a String Contains No Digits

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string s1 = "HelloWorld";
    std::string s2 = "Hello123";
    
    auto hasDigit = [](char c) -> bool {
        return std::isdigit(c);
    };
    
    bool noneDigits1 = std::none_of(s1.begin(), s1.end(), hasDigit);
    bool noneDigits2 = std::none_of(s2.begin(), s2.end(), hasDigit);
    
    std::cout << "s1 contains " << (noneDigits1 ? "no " : "some ") << "digits.\n";
    std::cout << "s2 contains " << (noneDigits2 ? "no " : "some ") << "digits.\n";
    
    return 0;
}
```

**Output:**
```
s1 contains no digits.
s2 contains some digits.
```

### Example 3: Using none_of with Custom Objects

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    
    auto isUnderage = [](const Person &p) -> bool {
        return p.age < 18;
    };
    
    bool allAdults = std::none_of(people.begin(), people.end(), isUnderage);
    
    std::cout << "All people are adults: " << (allAdults ? "Yes" : "No") << "\n";
    
    // Add an underage person
    people.emplace_back(Person{"Dave", 16});
    
    allAdults = std::none_of(people.begin(), people.end(), isUnderage);
    
    std::cout << "All people are adults after adding Dave: " << (allAdults ? "Yes" : "No") << "\n";
    
    return 0;
}
```

**Output:**
```
All people are adults: Yes
All people are adults after adding Dave: No
```

---

## 46. nth_element

### Description

`std::nth_element` partially sorts a range such that the element at the nth position is the element that would be in that position in a fully sorted sequence. All elements before the nth are less than or equal to it, and all elements after are greater than or equal to it.

### Example 1: Finding the Median Element

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {50, 20, 30, 10, 40};
    size_t n = vec.size() / 2;
    
    std::nth_element(vec.begin(), vec.begin() + n, vec.end());
    
    std::cout << "Median element: " << vec[n] << "\n";
    
    std::cout << "Vector after nth_element: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Median element: 30
Vector after nth_element: 20 10 30 50 40 
```

*Note: The elements before the median are less than or equal to it, and those after are greater or equal, but the order is not fully sorted.*

### Example 2: Using nth_element with Custom Comparator (Descending Order)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {15, 5, 20, 10, 25};
    size_t n = 2; // Third element
    
    // Arrange in descending order
    std::nth_element(vec.begin(), vec.begin() + n, vec.end(), [](int a, int b) -> bool {
        return a > b;
    });
    
    std::cout << "Third largest element: " << vec[n] << "\n";
    
    std::cout << "Vector after nth_element: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Third largest element: 15
Vector after nth_element: 20 25 15 10 5 
```

### Example 3: Finding the k-th Smallest Element in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 7> arr = {7, 2, 5, 3, 9, 1, 4};
    size_t k = 4; // 5th smallest element (0-based index)
    
    std::nth_element(arr.begin(), arr.begin() + k, arr.end());
    
    std::cout << "The " << k+1 << "-th smallest element is " << arr[k] << "\n";
    
    std::cout << "Array after nth_element: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
The 5-th smallest element is 5
Array after nth_element: 2 3 1 4 5 9 7 
```

*Note: Only the k-th element is guaranteed to be in its sorted position; other elements are not fully sorted.*

---

## 47. partial_sort

### Description

`std::partial_sort` sorts the first `n` elements in a range as if the entire range was sorted, leaving the rest of the elements unsorted.

### Example 1: Sorting Top 3 Elements in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {50, 20, 30, 10, 40, 60, 70};
    size_t n = 3;
    
    std::partial_sort(vec.begin(), vec.begin() + n, vec.end());
    
    std::cout << "Vector after partial_sort (top " << n << " elements sorted): ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after partial_sort (top 3 elements sorted): 10 20 30 50 40 60 70 
```

### Example 2: Partial Sorting with Custom Comparator (Descending Order)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {15, 5, 25, 10, 20};
    size_t n = 2;
    
    // Sort top 2 elements in descending order
    std::partial_sort(vec.begin(), vec.begin() + n, vec.end(), [](int a, int b) -> bool {
        return a > b;
    });
    
    std::cout << "Vector after partial_sort (top " << n << " elements descending): ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after partial_sort (top 2 elements descending): 25 20 15 10 5 
```

### Example 3: Sorting Partial Range in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {9, 4, 7, 1, 3, 8};
    size_t n = 4;
    
    std::partial_sort(arr.begin(), arr.begin() + n, arr.end());
    
    std::cout << "Array after partial_sort (first " << n << " elements sorted): ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after partial_sort (first 4 elements sorted): 1 3 4 7 9 8 
```

*Note: Only the first `n` elements are guaranteed to be sorted; the rest remain unsorted.*

---

## 48. partial_sort_copy

### Description

`std::partial_sort_copy` copies elements from a source range to a destination range and partially sorts them. It sorts the smallest (or largest) `n` elements depending on the comparator.

### Example 1: Copying and Sorting Top 3 Elements

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {50, 20, 30, 10, 40, 60, 70};
    std::vector<int> destination(3);
    
    std::partial_sort_copy(source.begin(), source.end(), destination.begin(), destination.end());
    
    std::cout << "Destination after partial_sort_copy (top 3 elements): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after partial_sort_copy (top 3 elements): 10 20 30 
```

### Example 2: Partial Sort Copy with Custom Comparator (Descending Order)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {15, 5, 25, 10, 20};
    std::vector<int> destination(2);
    
    // Sort top 2 elements in descending order
    std::partial_sort_copy(source.begin(), source.end(), destination.begin(), destination.end(), [](int a, int b) -> bool {
        return a > b;
    });
    
    std::cout << "Destination after partial_sort_copy (top 2 descending): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after partial_sort_copy (top 2 descending): 25 20 
```

### Example 3: Partial Sort Copy with Different Sized Destination

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> destination(5);
    
    std::partial_sort_copy(source.begin(), source.end(), destination.begin(), destination.end());
    
    std::cout << "Destination after partial_sort_copy (top 5 elements): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after partial_sort_copy (top 5 elements): 1 1 2 3 4 
```

*Note: The destination range size determines how many top elements are copied and sorted.*

---

## 49. partition

### Description

`std::partition` rearranges elements in a range so that elements satisfying a predicate come before those that do not. The relative order of elements is not preserved.

### Example 1: Partitioning Vector into Even and Odd Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 15, 20, 25, 30, 35};
    
    auto it = std::partition(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Even numbers: ";
    for(auto iter = vec.begin(); iter != it; ++iter)
        std::cout << *iter << " ";
    std::cout << "\nOdd numbers: ";
    for(auto iter = it; iter != vec.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Even numbers: 10 20 30 
Odd numbers: 15 25 35 
```

### Example 2: Partitioning Strings by Length

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "kiwi", "banana", "fig", "cherry"};
    
    auto it = std::partition(words.begin(), words.end(), [](const std::string &s) -> bool {
        return s.length() > 4;
    });
    
    std::cout << "Words longer than 4 characters: ";
    for(auto iter = words.begin(); iter != it; ++iter)
        std::cout << *iter << " ";
    std::cout << "\nShorter or equal to 4 characters: ";
    for(auto iter = it; iter != words.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Words longer than 4 characters: apple banana cherry 
Shorter or equal to 4 characters: kiwi fig 
```

### Example 3: Partitioning Based on Custom Object Property

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {{"Alice", 30}, {"Bob", 17}, {"Charlie", 25}, {"Dave", 16}};
    
    auto it = std::partition(people.begin(), people.end(), [](const Person &p) -> bool {
        return p.age >= 18;
    });
    
    std::cout << "Adults:\n";
    for(auto iter = people.begin(); iter != it; ++iter)
        std::cout << iter->name << " (" << iter->age << ")\n";
    std::cout << "Minors:\n";
    for(auto iter = it; iter != people.end(); ++iter)
        std::cout << iter->name << " (" << iter->age << ")\n";
    
    return 0;
}
```

**Output:**
```
Adults:
Alice (30)
Charlie (25)
Minors:
Bob (17)
Dave (16)
```

*Note: The order of elements within each partition is not guaranteed.*

---

## 50. partition_copy

### Description

`std::partition_copy` copies elements from a source range to two separate destination ranges based on a predicate. Elements satisfying the predicate go to one destination, and the rest go to another.

### Example 1: Partitioning Vector into Even and Odd Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {10, 15, 20, 25, 30, 35};
    std::vector<int> evens;
    std::vector<int> odds;
    
    std::partition_copy(source.begin(), source.end(), std::back_inserter(evens), std::back_inserter(odds), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Even numbers: ";
    for(auto num : evens)
        std::cout << num << " ";
    std::cout << "\nOdd numbers: ";
    for(auto num : odds)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Even numbers: 10 20 30 
Odd numbers: 15 25 35 
```

### Example 2: Partitioning Strings Based on Length

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> source = {"apple", "kiwi", "banana", "fig", "cherry"};
    std::vector<std::string> longWords;
    std::vector<std::string> shortWords;
    
    std::partition_copy(source.begin(), source.end(), std::back_inserter(longWords), std::back_inserter(shortWords), [](const std::string &s) -> bool {
        return s.length() > 4;
    });
    
    std::cout << "Words longer than 4 characters: ";
    for(auto &s : longWords)
        std::cout << s << " ";
    std::cout << "\nWords shorter or equal to 4 characters: ";
    for(auto &s : shortWords)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Words longer than 4 characters: apple banana cherry 
Words shorter or equal to 4 characters: kiwi fig 
```

### Example 3: Partitioning Custom Objects into Adults and Minors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> source = {{"Alice", 30}, {"Bob", 17}, {"Charlie", 25}, {"Dave", 16}};
    std::vector<Person> adults;
    std::vector<Person> minors;
    
    std::partition_copy(source.begin(), source.end(), std::back_inserter(adults), std::back_inserter(minors), [](const Person &p) -> bool {
        return p.age >= 18;
    });
    
    std::cout << "Adults:\n";
    for(auto &p : adults)
        std::cout << p.name << " (" << p.age << ")\n";
    std::cout << "Minors:\n";
    for(auto &p : minors)
        std::cout << p.name << " (" << p.age << ")\n";
    
    return 0;
}
```

**Output:**
```
Adults:
Alice (30)
Charlie (25)
Minors:
Bob (17)
Dave (16)
```

*Note: `partition_copy` does not modify the source range.*

---

## 51. partition_point

### Description

`std::partition_point` finds the partition point in a partitioned range. It returns an iterator to the first element in the second group (i.e., elements that do not satisfy the predicate).

### Example 1: Finding Partition Point After Partitioning Vector into Even and Odd Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 15, 25, 35};
    
    std::partition(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    auto it = std::partition_point(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Even numbers: ";
    for(auto iter = vec.begin(); iter != it; ++iter)
        std::cout << *iter << " ";
    std::cout << "\nOdd numbers: ";
    for(auto iter = it; iter != vec.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Even numbers: 10 20 30 
Odd numbers: 15 25 35 
```

### Example 2: Finding Partition Point in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string text = "AAAaaabbbCCCccc";
    
    std::partition(text.begin(), text.end(), [](char c) -> bool {
        return std::isupper(c);
    });
    
    auto it = std::partition_point(text.begin(), text.end(), [](char c) -> bool {
        return std::isupper(c);
    });
    
    std::cout << "Uppercase characters: ";
    for(auto iter = text.begin(); iter != it; ++iter)
        std::cout << *iter << " ";
    std::cout << "\nLowercase characters: ";
    for(auto iter = it; iter != text.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Uppercase characters: A A A C C C 
Lowercase characters: a a a b b b c c c 
```

### Example 3: Finding Partition Point with Custom Objects

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students = {{"Alice", 85.5}, {"Bob", 75.0}, {"Charlie", 90.0}, {"Dave", 65.0}};
    
    std::partition(students.begin(), students.end(), [](const Student &s) -> bool {
        return s.grade >= 80.0;
    });
    
    auto it = std::partition_point(students.begin(), students.end(), [](const Student &s) -> bool {
        return s.grade >= 80.0;
    });
    
    std::cout << "Students with grade >= 80:\n";
    for(auto iter = students.begin(); iter != it; ++iter)
        std::cout << iter->name << " (" << iter->grade << ")\n";
    std::cout << "Students with grade < 80:\n";
    for(auto iter = it; iter != students.end(); ++iter)
        std::cout << iter->name << " (" << iter->grade << ")\n";
    
    return 0;
}
```

**Output:**
```
Students with grade >= 80:
Alice (85.5)
Charlie (90)
Students with grade < 80:
Bob (75)
Dave (65)
```

*Note: `partition_point` assumes the range is already partitioned.*

---

## 52. pop_heap

### Description

`std::pop_heap` removes the largest element from a heap and adjusts the remaining elements to maintain the heap property. It moves the largest element to the end of the range.

### Example 1: Removing the Top Element from a Heap

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap = {50, 30, 40, 10, 20};
    
    // Ensure it's a heap
    std::make_heap(heap.begin(), heap.end());
    
    std::cout << "Original heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    std::pop_heap(heap.begin(), heap.end());
    int top = heap.back();
    heap.pop_back();
    
    std::cout << "Popped top element: " << top << "\n";
    std::cout << "Heap after pop_heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original heap: 50 30 40 10 20 
Popped top element: 50
Heap after pop_heap: 40 30 20 10 
```

### Example 2: Pop Heap from a Vector of Strings

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> heap = {"delta", "alpha", "charlie", "bravo"};
    
    // Create a max-heap based on lexicographical order
    std::make_heap(heap.begin(), heap.end());
    
    std::cout << "Original heap: ";
    for(auto &s : heap)
        std::cout << s << " ";
    std::cout << "\n";
    
    std::pop_heap(heap.begin(), heap.end());
    std::string top = heap.back();
    heap.pop_back();
    
    std::cout << "Popped top element: " << top << "\n";
    std::cout << "Heap after pop_heap: ";
    for(auto &s : heap)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original heap: delta charlie bravo alpha 
Popped top element: delta
Heap after pop_heap: charlie alpha bravo 
```

### Example 3: Using pop_heap with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<int> heap = {10, 20, 15, 30, 40};
    
    // Create a min-heap using custom comparator
    std::make_heap(heap.begin(), heap.end(), [](int a, int b) -> bool {
        return a > b; // Min-heap
    });
    
    std::cout << "Original min-heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    std::pop_heap(heap.begin(), heap.end(), [](int a, int b) -> bool {
        return a > b; // Min-heap
    });
    int top = heap.back();
    heap.pop_back();
    
    std::cout << "Popped top element (min): " << top << "\n";
    std::cout << "Heap after pop_heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original min-heap: 10 20 15 30 40 
Popped top element (min): 10
Heap after pop_heap: 15 20 40 30 
```

*Note: Custom comparators define different heap properties (max-heap vs. min-heap).*

---

## 53. prev_permutation

### Description

`std::prev_permutation` rearranges the elements into the previous lexicographically ordered permutation. It returns `true` if such a permutation exists, otherwise rearranges to the last permutation and returns `false`.

### Example 1: Generating Previous Permutation of a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 2};
    
    std::cout << "Original vector: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    bool hasPrev = std::prev_permutation(vec.begin(), vec.end());
    
    if(hasPrev) {
        std::cout << "Previous permutation: ";
        for(auto num : vec)
            std::cout << num << " ";
        std::cout << "\n";
    } else {
        std::cout << "No previous permutation. Vector is rearranged to the last permutation.\n";
    }

    return 0;
}
```

**Output:**
```
Original vector: 1 3 2 
Previous permutation: 1 2 3 
```

### Example 2: Iterating Through All Previous Permutations

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<char> vec = {'c', 'b', 'a'};
    
    std::cout << "All previous permutations:\n";
    do {
        for(auto c : vec)
            std::cout << c << " ";
        std::cout << "\n";
    } while(std::prev_permutation(vec.begin(), vec.end()));
    
    return 0;
}
```

**Output:**
```
All previous permutations:
c b a 
c a b 
b c a 
b a c 
a c b 
a b c 
```

### Example 3: Using prev_permutation with Custom Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::string s = "cba";
    
    std::cout << "Original string: " << s << "\n";
    
    // Generate previous permutation in ascending order
    bool hasPrev = std::prev_permutation(s.begin(), s.end(), [](char a, char b) -> bool {
        return a < b;
    });
    
    if(hasPrev) {
        std::cout << "Previous permutation: " << s << "\n";
    } else {
        std::cout << "No previous permutation. String is rearranged to the last permutation.\n";
    }
    
    return 0;
}
```

**Output:**
```
Original string: cba
Previous permutation: bca
```

*Note: The custom comparator defines different ordering logic for permutations.*

---

## 54. push_heap

### Description

`std::push_heap` adds a new element to an existing heap. It assumes that the new element is already placed at the end of the range and adjusts the heap accordingly.

### Example 1: Adding an Element to a Max-Heap

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap = {50, 30, 40, 10, 20};
    
    // Create a max-heap
    std::make_heap(heap.begin(), heap.end());
    
    std::cout << "Original heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    // Add a new element
    heap.push_back(60);
    std::push_heap(heap.begin(), heap.end());
    
    std::cout << "Heap after push_heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original heap: 50 30 40 10 20 
Heap after push_heap: 60 30 50 10 20 40 
```

### Example 2: Building a Heap Incrementally

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap;
    
    std::vector<int> elements = {10, 20, 5, 30, 15};
    
    for(auto num : elements) {
        heap.push_back(num);
        std::push_heap(heap.begin(), heap.end());
    }
    
    std::cout << "Heap after pushing elements: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Heap after pushing elements: 30 20 5 10 15 
```

### Example 3: Using push_heap with Custom Comparator (Min-Heap)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap;
    
    // Create a min-heap using custom comparator
    auto cmp = [](int a, int b) -> bool {
        return a > b;
    };
    
    std::vector<int> elements = {40, 10, 20, 30, 50};
    
    for(auto num : elements) {
        heap.push_back(num);
        std::push_heap(heap.begin(), heap.end(), cmp);
    }
    
    std::cout << "Min-Heap after pushing elements: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Min-Heap after pushing elements: 10 30 20 40 50 
```

*Note: Custom comparators allow creating different types of heaps (max-heap vs. min-heap).*

---

## 55. random_shuffle

### Description

`std::random_shuffle` randomly rearranges the elements in a range. *(Note: Deprecated in C++14 and removed in C++17. Use `std::shuffle` instead.)*

### Example 1: Shuffling a Vector of Integers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::srand(std::time(0)); // Seed for randomness
    
    std::random_shuffle(vec.begin(), vec.end());
    
    std::cout << "Shuffled Vector: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Shuffled Vector: 3 1 5 2 4 
```

*Note: The output will vary with each run.*

### Example 2: Shuffling a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    std::string s = "ABCDE";
    
    std::srand(std::time(0)); // Seed for randomness
    
    std::random_shuffle(s.begin(), s.end());
    
    std::cout << "Shuffled String: " << s << "\n";
    
    return 0;
}
```

**Output:**
```
Shuffled String: CBAED
```

*Note: The output will vary with each run.*

### Example 3: Shuffling with a Custom Random Number Generator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(vec.begin(), vec.end(), g);
    
    std::cout << "Shuffled Vector with custom RNG: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Shuffled Vector with custom RNG: 40 10 50 20 30 
```

*Note: `std::shuffle` is preferred over `std::random_shuffle` in modern C++.*

---

## 56. remove

### Description

`std::remove` removes all elements equal to a specified value from a range by moving the remaining elements to the front. It returns an iterator to the new end of the range. The actual container size remains unchanged; to resize, use container-specific methods.

### Example 1: Removing All Occurrences of a Value in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    
    auto newEnd = std::remove(vec.begin(), vec.end(), 2);
    
    vec.erase(newEnd, vec.end());
    
    std::cout << "Vector after removing 2s: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after removing 2s: 1 3 4 5 
```

### Example 2: Removing Characters from a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "hello world";
    
    auto newEnd = std::remove(s.begin(), s.end(), 'l');
    
    s.erase(newEnd, s.end());
    
    std::cout << "String after removing 'l': " << s << "\n";
    
    return 0;
}
```

**Output:**
```
String after removing 'l': heo word
```

### Example 3: Removing Elements from an Array (Using erase-remove idiom)

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 7> arr = {5, 10, 15, 10, 20, 10, 25};
    
    auto newEnd = std::remove(arr.begin(), arr.end(), 10);
    
    // Note: std::array has fixed size; elements beyond newEnd are unspecified
    std::cout << "Array after removing 10s: ";
    for(auto it = arr.begin(); it != newEnd; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after removing 10s: 5 15 20 25 
```

*Note: `std::array` has a fixed size; consider using `std::vector` for dynamic resizing.*

---

## 57. remove_copy

### Description

`std::remove_copy` copies elements from a source range to a destination, excluding elements equal to a specified value.

### Example 1: Copying Vector Without Specific Value

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 2, 4, 2, 5};
    std::vector<int> destination;
    
    std::remove_copy(source.begin(), source.end(), std::back_inserter(destination), 2);
    
    std::cout << "Destination after remove_copy (excluding 2): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after remove_copy (excluding 2): 1 3 4 5 
```

### Example 2: Removing Characters from a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

int main() {
    std::string source = "hello world";
    std::string destination;
    
    std::remove_copy(source.begin(), source.end(), std::back_inserter(destination), 'l');
    
    std::cout << "Destination after remove_copy (excluding 'l'): " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after remove_copy (excluding 'l'): heo word
```

### Example 3: Removing Elements from an Array and Copying to Another Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 7> source = {5, 10, 15, 10, 20, 10, 25};
    std::array<int, 7> destination = {0};
    
    std::remove_copy(source.begin(), source.end(), destination.begin(), 10);
    
    std::cout << "Destination after remove_copy (excluding 10s): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after remove_copy (excluding 10s): 5 15 20 25 0 0 0 
```

*Note: The remaining elements in the destination beyond the copied elements remain unchanged.*

---

## 58. remove_copy_if

### Description

`std::remove_copy_if` copies elements from a source range to a destination, excluding elements that satisfy a specified predicate.

### Example 1: Copying Vector Without Even Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5, 6};
    std::vector<int> destination;
    
    std::remove_copy_if(source.begin(), source.end(), std::back_inserter(destination), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Destination after remove_copy_if (excluding evens): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after remove_copy_if (excluding evens): 1 3 5 
```

### Example 2: Removing Vowels from a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

int main() {
    std::string source = "Hello World";
    std::string destination;
    
    std::remove_copy_if(source.begin(), source.end(), std::back_inserter(destination), [](char c) -> bool {
        return std::strchr("AEIOUaeiou", c) != nullptr;
    });
    
    std::cout << "Destination after remove_copy_if (excluding vowels): " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after remove_copy_if (excluding vowels): Hll Wrld
```

### Example 3: Removing Elements Based on Custom Predicate

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> source = {{"Alice", 30}, {"Bob", 17}, {"Charlie", 25}, {"Dave", 16}};
    std::vector<Person> destination;
    
    std::remove_copy_if(source.begin(), source.end(), std::back_inserter(destination), [](const Person &p) -> bool {
        return p.age < 18;
    });
    
    std::cout << "Destination after remove_copy_if (excluding minors):\n";
    for(auto &p : destination)
        std::cout << p.name << " (" << p.age << ")\n";
    
    return 0;
}
```

**Output:**
```
Destination after remove_copy_if (excluding minors):
Alice (30)
Charlie (25)
```

*Note: `remove_copy_if` does not modify the source range.*

---

## 59. remove_if

### Description

`std::remove_if` removes elements from a range that satisfy a specified predicate by moving the remaining elements to the front. It returns an iterator to the new end of the range. To actually remove the elements from the container, use container-specific methods like `erase`.

### Example 1: Removing All Odd Numbers from a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    auto newEnd = std::remove_if(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 != 0;
    });
    
    vec.erase(newEnd, vec.end());
    
    std::cout << "Vector after removing odd numbers: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after removing odd numbers: 2 4 6 
```

### Example 2: Removing Vowels from a String In-Place

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "Hello World";
    
    auto newEnd = std::remove_if(s.begin(), s.end(), [](char c) -> bool {
        return std::strchr("AEIOUaeiou", c) != nullptr;
    });
    
    s.erase(newEnd, s.end());
    
    std::cout << "String after removing vowels: " << s << "\n";
    
    return 0;
}
```

**Output:**
```
String after removing vowels: Hll Wrld
```

### Example 3: Removing Elements Based on Custom Predicate in Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 7> arr = {5, 10, 15, 20, 25, 30, 35};
    
    auto newEnd = std::remove_if(arr.begin(), arr.end(), [](int x) -> bool {
        return x > 20;
    });
    
    // Note: std::array has fixed size; elements beyond newEnd are unspecified
    std::cout << "Array after remove_if (removing >20): ";
    for(auto it = arr.begin(); it != newEnd; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after remove_if (removing >20): 5 10 15 20 
```

*Note: Use `std::vector` for dynamic resizing after removal.*

---

## 60. replace

### Description

`std::replace` replaces all elements in a range that are equal to a specified old value with a new value.

### Example 1: Replacing All Occurrences of a Value in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    
    std::replace(vec.begin(), vec.end(), 2, 20);
    
    std::cout << "Vector after replacing 2 with 20: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after replacing 2 with 20: 1 20 3 20 4 20 5 
```

### Example 2: Replacing Characters in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "banana";
    
    std::replace(s.begin(), s.end(), 'a', 'o');
    
    std::cout << "String after replacing 'a' with 'o': " << s << "\n";
    
    return 0;
}
```

**Output:**
```
String after replacing 'a' with 'o': bonono
```

### Example 3: Replacing Elements in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 5> arr = {5, 10, 15, 10, 20};
    
    std::replace(arr.begin(), arr.end(), 10, 100);
    
    std::cout << "Array after replacing 10 with 100: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after replacing 10 with 100: 5 100 15 100 20 
```

*Note: `std::replace` modifies the elements in place.*

---

## 61. replace_copy

### Description

`std::replace_copy` copies elements from a source range to a destination, replacing elements equal to a specified old value with a new value during the copy.

### Example 1: Copying Vector While Replacing Values

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 2, 4, 2, 5};
    std::vector<int> destination;
    
    std::replace_copy(source.begin(), source.end(), std::back_inserter(destination), 2, 20);
    
    std::cout << "Destination after replace_copy (2 -> 20): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after replace_copy (2 -> 20): 1 20 3 20 4 20 5 
```

### Example 2: Replacing Characters While Copying String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

int main() {
    std::string source = "banana";
    std::string destination;
    
    std::replace_copy(source.begin(), source.end(), std::back_inserter(destination), 'a', 'o');
    
    std::cout << "Destination after replace_copy ('a' -> 'o'): " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after replace_copy ('a' -> 'o'): bonono
```

### Example 3: Replacing Elements While Copying Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 5> source = {5, 10, 15, 10, 20};
    std::array<int, 5> destination = {0};
    
    std::replace_copy(source.begin(), source.end(), destination.begin(), 10, 100);
    
    std::cout << "Destination after replace_copy (10 -> 100): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after replace_copy (10 -> 100): 5 100 15 100 20 
```

*Note: `replace_copy` does not modify the source range.*

---

## 62. replace_copy_if

### Description

`std::replace_copy_if` copies elements from a source range to a destination, replacing elements that satisfy a specified predicate with a new value during the copy.

### Example 1: Replacing Odd Numbers with 0 While Copying

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5, 6};
    std::vector<int> destination;
    
    std::replace_copy_if(source.begin(), source.end(), std::back_inserter(destination), [](int x) -> bool {
        return x % 2 != 0;
    }, 0);
    
    std::cout << "Destination after replace_copy_if (odd -> 0): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after replace_copy_if (odd -> 0): 0 2 0 4 0 6 
```

### Example 2: Replacing Vowels with '*' While Copying String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::string source = "Hello World";
    std::string destination;
    
    std::replace_copy_if(source.begin(), source.end(), std::back_inserter(destination), [](char c) -> bool {
        return std::strchr("AEIOUaeiou", c) != nullptr;
    }, '*');
    
    std::cout << "Destination after replace_copy_if (vowels -> '*'): " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after replace_copy_if (vowels -> '*'): H*ll* W*rld
```

### Example 3: Replacing Elements Based on Age While Copying

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> source = {{"Alice", 30}, {"Bob", 17}, {"Charlie", 25}, {"Dave", 16}};
    std::vector<Person> destination;
    
    std::replace_copy_if(source.begin(), source.end(), std::back_inserter(destination), [](const Person &p) -> bool {
        return p.age < 18;
    }, Person{"Unknown", 0});
    
    std::cout << "Destination after replace_copy_if (minors -> Unknown):\n";
    for(auto &p : destination)
        std::cout << p.name << " (" << p.age << ")\n";
    
    return 0;
}
```

**Output:**
```
Destination after replace_copy_if (minors -> Unknown):
Alice (30)
Unknown (0)
Charlie (25)
Unknown (0)
```

*Note: `replace_copy_if` allows conditional replacement based on predicates.*

---

## 63. replace_if

### Description

`std::replace_if` replaces all elements in a range that satisfy a specified predicate with a new value.

### Example 1: Replacing Odd Numbers with 0 in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    std::replace_if(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 != 0;
    }, 0);
    
    std::cout << "Vector after replace_if (odd -> 0): ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after replace_if (odd -> 0): 0 2 0 4 0 6 
```

### Example 2: Replacing Vowels with '*' in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main() {
    std::string s = "Hello World";
    
    std::replace_if(s.begin(), s.end(), [](char c) -> bool {
        return std::strchr("AEIOUaeiou", c) != nullptr;
    }, '*');
    
    std::cout << "String after replace_if (vowels -> '*'): " << s << "\n";
    
    return 0;
}
```

**Output:**
```
String after replace_if (vowels -> '*'): H*ll* W*rld
```

### Example 3: Replacing Minors with Unknown in a Vector of Persons

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> vec = {{"Alice", 30}, {"Bob", 17}, {"Charlie", 25}, {"Dave", 16}};
    
    std::replace_if(vec.begin(), vec.end(), [](const Person &p) -> bool {
        return p.age < 18;
    }, Person{"Unknown", 0});
    
    std::cout << "Vector after replace_if (minors -> Unknown):\n";
    for(auto &p : vec)
        std::cout << p.name << " (" << p.age << ")\n";
    
    return 0;
}
```

**Output:**
```
Vector after replace_if (minors -> Unknown):
Alice (30)
Unknown (0)
Charlie (25)
Unknown (0)
```

*Note: `replace_if` modifies elements in place based on predicates.*

---

## 64. reverse

### Description

`std::reverse` reverses the order of elements in a range.

### Example 1: Reversing a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::reverse(vec.begin(), vec.end());
    
    std::cout << "Vector after reverse: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after reverse: 5 4 3 2 1 
```

### Example 2: Reversing a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "Hello";
    
    std::reverse(s.begin(), s.end());
    
    std::cout << "Reversed string: " << s << "\n";
    
    return 0;
}
```

**Output:**
```
Reversed string: olleH
```

### Example 3: Reversing a Subrange in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    
    // Reverse elements from index 2 to 5
    std::reverse(arr.begin() + 2, arr.begin() + 5);
    
    std::cout << "Array after partial reverse: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after partial reverse: 1 2 5 4 3 6 
```

*Note: `std::reverse` can operate on any bidirectional range.*

---

## 65. reverse_copy

### Description

`std::reverse_copy` copies elements from a source range to a destination in reverse order.

### Example 1: Copying Vector to Another in Reverse

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination;
    
    std::reverse_copy(source.begin(), source.end(), std::back_inserter(destination));
    
    std::cout << "Destination after reverse_copy: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after reverse_copy: 5 4 3 2 1 
```

### Example 2: Reverse Copying a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

int main() {
    std::string source = "Hello";
    std::string destination;
    
    std::reverse_copy(source.begin(), source.end(), std::back_inserter(destination));
    
    std::cout << "Destination after reverse_copy: " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after reverse_copy: olleH
```

### Example 3: Reverse Copying Part of an Array to a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

int main() {
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    std::vector<int> destination;
    
    // Reverse copy elements from index 1 to 4
    std::reverse_copy(arr.begin() + 1, arr.begin() + 4, std::back_inserter(destination));
    
    std::cout << "Destination after reverse_copy of subrange: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after reverse_copy of subrange: 4 3 2 
```

*Note: `reverse_copy` does not modify the source range.*

---

## 66. rotate

### Description

`std::rotate` rotates the elements in a range such that a specified element becomes the new first element.

### Example 1: Rotating a Vector to Start from a Specific Element

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Rotate so that 3 becomes the first element
    auto newFirst = std::find(vec.begin(), vec.end(), 3);
    std::rotate(vec.begin(), newFirst, vec.end());
    
    std::cout << "Vector after rotate: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after rotate: 3 4 5 1 2 
```

### Example 2: Rotating a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "abcdef";
    
    // Rotate so that 'd' becomes the first character
    auto newFirst = std::find(s.begin(), s.end(), 'd');
    std::rotate(s.begin(), newFirst, s.end());
    
    std::cout << "String after rotate: " << s << "\n";
    
    return 0;
}
```

**Output:**
```
String after rotate: defabc
```

### Example 3: Rotating an Array by 2 Positions

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    
    // Rotate by 2 positions
    std::rotate(arr.begin(), arr.begin() + 2, arr.end());
    
    std::cout << "Array after rotate by 2 positions: ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after rotate by 2 positions: 3 4 5 6 1 2 
```

*Note: `std::rotate` rearranges elements in place.*

---

## 67. rotate_copy

### Description

`std::rotate_copy` copies elements from a source range to a destination in a rotated order, without modifying the source range.

### Example 1: Rotating and Copying a Vector to Another Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination;
    
    // Rotate so that 3 becomes the first element and copy
    auto newFirst = std::find(source.begin(), source.end(), 3);
    std::rotate_copy(source.begin(), newFirst, source.end(), std::back_inserter(destination));
    
    std::cout << "Destination after rotate_copy: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after rotate_copy: 3 4 5 1 2 
```

### Example 2: Rotating and Copying a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

int main() {
    std::string source = "abcdef";
    std::string destination;
    
    // Rotate so that 'd' becomes the first character and copy
    auto newFirst = std::find(source.begin(), source.end(), 'd');
    std::rotate_copy(source.begin(), newFirst, source.end(), std::back_inserter(destination));
    
    std::cout << "Destination after rotate_copy: " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after rotate_copy: defabc
```

### Example 3: Rotating and Copying Part of an Array to a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

int main() {
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    std::vector<int> destination;
    
    // Rotate first three elements to the beginning and copy
    std::rotate_copy(arr.begin(), arr.begin() + 3, arr.end(), std::back_inserter(destination));
    
    std::cout << "Destination after rotate_copy: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after rotate_copy: 4 5 6 1 2 3 
```

*Note: `rotate_copy` does not modify the source range.*

---

## 68. search

### Description

`std::search` searches for the first occurrence of a subsequence within a range. It returns an iterator to the beginning of the first match or the end iterator if not found.

### Example 1: Searching for a Subsequence in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> haystack = {1, 2, 3, 4, 2, 3, 5};
    std::vector<int> needle = {2, 3};
    
    auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
    
    if(it != haystack.end()) {
        std::cout << "Subsequence found starting at position " << std::distance(haystack.begin(), it) << "\n";
    } else {
        std::cout << "Subsequence not found.\n";
    }

    return 0;
}
```

**Output:**
```
Subsequence found starting at position 1
```

### Example 2: Searching for a Substring in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string haystack = "Hello World";
    std::string needle = "World";
    
    auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
    
    if(it != haystack.end()) {
        std::cout << "Subsequence \"" << needle << "\" found at position " << std::distance(haystack.begin(), it) << "\n";
    } else {
        std::cout << "Subsequence \"" << needle << "\" not found.\n";
    }

    return 0;
}
```

**Output:**
```
Subsequence "World" found at position 6
```

### Example 3: Searching with Custom Comparator (Case-Insensitive)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::string haystack = "Hello World";
    std::string needle = "world";
    
    auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(),
                          [](char a, char b) -> bool {
                              return std::tolower(a) == std::tolower(b);
                          });
    
    if(it != haystack.end()) {
        std::cout << "Subsequence \"" << needle << "\" found at position " << std::distance(haystack.begin(), it) << " (case-insensitive).\n";
    } else {
        std::cout << "Subsequence \"" << needle << "\" not found.\n";
    }

    return 0;
}
```

**Output:**
```
Subsequence "world" found at position 6 (case-insensitive).
```

*Note: Custom comparators allow for flexible matching criteria.*

---

## 69. search_n

### Description

`std::search_n` searches for the first occurrence of `count` consecutive elements that satisfy a specified predicate or are equal to a given value.

### Example 1: Finding Three Consecutive Even Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 6, 3, 4, 6, 8};
    
    auto it = std::search_n(vec.begin(), vec.end(), 3, 4, [](int a, int b) -> bool {
        return a == b;
    });
    
    if(it != vec.end()) {
        std::cout << "Found three consecutive 4s starting at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No three consecutive 4s found.\n";
    }

    return 0;
}
```

**Output:**
```
No three consecutive 4s found.
```

### Example 2: Searching for Consecutive Vowels in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "beautiful";
    
    auto it = std::search_n(s.begin(), s.end(), 2, 'u', [](char a, char b) -> bool {
        return std::tolower(a) == std::tolower(b);
    });
    
    if(it != s.end()) {
        std::cout << "Found two consecutive 'u's starting at position " << std::distance(s.begin(), it) << "\n";
    } else {
        std::cout << "No two consecutive 'u's found.\n";
    }

    return 0;
}
```

**Output:**
```
No two consecutive 'u's found.
```

### Example 3: Finding Two Consecutive Elements Greater Than a Value

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {5, 7, 8, 3, 9, 10, 2};
    
    auto it = std::search_n(vec.begin(), vec.end(), 2, 0, [](int a, int b) -> bool {
        return a > 5;
    });
    
    if(it != vec.end()) {
        std::cout << "Found two consecutive elements greater than 5 starting at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No two consecutive elements greater than 5 found.\n";
    }

    return 0;
}
```

**Output:**
```
Found two consecutive elements greater than 5 starting at position 1
```

*Note: `search_n` can use custom predicates for flexible matching.*

---

## 70. set_difference

### Description

`std::set_difference` computes the difference between two sorted ranges, copying elements from the first range that are not present in the second range to a destination.

### Example 1: Finding Elements in vec1 Not in vec2

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {2, 4, 6};
    std::vector<int> difference;
    
    std::set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(difference));
    
    std::cout << "Elements in vec1 not in vec2: ";
    for(auto num : difference)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Elements in vec1 not in vec2: 1 3 5 
```

### Example 2: Finding Strings in First List Not Present in Second List

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

int main() {
    std::vector<std::string> list1 = {"apple", "banana", "cherry", "date"};
    std::vector<std::string> list2 = {"banana", "date", "fig"};
    std::vector<std::string> difference;
    
    std::set_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(difference));
    
    std::cout << "Strings in list1 not in list2: ";
    for(auto &s : difference)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Strings in list1 not in list2: apple cherry 
```

### Example 3: Using Custom Comparator for set_difference

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::vector<std::string> vec1 = {"Apple", "Banana", "Cherry"};
    std::vector<std::string> vec2 = {"banana", "cherry", "Date"};
    std::vector<std::string> difference;
    
    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    std::sort(vec1.begin(), vec1.end(), cmp);
    std::sort(vec2.begin(), vec2.end(), cmp);
    
    std::set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(difference), cmp);
    
    std::cout << "Strings in vec1 not in vec2 (case-insensitive): ";
    for(auto &s : difference)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Strings in vec1 not in vec2 (case-insensitive): apple 
```

*Note: Both input ranges must be sorted according to the same comparator.*

---

## 71. set_intersection

### Description

`std::set_intersection` computes the intersection of two sorted ranges, copying elements that are present in both ranges to a destination.

### Example 1: Finding Common Elements Between Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {3, 4, 5, 6, 7};
    std::vector<int> intersection;
    
    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(intersection));
    
    std::cout << "Common elements: ";
    for(auto num : intersection)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Common elements: 3 4 5 
```

### Example 2: Finding Common Strings Between Two Lists

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

int main() {
    std::vector<std::string> list1 = {"apple", "banana", "cherry"};
    std::vector<std::string> list2 = {"banana", "date", "cherry", "fig"};
    std::vector<std::string> intersection;
    
    std::set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(intersection));
    
    std::cout << "Common strings: ";
    for(auto &s : intersection)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Common strings: banana cherry 
```

### Example 3: Using Custom Comparator for set_intersection

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::vector<std::string> vec1 = {"Apple", "Banana", "Cherry"};
    std::vector<std::string> vec2 = {"banana", "cherry", "Date"};
    std::vector<std::string> intersection;
    
    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    std::sort(vec1.begin(), vec1.end(), cmp);
    std::sort(vec2.begin(), vec2.end(), cmp);
    
    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(intersection), cmp);
    
    std::cout << "Common strings (case-insensitive): ";
    for(auto &s : intersection)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Common strings (case-insensitive): banana cherry 
```

*Note: Both input ranges must be sorted according to the same comparator.*

---

## 72. set_symmetric_difference

### Description

`std::set_symmetric_difference` computes the symmetric difference of two sorted ranges, copying elements that are in either of the ranges but not in both to a destination.

### Example 1: Finding Symmetric Difference Between Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {3, 4, 5, 6, 7};
    std::vector<int> symDifference;
    
    std::set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(symDifference));
    
    std::cout << "Symmetric difference: ";
    for(auto num : symDifference)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Symmetric difference: 1 2 6 7 
```

### Example 2: Finding Symmetric Difference of Strings

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

int main() {
    std::vector<std::string> list1 = {"apple", "banana", "cherry"};
    std::vector<std::string> list2 = {"banana", "date", "cherry", "fig"};
    std::vector<std::string> symDifference;
    
    std::set_symmetric_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(symDifference));
    
    std::cout << "Symmetric difference of strings: ";
    for(auto &s : symDifference)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Symmetric difference of strings: apple date fig 
```

### Example 3: Using Custom Comparator for Symmetric Difference

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::vector<std::string> vec1 = {"Apple", "Banana", "Cherry"};
    std::vector<std::string> vec2 = {"banana", "Date", "Cherry", "Fig"};
    std::vector<std::string> symDifference;
    
    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    std::sort(vec1.begin(), vec1.end(), cmp);
    std::sort(vec2.begin(), vec2.end(), cmp);
    
    std::set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(symDifference), cmp);
    
    std::cout << "Symmetric difference of strings (case-insensitive): ";
    for(auto &s : symDifference)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Symmetric difference of strings (case-insensitive): apple date fig 
```

*Note: Both input ranges must be sorted according to the same comparator.*

---

## 73. set_union

### Description

`std::set_union` computes the union of two sorted ranges, copying all distinct elements from both ranges to a destination.

### Example 1: Finding Union of Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 5};
    std::vector<int> vec2 = {2, 4, 5, 6};
    std::vector<int> unionVec;
    
    std::set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(unionVec));
    
    std::cout << "Union of vectors: ";
    for(auto num : unionVec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Union of vectors: 1 2 3 4 5 6 
```

### Example 2: Union of Strings

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

int main() {
    std::vector<std::string> list1 = {"apple", "banana", "cherry"};
    std::vector<std::string> list2 = {"banana", "date", "fig"};
    std::vector<std::string> unionList;
    
    std::set_union(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(unionList));
    
    std::cout << "Union of strings: ";
    for(auto &s : unionList)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Union of strings: apple banana cherry date fig 
```

### Example 3: Using Custom Comparator for Union

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::vector<std::string> vec1 = {"Apple", "Banana", "Cherry"};
    std::vector<std::string> vec2 = {"banana", "Date", "Fig"};
    std::vector<std::string> unionVec;
    
    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    std::sort(vec1.begin(), vec1.end(), cmp);
    std::sort(vec2.begin(), vec2.end(), cmp);
    
    std::set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(unionVec), cmp);
    
    std::cout << "Union of strings (case-insensitive): ";
    for(auto &s : unionVec)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Union of strings (case-insensitive): Apple banana Cherry Date Fig 
```

*Note: Both input ranges must be sorted according to the same comparator.*

---

## 74. shuffle

### Description

`std::shuffle` randomly rearranges the elements in a range using a provided random number generator. It is the modern replacement for the deprecated `std::random_shuffle`.

### Example 1: Shuffling a Vector of Integers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(vec.begin(), vec.end(), g);
    
    std::cout << "Shuffled Vector: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Shuffled Vector: 3 1 5 2 4 
```

*Note: The output will vary with each run.*

### Example 2: Shuffling a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <random>

int main() {
    std::string s = "abcdef";
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(s.begin(), s.end(), g);
    
    std::cout << "Shuffled string: " << s << "\n";
    
    return 0;
}
```

**Output:**
```
Shuffled string: badfec
```

*Note: The output will vary with each run.*

### Example 3: Shuffling Elements in a Vector with Custom Random Number Generator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    // Using a specific seed for reproducibility
    std::mt19937 g(42);
    
    std::shuffle(vec.begin(), vec.end(), g);
    
    std::cout << "Shuffled Vector with seed 42: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Shuffled Vector with seed 42: 30 10 50 20 40 
```

*Note: Using a fixed seed results in the same shuffle order every time.*

---

## 75. sort

### Description

`std::sort` sorts the elements in a range in ascending order by default. It can also use a custom comparator to define the sorting order.

### Example 1: Sorting a Vector of Integers in Ascending Order

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {50, 20, 40, 10, 30};
    
    std::sort(vec.begin(), vec.end());
    
    std::cout << "Sorted Vector (Ascending): ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Sorted Vector (Ascending): 10 20 30 40 50 
```

### Example 2: Sorting a Vector of Strings in Descending Order

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "date"};
    
    std::sort(vec.begin(), vec.end(), [](const std::string &a, const std::string &b) -> bool {
        return a > b; // Descending order
    });
    
    std::cout << "Sorted Vector (Descending): ";
    for(auto &s : vec)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Sorted Vector (Descending): date cherry banana apple 
```

### Example 3: Sorting an Array with Custom Comparator (Even Numbers First)

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {5, 2, 8, 1, 4, 7};
    
    // Even numbers come first
    std::sort(arr.begin(), arr.end(), [](int a, int b) -> bool {
        if(a % 2 == 0 && b % 2 != 0)
            return true;
        if(a % 2 != 0 && b % 2 == 0)
            return false;
        return a < b;
    });
    
    std::cout << "Sorted Array (Even first): ";
    for(auto num : arr)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Sorted Array (Even first): 2 4 8 1 5 7 
```

*Note: Custom comparators allow defining complex sorting criteria.*

---

## 76. sort_heap

### Description

`std::sort_heap` sorts a heap into ascending order. It assumes that the range is already a valid heap.

### Example 1: Sorting a Heap into Ascending Order

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap = {50, 30, 40, 10, 20};
    
    // Create a max-heap
    std::make_heap(heap.begin(), heap.end());
    
    std::cout << "Original heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    // Sort the heap
    std::sort_heap(heap.begin(), heap.end());
    
    std::cout << "Heap after sort_heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original heap: 50 30 40 10 20 
Heap after sort_heap: 10 20 30 40 50 
```

### Example 2: Sorting a Heap of Strings

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> heap = {"delta", "alpha", "charlie", "bravo"};
    
    // Create a max-heap based on lexicographical order
    std::make_heap(heap.begin(), heap.end());
    
    std::cout << "Original heap: ";
    for(auto &s : heap)
        std::cout << s << " ";
    std::cout << "\n";
    
    // Sort the heap
    std::sort_heap(heap.begin(), heap.end());
    
    std::cout << "Heap after sort_heap: ";
    for(auto &s : heap)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original heap: delta charlie bravo alpha 
Heap after sort_heap: alpha bravo charlie delta 
```

### Example 3: Sorting a Min-Heap

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> heap = {10, 20, 15, 30, 40};
    
    // Create a min-heap using custom comparator
    auto cmp = [](int a, int b) -> bool {
        return a > b;
    };
    std::make_heap(heap.begin(), heap.end(), cmp);
    
    std::cout << "Original min-heap: ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    // Sort the heap
    std::sort_heap(heap.begin(), heap.end(), cmp);
    
    std::cout << "Heap after sort_heap (min-heap sorted): ";
    for(auto num : heap)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Original min-heap: 10 20 15 30 40 
Heap after sort_heap (min-heap sorted): 40 30 15 20 10 
```

*Note: Sorting a min-heap with `sort_heap` and a custom comparator results in descending order.*

---

## 77. stable_partition

### Description

`std::stable_partition` rearranges elements in a range so that elements satisfying a predicate come before those that do not, preserving the relative order of elements within each group.

### Example 1: Stable Partitioning Vector into Even and Odd Numbers

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {2, 1, 4, 3, 6, 5};
    
    std::stable_partition(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Vector after stable_partition (evens first): ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after stable_partition (evens first): 2 4 6 1 3 5 
```

### Example 2: Stable Partitioning Strings Based on Length

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "kiwi", "banana", "fig", "cherry"};
    
    std::stable_partition(words.begin(), words.end(), [](const std::string &s) -> bool {
        return s.length() > 4;
    });
    
    std::cout << "Words longer than 4 characters (maintaining order): ";
    for(auto &s : words)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Words longer than 4 characters (maintaining order): apple banana cherry kiwi fig 
```

### Example 3: Stable Partitioning with Custom Objects

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Employee {
    std::string name;
    double salary;
};

int main() {
    std::vector<Employee> employees = {{"Alice", 70000}, {"Bob", 50000}, {"Charlie", 60000}, {"Dave", 50000}};
    
    std::stable_partition(employees.begin(), employees.end(), [](const Employee &e) -> bool {
        return e.salary > 55000;
    });
    
    std::cout << "Employees with salary > 55000:\n";
    for(auto &e : employees)
        if(e.salary > 55000)
            std::cout << e.name << " (" << e.salary << ")\n";
    std::cout << "Employees with salary <= 55000:\n";
    for(auto &e : employees)
        if(e.salary <= 55000)
            std::cout << e.name << " (" << e.salary << ")\n";
    
    return 0;
}
```

**Output:**
```
Employees with salary > 55000:
Alice (70000)
Charlie (60000)
Employees with salary <= 55000:
Bob (50000)
Dave (50000)
```

*Note: `stable_partition` preserves the relative order within each group.*

---

## 78. stable_sort

### Description

`std::stable_sort` sorts the elements in a range while maintaining the relative order of equivalent elements. It is useful when the stability of sorting is important.

### Example 1: Stable Sorting Vector with Equivalent Elements

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 25}, {"Dave", 35}};
    
    std::stable_sort(people.begin(), people.end(), [](const Person &a, const Person &b) -> bool {
        return a.age < b.age;
    });
    
    std::cout << "People after stable_sort by age:\n";
    for(auto &p : people)
        std::cout << p.name << " (" << p.age << ")\n";
    
    return 0;
}
```

**Output:**
```
People after stable_sort by age:
Bob (25)
Charlie (25)
Alice (30)
Dave (35)
```

*Note: `Bob` and `Charlie` maintain their original relative order.*

### Example 2: Sorting Strings While Preserving Case Order

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::vector<std::string> words = {"apple", "Banana", "cherry", "Apple", "banana"};
    
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    });
    
    std::cout << "Words after stable_sort (case-insensitive): ";
    for(auto &s : words)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Words after stable_sort (case-insensitive): apple Apple Banana banana cherry 
```

*Note: "apple" and "Apple" maintain their original order relative to each other.*

### Example 3: Stable Sorting an Array of Structures

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

struct Book {
    std::string title;
    double price;
};

int main() {
    std::array<Book, 5> books = {
        Book{"Book A", 20.0},
        Book{"Book B", 15.0},
        Book{"Book C", 20.0},
        Book{"Book D", 10.0},
        Book{"Book E", 15.0}
    };
    
    std::stable_sort(books.begin(), books.end(), [](const Book &a, const Book &b) -> bool {
        return a.price < b.price;
    });
    
    std::cout << "Books after stable_sort by price:\n";
    for(auto &book : books)
        std::cout << book.title << " ($" << book.price << ")\n";
    
    return 0;
}
```

**Output:**
```
Books after stable_sort by price:
Book D ($10)
Book B ($15)
Book E ($15)
Book A ($20)
Book C ($20)
```

*Note: Books with the same price retain their original relative order.*

---

## 79. swap

### Description

`std::swap` exchanges the values of two objects.

### Example 1: Swapping Two Integers

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int a = 10;
    int b = 20;
    
    std::swap(a, b);
    
    std::cout << "After swap: a = " << a << ", b = " << b << "\n";
    
    return 0;
}
```

**Output:**
```
After swap: a = 20, b = 10
```

### Example 2: Swapping Elements in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};
    
    std::swap(vec[0], vec[2]);
    
    std::cout << "Vector after swap: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after swap: 3 2 1 
```

### Example 3: Swapping Custom Objects

```cpp
#include <iostream>
#include <algorithm>
#include <string>

struct Point {
    int x;
    int y;
};

int main() {
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    
    std::cout << "Before swap:\n";
    std::cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")\n";
    
    std::swap(p1, p2);
    
    std::cout << "After swap:\n";
    std::cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")\n";
    
    return 0;
}
```

**Output:**
```
Before swap:
p1: (1, 2)
p2: (3, 4)
After swap:
p1: (3, 4)
p2: (1, 2)
```

*Note: `std::swap` can be used with any objects that are swappable.*

---

## 80. swap_ranges

### Description

`std::swap_ranges` swaps elements between two ranges of the same size. It returns an iterator to the end of the second range.

### Example 1: Swapping Elements Between Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8, 9, 10};
    
    std::swap_ranges(vec1.begin(), vec1.end(), vec2.begin());
    
    std::cout << "vec1 after swap_ranges: ";
    for(auto num : vec1)
        std::cout << num << " ";
    std::cout << "\nvec2 after swap_ranges: ";
    for(auto num : vec2)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
vec1 after swap_ranges: 6 7 8 9 10 
vec2 after swap_ranges: 1 2 3 4 5 
```

### Example 2: Swapping Part of Two Arrays

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {6, 7, 8, 9, 10};
    
    // Swap first three elements
    std::swap_ranges(arr1.begin(), arr1.begin() + 3, arr2.begin());
    
    std::cout << "arr1 after swap_ranges: ";
    for(auto num : arr1)
        std::cout << num << " ";
    std::cout << "\narr2 after swap_ranges: ";
    for(auto num : arr2)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
arr1 after swap_ranges: 6 7 8 4 5 
arr2 after swap_ranges: 1 2 3 9 10 
```

### Example 3: Swapping Elements Between Different Containers (with Sufficient Size)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::list<int> lst = {4, 5, 6};
    
    // Convert list to vector iterator
    std::vector<int> lstAsVec(lst.begin(), lst.end());
    
    std::swap_ranges(vec.begin(), vec.end(), lstAsVec.begin());
    
    std::cout << "Vector after swap_ranges: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\nList after swap_ranges: ";
    for(auto num : lstAsVec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after swap_ranges: 4 5 6 
List after swap_ranges: 1 2 3 
```

*Note: Both ranges must have at least the number of elements being swapped.*

---

## 81. transform

### Description

`std::transform` applies a function to each element in a range and stores the result in a destination range. It can be used for unary or binary transformations.

### Example 1: Doubling Each Element in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination(source.size());
    
    std::transform(source.begin(), source.end(), destination.begin(), [](int x) -> int {
        return x * 2;
    });
    
    std::cout << "Destination after transform (double): ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after transform (double): 2 4 6 8 10 
```

### Example 2: Converting Characters to Uppercase

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::string source = "Hello World";
    std::string destination(source.size(), ' ');
    
    std::transform(source.begin(), source.end(), destination.begin(), [](char c) -> char {
        return std::toupper(c);
    });
    
    std::cout << "Destination after transform (uppercase): " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after transform (uppercase): HELLO WORLD
```

### Example 3: Adding Elements from Two Vectors

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> result(vec1.size());
    
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), [](int a, int b) -> int {
        return a + b;
    });
    
    std::cout << "Result after transform (addition): ";
    for(auto num : result)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Result after transform (addition): 5 7 9 
```

*Note: `std::transform` can operate with unary and binary functions.*

---

## 82. unique

### Description

`std::unique` removes consecutive duplicate elements from a range by moving the unique elements to the front. It returns an iterator to the new end of the range. The container size remains unchanged; to resize, use container-specific methods like `erase`.

### Example 1: Removing Consecutive Duplicates in a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    
    auto newEnd = std::unique(vec.begin(), vec.end());
    
    vec.erase(newEnd, vec.end());
    
    std::cout << "Vector after unique: ";
    for(auto num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Vector after unique: 1 2 3 4 5 
```

### Example 2: Removing Consecutive Duplicate Characters in a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "Hheellloo WWoorrldd";
    
    auto newEnd = std::unique(s.begin(), s.end(), [](char a, char b) -> bool {
        return std::tolower(a) == std::tolower(b);
    });
    
    s.erase(newEnd, s.end());
    
    std::cout << "String after unique: " << s << "\n";
    
    return 0;
}
```

**Output:**
```
String after unique: Helo World
```

### Example 3: Removing Consecutive Duplicates in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 8> arr = {5, 5, 10, 10, 10, 15, 20, 20};
    
    auto newEnd = std::unique(arr.begin(), arr.end());
    
    // Note: std::array has fixed size; elements beyond newEnd are unspecified
    std::cout << "Array after unique: ";
    for(auto it = arr.begin(); it != newEnd; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Array after unique: 5 10 15 20 
```

*Note: `std::unique` only removes consecutive duplicates. Sort the range first if needed.*

---

## 83. unique_copy

### Description

`std::unique_copy` copies elements from a source range to a destination, excluding consecutive duplicates. It can copy to an output iterator, allowing the original range to remain unchanged.

### Example 1: Copying Unique Elements from a Vector to Another Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    std::vector<int> destination;
    
    std::unique_copy(source.begin(), source.end(), std::back_inserter(destination));
    
    std::cout << "Destination after unique_copy: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after unique_copy: 1 2 3 4 5 
```

### Example 2: Unique Copying Characters from a String

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>

int main() {
    std::string source = "Hheellloo WWoorrldd";
    std::string destination;
    
    std::unique_copy(source.begin(), source.end(), std::back_inserter(destination), [](char a, char b) -> bool {
        return std::tolower(a) == std::tolower(b);
    });
    
    std::cout << "Destination after unique_copy: " << destination << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after unique_copy: Helo World
```

### Example 3: Unique Copying Elements from an Array to a Vector

```cpp
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

int main() {
    std::array<int, 8> arr = {5, 5, 10, 10, 10, 15, 20, 20};
    std::vector<int> destination;
    
    std::unique_copy(arr.begin(), arr.end(), std::back_inserter(destination));
    
    std::cout << "Destination after unique_copy: ";
    for(auto num : destination)
        std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Output:**
```
Destination after unique_copy: 5 10 15 20 
```

*Note: `unique_copy` can take a custom predicate to define uniqueness.*

---

## 84. upper_bound

### Description

`std::upper_bound` finds the first element in a sorted range that is greater than a specified value. It returns an iterator to this element or the end iterator if no such element exists.

### Example 1: Finding Upper Bound in a Sorted Vector

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 20, 30, 40, 40, 50};
    int target = 20;
    
    auto it = std::upper_bound(vec.begin(), vec.end(), target);
    
    if(it != vec.end()) {
        std::cout << "First element greater than " << target << " is " << *it << " at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No element greater than " << target << " found.\n";
    }

    return 0;
}
```

**Output:**
```
First element greater than 20 is 30 at position 3
```

### Example 2: Using Custom Comparator with upper_bound

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "date", "fig"};
    std::string target = "cherry";
    
    // Custom comparator: case-insensitive
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    // Ensure the vector is sorted with the comparator
    std::sort(vec.begin(), vec.end(), cmp);
    
    auto it = std::upper_bound(vec.begin(), vec.end(), target, cmp);
    
    if(it != vec.end()) {
        std::cout << "First string greater than \"" << target << "\" is \"" << *it << "\" at position " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "No string greater than \"" << target << "\" found.\n";
    }
    
    return 0;
}
```

**Output:**
```
First string greater than "cherry" is "date" at position 3
```

### Example 3: Finding Upper Bound in an Array

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 6> arr = {5, 10, 10, 15, 20, 25};
    int target = 10;
    
    auto it = std::upper_bound(arr.begin(), arr.end(), target);
    
    if(it != arr.end()) {
        std::cout << "First element greater than " << target << " is " << *it << " at index " << std::distance(arr.begin(), it) << "\n";
    } else {
        std::cout << "No element greater than " << target << " found in the array.\n";
    }

    return 0;
}
```

**Output:**
```
First element greater than 10 is 15 at index 3
```

*Note: The range must be sorted according to the same comparator used by `upper_bound`.*

---

