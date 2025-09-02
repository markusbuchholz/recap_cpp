# Eigen 2

# 1. Homogeneous Transformation Matrix (4×4)

A 3D pose (rotation + translation) is often represented as a 4×4 homogeneous transform.

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    // Rotation (90° about Z axis)
    Matrix3d R;
    R = AngleAxisd(M_PI/2, Vector3d::UnitZ());

    // Translation (x=1, y=2, z=3)
    Vector3d t(1, 2, 3);

    // Build 4x4 homogeneous transform
    Matrix4d T = Matrix4d::Identity();
    T.block<3,3>(0,0) = R;  // top-left 3x3 = rotation
    T.block<3,1>(0,3) = t;  // top-right 3x1 = translation

    std::cout << "Homogeneous transform T:\n" << T << "\n";

    // Apply transform to a point
    Vector4d p(1, 0, 0, 1);  // homogeneous point
    Vector4d p_new = T * p;

    std::cout << "Transformed point:\n" << p_new.transpose() << "\n";
}
```

Output:

```
Homogeneous transform T:
 0 -1  0  1
 1  0  0  2
 0  0  1  3
 0  0  0  1

Transformed point:
1 3 3 1
```

---

# 2. Rotation Matrices and Euler Angles

Eigen provides handy conversions.

```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    // Define rotation from roll-pitch-yaw (ZYX order)
    Vector3d rpy(M_PI/2, 0, M_PI/4); // roll, pitch, yaw
    Matrix3d R;
    R = AngleAxisd(rpy[2], Vector3d::UnitZ())
      * AngleAxisd(rpy[1], Vector3d::UnitY())
      * AngleAxisd(rpy[0], Vector3d::UnitX());

    std::cout << "Rotation matrix:\n" << R << "\n";

    // Convert back to Euler angles
    Vector3d euler = R.eulerAngles(2,1,0); // yaw-pitch-roll
    std::cout << "Recovered yaw-pitch-roll: " 
              << euler.transpose() << "\n";
}
```

---

# 3. Quaternions

Quaternions are widely used for 3D rotations in robotics.

```cpp
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace Eigen;

int main() {
    // Define quaternion from axis-angle (90° around Z)
    AngleAxisd aa(M_PI/2, Vector3d::UnitZ());
    Quaterniond q(aa);

    std::cout << "Quaternion (x,y,z,w): "
              << q.coeffs().transpose() << "\n"; // note: coeffs = (x,y,z,w)

    // Rotate a vector using quaternion
    Vector3d v(1,0,0);
    Vector3d v_rotated = q * v;
    std::cout << "Rotated vector: " << v_rotated.transpose() << "\n";

    // Convert quaternion to rotation matrix
    Matrix3d R = q.toRotationMatrix();
    std::cout << "Rotation matrix:\n" << R << "\n";
}
```

Output:

```
Quaternion (x,y,z,w): 0 0 0.707107 0.707107
Rotated vector: 0 1 0
Rotation matrix:
 0 -1  0
 1  0  0
 0  0  1
```

---

# 4. Example: Forward Kinematics for a Simple Robot Arm

```cpp
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace Eigen;

int main() {
    // Joint 1: rotate about Z by 90°, translate along X by 1
    Matrix4d T1 = Matrix4d::Identity();
    T1.block<3,3>(0,0) = AngleAxisd(M_PI/2, Vector3d::UnitZ()).toRotationMatrix();
    T1(0,3) = 1.0;

    // Joint 2: rotate about Y by 90°, translate along Z by 2
    Matrix4d T2 = Matrix4d::Identity();
    T2.block<3,3>(0,0) = AngleAxisd(M_PI/2, Vector3d::UnitY()).toRotationMatrix();
    T2(2,3) = 2.0;

    // End-effector transform = T1 * T2
    Matrix4d T = T1 * T2;
    std::cout << "End effector transform:\n" << T << "\n";
}
```

---


