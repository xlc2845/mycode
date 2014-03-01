#include <stdio.h>
#include <stdlib.h>
 
 
int main()
{
    freopen("d://in.txt", "r", stdin);
    int x,y;
    char a[]="Yes",b[]="No";
    scanf("%d",&x);
     y=x%4==0&&x%100!=0||x%400==0?a:b;
     puts(y);
    //printf("%d\n", x);
    return 0;
}