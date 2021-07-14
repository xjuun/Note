package main

import "fmt"

func main() {
	//if语句
	if true {
		fmt.Println("true")
	} else if false {
		fmt.Println("false")
	} else {
		fmt.Println("none")
	}

	//for
	for i := 0; i < 10; i++ {
		fmt.Printf("%d ", i)
	}
	fmt.Println()
	//switch--case

	a := 1
	switch a {
	case 1:
		fmt.Println("1")
	case 2:
		fmt.Println("2")
	default:
		fmt.Println("3")
	}

}
