// vector_lib.cpp
#include "vector_lib.h"
#include <stdexcept> // ��� std::exception
#include <cmath>

// ����������� �� ��������� - ������� ������ ������� �����
Vector::Vector() {}

// �����������, ��������� ������ �������� ����������� � ���������������� ��� ������
Vector::Vector(int size) : data(size, 0.0) {}

// ����������� �����������
Vector::Vector(const Vector& other) : data(other.data) {}

// �������� ������� � �������� ������� �� ������� []
double& Vector::operator[](int index) {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}


// �������� ������������ =
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

void Vector::fill(const std::vector<double>& values) {
    if (values.size() == data.size()) {
        for (int i = 0; i < data.size(); ++i) {
            data[i] = values[i];
        }
    }
    else {
        std::cerr << "Error: Vector sizes do not match." << std::endl;
        throw std::exception();
    }
}


// ����� ��� ���������� ����� �������
double Vector::length() const {
    double sum = 0.0;
    for (double val : data) {
        sum += val * val;
    }
    return std::sqrt(sum);
}

// �������� ��������� �� ������
Vector Vector::operator*(double scalar) const {
    Vector result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        result[i] = data[i] * scalar;
    }
    return result;
}

// �������� ���������� ������������ ���� ��������
double Vector::operator*(const Vector& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Vectors must have the same dimension");
    }
    double result = 0.0;
    for (int i = 0; i < data.size(); ++i) {
        result += data[i] * other.data[i];
    }
    return result;
}

// ����� ��� �������� �������������� ���� ��������
bool Vector::isCollinear(const Vector& other) const {
    double epsilon = 1e-6;
    double length1 = length();
    double length2 = other.length();
    if (std::fabs(length1) < epsilon || std::fabs(length2) < epsilon) {
        return true; // �������������� ��� ������� ��������
    }
    double angleCosine = (*this * other) / (length1 * length2);
    return std::fabs(angleCosine - 1.0) < epsilon;
}

// ����� ��� ���������� ���� ����� ����� ��������� � ��������
double Vector::angleWith(const Vector& other) const {
    double epsilon = 1e-6;
    double angleCosine = (*this * other) / (length() * other.length());
    if (angleCosine < -1.0) angleCosine = -1.0;
    if (angleCosine > 1.0) angleCosine = 1.0;
    return std::acos(angleCosine) * 180.0 / 3.14;
}





// ����� ��� ���������� ������� � ����
void Vector::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "������� ��� ������� ����� ��� ������." << std::endl;
        return;
    }

    for (const double& val : data) {
        outFile << val << " ";
    }
    outFile << std::endl; // ��������� ������� ������ ����� ���������

    outFile.close();
    std::cout << "������ ��������� � ���� '" << filename << "'." << std::endl;
}



void Vector::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "������� ��� ������� ����� ��� �������." << std::endl;
        return;
    }

    data.clear();
    double val;
    while (inFile >> val) {
        data.push_back(val);
    }
    inFile.close();
    std::cout << "������ ����������� � ����� '" << filename << "'." << std::endl;
}

// �������� ������ ������� � �����
std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    os << "(";
    for (int i = 0; i < vector.data.size(); ++i) {
        os << vector.data[i];
        if (i < vector.data.size() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

// �������� -> ��� "������ �������" (�������� �� ������� ������ � ������� ��������)
double& Vector::operator->() {
    if (data.size() == 1) {
        return data[0];
    }
    else {
        throw std::logic_error("Pseudo-variable can only be used for vectors of size 1.");
    }
}

// �������� () ��� ������� � �������� �� ������� (�� �������� � [])
double& Vector::operator()(int index) {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// �������� () ��� ������� � �������� �� ������� (����������� ������)
double Vector::operator()(int index) const {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
