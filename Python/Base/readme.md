对python的基础打的还是不扎实，看官方的手册在学一遍。

[TOC]









# 4.深入python流程控制

## 4.3 range()函数

```python
for i in range(10):
for i in range(0,10):
for i in range(0,10,1):
#以上效果是一样的，从0到9，就是index
```

可以组合：

```python
a = ['Mary', 'had', 'a', 'little', 'lamb']
for i in range(len(a)):
	print(a[i])
```

## 4.5 pass 语句

pass 语句什么也不做。它用于那些语法上必须要有什么语句，但程序什么也不做的场合，例如:

```python
while True:
    pass
```

## 4.7深入pyhton函数的定义

### 4.7.1.可以写全部参数或者部分参数：

```python
def fun(par1,par2=1,par3="aaaa"):
    print("par1:",par1)
    print("par2:", par2)
    print("par3:", par3)
fun("as",3,"zxcv")
fun("as",4)
fun("as")
```

### 4.7.3.可变参数列表

```python
def change_args_1(p1,p2,*args):
    print("p1 and p2",p1," ",p2)
    print("args:",args)
change_args_1(1,2,3,4,5,6)
```

### 4.7.5. Lambda 形式

就是匿名函数

# 5.数据结构

## 5.1关于列表

-   list.append(x)：把一个元素添加到结尾
-   list.extend(L)：将一个给定列表中的所有元素都添加到另一个列表中
-   list.insert(i,x):插入元素
-   list,remove(x):删除元素
-   list.index(x)：返回第一个值为x的索引
-   list.count(s)：返回出现的次数
-   list.sort()：排序
-   list.reverse()：倒排



## 5.2 del语句

```python
>>> a = [-1, 1, 66.25, 333, 333, 1234.5]
>>> del a[0]
>>> a
[1, 66.25, 333, 333, 1234.5]
```

## 5.3 元组

`a = (1,2,3,4)`

## 5.4 集合

`a ={1,2,3,4}`

## 5.5 字典

`a = {'aa':123,'bb':345}`

字典循环时可以用items方法：

```python
for i,j in a.items():
```



# 7.输入和输出

-   str.zfill()用于向数值的字符串表达式左侧填充0；

-   str.format():

    `print("asdf{0}asdf{1}".format('sdf','asdfas'))`

















