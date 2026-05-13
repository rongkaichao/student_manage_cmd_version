#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include "Student.h"
#include "StudentManager.h"

int main()
{
    int passed = 0, failed = 0;
    int testNum = 0;

    // 测试1: 正常添加学生，返回 true
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok = mgr.addStudent("Alice", 20, 85.5);
        if (ok)
        {
            std::cout << "PASS: AddStudentReturnsTrue\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: AddStudentReturnsTrue\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试2: 添加后学生数 +1
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Bob", 18, 90.0);
        if (mgr.getStudentCount() == 1)
        {
            std::cout << "PASS: AddStudentIncrementsCount\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: AddStudentIncrementsCount, count=" << mgr.getStudentCount() << "\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试3: 添加后 ID 自增
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        mgr.addStudent("Bob", 18, 90.0);
        const Student &s = mgr.getStudent(1);
        if (s.getId() == 2 && s.getName() == "Bob")
        {
            std::cout << "PASS: AddStudentAutoIncrementId\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: AddStudentAutoIncrementId\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试4: 年龄 < 0，拒绝添加
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok = mgr.addStudent("Bob", -1, 80.0);
        if (!ok && mgr.getStudentCount() == 0)
        {
            std::cout << "PASS: RejectNegativeAge\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RejectNegativeAge\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试5: 年龄 > 150，拒绝添加
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok = mgr.addStudent("Bob", 200, 80.0);
        if (!ok && mgr.getStudentCount() == 0)
        {
            std::cout << "PASS: RejectAgeOver150\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RejectAgeOver150\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试6: 成绩 < 0，拒绝添加
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok = mgr.addStudent("Bob", 20, -1.0);
        if (!ok && mgr.getStudentCount() == 0)
        {
            std::cout << "PASS: RejectNegativeScore\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RejectNegativeScore\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试7: 成绩 > 100，拒绝添加
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok = mgr.addStudent("Bob", 20, 150.0);
        if (!ok && mgr.getStudentCount() == 0)
        {
            std::cout << "PASS: RejectScoreOver100\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RejectScoreOver100\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试8: 边界值 - 年龄 0 和 150 有效
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok1 = mgr.addStudent("A", 0, 0.0);
        bool ok2 = mgr.addStudent("B", 150, 100.0);
        if (ok1 && ok2 && mgr.getStudentCount() == 2)
        {
            std::cout << "PASS: BoundaryAgeValues\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: BoundaryAgeValues\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试9: 边界值 - 成绩 0 和 100 有效
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        bool ok1 = mgr.addStudent("A", 20, 0.0);
        bool ok2 = mgr.addStudent("B", 20, 100.0);
        if (ok1 && ok2 && mgr.getStudentCount() == 2)
        {
            std::cout << "PASS: BoundaryScoreValues\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: BoundaryScoreValues\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试10: 按 ID 查询能找到学生
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        mgr.addStudent("Bob", 18, 90.0);
        int idx = mgr.findIndexById(1);
        if (idx == 0)
        {
            std::cout << "PASS: FindIndexByIdFound\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: FindIndexByIdFound\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试11: 按 ID 查询不存在的学生返回 -1
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        int idx = mgr.findIndexById(999);
        if (idx == -1)
        {
            std::cout << "PASS: FindIndexByIdNotFound\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: FindIndexByIdNotFound\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试12: 按姓名查询能找到学生
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        mgr.addStudent("Bob", 18, 90.0);
        mgr.addStudent("Alice", 25, 70.0);
        std::vector<int> indices = mgr.findIndexesByName("Alice");
        if (indices.size() == 2 && indices[0] == 0 && indices[1] == 2)
        {
            std::cout << "PASS: FindByNameMultipleResults\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: FindByNameMultipleResults, size=" << indices.size() << "\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试13: 按姓名查询不存在的名字返回空
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        std::vector<int> indices = mgr.findIndexesByName("Zhang");
        if (indices.empty())
        {
            std::cout << "PASS: FindByNameNotFound\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: FindByNameNotFound\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试14: 按 ID 删除学生
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        mgr.addStudent("Bob", 18, 90.0);
        bool ok = mgr.removeStudentById(1);
        if (ok && mgr.getStudentCount() == 1 && mgr.getStudent(0).getName() == "Bob")
        {
            std::cout << "PASS: RemoveStudentByIdSuccess\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RemoveStudentByIdSuccess\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试15: 删除不存在的 ID 返回 false
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        bool ok = mgr.removeStudentById(999);
        if (!ok && mgr.getStudentCount() == 1)
        {
            std::cout << "PASS: RemoveStudentByIdNotFound\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RemoveStudentByIdNotFound\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试16: 删除后后续学生索引正确
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        mgr.addStudent("Bob", 18, 90.0);
        mgr.addStudent("Charlie", 25, 70.0);
        mgr.removeStudentById(2); // 删 Bob
        if (mgr.getStudentCount() == 2 && mgr.getStudent(0).getName() == "Alice" && mgr.getStudent(1).getName() == "Charlie")
        {
            std::cout << "PASS: RemoveStudentByIdShiftIndex\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: RemoveStudentByIdShiftIndex\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试17: 修改学生姓名
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        mgr.updateStudent(1, "Alicia", -1, -1);
        if (mgr.getStudent(0).getName() == "Alicia" && mgr.getStudent(0).getAge() == 20 && mgr.getStudent(0).getScore() == 85.5)
        {
            std::cout << "PASS: UpdateStudentNameOnly\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: UpdateStudentNameOnly\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试18: 修改学生年龄和成绩
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Bob", 18, 90.0);
        mgr.updateStudent(1, "-", 25, 95.0);
        if (mgr.getStudent(0).getName() == "Bob" && mgr.getStudent(0).getAge() == 25 && mgr.getStudent(0).getScore() == 95.0)
        {
            std::cout << "PASS: UpdateStudentAgeAndScore\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: UpdateStudentAgeAndScore\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试19: 全部字段更新
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Charlie", 22, 78.0);
        mgr.updateStudent(1, "Chuck", 30, 88.0);
        const Student &s = mgr.getStudent(0);
        if (s.getName() == "Chuck" && s.getAge() == 30 && s.getScore() == 88.0)
        {
            std::cout << "PASS: UpdateStudentAllFields\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: UpdateStudentAllFields\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试20: 修改不存在的 ID 返回 false
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 85.5);
        bool ok = mgr.updateStudent(999, "X", 10, 50.0);
        if (!ok && mgr.getStudent(0).getName() == "Alice")
        {
            std::cout << "PASS: UpdateStudentNotFound\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: UpdateStudentNotFound\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试21: 空列表统计返回默认值
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        double avg = mgr.getAverageScore();
        double maxS = mgr.getMaxScore();
        double minS = mgr.getMinScore();
        int passRate = mgr.getPassRate();
        if (avg == 0.0 && maxS == 0.0 && minS == 0.0 && passRate == 0)
        {
            std::cout << "PASS: StatisticsEmptyList\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: StatisticsEmptyList\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试22: 单个学生的统计
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 80.0);
        if (mgr.getAverageScore() == 80.0 && mgr.getMaxScore() == 80.0 && mgr.getMinScore() == 80.0 && mgr.getPassRate() == 100)
        {
            std::cout << "PASS: StatisticsSingleStudent\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: StatisticsSingleStudent\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试23: 多个学生统计
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 80.0);   // 及格
        mgr.addStudent("Bob", 18, 50.0);     // 不及格
        mgr.addStudent("Charlie", 22, 90.0); // 及格
        // 平均: (80+50+90)/3 = 73.333..., 最高90, 最低50, 及格率2/3=66%
        bool avgOk = std::abs(mgr.getAverageScore() - 73.33) < 0.5;
        bool maxOk = mgr.getMaxScore() == 90.0;
        bool minOk = mgr.getMinScore() == 50.0;
        bool passOk = mgr.getPassRate() == 66;
        if (avgOk && maxOk && minOk && passOk)
        {
            std::cout << "PASS: StatisticsMultipleStudents\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: StatisticsMultipleStudents avg="
                      << mgr.getAverageScore() << " pass=" << mgr.getPassRate() << "\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试24: 全部不及格
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        StudentManager mgr(file);
        mgr.addStudent("Alice", 20, 30.0);
        mgr.addStudent("Bob", 18, 59.0);
        if (mgr.getPassRate() == 0 && mgr.getMaxScore() == 59.0)
        {
            std::cout << "PASS: StatisticsAllFail\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: StatisticsAllFail\n";
            failed++;
        }
        std::remove(file.c_str());
    }

    // 测试25: 写入后重新加载数据完整
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        {
            StudentManager mgr(file);
            mgr.addStudent("Alice", 20, 85.5);
            mgr.addStudent("Bob", 18, 90.0);
        } // mgr 销毁，数据已写入文件
        {
            StudentManager mgr(file); // 从文件加载
            if (mgr.getStudentCount() == 2 && mgr.getStudent(0).getName() == "Alice" && mgr.getStudent(1).getName() == "Bob")
            {
                std::cout << "PASS: PersistenceLoadData\n";
                passed++;
            }
            else
            {
                std::cout << "FAIL: PersistenceLoadData\n";
                failed++;
            }
        }
        std::remove(file.c_str());
    }

    // 测试26: 删除后重新加载数据正确
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        {
            StudentManager mgr(file);
            mgr.addStudent("Alice", 20, 85.5);
            mgr.addStudent("Bob", 18, 90.0);
            mgr.removeStudentById(1); // 删 Alice
        }
        {
            StudentManager mgr(file);
            if (mgr.getStudentCount() == 1 && mgr.getStudent(0).getName() == "Bob")
            {
                std::cout << "PASS: PersistenceAfterDelete\n";
                passed++;
            }
            else
            {
                std::cout << "FAIL: PersistenceAfterDelete\n";
                failed++;
            }
        }
        std::remove(file.c_str());
    }

    // 测试27: 修改后重新加载数据正确
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        {
            StudentManager mgr(file);
            mgr.addStudent("Alice", 20, 85.5);
            mgr.updateStudent(1, "Alicia", 25, 95.0);
        }
        {
            StudentManager mgr(file);
            if (mgr.getStudentCount() == 1 && mgr.getStudent(0).getName() == "Alicia" && mgr.getStudent(0).getAge() == 25 && mgr.getStudent(0).getScore() == 95.0)
            {
                std::cout << "PASS: PersistenceAfterUpdate\n";
                passed++;
            }
            else
            {
                std::cout << "FAIL: PersistenceAfterUpdate\n";
                failed++;
            }
        }
        std::remove(file.c_str());
    }

    // 测试28: 文件不存在时不崩溃
    {
        std::string file = "test_" + std::to_string(++testNum) + ".txt";
        std::remove(file.c_str()); // 确保文件不存在
        StudentManager mgr(file);
        if (mgr.getStudentCount() == 0)
        {
            std::cout << "PASS: LoadFromNonexistentFile\n";
            passed++;
        }
        else
        {
            std::cout << "FAIL: LoadFromNonexistentFile\n";
            failed++;
        }
    }

    std::cout << "\n"
              << passed << " passed, " << failed << " failed\n";
    return failed > 0 ? 1 : 0;
}
