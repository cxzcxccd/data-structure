#include<iostream>
using namespace std;
int main()
{
  //c语言常用方法
  char str[100];
  gets(str);
  scanf("%[^\n]",str);
  //c++常用方法
  getline(cin,str);
 //读取文章，对整篇的文章进行处理时常用方法
  //方法一：（c++）
  string str[3];
for(int i=0;i<3;i++)
    getline(cin,str[i]);
  //方法二：（c语言）
   char  txt[100020];
   while(scanf("%[^\n]",txt)!=EOF)
   {
     这里面是对每一行进行的操作
   }
  return 0;
}
