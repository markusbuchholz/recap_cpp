# C++ File Input/Output (I/O) Recap


## Table of Contents

1. [Introduction to File I/O](#1-introduction-to-file-io)
2. [Reading from Files](#2-reading-from-files)
    - [2.1. Reading a File Line by Line into a Vector](#21-reading-a-file-line-by-line-into-a-vector)
    - [2.2. Reading Words into a Set](#22-reading-words-into-a-set)
    - [2.3. Parsing CSV Data into a Map](#23-parsing-csv-data-into-a-map)
3. [Writing to Files](#3-writing-to-files)
    - [3.1. Writing Data from a Vector to a File](#31-writing-data-from-a-vector-to-a-file)
    - [3.2. Writing a Map to a File](#32-writing-a-map-to-a-file)
    - [3.3. Appending to a File](#33-appending-to-a-file)
4. [Common File Operations](#4-common-file-operations)
    - [4.1. Checking if a File Exists](#41-checking-if-a-file-exists)
    - [4.2. Handling File Errors](#42-handling-file-errors)
    - [4.3. Reading Binary Files](#43-reading-binary-files)
5. [Summary](#5-summary)


---

## 1. Introduction to File I/O

### Description

**File Input/Output (I/O)** in C++ allows programs to interact with files on the filesystem. This enables reading data from files, writing data to files, and manipulating file contents. The `<fstream>` library provides classes such as `std::ifstream` for reading, `std::ofstream` for writing, and `std::fstream` for both reading and writing.

### Key Classes

- **`std::ifstream`**: Input file stream for reading from files.
- **`std::ofstream`**: Output file stream for writing to files.
- **`std::fstream`**: File stream for both reading and writing.

### Key Operations

- **Opening Files**: Specify the file path and mode.
- **Closing Files**: Release file resources.
- **Reading Data**: Extract data using `>>`, `getline()`, or other methods.
- **Writing Data**: Insert data using `<<` operator.
- **Error Handling**: Check if file operations succeed.

---

## 2. Reading from Files

### 2.1. Reading a File Line by Line into a Vector

#### Description

Reading a file line by line and storing each line into a container such as `std::vector` is a common operation for processing text data.

#### Example 1: Reading Lines into a Vector

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("sample.txt");
    if(!file.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    std::cout << "File Contents:\n";
    for(const auto &l : lines) {
        std::cout << l << "\n";
    }

    return 0;
}
```

**Assuming `sample.txt` contains:**

```
Hello, World!
Welcome to C++ File I/O.
This is the third line.
```

**Output:**

```
File Contents:
Hello, World!
Welcome to C++ File I/O.
This is the third line.
```

---

### 2.2. Reading Words into a Set

#### Description

Reading individual words from a file and storing them in a `std::set` ensures that each word is unique and automatically sorted.

#### Example 2: Reading Words into a Set

```cpp
#include <iostream>
#include <fstream>
#include <set>
#include <string>

int main() {
    std::ifstream file("words.txt");
    if(!file.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    std::set<std::string> uniqueWords;
    std::string word;
    while(file >> word) {
        uniqueWords.insert(word);
    }

    file.close();

    std::cout << "Unique Words:\n";
    for(const auto &w : uniqueWords) {
        std::cout << w << "\n";
    }

    return 0;
}
```

**Assuming `words.txt` contains:**

```
apple banana apple orange banana grape
```

**Output:**

```
Unique Words:
apple
banana
grape
orange
```

---

### 2.3. Parsing CSV Data into a Map

#### Description

Parsing CSV (Comma-Separated Values) files involves reading data separated by commas and storing it into appropriate containers like `std::map` for key-value pairs.

#### Example 3: Parsing CSV into a Map

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("data.csv");
    if(!file.is_open()) {
        std::cerr << "Failed to open the CSV file.\n";
        return 1;
    }

    std::map<std::string, int> dataMap;
    std::string line;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key;
        int value;
        if(std::getline(ss, key, ',') && (ss >> value)) {
            dataMap[key] = value;
        }
    }

    file.close();

    std::cout << "CSV Data:\n";
    for(const auto &pair : dataMap) {
        std::cout << pair.first << " : " << pair.second << "\n";
    }

    return 0;
}
```

**Assuming `data.csv` contains:**

```
Apple,50
Banana,30
Orange,20
Grape,40
```

**Output:**

```
CSV Data:
Apple : 50
Banana : 30
Grape : 40
Orange : 20
```

---

## 3. Writing to Files

### 3.1. Writing Data from a Vector to a File

#### Description

Writing data from a container such as `std::vector` to a file involves iterating over the container and writing each element to the file using `std::ofstream`.

#### Example 1: Writing Vector Contents to a File

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry", "Date"};

    std::ofstream file("output.txt");
    if(!file.is_open()) {
        std::cerr << "Failed to open the file for writing.\n";
        return 1;
    }

    for(const auto &fruit : fruits) {
        file << fruit << "\n";
    }

    file.close();
    std::cout << "Data written to output.txt successfully.\n";

    return 0;
}
```

**Output:**

```
Data written to output.txt successfully.
```

**Resulting `output.txt`:**

```
Apple
Banana
Cherry
Date
```

---

### 3.2. Writing a Map to a File

#### Description

Writing key-value pairs from a `std::map` to a file allows for structured data storage, such as configuration files or lookup tables.

#### Example 2: Writing Map Contents to a File

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> inventory = {
        {"Apples", 50},
        {"Bananas", 30},
        {"Cherries", 20},
        {"Dates", 40}
    };

    std::ofstream file("inventory.txt");
    if(!file.is_open()) {
        std::cerr << "Failed to open inventory.txt for writing.\n";
        return 1;
    }

    for(const auto &item : inventory) {
        file << item.first << "," << item.second << "\n";
    }

    file.close();
    std::cout << "Inventory data written to inventory.txt successfully.\n";

    return 0;
}
```

**Output:**

```
Inventory data written to inventory.txt successfully.
```

**Resulting `inventory.txt`:**

```
Apples,50
Bananas,30
Cherries,20
Dates,40
```

---

### 3.3. Appending to a File

#### Description

Appending data to an existing file involves opening the file in append mode (`std::ios::app`) to add new content without overwriting the existing data.

#### Example 3: Appending Data to a File

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream file("log.txt", std::ios::app);
    if(!file.is_open()) {
        std::cerr << "Failed to open log.txt for appending.\n";
        return 1;
    }

    std::string logEntry = "New log entry at " + std::to_string(time(nullptr));
    file << logEntry << "\n";

    file.close();
    std::cout << "Log entry appended to log.txt successfully.\n";

    return 0;
}
```

**Output:**

```
Log entry appended to log.txt successfully.
```

**Resulting `log.txt` after multiple runs:**

```
New log entry at 1701360023
New log entry at 1701360030
```

*Note: The timestamps will vary based on when the program is run.*

---

## 4. Common File Operations

### 4.1. Checking if a File Exists

#### Description

Before performing file operations, it's often necessary to check if a file exists to avoid errors or unintended behavior.

#### Example 1: Checking File Existence

```cpp
#include <iostream>
#include <fstream>
#include <string>

bool fileExists(const std::string &filename) {
    std::ifstream file(filename);
    return file.good();
}

int main() {
    std::string filename = "sample.txt";

    if(fileExists(filename)) {
        std::cout << filename << " exists.\n";
    } else {
        std::cout << filename << " does not exist.\n";
    }

    return 0;
}
```

**Output (assuming `sample.txt` exists):**

```
sample.txt exists.
```

**Output (if `sample.txt` does not exist):**

```
sample.txt does not exist.
```

---

### 4.2. Handling File Errors

#### Description

Proper error handling ensures that your program can gracefully handle scenarios where file operations fail, such as attempting to read a non-existent file or encountering read/write errors.

#### Example 2: Handling File Open Errors

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "nonexistent.txt";
    std::ifstream file(filename);

    if(!file) {
        std::cerr << "Error: Unable to open " << filename << " for reading.\n";
        return 1;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << "\n";
    }

    file.close();
    return 0;
}
```

**Output:**

```
Error: Unable to open nonexistent.txt for reading.
```

---

### 4.3. Reading Binary Files

#### Description

Reading binary files involves handling data in binary format, which is essential for applications that process non-text data like images, audio files, or custom binary formats.

#### Example 3: Reading a Binary File

```cpp
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::string filename = "data.bin";

    // Open the file in binary mode
    std::ifstream file(filename, std::ios::binary);
    if(!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for reading.\n";
        return 1;
    }

    // Read the binary data into a vector
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    std::cout << "Read " << buffer.size() << " bytes from " << filename << ".\n";

    return 0;
}
```

**Output (assuming `data.bin` contains 100 bytes):**

```
Read 100 bytes from data.bin.
```

*Note: Ensure that `data.bin` exists and contains binary data.*

---

## 5. Summary

C++ File I/O operations are essential for interacting with data stored in files, enabling tasks such as data processing, storage, and retrieval. Here's a quick overview of the topics covered:

- **Reading from Files**:
  - Reading lines into containers like `std::vector`.
  - Extracting unique words using `std::set`.
  - Parsing structured data like CSV into `std::map`.

- **Writing to Files**:
  - Writing data from containers (e.g., `std::vector`, `std::map`) to files.
  - Appending data to existing files without overwriting.

- **Common File Operations**:
  - Checking file existence to prevent errors.
  - Handling file operation errors gracefully.
  - Reading binary files for non-text data processing.

- **Best Practices**:
  - Always check if a file is successfully opened before performing operations.
  - Properly close files to release resources.
  - Use appropriate containers based on the data and required operations.
  - Handle binary and text data appropriately using the correct modes.

