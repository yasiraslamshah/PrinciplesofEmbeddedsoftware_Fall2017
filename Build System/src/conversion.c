/**
 * @file conversion.c 
 * @brief This file is to be used to project 1.
 *
 * @author Gautham and Yasir
 * @date Oct 2, 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "platform.h"
#include "project1.h"
#include "conversion.h"


uint8_t my_itoa(int32_t data,uint8_t* ptr, uint32_t base)
{

uint8_t a=1;
int sign=0;
int8_t i=0,j=0;
uint8_t temp;

if(data==0)
  {
    *(ptr+a++)='0';
    return 0;
  }

if (data<0)
  {
   sign=1;
   data = -1*data;
  }

while(data!=0)
  {
   uint32_t rem=data % base;
   if(rem>9)
    {
      *(ptr+a++)=(rem-10)+'a';
     }
   else
     {
      *(ptr+a++)= rem+'0';
     }
 data = data/base;
  }

if(sign==1)
  {
   *(ptr+a++)='-';
  }


i=a-1;
j=0;
 while(j <i)
       {
         temp= *(ptr+j);
         *(ptr+j) = *(ptr+i);
         *(ptr+i)=temp;
         j++;
         i--;
       }
*(ptr+a)='\0';




return a;
}



int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
int i=0,q=0;
int sign;
int32_t res=0, val = 0 , count = 0;


if(*ptr == '-')
{

i++;
q++;
count++;
sign=1;
}

if(base==10)
{
while(i<digits-1)
  {
res= res*10+*(ptr+i)-'0';
i++;
  }
}


if(base==16)
{


while(i<digits-1)
  {
  if((*(ptr+i-'0')>9))
   {
   val= *(ptr+i)-'a'+10;

   }
  else
  {
  val=*(ptr+i);
  val = val - '0';
  }

i++;
res =res*16+val;
}
}
if(sign==1)
{
res= -1*res;
}
return res;
}


int8_t little_to_big32(uint32_t *data, uint32_t length)
{
    uint32_t i = 0;
    while(i< length)
    {
        uint32_t m = *(data + i);

        int8_t a1,a2,a3,a4;
        a1 = (m & 0x000000ff);
        a2 = (m & 0x0000ff00) >> 8;
        a3 = (m & 0x00ff0000) >> 16;
        a4 = (m & 0xff000000) >> 24;

        m = ((a1<<24)|(a2<<16)|(a3<<8)|(a4));

        *(data + i) = m;
        i++;

    }
    return 0;

}

int8_t big_to_little32(uint32_t *data, uint32_t length)
{
    uint32_t i = 0;
    while(i < length)
    {
        uint32_t m = *(data + i);

        int8_t m1,m2,m3,m4;
        m1 = (m & 0xff000000) >> 24;         //00000004
        m2 = (m & 0x00ff0000) >> 16;         //00000003
        m3 = (m & 0x0000ff00) >> 8;          //00000002
        m4 = (m & 0x000000ff);               //00000001

        m = ((m1)|(m2<<8)|(m3<<16)|(m4<<24));  //01020304

        *(data + i) = m;
        i++;

    }
    return 0;
}	





