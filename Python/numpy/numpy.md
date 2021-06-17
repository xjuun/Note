[TOC]

# Numpy Ndarry对象

```python
import numpy as np
a = np.array([1,2,3,9])
b = np.array([[1,2,3],[1,1,3]])#多一个维度
print(a)
```

```
numpy.array(object, dtype = None, copy = True, order = None, subok = False, ndmin = 0)
```

参数：

| 名称   | 描述                                                      |
| :----- | :-------------------------------------------------------- |
| object | 数组或嵌套的数列                                          |
| dtype  | 数组元素的数据类型，可选                                  |
| copy   | 对象是否需要复制，可选                                    |
| order  | 创建数组的样式，C为行方向，F为列方向，A为任意方向（默认） |
| subok  | 默认返回一个与基类类型一致的数组                          |
| ndmin  | 指定生成数组的最小维度                                    |

# numpy数据类型

| 名称       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| bool_      | 布尔型数据类型（True 或者 False）                            |
| int_       | 默认的整数类型（类似于 C 语言中的 long，int32 或 int64）     |
| intc       | 与 C 的 int 类型一样，一般是 int32 或 int 64                 |
| intp       | 用于索引的整数类型（类似于 C 的 ssize_t，一般情况下仍然是 int32 或 int64） |
| int8       | 字节（-128 to 127）                                          |
| int16      | 整数（-32768 to 32767）                                      |
| int32      | 整数（-2147483648 to 2147483647）                            |
| int64      | 整数（-9223372036854775808 to 9223372036854775807）          |
| uint8      | 无符号整数（0 to 255）                                       |
| uint16     | 无符号整数（0 to 65535）                                     |
| uint32     | 无符号整数（0 to 4294967295）                                |
| uint64     | 无符号整数（0 to 18446744073709551615）                      |
| float_     | float64 类型的简写                                           |
| float16    | 半精度浮点数，包括：1 个符号位，5 个指数位，10 个尾数位      |
| float32    | 单精度浮点数，包括：1 个符号位，8 个指数位，23 个尾数位      |
| float64    | 双精度浮点数，包括：1 个符号位，11 个指数位，52 个尾数位     |
| complex_   | complex128 类型的简写，即 128 位复数                         |
| complex64  | 复数，表示双 32 位浮点数（实数部分和虚数部分）               |
| complex128 | 复数，表示双 64 位浮点数（实数部分和虚数部分）               |

**numpy 的数值类型实际上是 dtype 对象的实例，并对应唯一的字符，包括 np.bool_，np.int32，np.float32，等等。**

## 数据类型对象（dtype）

数据类型对象（numpy.dtype 类的实例）用来描述与数组对应的内存区域是如何使用，它描述了数据的以下几个方面：：

-   数据的类型（整数，浮点数或者 Python 对象）
-   数据的大小（例如， 整数使用多少个字节存储）
-   数据的字节顺序（小端法或大端法）
-   在结构化类型的情况下，字段的名称、每个字段的数据类型和每个字段所取的内存块的部分
-   如果数据类型是子数组，那么它的形状和数据类型是什么

```python
import numpy as np
# 使用标量类型
dt = np.dtype(np.int32)
print(dt)
```

```python
import numpy as np
# int8, int16, int32, int64 四种数据类型可以使用字符串 'i1', 'i2','i4','i8' 代替
dt = np.dtype('i4')
print(dt)
```

```python
import numpy as np
# 字节顺序标注
dt = np.dtype('<i4')#<是小端，>是大端
print(dt)
```

# numpy数组属性

NumPy 数组的维数称为秩（rank），秩就是轴的数量，即数组的维度。

在 NumPy中，每一个线性的数组称为是一个轴（axis），也就是维度（dimensions）。

NumPy 的数组中比较重要 ndarray 对象属性有：

| 属性             | 说明                                                         |
| :--------------- | :----------------------------------------------------------- |
| ndarray.ndim     | 秩，即轴的数量或维度的数量                                   |
| ndarray.shape    | 数组的维度，对于矩阵，n 行 m 列                              |
| ndarray.size     | 数组元素的总个数，相当于 .shape 中 n*m 的值                  |
| ndarray.dtype    | ndarray 对象的元素类型                                       |
| ndarray.itemsize | ndarray 对象中每个元素的大小，以字节为单位                   |
| ndarray.flags    | ndarray 对象的内存信息                                       |
| ndarray.real     | ndarray元素的实部                                            |
| ndarray.imag     | ndarray 元素的虚部                                           |
| ndarray.data     | 包含实际数组元素的缓冲区，由于一般通过数组的索引获取元素，所以通常不需要使用这个属性。 |

```python
import numpy as np
a = np.arange(24)
print(a.ndim)#a只有一个维度
b = a.reshape(2,4,3)
print(b.ndim)#3个维度
```

ndarray.flags 返回 ndarray 对象的内存信息，包含以下属性：

| 属性             | 描述                                                         |
| :--------------- | :----------------------------------------------------------- |
| C_CONTIGUOUS (C) | 数据是在一个单一的C风格的连续段中                            |
| F_CONTIGUOUS (F) | 数据是在一个单一的Fortran风格的连续段中                      |
| OWNDATA (O)      | 数组拥有它所使用的内存或从另一个对象中借用它                 |
| WRITEABLE (W)    | 数据区域可以被写入，将该值设置为 False，则数据为只读         |
| ALIGNED (A)      | 数据和所有元素都适当地对齐到硬件上                           |
| UPDATEIFCOPY (U) | 这个数组是其它数组的一个副本，当这个数组被释放时，原数组的内容将被更新 |

# numpy创建数组

ndarry数组还可以使用以下几种方式创建

## numpy.empty

用来创建一个指定形状、数据类型且未初始化的数组：

