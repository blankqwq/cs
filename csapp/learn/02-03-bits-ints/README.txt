# 深入操作系统

目标
1. Ints are not integers,floats are not reals(Computer Arithmetic)
2. You've got to know assembly
3. Memory Matters(Random access Memory is an Unphysical Abstraction)
    - MemorySystemPerformanceExample
4. 

## 概述

```c
typedef struct {
    int a[2];
    double d;
}struct_t;

double fun(int i){
    volatile struct_t s;
    s.d=3.14;
    s.a[i]=1073741824;
    return s.d;
}

//fun(6)...segment fault
```
> 实际

```shell
//todo
```

```c
// 命中
for(i=0;i<2048;i++){
    for(j=0;j<2048;j++)
        dst[i][j]=src[i][j]
}

// 每次缓存的数据无法使用
for(i=0;i<2048;i++){
    for(j=0;j<2048;j++)
        dst[j][i]=src[i][j]
}
```



## 数值的重要性

> Bits,Bytes,and Integers

1. 每一个bit是0/1
2. 信号编码:模拟信号和数字信号
3. 二进制表示

> bytes=8bits

1. Binary 0000 0000 -> 1111 1111
2. hex    00        -> FF
3. Dec     0        -> 255



| C DataType | 32 | 64bit | x86-64 |
| --- | --- | --- | --- |
| char | 1 | 1 | 1 |
| short | 2 | 2 | 2 |
| int | 4 | 4 | 4 |
| float | 4 | 4 | 4 |
| long int | 4 | 8 | 8 |
| double | 8 | 8 | 8 |
| long double | - | - | 10/16 |
| point | 4 | 8 | 8 |

> 布尔运算

- &(and)
- |(or)
- ~(not)
- ^(xor)


- 数值的存储
    - 原码
    - 反码
    - 补码
        - 将加减运算都变为加法
        - 乘除当作无符号数运算
            - -3*-2=1101*1110==13*14=182==b6=1011 | 0110=6
        - 正溢出
            - 5+6: 0101+0110 = 1011 = -8+3=-5
        - 反溢出
            - -3-6= 1101+1010 = 0111 = 7


- 有符号
    - 符号扩展
        - 4bit->8bit
        - 直接添加1
        - 负数扩展
- 无符号
    - 因为无符号运算导致的惨案
```c
#include int main(){ 
    unsigned a=128; int b=-1; 
    printf("%d",b>a); 
    char c[1000]={""}; 
    int i; int m=1000; 
    // 转换为无符号类型,所以始终会大于0,死循环
    for(i=1000-1;i-sizeof(char)>=0;i--) {           
        printf("%d,%d,%d---,%u\n",c[i],i,m--,i-sizeof(char));
    } 
    return 0;
}
```


## 浮点数

IEE-754 & kahan算法 & 手动实现bigdecimal

show-bytes.c
        Demonstrates byte respresentations of different data types

show-bytes.{32,64}
        32- and 64-byte versions of show-bytes.c

sb64-15213.txt
        Output of ./show-bytes64 15213


