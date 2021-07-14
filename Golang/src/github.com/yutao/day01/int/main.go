package main

import "fmt"

func main() {
	var a1 int = 0x20
	a2 := 0b10010
	fmt.Printf("a1: %d\n", a1)
	fmt.Printf("a1: %o\n", a1)
	fmt.Printf("a1: %b\n", a1)
	fmt.Printf("a1: %x\n", a1)
	fmt.Printf("a1: %X\n", a1)
	fmt.Printf("a2: %b\n", a2)
	fmt.Printf("a2: %T\n", a2) //查看变量的类型

	//声明int8类型 的变量
	a3 := int8(123)
	fmt.Printf("a3: %b\n", a3)
}
