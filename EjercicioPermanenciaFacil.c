#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int main(void)
{
int he,me,hs,ms,mintot;
scanf("%d:%d",&hs,&ms);
me=he*60+me;
ms=hs*60+ms;
if(ms<me)
    mintot=ms+(60*24-me);
  else
    mintot=ms-me;
mintot/60,mintot%60);
printf("Permanencia: %02d:%02d\n", );
