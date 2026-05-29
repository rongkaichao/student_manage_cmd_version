#include "Student.h"
#include <iostream>
#include "StudentManager.h"

int main()
{
    // 测试Student类
    Student stu(1, "xx", 12, 88.0);
    stu.display();

    // 测试序列化
    Student s1(1, "张三", 20, 95.5);
    std::string str = s1.toString();
    Student s2 = Student::fromString(str);
    s2.display();

    int passCount = 0;
    int fialCount = 0;
    // 测试StudentManager类的实现
    // 1. 构造
    StudentManager stuManager("data/newstudents.txt");
    // 2. 添加学生
    if (stuManager.addStudent("xixi", 10, 88.8))
    {
        std::cout << "pass : addStudent" << std::endl;
        passCount++;
    }
    else
    {
        std::cout << "fail : addStudent" << std::endl;
        fialCount++;
    }
    // 3.
    {
        Student s = stuManager.getStudent(0);
        if (s.getId() == 1 && s.getName() == "xixi" && s.getAge() == 10 && s.getScore() == 88.8)
        {
            std::cout << "pass : getStudent" << std::endl;
            passCount++;
        }
        else
        {
            std::cout << "fail : getStudent" << std::endl;
            fialCount++;
        }
    }

    // 4.
    {
        int size = stuManager.getStudentCount();
        if(size == 1)
        {
            std::cout << "pass : getStudentCount" << std::endl;
            passCount++;
        }
        else
        {
            std::cout << "fail : getStudentCount" << std::endl;
            fialCount++;
        }
    }
    
    std::cout << "passed : " << passCount << "  failed : " << fialCount << std::endl;
    return 0;
}