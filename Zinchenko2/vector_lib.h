// vector_lib.h
#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class Vector {
public:
    // Конструкторы
    Vector();
    Vector(int size);
    Vector(const Vector& other); // Конструктор копирования

    // Операторы
    double& operator[](int index);
    Vector& operator=(const Vector& other);

    // Методы для операций с векторами
    double length() const;
    Vector operator*(double scalar) const;
    double operator*(const Vector& other) const; // Скалярное произведение
    bool isCollinear(const Vector& other) const;
    double angleWith(const Vector& other) const;
    void fill(const std::vector<double>& values);

    int size() const {
        return data.size();
    }


    // Методы для сохранения и загрузки векторов из файла
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Визуализация и "умный доступ"
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    double& operator->();

    // Псевдозначения
    double& operator()(int index);
    double operator()(int index) const;

private:
    std::vector<double> data;
};

#endif // VECTOR_LIB_H
