//time:2022年1月16日21:37:52

---------------------------------------------安装Git--------------------------------------------------

1、在Windows上安装Git，安装完毕之后，初始化姓名邮箱
	git config --global user.name "Your Name"
	git config --global user.email "email@example.com"
2、注意git config命令的--global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置



---------------------------------------------创建版本库方法-------------------------------------------

1、创建一个空的GitHub命令是
	mkdir flodername
	cd  flodername
	pwd  //显示你当前所在位置

2、初始化版本库
	使用命令 git init


	
3、添加（上传）一个文件，需要分三步
	1）先在本地创建一个文件（比如txt、md、c等）//最好不要使用记事本创建，可以更改为.c文件用notepad++写
		创建文件 touch FileName.txt
		删除文件 rm  FileName.txt
	2）使用 git add  filename.txt   //将本地的文件添加到暂存区，可反复多次添加工作区的修改，最后一次性提交，就会全部提交。
		如果添加了
	3）使用 git commit -m "添加提交说明"  //将添加的文件提交到GitHub，可以一次添加多个文件

特别提醒：以上所有命令操作都是在自己的GitHub里面操作。

---------------------------------------------查看修改--------------------------------------------------

p1、修改文件后查看提交状态
	git status//查看工作区是否有需要有添加和提交的文件
	git diff  //对比展示详细的修改区别
	git add    
	git commit //再次重新添加和提交已修改的文件，完成提交
	
注意：
	p1）要明白这3个概念，工作区（working tree），暂存区（index /stage），仓库（repository）
		git跟不同的参数，比较不同的区间的版本。
		git diff：是查看working tree与index的差别的，就是查看工作区修改的，有没有添加到暂存区，没添加到，就有不同。
		git diff --cached：是查看index与repository的差别的，查看已经添加到暂存区的有没有提交，没提交，就有不同。
		git diff HEAD：是查看working tree和repository的差别的。其中：HEAD代表的是最近的一次commit的信息。直接查询工作区做的修改有没有提交到仓库
	综上所述：git diff 后面跟文件名称是是查看工作区（working tree）与暂存区（index）的差别的。
	


---------------------------------------------版本回退--------------------------------------------------

p1、版本回退
	使用git log 命令查看当前文件已有的历史版本
	使用git log --pretty=oneline可以查看简化的历史版本
	使用git reset --hard HEAD^ 回退到上一版本，
		HEAD表示当前版本的指针，HEAD^表示上一版本，HEAD^^表示回退两个版本，HEAD~100，表示回退一百个版本
	如果想要回退到已经被回退到的之前那个版本，也就是回退之后反悔了，想退回去
	使用git reset --hard 1094a，后面的1094a表示一个版本的版本号，只要知道版本号可以回退到任意版本
	使用git reflog可以查看历次的版本号
	
	
注意：
	//hard参数的意义是：
	
	
	
---------------------------------------------工作区和暂存区--------------------------------------------------
	工作区（Working Directory）
	就是你在电脑里能看到的目录，比如我的learngit文件夹就是一个工作区：

	版本库（Repository）
	工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库。
	Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。
	
	前面讲了我们把文件往Git版本库里添加的时候，是分两步执行的：
	第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；
	第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。

	因为我们创建Git版本库时，Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改。
	你可以简单理解为，需要提交的文件修改通通放到暂存区，然后，一次性提交暂存区的所有修改。

注意（网友补充）：
	Git管理的文件分为：工作区，版本库，版本库又分为暂存区stage和暂存区分支master(仓库)
	工作区>>>暂存区>>>仓库
	git add把文件从工作区>>>暂存区，git commit把文件从暂存区>>>仓库，
	git diff查看工作区和暂存区差异，
	git diff --cached查看暂存区和仓库差异，
	git diff HEAD 查看工作区和仓库的差异，
	git add的反向命令git checkout，撤销工作区修改，即把暂存区最新版本转移到工作区，
	git commit的反向命令git reset HEAD，就是把仓库最新版本转移到暂存区。


---------------------------------------------撤销修改--------------------------------------------------
	p1、撤销工作区的修改：
	git resotre --worktree readme.txt
	
	p2、从master恢复暂存区 
	git restore --staged readme.txt
	
	p3、从master同时恢复工作区和暂存区   //没有修改成功，评论区意见不一，没有更好的
	git restore --source=HEAD --staged --worktree readme.txt



