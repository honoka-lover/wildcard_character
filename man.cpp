#include<iostream>
using namespace std;
bool PathernMatch(char *pat,char *str)
{
 char *s=NULL;
 char *p=NULL;
 bool star=false;
 bool bBreak=false;
 do
 {
    bBreak=false;
    for(s=str,p=pat;*s;++s,++p)
    {
     switch(*p)
     {
     case '?':
      break;
     case '*':
      star=true; //出现*匹配符
      str=s;
      pat=p;
      if(!*++pat)
          return true;
      bBreak=true; //退出循环
      break;
     default:
      if(*s!=*p)
      {
       if(!star)
        return false;
       str++;
       bBreak=true;
      }
      break;
     }
     if(bBreak) //退出循环 重新开始循环
      break;
    }
    if(bBreak==false)
    {
        if(*p=='*'){
            ++p;
            if(*p!='\0'){
                pat=p;
                ++pat;
                continue;
            }
        }
        return (!*p);
    }
 } while(true);
}
int main()
{
   char a[100]="*12";
   char b[100]="1212";
   cout<<PathernMatch(a,b)<<endl;
   return 0;
}
