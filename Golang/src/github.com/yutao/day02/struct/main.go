package main

import "fmt"

type Mystruct struct {
	name string
	age  int
}

//方法：
func (s Mystruct) Print() {
	fmt.Println("name is:", s.name, "age is :", s.age)
	fmt.Println("方法执行成功")
}

//构造函数
func GouZao(name string, age int) *Mystruct {
	fmt.Println("构造函数执行成功")
	return &Mystruct{
		name, age,
	}
}

func main() {
	var a1 Mystruct
	a1.name = "qwer"
	a1.age = 123
	fmt.Println("name:", a1.name, "age:", a1.age)

	//匿名结构体
	var a2 struct {
		name string
		age  int
	}
	a2.name = "adsf"
	a2.age = 1345
	fmt.Printf("a2:%#v\n", a2)

	//使用键值对初始化
	a3 := Mystruct{
		name: "zcxv",
		age:  12,
	}
	fmt.Printf("a3:%#v\n", a3)

	//构造函数然后使用方法，
	a4 := GouZao("qwe", 88)
	a4.Print()
}
