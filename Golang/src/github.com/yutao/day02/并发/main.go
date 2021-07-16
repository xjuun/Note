package main

import (
	"fmt"
	"time"
)

func hello() {
	fmt.Println("hello hello")
}

func main() {
	go hello() //在函数前加一个go就OK
	fmt.Println("hello main")
	time.Sleep(1)
}
