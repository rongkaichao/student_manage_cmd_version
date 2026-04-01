# C++相关
1. getline返回类型：std::istream&
2. 链式调用：函数在多次调用时像链条一样咬合住。该函数可以链式调用的前提是--函数的返回值可以作为自己的参数。
3. std::istream与std::cin的关系：std::cin是std::istream类的一个全局对象
4. std::istream类成员函数之一：operator<<()
5. 流操作可能会刷新流对象的状态，几种获取流状态的成员方法：istream.eof(); istream.fail(); istream.bad()
6. std::getline有两个重载版本：
    1. getline(流对象, 获取的token, 分隔符)
    2. getline(流对象, 获取的token), 分隔符默认是\n
7. getline可以作为while等条件语句的条件。
    1. 返回类型std::istream类型在条件语句环境下可以隐式转换成bool类型
    2. std::istream有bool类型转换运算符：eg(explicit operator bool())
    3. 这种隐式转成bool类型仅是在条件语句环境下，因为是明确bool类型，C++11后
8. 显示调用：主动明确的去使用某种方式
    1. bool flag = static_cast<bool>(obj)
    2. bool flag = obj.operator bool()
9. istream类中调用 >> 和 operator bool()调用的方式不同
    1. >>是内置运算符，经常使用为它设计了简洁的中缀形式
    2. operator bool()是新的类型转换运算符，仅在条件语句下自动进行，不会有频繁调用
10. string.empty()
11. try{} catch(){}块
    1. 避免程序因为异常崩溃
    2. 可在catch块中释放相关资源
    3. 后面的代码会继续执行
12. std::ostringstream类的str()方法
13. std::to_string(非字符串参数)
14. static在类中的三种用法
    1. 修饰成员方法，该方法就是属于类本身，不依赖具体实例去调用
    2. 修饰成员变量，该变量在所有的实例中共享，也就是说所有实例的该成员是一样的。
    3. 用来创建工具函数，这个函数不依赖任何实例的成员变量值，参数很可能是外部变量
15. const 类型的函数作用？
    返回值是const类型，需要使用const类型去接收。
16. const& 类型的函数作用？
    返回是&, 则返回的是返回值本身，如果被赋值的变量被修改那么函数的返回值也会被修改。
    const& 函数需要使用const& 类型变量接收，防止修改这个变量，从而间接修改返回值本身。
17. auto it = std::find_if(students.begin(),students.end(), [id](const Student& s) { return s.getId() == id; });
    有了容器的迭代器首和尾就可以遍历容器，内部实现for循环，迭代器引用传给lambda表达式的形参。
# 设计模式
1. 工程方法模式
    解决的问题：根据不同条件创建不同的对象。
    前提：设计基类和多个子类


# 程序运行相关
1. 执行目录：当前打开的文件夹
2. 执行程序：./student_manager.exe

# 命令行指令
1. cd student_manament
2. mkdir student_manage
3. touch test.txt
4. rm -r student_manament

# g++指令
1. 编译：g++ -o student_manament.exe student_manament/src/main.cpp student_manament/src/student.cpp student_manament/src/studentManager.cpp

# git
1. 创建本地仓库：在目标目录git init
2. github创建仓库：最上面一行+-->new repository;设置仓库信息
3. 远程和本地仓库合并
 1. 把两个无关的历史强行拼在一起：git pull origin main --allow-unrelated-histories
 2. 本地仓库连接远程仓库（仓库建立连接）：git remote add origin url(https://github.com/rongkaichao/student_manage_cmd_version)
 3. 本地分支新的内容推送到远程仓库对应的分支，并建立上下游联系（以后直接使用push即可）：git push -u origin main
4. 在指定文件夹clone远程仓库到本地，默认本地和远程仓库连接，默认自带连接，自带分支，自带上游：git clone https://github.com/rongkaichao/student_manage_cmd_version.git
6. git branch --set-upstream-to=origin/main main
7. git push -u origin main
8. git commit -m "[] 写做了什么，不要写文件名"
