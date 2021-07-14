package main

import (
	"fmt"
	"strings"
)

func main() {
	var1 := "aaa"
	fmt.Printf("%d\n", len(var1))

	var2 := "bbb"
	var3 := "ccc"
	var4 := var3 + var2
	fmt.Println("var4:", var4)
	var5 := fmt.Sprintf("%s%s", var3, var4)
	fmt.Println("var5:", var5)
	s := "qwqw.e.wer.qwe.qwer.asdfg"
	var6 := strings.Split(s, ".")
	fmt.Println("var6:", var6)
	var7 := strings.Contains(s, "e")
	fmt.Println("var7:", var7)
	s = "asdfghjkl;"

	var8 := strings.HasPrefix(s, "as") //前缀
	fmt.Println("var8:", var8)
	var9 := strings.HasSuffix(s, "as") //后缀
	fmt.Println("var9:", var9)
	var10 := strings.Index(s, "fg") //第一次出现的位置
	fmt.Println("var10:", var10)
	var11 := strings.LastIndex(s, "jk") //最后出现的位置
	fmt.Println("var11:", var11)

	//字符串修改
	a := "hello"
	bytes1 := []byte(a)
	bytes1[0] = 'H'
	fmt.Println("s:", string(bytes1))

	//中文
	b := "中文修改"
	runes1 := []rune(b)
	runes1[0] = '啊'
	fmt.Println("b:", string(runes1))

	//类型转换
	var_float := 123.456
	var_int := int(var_float)
	fmt.Println("强制类型转换：", var_int)

}
