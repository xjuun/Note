package main

import (
	"fmt"
	"math"
)

func main() {
	a := math.MaxFloat64

	fmt.Println(a)
	fmt.Printf("%T", a)
	var b bool
	fmt.Printf("b: %T,,value:%v", b, b)

	v1 := "啊啊啊啊"
	//c := len(v1)
	fmt.Printf("\n\n%d", len(v1))
}
