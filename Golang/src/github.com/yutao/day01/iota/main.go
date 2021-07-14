package main

import "fmt"

//iota从0开始
const (
	v1 = iota + 1
	v2
	v3
	_
	v5
)

//插队
const (
	a1 = iota
	a2 = 100
	a3
	a4 = iota //const中每新增`一行`常量声明将使iota计数一次
)

const (
	b1, b2 = iota, iota
)

//定义数量级
const (
	_ = iota
	a = 1 << (10 * iota)
	b = 1 << (10 * iota)
	c = 1 << (10 * iota)
)

func main() {

	// fmt.Println("v1:", v1)
	// fmt.Println("v2:", v2)
	// fmt.Println("v3:", v3)
	// fmt.Println("v5:", v5)

	// fmt.Println("a1:", a1)
	// fmt.Println("a2:", a2)
	// fmt.Println("a3:", a3)
	// fmt.Println("a4:", a4)

	// fmt.Println("b1,b2", b1, b2)

	fmt.Println("a,b,c:", a, b, c)
}
