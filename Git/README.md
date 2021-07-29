```bash
# 列出所有本地分支
git branch
# 列出所有远程分支
git branch -r
# 新建一个分支，但依然停留在当前分支
git branch [branch-name]
# 新建一个分支，并切换到该分支
git checkout -b [branch]
# 合并指定分支到当前分支
$ git merge [branch]
# 删除分支
$ git branch -d [branch-name]
# 删除远程分支
$ git push origin --delete [branch-name]
$ git branch -dr [remote/branch]
```




```bash
#初始化
git init
#删除初始化
rm -rf .git
#连接远程仓库
git remote add origin 仓库地址
#查看连接的仓库
git remote -v
#创建并切换到分支
git checkout -b 分支名
#添加本地需要提交的代码
git add . （.表示所有代码）
#提交代码并添加说明
git commit -m “说明内容”
#上传代码到新分支
git push origin 本地分支名:远程分支名
（若远程分支不存在会新建）
#查看本地分支
git branch
#查看远程分支
git branch -a
```



```bash
git branch  //查看本地分支
git branch -r   //查看远程分支
git branch -a   //查看本地和远程分支
git checkout <branch-name>  //从当前分支，切换到其他分支
git checkout -b <branch-name>   //创建并切换新建分支
git branch -d <branch-name>     //删除本地分支(本地)
git branch -D <branch-name> //强制删除分支（提交记录并没合并过 -d是删除不了 ）
git merge <branch-name>         //当前分支与指定分支合并
git merge --abort               //合并冲突时（merging），取消git合并分支
git branch --merged             //查看哪些分支已经合并到当前分支
git branch --no-merged          //查看哪些分支没有合并到当前分支
git branch -v               //查看各个分支最后一个提交对象信息
git push origin --delete <branch>     //删除远程分支
git branch -m <old-name> <new-name> //重命名分支
git checkout -b 本地分支 origin/远程分支    //拉取远程分支并创建本地分支
git rebase <branch-name>    //衍合指定分支记录到当前分支(不产生分支合并-推荐用)
git rebase --abort  //衍合冲突（rebase）的时候，取消衍合
```

