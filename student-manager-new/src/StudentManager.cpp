#include "StudentManager.h"
#include <fstream>
#include <iostream>

StudentManager::StudentManager(const std::string &filePath) : filePath_(filePath), nextId_(1)
{
    loadFromFile();
}

bool StudentManager::addStudent(const std::string &name, int age, double score)
{
    // 构造学生对象
    Student s(nextId_, name, age, score);

    // 更新nextID_
    nextId_++;

    // 将学生对象添加到vector
    students_.push_back(s);

    return true;
}

int StudentManager::getStudentCount() const
{
    return students_.size();
}

const Student &StudentManager::getStudent(int index) const
{
    return students_[index];
}

// void deleteStudent();

// void updateStudent();

// void queryStudent();

void StudentManager::loadFromFile()
{
    // 读取文件到内存
    std::ifstream ifs(filePath_);

    // 打不开文件
    if (!ifs.is_open())
    {
        // 文件不存在或打不开，不报错，从空列表开始
        std::cout << "cannot open file, start with 0" << std::endl;
        return;
    }

    // 获取所有的学生信息并初始化student_
    std::string line;
    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;

        Student s = Student::fromString(line);
        students_.push_back(s);

        // 更新nextId_
        if (s.getId() >= nextId_)
        {
            nextId_ = s.getId() + 1;
        }
    }

    ifs.close();
}

void StudentManager::saveToFile()
{
    // 覆盖打开文件
    std::ofstream file(filePath_);

    // 不能打开
    if (!file.is_open())
    {
        std::cout << "error: cannot open file" << std::endl;
        return;
    }
    // 把student_中 所有的学生信息添加到文件流中
    for (auto student : students_)
    {
        file << student.toString() << '\n';
    }
    // 关闭文件
    file.close();
}

void StudentManager::addStudent()
{
    // 提示输入对象参数,获取Student对象参数 
    std::cout << "input name" << std::endl;
    std::string name;
    std::cin >> name;

    std::cout << "input score" << std::endl;
    int score;
    std::cin >> score;
    
    std::cout << "input age" << std::endl;
    int age;
    std::cin >> age;

    // 构建Student 实例
    Student s(nextId_, name, age, score);

    // 更新nextid_
    nextId_++;

    //将Student实例push vector
    students_.push_back(s);

    // 保存到文件
    saveToFile()
}

void StudentManager::displayAll()
{

}