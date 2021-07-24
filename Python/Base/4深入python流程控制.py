#!/usr/bin/env python
# -*- coding:utf-8 -*-

def fun(par1, par2=1, par3="aaaa"):
    print("par1:", par1)
    print("par2:", par2)
    print("par3:", par3)
    print(";;;;;;;;;;;;")


def change_args_1(p1, p2, *args):
    print("p1 and p2", p1, " ", p2)
    print("args:", args)


if __name__ == "__main__":
    # for i in range(10):
    # for i in range(0,10):
    for i in range(0, 10, 1):
        print(i)
    print("#########################################")
    a = ['Mary', 'had', 'a', 'little', 'lamb']
    for i in range(len(a)):
        print(a[i])
    print("#########################################")
    fun("as", 3, "zxcv")
    fun("as", 4)
    fun("as")
    print("#########################################")
    change_args_1(1, 2, 3, 4, 5, 6)
