package main

import "fmt"

func main() {
	a := [5]int{1, 2, 3, 4, 5}
	b := a[1:3] //左包含，右不包含
	fmt.Println(b, len(b), cap(b))
	b = a[:5]
	fmt.Println(b)

	//完整切片表达式:a[low:hight:max]
	//切片的赋值拷贝,对一个切片的修改会影响另一个切片的内容
	s1 := make([]int, 3)
	s2 := s1
	s2[0] = 100
	fmt.Println(s1)
	fmt.Println(s2)

	//append()方法为切片增加元素
	s := []int{1, 2, 3}
	s = append(s, 4, 5, 6)
	fmt.Println(s)

	//使用copy()函数复制切片
	aa := []int{1, 2, 3, 4, 5}
	cc := make([]int, 5, 5)
	fmt.Println(aa)
	fmt.Println(cc)
	copy(cc, aa)
	fmt.Println(aa)
	fmt.Println(cc)

	//从切片中删除元素
	aa = []int{1, 2, 3, 4, 5, 6}
	aa = append(aa[:2], aa[3:]...)
	fmt.Println(aa)

}
