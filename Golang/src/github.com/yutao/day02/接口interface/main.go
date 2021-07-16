package main

import "fmt"

type dog struct{}

type cat struct{}

func (d dog) say() {
	fmt.Println("wangwagn")
}

func (c cat) say() {
	fmt.Println("miaomiaomiao")
}

//接口不管你是什么类型，只管你要实现什么方法
// func da(arg ？？？) {
// 	arg.say()
// }

type sayer interface {
	say()
}

//上面注释的实现
func da(arg sayer) {
	arg.say()
}

func main() {

	c1 := cat{}
	da(c1)
	d1 := dog{}
	da(d1)
}
