#include "Student.h"
#include <iostream>
#include <sstream>

Student::Student() : id_(0), name_(), age_(), score_()
{
}

Student::Student(int id, const std::string &name, int age, double score) : id_(id), name_(name), age_(age), score_(score)
{
}

int Student::getId() const
{
    return id_;
}

std::string Student::getName() const
{
    return name_;
}

int Student::getAge() const
{
    return age_;
}

double Student::getScore() const
{
    return score_;
}

// setter
// void setId();

void Student::setName(const std::string &name)
{
    name_ = name;
}

void Student::setAge(int age)
{
    age_ = age;
}

void Student::setScore(double score)
{
    score_ = score;
}

// id name age score
void Student::display() const
{
    std::cout << "ID: " << id_ << "  Name: " << name_ << "  Age: " << age_ << "  Score: " << score_ << std::endl;
}

std::string Student::toString() const
{
    std::ostringstream oss;
    oss << id_ << ',' <<  name_ << ',' << age_ << ',' << score_; 
    return oss.str();
}

Student Student::fromString(const std::string& line)
{
    std::istringstream iss(line);
    std::string token;
    std::getline(iss, token, ',');
    int id = stoi(token);

    std::string name;
    std::getline(iss, name, ',');

    std::getline(iss, token, ',');
    int age = stoi(token);

    std::getline(iss, token, ',');
    double score = stod(token);

    return Student(id, name, age, score);
}