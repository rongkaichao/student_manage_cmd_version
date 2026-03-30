#include "Student.h"
#include <sstream>

// 默认构造函数
Student::Student() : id(0), name(""), age(0), score(0.0) {}

// 带参构造函数
Student::Student(int id, const std::string& name, int age, double score)
    : id(id), name(name), age(age), score(score) {}

// getter
int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
double Student::getScore() const { return score; }

// setter
void Student::setName(const std::string& name) { this->name = name; }
void Student::setAge(int age) { this->age = age; }
void Student::setScore(double score) { this->score = score; }

// 显示学生信息
void Student::display() const {
    std::cout << "ID: " << id
              << "  Name: " << name
              << "  Age: " << age
              << "  Score: " << score
              << std::endl;
}

// 转成字符串（用逗号分隔，方便存文件）
// 格式: id,name,age,score
std::string Student::toString() const {
    std::ostringstream oss;
    oss << id << "," << name << "," << age << "," << score;
    return oss.str();
}

// 从字符串解析出 Student 对象
Student Student::fromString(const std::string& line) {
    std::istringstream iss(line);
    std::string token;
    int id, age;
    std::string name;
    double score;

    // 按逗号分割
    std::getline(iss, token, ',');
    id = std::stoi(token);

    std::getline(iss, name, ',');

    std::getline(iss, token, ',');
    age = std::stoi(token);

    try{
        std::getline(iss, token, ',');
        score = std::stod(token);
    }catch(std::exception& e){
        std::cout << "out_of_range exception:" << e.what() << std::endl;
    }
    

    return Student(id, name, age, score);
}
