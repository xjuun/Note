package main

import "fmt"

func main() {
	//函数内部无法声明带名字的函数
	//匿名函数
	f1 := func(x, y int) {

		fmt.Print(x+y, "\n")

	}
	f1(11, 22)

	//如果值是调用一次，还可以写成立即执行函数
	func(x, y int) {
		fmt.Println(x + y)
	}(12, 123)

}
