package main

import "fmt"

func main() {
	//指针基础
	a := 10
	b := &a
	c := *b
	fmt.Printf("a:%d,\t\t&a:%p\n", a, &a)
	fmt.Printf("b:%x,\t\t&b:%p\n", b, &b)
	fmt.Printf("c:%d,\t\t&c:%p\n", c, &c)
	fmt.Printf("b's type:%T\n&b'stype:%T\n", b, &b)

	//new函数：new函数不太常用，使用new函数得到的是一个类型的指针
	//并且该指针对应的值为该类型的零值
	a1 := new(int)
	fmt.Printf("new a1:,type:%T", a1)

	//make函数，它只用于slice、map以及chan的内存创建
}
