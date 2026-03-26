#include "StudentManager.h"
#include <iostream>

void showMenu() {
    std::cout << "\n=============================" << std::endl;
    std::cout << "  Student Manager v1.0" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "  1. Add Student" << std::endl;
    std::cout << "  2. Delete Student" << std::endl;
    std::cout << "  3. Modify Student" << std::endl;
    std::cout << "  4. Query Student" << std::endl;
    std::cout << "  5. Display All" << std::endl;
    std::cout << "  6. Statistics" << std::endl;
    std::cout << "  0. Exit" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Choose: ";
}

int main() {
    StudentManager manager("data/students.txt");

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input, please enter a number!" << std::endl;
            continue;
        }

        switch (choice) {
            case 1: manager.addStudent();     break;
            case 2: manager.deleteStudent();   break;
            case 3: manager.modifyStudent();   break;
            case 4: manager.queryStudent();    break;
            case 5: manager.displayAll();      break;
            case 6: manager.showStatistics();  break;
            case 0:
                std::cout << "Bye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