>   numpy.empyt(shape, dtype = float, order = 'C')

参数说明：

| 参数  | 描述                                                         |
| :---- | :----------------------------------------------------------- |
| shape | 数组形状                                                     |
| dtype | 数据类型，可选                                               |
| order | 有"C"和"F"两个选项,分别代表，行优先和列优先，在计算机内存中的存储元素的顺序。 |

```python
import numpy as np 
x = np.empty([3,2], dtype = int) 
print (x)#是随机值
```

## numpy.zeros

创建指定大小的数组，数组元素用0来填充，参数和上面的一样

## numpy.ones

创建指定大小的数组，数组元素用1来填充，参数和上面的一样

# NumPy 从已有的数组创建数组

## numpy.asarry

>   numpy.asarry(a, dtype = None, order =  None)

| 参数  | 描述                                                         |
| :---- | :----------------------------------------------------------- |
| a     | 任意形式的输入参数，可以是，列表, 列表的元组, 元组, 元组的元组, 元组的列表，多维数组 |
| dtype | 数据类型，可选                                               |
| order | 可选，有"C"和"F"两个选项,分别代表，行优先和列优先，在计算机内存中的存储元素的顺序。 |

```python
import numpy as np
x = [1,2,3]
a = np.asarray(x)
print(a)
```

```python
import numpy as np
x = [1,2,3]
a = np.asarray(x,dtype = float)
print(a)
```

## numpy.frombuffer

用于实现动态数组

>    numpy.frombuffer(buffer, dtype = float, count = -1.offset = 9)
>
>   注意：buffer 是字符串的时候，Python3 默认 str 是 Unicode 类型，所以要转成 bytestring 在原 str 前加上 b。

参数说明：

| 参数   | 描述                                     |
| :----- | :--------------------------------------- |
| buffer | 可以是任意对象，会以流的形式读入。       |
| dtype  | 返回数组的数据类型，可选                 |
| count  | 读取的数据数量，默认为-1，读取所有数据。 |
| offset | 读取的起始位置，默认为0。                |

```python
import numpy as np
s = b'asdf'
a = np.frombuffer(s,dtype = 'S1')
print(a)
```

## numpy.fromiter

numpy.fromiter 方法从可迭代对象中建立 ndarray 对象，返回一维数组。


> numpy.fromiter(iterable, dtype, count=-1)


| 参数     | 描述                                   |
| :------- | :------------------------------------- |
| iterable | 可迭代对象                             |
| dtype    | 返回数组的数据类型                     |
| count    | 读取的数据数量，默认为-1，读取所有数据 |

```python
import numpy as np
list = range(6)
it = iter(list)
x = np.fromiter(it,dtype = int)
print(x)
```

# numpy从数值范围创建数组

## numpy.arrange

numpy.arrange(start,stop,step,dtype)

很好理解，就不写参数了，step默认是1，star默认是0

```python
import numpy as np
x = np.arange(5,dtype = int)
print(x)
```



## numpy.linspace

用于创建一个以为数组，数组是等差数列构成的：

np.linspace(star, stop ,num = 50, endpoint = True, retstep = False, dtype = None)

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| `start`    | 序列的起始值                                                 |
| `stop`     | 序列的终止值，如果`endpoint`为`true`，该值包含于数列中       |
| `num`      | 要生成的等步长的样本数量，默认为`50`                         |
| `endpoint` | 该值为 `true` 时，数列中包含`stop`值，反之不包含，默认是True。 |
| `retstep`  | 如果为 True 时，生成的数组中会显示间距，反之不显示。         |
| `dtype`    | `ndarray` 的数据类型                                         |

## numpy.logspace

numpy.logspace 函数用于创建一个于等比数列。格式如下：

> np.logspace(start, stop, num=50, endpoint=True, base=10.0, dtype=None)

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| `start`    | 序列的起始值为：base ** start                                |
| `stop`     | 序列的终止值为：base ** stop。如果`endpoint`为`true`，该值包含于数列中 |
| `num`      | 要生成的等步长的样本数量，默认为`50`                         |
| `endpoint` | 该值为 `true` 时，数列中中包含`stop`值，反之不包含，默认是True。 |
| `base`     | 对数 log 的底数。                                            |
| `dtype`    | `ndarray` 的数据类型                                         |

```python
import numpy as np
x= np.logspace(1,2,num = 10)
print(x)
x = np.logspace(0,9,10,base=2)
print(x)
```

# numpy切片和索引

切片对象可以通过内置的 slice 函数，并设置 start, stop 及 step 参数进行，从原数组中切割出一个新数组。

```python
import numpy as np
a = np.arange(10)
s = slice(2,7,2)   # 从索引 2 开始到索引 7 停止，间隔为2
print (a[s])
```

# numpy高级索引

NumPy 比一般的 Python 序列提供更多的索引方式。除了之前看到的用整数和切片的索引外，数组可以由整数数组索引、布尔索引及花式索引。

## 整数数组索引



```python
import numpy as np 
#以下实例获取数组中(0,0)，(1,1)和(2,0)位置处的元素
x = np.array([[1,  2],  [3,  4],  [5,  6]]) 
y = x[[0,1,2],  [0,1,0]]  
print (y)
;;;;;;;;;;;;;;;;;
output:
    [1  4  5]
```

## 布尔索引

## 花式索引 

# numpy广播（broadcast）

如果两个数组的形状相同，即a.shapr == b.shape，那么可以使用a*b

```python
import numpy as np
a = np.array([1,4,5])
b = np.array([234,54,1])
print(a*b)
```

当形状不同时会广播：

```python
import numpy as np
a = np.array([[0, 0, 0],
              [10, 10, 10],
              [20, 20, 20],
              [30, 30, 30]])
b = np.array([1, 2, 3])
print(a + b)
```

























