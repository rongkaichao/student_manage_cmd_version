#include "StudentManager.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>

StudentManager::StudentManager(const std::string& filePath)
    : filePath(filePath), nextId(1) {
    loadFromFile();
}

// ===== File I/O =====

void StudentManager::loadFromFile() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        Student s = Student::fromString(line);
        students.push_back(s);
        if (s.getId() >= nextId) {
            nextId = s.getId() + 1;
        }
    }
    file.close();
}

void StudentManager::saveToFile() {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cout << "Error: Cannot open file to save data!" << std::endl;
        return;
    }
    for (const auto& s : students) {
        file << s.toString() << "\n";
    }
    file.close();
}

// ===== Core Functions =====

void StudentManager::addStudent() {
    std::string name;
    int age;
    double score;

    std::cout << "\n--- Add Student ---" << std::endl;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter score: ";
    std::cin >> score;

    if (age < 0 || age > 150) {
        std::cout << "Invalid age!" << std::endl;
        return;
    }
    if (score < 0 || score > 100) {
        std::cout << "Score must be 0-100!" << std::endl;
        return;
    }

    Student s(nextId++, name, age, score);
    students.push_back(s);
    saveToFile();

    std::cout << "Added successfully!" << std::endl;
    s.display();
}

void StudentManager::deleteStudent() {
    if (students.empty()) {
        std::cout << "\nNo records." << std::endl;
        return;
    }

    int id;
    std::cout << "\n--- Delete Student ---" << std::endl;
    std::cout << "Enter student ID to delete: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });

    if (it == students.end()) {
        std::cout << "Student with ID " << id << " not found." << std::endl;
        return;
    }

    std::cout << "Confirm delete this student?" << std::endl;
    it->display();
    std::cout << "Type y to confirm, other to cancel: ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        students.erase(it);
        saveToFile();
        std::cout << "Deleted!" << std::endl;
    } else {
        std::cout << "Cancelled." << std::endl;
    }
}

void StudentManager::modifyStudent() {
    if (students.empty()) {
        std::cout << "\nNo records." << std::endl;
        return;
    }

    int id;
    std::cout << "\n--- Modify Student ---" << std::endl;
    std::cout << "Enter student ID to modify: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });

    if (it == students.end()) {
        std::cout << "Student with ID " << id << " not found." << std::endl;
        return;
    }

    std::cout << "Current info:" << std::endl;
    it->display();

    std::string name;
    int age;
    double score;

    std::cout << "New name (- to skip): ";
    std::cin >> name;
    if (name != "-") {
        it->setName(name);
    }

    std::cout << "New age (-1 to skip): ";
    std::cin >> age;
    if (age != -1) {
        it->setAge(age);
    }

    std::cout << "New score (-1 to skip): ";
    std::cin >> score;
    if (score != -1) {
        it->setScore(score);
    }

    saveToFile();
    std::cout << "Updated!" << std::endl;
    it->display();
}

void StudentManager::queryStudent() {
    if (students.empty()) {
        std::cout << "\nNo records." << std::endl;
        return;
    }

    std::cout << "\n--- Query Student ---" << std::endl;
    std::cout << "1. By ID" << std::endl;
    std::cout << "2. By Name" << std::endl;
    std::cout << "Choose: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        int id;
        std::cout << "Enter ID: ";
        std::cin >> id;

        auto it = std::find_if(students.begin(), students.end(),
            [id](const Student& s) { return s.getId() == id; });

        if (it != students.end()) {
            it->display();
        } else {
            std::cout << "Not found." << std::endl;
        }
    } else if (choice == 2) {
        std::string name;
        std::cout << "Enter name: ";
        std::cin >> name;

        bool found = false;
        for (const auto& s : students) {
            if (s.getName() == name) {
                s.display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Not found." << std::endl;
        }
    } else {
        std::cout << "Invalid choice." << std::endl;
    }
}

void StudentManager::displayAll() {
    if (students.empty()) {
        std::cout << "\nNo records." << std::endl;
        return;
    }

    std::cout << "\n===== Total: " << students.size() << " students =====" << std::endl;
    std::cout << std::left
              << std::setw(8) << "ID"
              << std::setw(12) << "Name"
              << std::setw(8) << "Age"
              << std::setw(8) << "Score"
              << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (const auto& s : students) {
        std::cout << std::left
                  << std::setw(8) << s.getId()
                  << std::setw(12) << s.getName()
                  << std::setw(8) << s.getAge()
                  << std::setw(8) << s.getScore()
                  << std::endl;
    }
}

void StudentManager::showStatistics() {
    if (students.empty()) {
        std::cout << "\nNo records." << std::endl;
        return;
    }

    double total = 0;
    double maxScore = students[0].getScore();
    double minScore = students[0].getScore();
    std::string maxName = students[0].getName();
    std::string minName = students[0].getName();
    int passCount = 0;

    for (const auto& s : students) {
        double sc = s.getScore();
        total += sc;
        if (sc > maxScore) { maxScore = sc; maxName = s.getName(); }
        if (sc < minScore) { minScore = sc; minName = s.getName(); }
        if (sc >= 60) passCount++;
    }

    double avg = total / students.size();

    std::cout << "\n===== Statistics =====" << std::endl;
    std::cout << "Total students: " << students.size() << std::endl;
    std::cout << "Average score:  " << std::fixed << std::setprecision(1) << avg << std::endl;
    std::cout << "Highest score:  " << maxScore << " (" << maxName << ")" << std::endl;
    std::cout << "Lowest score:   " << minScore << " (" << minName << ")" << std::endl;
    std::cout << "Pass rate:      " << std::fixed << std::setprecision(1)
              << (passCount * 100.0 / students.size()) << "%" << std::endl;
}
