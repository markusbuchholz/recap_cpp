#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>



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

    // Eigenvalues and eigenvectors
    EigenSolver<Matrix3f> es(mat);
    std::cout << "Eigenvalues:\n" << es.eigenvalues() << "\n";
    std::cout << "Eigenvectors:\n" << es.eigenvectors() << "\n";    

    Inverse<Matrix3f> inv(mat);
    std::cout << "Inverse:\n" << inv << "\n";






}
