// 名词--类名--单一变化原因--单一职责--存什么--做什么
// 学生管理--StudentManager--学生管理操作--管理学生--存所有学生--增删改查，加载，存储

/*
1. 写程序思维：每一步都可能出问题，要保证该步正确是下面步骤正确的前提。构造函数初始化Student_, 文件正常打开，获取的每一行都不为空，才能正确初始化Student
2. std::getline()返回值是什么？
3. 文件流头文件<fstream>
4. addStudent函数没有写return语句
5. saveToFile函数中每条记录没有添加换行符'\n'
*/
#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include <vector>
#include "Student.h"

class StudentManager
{
public:
    StudentManager(const std::string &filePath);

    bool addStudent(const std::string &name, int age, double score);

    int getStudentCount() const;

    const Student& getStudent(int index) const;

    // void deleteStudent();

    // void updateStudent();

    // void queryStudent();

private:
    void loadFromFile();

    void saveToFile();

private:
    std::vector<Student> students_;
    std::string filePath_;
    int nextId_;
};
#endif