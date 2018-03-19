/*
1002. 写出这个数 (20)

读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

#include <cstdio>
#include <cstring>
int main() {
  char str[110];
  gets(str);
  int len = strlen(str);
  int sum = 0;  // sum 存放所有数位之和
  for (int i = 0; i < len; i++) {
    sum += str[i] - '0';  //将每一位累加
  }

  int num = 0, ans[10]; //num表示sum的位数
  while(sum != 0) {
    //将sum中的每一位存到数组中，sum的底位存到ans[]的低位
    ans[num] = sum % 10;
    num++;
    sum /= 10;
  }

  char change[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
  }; //定义二维字符数组，即change[0] = "ling", change[1] = "yi"...
  for (int i = num -1; i >= 0; i--) { // 从高位开始输出
    printf("%s", change[ans[i]]);  //ans[i]即为从高位开始的第一个数字
    if(i!=0) printf(" "); //如果i没有到0（即不是最后一次循环），则输出空格
    else printf("\n");  //如果是最后一次循环，则输出换行
  }
  
  return 0;
}
