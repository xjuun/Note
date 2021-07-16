package main

import "fmt"

func main() {
	a := Sum(3, 5)
	fmt.Println(a)
	var c, b int
	c, b = more_return()
	fmt.Println(b, c)
	fmt.Println("")

	f1_1 := f1
	fmt.Printf("%T\n", f1_1) //返回是func（）

	f2_2 := f2
	fmt.Printf("%T\n", f2_2) //返回是func() int // 返回值是int的函数类型

	f3(f2) //将函数作为参数进行传递
	//f3(f4(3, 5))  参数不同

	//返回值还可以是 函数类型

}

func f1() {
	fmt.Println("hello f1")
}
func f2() int {
	return 1
}
func f3(x func() int) {
	ret := x()
	fmt.Println(ret)

}
func f4(x, y int) int {
	return x + y
}
func ff(x, y int) int {
	return x + y
}
func f5(func(x, y int)) func(int, int) int {
	//func(int, int) int    整个 是一个类型
	return ff
}

//如果参数类型一样可以简写：x,y int
func Sum(x int, y int) int {

	return x + y
}

//多返回值
func more_return() (int, int) {
	return 1, 2
}
