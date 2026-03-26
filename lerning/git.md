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
