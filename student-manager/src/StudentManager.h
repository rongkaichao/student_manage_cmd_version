#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>
#include <string>

class StudentManager {
private:
    std::vector<Student> students;  // 用 vector 存储所有学生
    std::string filePath;            // 数据文件路径
    int nextId;                      // 自增学号

    // 从文件加载数据
    void loadFromFile();
    // 保存数据到文件
    void saveToFile();

public:
    StudentManager(const std::string& filePath);

    void addStudent();         // 添加学生
    void deleteStudent();      // 删除学生
    void modifyStudent();      // 修改学生信息
    void queryStudent();       // 查询学生
    void displayAll();         // 显示所有学生
    void showStatistics();     // 统计信息
};

#endif
