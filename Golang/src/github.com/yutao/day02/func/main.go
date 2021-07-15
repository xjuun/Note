package main

import "fmt"

func main() {
	a := Sum(3, 5)
	fmt.Println(a)
	var c, b int
	c, b = more_return()
	fmt.Println(b, c)
}

//如果参数类型一样可以简写：x,y int
func Sum(x int, y int) int {

	return x + y
}

//多返回值
func more_return() (int, int) {
	return 1, 2
}
