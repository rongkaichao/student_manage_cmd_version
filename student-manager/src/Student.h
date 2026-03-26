#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    int id;              // 学号
    std::string name;    // 姓名
    int age;             // 年龄
    double score;        // 成绩

public:
    // 构造函数
    Student();
    Student(int id, const std::string& name, int age, double score);

    // getter 方法
    int getId() const;
    std::string getName() const;
    int getAge() const;
    double getScore() const;

    // setter 方法
    void setName(const std::string& name);
    void setAge(int age);
    void setScore(double score);

    // 显示学生信息
    void display() const;

    // 用于文件存储：转成字符串 / 从字符串解析
    std::string toString() const;
    static Student fromString(const std::string& line);
};

#endif
