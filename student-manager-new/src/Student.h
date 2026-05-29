/*
1. 创建头文件
2. 创建类（成员变量，构造函数，成员方法
---学习
1. 默认构造的作用：创建合法对象，虽然这个对象不会被取值，但会在后续被更改。
2. const&的使用场景
3. toString函数的实现--ostringstream类，str()，sstream头文件，
4. fromString函数使用static
5. 

类名-唯一变化源--职责
学生类--学生信息--管理学生信息
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    Student(); //默认构造应该怎么初始化成员变量

    Student(int id, const std::string& name, int age, double score);

    int getId() const;

    std::string getName() const;

    int getAge() const;

    double getScore() const;

    //setter
    //void setId();

    void setName(const std::string& name);

    void setAge(int age);

    void setScore(double score);

    //
    void display() const;

    //
    std::string toString() const;

    static Student fromString(const std::string& line);
private:
    //学号假设是从1开始的数字
    int id_;
    std::string name_;
    int age_;
    double score_;
};
#endif