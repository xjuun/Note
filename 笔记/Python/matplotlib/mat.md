

[TOC]

# Matplotlib折线图

## P1

```Python
from matplotlib import pyplot as plt

x = range(2,26,2)
y = [15,13,14,17,20,25,26,27,27,22,18,15]

plt.plot(x,y)
plt.show()
```

## P2

```Python
from matplotlib import pyplot as plt

x = range(2,26,2)
y = [15,13,14,17,20,25,26,27,27,22,18,15]
fig = plt.figure(figsize = (10,8),dpi = 80)

plt.plot(x,y)
plt.savefig("./a.png")
#可以保存为svg这种矢量图格式
#plt.show()

```



指定x轴刻度：

```Python
from matplotlib import pyplot as plt

x = range(2,26,2)
y = [15,13,14,17,20,25,26,27,27,22,18,15]
fig = plt.figure(figsize = (10,8),dpi = 80)

plt.plot(x,y)
plt.xticks(x)
#plt.xticks(range(2,25))
#同样y轴也有yticks
plt.show()
```

## P3 matplotlib的绘制10点到12点气温

```Python
from matplotlib import  pyplot as plt
import random

x = range(0,120)
y = [random.randint(20,35) for i in range(120)]
plt.figure(figsize=(10,6))
plt.plot(x,y)
plt.show()
```

## P4matplotlib设置显示中文、

```python
# coding=utf-8
from matplotlib import  pyplot as plt
import random
plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
x = range(0,120)
y = [random.randint(20,35) for i in range(120)]
plt.figure(figsize=(20,6))
plt.plot(x,y)
_x = list(x)
_xtick_labels = ['10点{}分'.format(i) for i in range(60)]
_xtick_labels += ['11点{}分'.format(i)for i in range(60)]
plt.xticks(_x[::3],_xtick_labels[::3],rotation=45)
#rotation旋转角度
#默认不支持中文
plt.show()
```

## P5matplotlib的设置图形信息

```python
from matplotlib import pyplot as plt
import random

plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
x = range(0,120)
y = [random.randint(20,35) for i in range(0,120)]

plt.figure(figsize=(20,8))
plt.plot(x,y)
_x = list(x)
_xtick_labels = ['10:{}'.format(i) for i in range(60)]
_xtick_labels += ['11:{}'.format(i) for i in range(60)]

plt.xticks(_x[::3],_xtick_labels[::3], rotation=45)
plt.xlabel("时间")
plt.ylabel("温度")
plt.title("10点到12点每分钟气温变化情况")
plt.show()
```





```python
from matplotlib import pyplot as plt
import random

plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.figure(figsize=(10,6),dpi = 80)
x = range(11,30)
y = [random.randint(1,3) for i in range(1,20)]
plt.xticks(range(11,30)[::3])
plt.yticks(range(1,4))
plt.plot(list(x),y)
#绘制网格
plt.grid(alpha = 0.4)

plt.show()
```




``` Python
from matplotlib import pyplot as plt
import random

plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.figure(figsize=(10,6),dpi = 80)
x = range(11,30)
y_1 = [random.randint(1,3) for i in range(1,20)]
y_2 = [random.randint(1,3) for i in range(1,20)]
plt.xticks(range(11,30)[::3])
plt.yticks(range(1,4))
plt.plot(list(x),y_1,label='自己')
plt.plot(list(x),y_2,label='同桌')
#绘制网格
plt.grid(alpha = 0.4)

#添加图例
plt.legend()


plt.show()
```

## 总结

<img src="D:\笔记\Python\matplotlib\Untitled.assets\image-20210328141115352.png" alt="image-20210328141115352" style="zoom:50%;" />

# Matplotlib常用统计图

## P1 散点图

```python
from matplotlib import  pyplot as plt
import  random

y =  [random.randint(1,9) for i in range(1,60)]
y2 = [random.randint(20,30) for i in range(1,60)]
x = range (1,60)
plt.scatter(x,list(y),label ="下")
#散点图
plt.plot(x,y2,label = "上")


plt.legend()
plt.show()
```

## P2 条形图



```python 
from matplotlib import  pyplot as plt
import  random
y2 = [random.randint(20,30) for i in range(1,60)]
y3 = [random.randint(40,60) for i in range(1,60)]
x = range (1,60)
plt.figure(figsize=(20,9))
plt.legend()

plt.plot(x,y2,label = "上")
plt.bar(x,y3)
plt.show()
```

