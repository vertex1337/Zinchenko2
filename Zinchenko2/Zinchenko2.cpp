#include <iostream>
#include "vector_lib.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Vector v1;
    Vector v2;
    int choice;

    while (true) {
        std::cout << "\n----- MENU -----" << std::endl;
        std::cout << "1. Create objects" << std::endl;
        std::cout << "2. Visualize objects" << std::endl;
        std::cout << "3. Perform operations on objects" << std::endl;
        std::cout << "4. Save on file" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int size1, size2;
            std::cout << "Enter the size of the first vector: ";
            std::cin >> size1;
            v1 = Vector(size1);

            // Заполняем первый вектор значениями
            std::vector<double> values1;
            for (int i = 0; i < size1; ++i) {
                double value;
                std::cout << "Enter value " << i + 1 << " for the first vector: ";
                std::cin >> value;
                values1.push_back(value);
            }
            v1.fill(values1);

            std::cout << "Enter the size of the second vector: ";
            std::cin >> size2;
            v2 = Vector(size2);

            // Заполняем второй вектор значениями
            std::vector<double> values2;
            for (int i = 0; i < size2; ++i) {
                double value;
                std::cout << "Enter value " << i + 1 << " for the second vector: ";
                std::cin >> value;
                values2.push_back(value);
            }
            v2.fill(values2);

            std::cout << "Objects created and filled." << std::endl;
            break;
        }
        case 2: {
            std::cout << "Vector v1: " << v1 << std::endl;
            std::cout << "Vector v2: " << v2 << std::endl;
            break;
        }
        case 3: {
            int operation;
            std::cout << "----- Operations Menu -----" << std::endl;
            std::cout << "1. Calculate length" << std::endl;
            std::cout << "2. Multiply by scalar" << std::endl;
            std::cout << "3. Calculate scalar product" << std::endl;
            std::cout << "4. Check collinearity" << std::endl;
            std::cout << "5. Calculate angle" << std::endl;
            std::cout << "6. Use pseudo-variable" << std::endl;
            std::cout << "0. Back to Main Menu" << std::endl;
            std::cout << "---------------------------" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> operation;

            switch (operation) {
            case 1: {
                std::cout << "Length of v1: " << v1.length() << std::endl;
                std::cout << "Length of v2: " << v2.length() << std::endl;
                break;
            }
            case 2: {
                double scalar;
                std::cout << "Enter a scalar value: ";
                std::cin >> scalar;
                Vector result1 = v1 * scalar;
                Vector result2 = v2 * scalar;
                std::cout << "Result of v1 * scalar: " << result1 << std::endl;
                std::cout << "Result of v2 * scalar: " << result2 << std::endl;
                break;
            }
            case 3: {
                if (v1.size() != v2.size()) {
                    std::cout << "Vectors have different dimensions. Scalar product cannot be calculated." << std::endl;
                }
                else {
                    double scalarProduct = v1 * v2;
                    std::cout << "Scalar product of v1 and v2: " << scalarProduct << std::endl;
                }
                break;
            }
            case 4: {
                if (v1.size() != v2.size()) {
                    std::cout << "Vectors have different dimensions. Collinearity check cannot be performed." << std::endl;
                }
                else if (v1.isCollinear(v2)) {
                    std::cout << "v1 and v2 are collinear." << std::endl;
                }
                else {
                    std::cout << "v1 and v2 are not collinear." << std::endl;
                }
                break;
            }
            case 5: {
                if (v1.size() != v2.size()) {
                    std::cout << "Vectors have different dimensions. Angle calculation cannot be performed." << std::endl;
                }
                else {
                    double angle = v1.angleWith(v2);
                    std::cout << "Angle between v1 and v2: " << angle << " degrees" << std::endl;
                }
                break;
            }
            case 6: {
                double newValue;
                int index;
                int vectorChoice;

                std::cout << "Choose a vector to change (1 or 2): ";
                std::cin >> vectorChoice;

                if (vectorChoice == 1 || vectorChoice == 2) {
                    int vectorSize = (vectorChoice == 1) ? v1.length() : v2.length();

                    std::cout << "Enter a new value for the pseudo-variable: ";
                    std::cin >> newValue;
                    std::cout << "Enter an index for changing: ";
                    std::cin >> index;

                    if (index >= 1 && index <= vectorSize) {
                        if (vectorChoice == 1) {
                            v1[index - 1] = newValue;
                            std::cout << "Pseudo-variable in v1 updated." << std::endl;
                        }
                        else if (vectorChoice == 2) {
                            v2[index - 1] = newValue;
                            std::cout << "Pseudo-variable in v2 updated." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Invalid index. Please enter an index within the vector's size." << std::endl;
                    }
                }
                else {
                    std::cout << "Invalid vector choice. Please enter 1 or 2." << std::endl;
                }
                break;
            }
            }
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Enter the filename to save: ";
            std::cin >> filename;

            std::ofstream outFile(filename);
            if (!outFile) {
                std::cerr << "Помилка при відкритті файлу для запису." << std::endl;
                break;
            }

            outFile << "Vector v1: " << v1 << std::endl;
            outFile << "Vector v2: " << v2 << std::endl;

            outFile.close();
            std::cout << "Objects saved to file '" << filename << "'." << std::endl;
            break;
        }


        case 0: {
            std::cout << "Exiting the program." << std::endl;
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}
