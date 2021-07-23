package main

import "fmt"

//参数：func()
//无返回值
func f1(f func()) {
	fmt.Println("同事写的func1")

}

//参数：int,int
//无返回值
func f2(x, y int) {
	fmt.Println("同事写的func2")
	fmt.Println(x + y)
}

func main() {
	ret := f3(f2, 11, 22)
	f1(ret)
}

func f3(f func(int, int), x, y int) func() {
	a := func() {
		f2(x, y)
	}
	return a
}
