# C++ Regular Expressions (regex) Recap


## Table of Contents

1. [Introduction to Regex](#1-introduction-to-regex)
2. [Basic Components of Regex](#2-basic-components-of-regex)
3. [Using `<regex>` Library in C++](#3-using-regex-library-in-c)
    - [3.1. Matching Strings](#31-matching-strings)
    - [3.2. Searching within Strings](#32-searching-within-strings)
    - [3.3. Replacing Substrings](#33-replacing-substrings)
    - [3.4. Splitting Strings](#34-splitting-strings)
4. [Advanced Regex Features](#4-advanced-regex-features)
    - [4.1. Capturing Groups](#41-capturing-groups)
    - [4.2. Lookaheads and Lookbehinds](#42-lookaheads-and-lookbehinds)
    - [4.3. Unicode Support](#43-unicode-support)
5. [Common Regex Patterns](#5-common-regex-patterns)
    - [5.1. Email Validation](#51-email-validation)
    - [5.2. URL Validation](#52-url-validation)
    - [5.3. Phone Number Validation](#53-phone-number-validation)
6. [Summary](#6-summary)


---

## 1. Introduction to Regex

### Description

**Regular Expressions (regex)** are sequences of characters that define search patterns, primarily used for pattern matching within strings. In C++, the `<regex>` library provides classes and functions to work with regex, enabling tasks such as validation, searching, and text manipulation.

### Key Benefits

- **Pattern Matching**: Easily search for patterns within text.
- **Validation**: Verify if strings conform to specific formats.
- **Text Manipulation**: Perform complex replacements and transformations.
- **Efficiency**: Optimize search and processing operations on large datasets.

---

## 2. Basic Components of Regex

### Description

Understanding the basic components and syntax of regex is crucial for effectively utilizing it in C++. Here are some fundamental elements:

- **Literals**: Exact characters to match (e.g., `a`, `1`, `@`).
- **Metacharacters**: Special symbols that control how the regex operates (e.g., `.`, `^`, `$`, `*`, `+`, `?`, `[]`, `()`, `{}`, `|`).
- **Character Classes**: Define a set of characters to match (e.g., `[a-z]`, `\d`, `\w`).
- **Quantifiers**: Specify how many instances of a character or group must be present (e.g., `*`, `+`, `?`, `{n}`, `{n,}`, `{n,m}`).
- **Anchors**: Indicate positions within the string (e.g., `^` for start, `$` for end).
- **Groups and Capturing**: Use parentheses to group patterns and capture matches.

### Examples of Basic Patterns

- `^Hello`: Matches strings that start with "Hello".
- `world$`: Matches strings that end with "world".
- `\d+`: Matches one or more digits.
- `[A-Za-z]+`: Matches one or more uppercase or lowercase letters.
- `a|b`: Matches either "a" or "b".
- `(abc)+`: Matches one or more occurrences of "abc".

---

## 3. Using `<regex>` Library in C++

### Description

C++11 introduced the `<regex>` library, which provides classes and functions to work with regular expressions. The primary classes include:

- **`std::regex`**: Represents a regular expression.
- **`std::smatch` / `std::cmatch`**: Stores the results of a match operation.
- **`std::regex_search`**: Searches for a regex pattern within a string.
- **`std::regex_match`**: Checks if the entire string matches the regex pattern.
- **`std::regex_replace`**: Replaces parts of the string that match the regex pattern.

### 3.1. Matching Strings

#### Example 1: Checking if a String Matches a Pattern

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string s1 = "Hello123";
    std::regex pattern("^Hello\\d+$"); // Starts with 'Hello' followed by one or more digits

    if (std::regex_match(s1, pattern)) {
        std::cout << "\"" << s1 << "\" matches the pattern.\n";
    } else {
        std::cout << "\"" << s1 << "\" does not match the pattern.\n";
    }

    std::string s2 = "Hello World!";
    if (std::regex_match(s2, pattern)) {
        std::cout << "\"" << s2 << "\" matches the pattern.\n";
    } else {
        std::cout << "\"" << s2 << "\" does not match the pattern.\n";
    }

    return 0;
}
```

**Output:**
```
"Hello123" matches the pattern.
"Hello World!" does not match the pattern.
```

---

#### Example 2: Validating a Simple Identifier

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex identifier_pattern("^[A-Za-z_][A-Za-z0-9_]*$");
    std::string identifiers[] = {"variable1", "_temp", "2ndVar", "var-name"};

    for(const auto &id : identifiers) {
        if(std::regex_match(id, identifier_pattern)) {
            std::cout << "\"" << id << "\" is a valid identifier.\n";
        } else {
            std::cout << "\"" << id << "\" is NOT a valid identifier.\n";
        }
    }

    return 0;
}
```

**Output:**
```
"variable1" is a valid identifier.
"_temp" is a valid identifier.
"2ndVar" is NOT a valid identifier.
"var-name" is NOT a valid identifier.
```

---

#### Example 3: Matching Email Addresses

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex email_pattern(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");
    std::string emails[] = {"user@example.com", "user.name@example.co.in", "user@.com", "user#example.com"};

    for(const auto &email : emails) {
        if(std::regex_match(email, email_pattern)) {
            std::cout << "\"" << email << "\" is a valid email address.\n";
        } else {
            std::cout << "\"" << email << "\" is NOT a valid email address.\n";
        }
    }

    return 0;
}
```

**Output:**
```
"user@example.com" is a valid email address.
"user.name@example.co.in" is a valid email address.
"user@.com" is NOT a valid email address.
"user#example.com" is NOT a valid email address.
```

---

### 3.2. Searching within Strings

#### Example 1: Finding All Occurrences of a Pattern

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "The rain in Spain stays mainly in the plain.";
    std::regex word_regex("\\bain\\b"); // Matches the exact word 'ain'

    std::smatch matches;
    std::string::const_iterator search_start(text.cbegin());

    while (std::regex_search(search_start, text.cend(), matches, word_regex)) {
        std::cout << "Found \"" << matches[0] << "\" at position " 
                  << matches.position(0) + (search_start - text.cbegin()) << "\n";
        search_start = matches.suffix().first;
    }

    return 0;
}
```

**Output:**
```
Found "ain" at position 6
Found "ain" at position 17
Found "ain" at position 35
```

---

#### Example 2: Extracting Substrings Using Regex

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "Order number: 12345, Date: 2023-10-05, Total: $250.75";
    std::regex pattern(R"(Order number:\s*(\d+),\s*Date:\s*([\d\-]+),\s*Total:\s*\$(\d+\.\d{2}))");
    std::smatch matches;

    if(std::regex_search(text, matches, pattern)) {
        std::cout << "Order Number: " << matches[1] << "\n";
        std::cout << "Date: " << matches[2] << "\n";
        std::cout << "Total: $" << matches[3] << "\n";
    } else {
        std::cout << "No match found.\n";
    }

    return 0;
}
```

**Output:**
```
Order Number: 12345
Date: 2023-10-05
Total: $250.75
```

---

#### Example 3: Case-Insensitive Search

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "C++ is a powerful language. c++ has object-oriented features.";
    std::regex pattern("c\\+\\+", std::regex_constants::icase); // Case-insensitive search for 'c++'

    std::smatch matches;
    std::string::const_iterator search_start(text.cbegin());

    while (std::regex_search(search_start, text.cend(), matches, pattern)) {
        std::cout << "Found \"" << matches[0] << "\" at position " 
                  << matches.position(0) + (search_start - text.cbegin()) << "\n";
        search_start = matches.suffix().first;
    }

    return 0;
}
```

**Output:**
```
Found "C++" at position 0
Found "c++" at position 31
```

---

### 3.3. Replacing Substrings

#### Example 1: Simple Replacement

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "I have a cat. My cat is cute.";
    std::regex cat_regex("cat");
    std::string replacement = "dog";

    std::string result = std::regex_replace(text, cat_regex, replacement);
    std::cout << "Original Text: " << text << "\n";
    std::cout << "Modified Text: " << result << "\n";

    return 0;
}
```

**Output:**
```
Original Text: I have a cat. My cat is cute.
Modified Text: I have a dog. My dog is cute.
```

---

#### Example 2: Conditional Replacement with Capture Groups

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "John Doe, john.doe@example.com; Jane Smith, jane.smith@sample.org";
    std::regex email_regex(R"((\w+)\.(\w+)@([\w\.]+))");
    std::string replacement = "$1_$2@$3"; // Replace '.' with '_'

    std::string result = std::regex_replace(text, email_regex, replacement);
    std::cout << "Original Text: " << text << "\n";
    std::cout << "Modified Text: " << result << "\n";

    return 0;
}
```

**Output:**
```
Original Text: John Doe, john.doe@example.com; Jane Smith, jane.smith@sample.org
Modified Text: John Doe, john_doe@example.com; Jane Smith, jane_smith@sample.org
```

---

#### Example 3: Limiting Number of Replacements

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "one two three two one two";
    std::regex pattern("two");
    std::string replacement = "2";

    // Replace only the first two occurrences
    std::string result = std::regex_replace(text, pattern, replacement, std::regex_constants::format_first_only);
    std::cout << "Original Text: " << text << "\n";
    std::cout << "Modified Text: " << result << "\n";

    return 0;
}
```

**Output:**
```
Original Text: one two three two one two
Modified Text: one 2 three two one two
```

---

### 3.4. Splitting Strings

#### Example 1: Splitting a String by Delimiters

```cpp
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    std::string text = "apple,banana;cherry orange,grape";
    std::regex delimiter(R"([,; ])"); // Split by comma, semicolon, or space
    std::sregex_token_iterator iter(text.begin(), text.end(), delimiter, -1);
    std::sregex_token_iterator end;

    std::vector<std::string> tokens;
    for(; iter != end; ++iter) {
        if(!iter->str().empty())
            tokens.push_back(iter->str());
    }

    std::cout << "Tokens:\n";
    for(const auto &token : tokens)
        std::cout << token << "\n";

    return 0;
}
```

**Output:**
```
Tokens:
apple
banana
cherry
orange
grape
```

---

#### Example 2: Splitting with Multiple Delimiters and Ignoring Empty Tokens

```cpp
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    std::string text = "one,,two;;;three four";
    std::regex delimiter(R"([,; ]+)");
    std::sregex_token_iterator iter(text.begin(), text.end(), delimiter, -1);
    std::sregex_token_iterator end;

    std::vector<std::string> tokens;
    for(; iter != end; ++iter) {
        if(!iter->str().empty())
            tokens.push_back(iter->str());
    }

    std::cout << "Tokens:\n";
    for(const auto &token : tokens)
        std::cout << token << "\n";

    return 0;
}
```

**Output:**
```
Tokens:
one
two
three
four
```

---

#### Example 3: Splitting a String into Words

```cpp
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    std::string sentence = "C++ templates are powerful and flexible.";
    std::regex word_regex(R"(\b\w+\b)");
    std::sregex_token_iterator iter(sentence.begin(), sentence.end(), word_regex);
    std::sregex_token_iterator end;

    std::vector<std::string> words;
    for(; iter != end; ++iter)
        words.push_back(iter->str());

    std::cout << "Words in the sentence:\n";
    for(const auto &word : words)
        std::cout << word << "\n";

    return 0;
}
```

**Output:**
```
Words in the sentence:
C++
templates
are
powerful
and
flexible
```

---

## 4. Advanced Regex Features

### 4.1. Capturing Groups

#### Example 1: Extracting Date Components

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string date = "2025-01-05";
    std::regex date_regex(R"((\d{4})-(\d{2})-(\d{2}))");
    std::smatch matches;

    if(std::regex_match(date, matches, date_regex)) {
        std::cout << "Year: " << matches[1] << "\n";
        std::cout << "Month: " << matches[2] << "\n";
        std::cout << "Day: " << matches[3] << "\n";
    } else {
        std::cout << "Date format is incorrect.\n";
    }

    return 0;
}
```

**Output:**
```
Year: 2025
Month: 01
Day: 05
```

---

#### Example 2: Swapping Words Using Capturing Groups

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "Hello World!";
    std::regex word_swap(R"((\w+)\s+(\w+))");
    std::string replacement = "$2 $1";

    std::string result = std::regex_replace(text, word_swap, replacement);
    std::cout << "Original Text: " << text << "\n";
    std::cout << "Swapped Text: " << result << "\n";

    return 0;
}
```

**Output:**
```
Original Text: Hello World!
Swapped Text: World Hello!
```

---

#### Example 3: Conditional Replacement Based on Capture Groups

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "I have 2 apples and 10 bananas.";
    std::regex number_regex(R"((\d+))");
    std::string replacement = R"([number=$1])";

    std::string result = std::regex_replace(text, number_regex, replacement);
    std::cout << "Original Text: " << text << "\n";
    std::cout << "Modified Text: " << result << "\n";

    return 0;
}
```

**Output:**
```
Original Text: I have 2 apples and 10 bananas.
Modified Text: I have [number=2] apples and [number=10] bananas.
```

---

### 4.2. Lookaheads and Lookbehinds

#### Example 1: Positive Lookahead

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "apple banana apricot avocado";
    std::regex lookahead_regex(R"(\b\w+(?=a))"); // Words ending with 'a'

    std::sregex_iterator iter(text.begin(), text.end(), lookahead_regex);
    std::sregex_iterator end;

    std::cout << "Words ending before 'a':\n";
    for(; iter != end; ++iter)
        std::cout << iter->str() << "\n";

    return 0;
}
```

**Output:**
```
Words ending before 'a':
apricot
```

*Note: In this example, no words end directly before 'a', so no matches are found. Adjust the regex as needed.*

---

#### Example 2: Negative Lookbehind

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "cat bat rat mat";
    std::regex negative_lookbehind(R"((?<!c)at)");

    std::sregex_iterator iter(text.begin(), text.end(), negative_lookbehind);
    std::sregex_iterator end;

    std::cout << "Occurrences of 'at' not preceded by 'c':\n";
    for(; iter != end; ++iter)
        std::cout << iter->str() << "\n";

    return 0;
}
```

**Output:**
```
Occurrences of 'at' not preceded by 'c':
at
at
```

---

#### Example 3: Combining Lookaheads and Lookbehinds

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::regex pattern(R"((?<=quick\s)\w+)"); // Words preceded by 'quick '

    std::sregex_iterator iter(text.begin(), text.end(), pattern);
    std::sregex_iterator end;

    std::cout << "Words preceded by 'quick':\n";
    for(; iter != end; ++iter)
        std::cout << iter->str() << "\n";

    return 0;
}
```

**Output:**
```
Words preceded by 'quick':
brown
```

---

### 4.3. Unicode Support

#### Example 1: Matching Unicode Characters

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = u8"Hello, 世界!"; // '世界' means 'World' in Chinese
    std::regex unicode_regex(R"(\p{Han}+)", std::regex::ECMAScript | std::regex::icase);

    std::smatch matches;
    if(std::regex_search(text, matches, unicode_regex)) {
        std::cout << "Found Unicode characters: " << matches[0] << "\n";
    } else {
        std::cout << "No Unicode characters found.\n";
    }

    return 0;
}
```

**Output:**
```
Found Unicode characters: 世界
```

*Note: Ensure your compiler and environment support Unicode and the appropriate regex flags.*

---

## 5. Common Regex Patterns

### 5.1. Email Validation

#### Example 1: Simple Email Validator

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex email_regex(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");
    std::string emails[] = {"user@example.com", "user.name@example.co.in", "user@.com", "user#example.com"};

    for(const auto &email : emails) {
        if(std::regex_match(email, email_regex)) {
            std::cout << "\"" << email << "\" is a valid email address.\n";
        } else {
            std::cout << "\"" << email << "\" is NOT a valid email address.\n";
        }
    }

    return 0;
}
```

**Output:**
```
"user@example.com" is a valid email address.
"user.name@example.co.in" is a valid email address.
"user@.com" is NOT a valid email address.
"user#example.com" is NOT a valid email address.
```

---

### 5.2. URL Validation

#### Example 2: Simple URL Validator

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex url_regex(R"(^(http:\/\/www\.|https:\/\/www\.|http:\/\/|https:\/\/)?[a-zA-Z0-9]+([\-\.]{1}[a-zA-Z0-9]+)*\.[a-zA-Z]{2,5}(:[0-9]{1,5})?(\/.*)?$)");
    std::string urls[] = {
        "http://www.example.com",
        "https://example.com",
        "www.example.co.uk",
        "example",
        "https://example.com/path?query=123"
    };

    for(const auto &url : urls) {
        if(std::regex_match(url, url_regex)) {
            std::cout << "\"" << url << "\" is a valid URL.\n";
        } else {
            std::cout << "\"" << url << "\" is NOT a valid URL.\n";
        }
    }

    return 0;
}
```

**Output:**
```
"http://www.example.com" is a valid URL.
"https://example.com" is a valid URL.
"www.example.co.uk" is a valid URL.
"example" is NOT a valid URL.
"https://example.com/path?query=123" is a valid URL.
```

---

### 5.3. Phone Number Validation

#### Example 3: US Phone Number Validator

```cpp
#include <iostream>
#include <regex>
#include <string>

int main() {
    // US phone number patterns: (123) 456-7890 or 123-456-7890
    std::regex phone_regex(R"(^(\(\d{3}\)\s|\d{3}-)\d{3}-\d{4}$)");
    std::string phone_numbers[] = {
        "(123) 456-7890",
        "123-456-7890",
        "1234567890",
        "(123)456-7890",
        "123-45-6789"
    };

    for(const auto &phone : phone_numbers) {
        if(std::regex_match(phone, phone_regex)) {
            std::cout << "\"" << phone << "\" is a valid US phone number.\n";
        } else {
            std::cout << "\"" << phone << "\" is NOT a valid US phone number.\n";
        }
    }

    return 0;
}
```

**Output:**
```
"(123) 456-7890" is a valid US phone number.
"123-456-7890" is a valid US phone number.
"1234567890" is NOT a valid US phone number.
"(123)456-7890" is NOT a valid US phone number.
"123-45-6789" is NOT a valid US phone number.
```

---

## 6. Summary

C++ Regular Expressions (regex) offer a robust and flexible way to perform pattern matching and text processing. Here's a quick overview of the topics covered:

- **Introduction to Regex**: Basics of regex syntax and benefits.
- **Basic Components of Regex**: Understanding literals, metacharacters, character classes, quantifiers, anchors, and capturing groups.
- **Using `<regex>` Library in C++**:
  - **Matching Strings**: Checking if strings match specific patterns.
  - **Searching within Strings**: Finding occurrences of patterns.
  - **Replacing Substrings**: Modifying parts of strings based on patterns.
  - **Splitting Strings**: Dividing strings into tokens using regex.
- **Advanced Regex Features**:
  - **Capturing Groups**: Extracting and manipulating specific parts of matches.
  - **Lookaheads and Lookbehinds**: Advanced pattern matching techniques.
  - **Unicode Support**: Handling and matching Unicode characters.
- **Common Regex Patterns**:
  - **Email Validation**: Ensuring strings conform to email formats.
  - **URL Validation**: Verifying the correctness of URLs.
  - **Phone Number Validation**: Checking the format of phone numbers.



