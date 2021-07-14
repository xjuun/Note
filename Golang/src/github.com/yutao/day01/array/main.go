package main

import "fmt"

func main() {
	//方法一
	var a [3]int
	var b = [3]int{1, 2, 3}
	var c = [3]string{"aa", "bb", "cc"}
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;")
	//方法二：让编译器自己推断
	var d [3]int
	var e = [...]int{1, 2, 3, 4}
	var f = [...]string{"aa", "bb", "cc"}
	fmt.Println(d)
	fmt.Println(e)
	fmt.Println(f)
	//方法三：指定索引
	g := [5]int{1: 1, 3: 3}
	fmt.Println(g)
	fmt.Printf("%T\n", g)

	//数组的遍历,方法一
	h := [...]string{"asd", "xcv", "qwer", "阿斯蒂芬"}
	for i := 0; i < len(h); i++ {
		fmt.Print(h[i], " ")
	}
	fmt.Print("\n")
	//方法二
	for aa, bb := range h {
		fmt.Println(aa, bb)
	}
}
