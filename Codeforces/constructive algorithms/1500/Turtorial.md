[1368B. Codeforces Subsequences](https://codeforces.com/problemset/problem/1368/B)

在乘积相等时，和最小的情况是几个数尽量接近，两个数之间差值最多为1.枚举t和t+1的个数即可

[1542B. Plus and Multiply](https://codeforces.com/problemset/problem/1542/B)

如果n在其中，比n小的m也在其中只有可能$(n mod b) = (m mod b) + a^k$，因此最终转化为$a^k+mb=n$，当a=1,退化成(n-1)%b，否则枚举a的个数

[1399D. Binary String To Subsequences](https://codeforces.com/problemset/problem/1399/D)

两个栈，一个维护末尾为0的编号，一个维护末尾为1的编号，当前位置为0时，如果末尾为1的栈为空，则计数器加1,否则把末尾为1的出栈，把当前数加入末尾为0的栈中，表示完成匹配，当前位置为1同理，最终来个栈中元素个数就是所求的种类数

[1372C. Omkar and Baseball](https://codeforces.com/problemset/problem/1372/C)

比较开脑洞，首先排除最简单的2种情况，自然有序和全部乱序，剩下的可以分别找到左边和右边的第一个无序的位置，然后把区间内的元素先乱序，在有序即可

[1440C. Binary String Reconstruction](https://codeforces.com/problemset/problem/1400/C)

根据$s_i=0$的位置，找出对应的w的值，然后再去判断当前序列是否合法