# Eigen

#  1. Install Eigen on Ubuntu 24.04

Eigen is **header-only** (no linking needed). Just install the headers:

```bash
sudo apt update
sudo apt install libeigen3-dev
```

It gets installed to:

```
/usr/include/eigen3/
```

---

#  2. Compile Eigen Programs

Since Eigen is header-only, you just include it and compile normally:

```bash
g++ -std=c++17 myprog.cpp -I /usr/include/eigen3 -o myprog
```

(`-I /usr/include/eigen3` is usually optional on Ubuntu because Eigen adds a symlink in `/usr/include/eigen3/Eigen`.)

---

#  3. Examples of Eigen Usage

Let’s go through **several core examples**.

---

## Example 1: Basic Matrix and Vector

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    // Define a 3x3 matrix and a 3D vector
    Matrix3f mat;
    Vector3f vec;

    mat << 1, 2, 3,
           4, 5, 6,
           7, 8, 9;

    vec << 1, 0, 1;

    std::cout << "Matrix:\n" << mat << "\n\n";
    std::cout << "Vector:\n" << vec << "\n\n";

    // Matrix * Vector multiplication
    Vector3f result = mat * vec;
    std::cout << "Result = mat * vec:\n" << result << "\n";
}
```

Output:

```
Matrix:
1 2 3
4 5 6
7 8 9

Vector:
1
0
1

Result = mat * vec:
4
10
16
```

---

## Example 2: Matrix Operations

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    Matrix2d A;
    A << 1, 2,
         3, 4;

    std::cout << "A =\n" << A << "\n\n";
    std::cout << "Transpose:\n" << A.transpose() << "\n\n";
    std::cout << "Determinant: " << A.determinant() << "\n\n";
    std::cout << "Inverse:\n" << A.inverse() << "\n\n";
}
```

Output:

```
A =
1 2
3 4

Transpose:
1 3
2 4

Determinant: -2

Inverse:
-2  1
1.5 -0.5
```

---

## Example 3: Vectors and Dot/Cross Product

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    Vector3d u(1, 2, 3);
    Vector3d v(4, 5, 6);

    std::cout << "u dot v = " << u.dot(v) << "\n";
    std::cout << "u cross v = \n" << u.cross(v) << "\n";
}
```

Output:

```
u dot v = 32
u cross v =
-3
6
-3
```

---

## Example 4: Solving Linear Systems

Solve $Ax = b$.

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    Matrix3f A;
    Vector3f b;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 10;
    b << 3, 3, 4;

    Vector3f x = A.colPivHouseholderQr().solve(b);

    std::cout << "Solution x:\n" << x << "\n";
}
```

Output:

```
Solution x:
-2
 1
 1
```

---

## Example 5: Eigenvalues and Eigenvectors

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    Matrix2d A;
    A << 3, 1,
         0, 2;

    EigenSolver<Matrix2d> es(A);

    std::cout << "Eigenvalues:\n" << es.eigenvalues() << "\n";
    std::cout << "Eigenvectors:\n" << es.eigenvectors() << "\n";
}
```

Example Output:

```
Eigenvalues:
(3,0)
(2,0)

Eigenvectors:
1 0.707107
0 0.707107
```

---

