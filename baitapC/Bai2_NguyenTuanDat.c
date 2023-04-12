#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



void readOnes(uint32_t num)
{
    uint32_t a = (num % 1000); // hang don vi
    switch ((a%10)) 
    {   
        case 1:printf("mot ");break;
        case 2:printf("hai ");break;
        case 3:printf(" ba  ");break;
        case 4:printf("bon  ");break;
        case 5:printf("nam ");break;
        case 6:printf("sau ");break;
        case 7:printf("bay ");break;
        case 8:printf("tam ");break;
        case 9:printf("chin ");break;
    default:break;
    } 
}

void  readTens(uint32_t num)
{
    uint32_t a = ((num % 1000)%100)/10; // hang chuc
         uint32_t arr[7];
    switch (a) 
    {   
        case 0:
           for (uint8_t  i = 0; 0 < num; i++)
        {
                
                arr[i]= num %10;
                num /=10;
                if (    i == 1 && arr[0] != 0 )
                {
            printf(" le  ");break;
                }

        }
        break;
        case 1:printf("muoi  ");break;
        case 2:printf("hai muoi  ");break;
        case 3:printf("ba muoi  ");break;
        case 4:printf("bon muoi  ");break;
        case 5:printf("nam muoi  ");break;
        case 6:printf("sau muoi  ");break;
        case 7:printf("bay muoi  ");break;
        case 8:printf("tam muoi  ");break;
        case 9:printf("chin muoi  ");break;
    default:break;
    } 
}

void readhundres (uint32_t num)
{
    uint32_t a = ((num % 1000)/100); //hang tram

    switch (a) 
    {   

        case 1:printf("mot tram  ");break;
        case 2:printf("hai tram  ");break;
        case 3:printf("ba tram  ");break;
        case 4:printf("bon tram  ");break;
        case 5:printf("nam tram  ");break;
        case 6:printf("sau tram  ");break;
        case 7:printf("bay tram  ");break;
        case 8:printf("tam tram  ");break;
        case 9:printf("chin tram  ");break;
    default:break;
    } 
}

void readThousands (uint32_t num)
{
     uint32_t arr[7];
    uint32_t a = (num % 1000000) / 1000; // hang nghin
 
    switch ((a%10)) 
    {   
        case 0:
           for (uint8_t  i = 0; 0 < num; i++)
                {
                arr[i]= num %10;
                num /=10;
                if (arr[i]==0)
                {
                    if (   i == 3 && (arr[7] != 0 ))
                    {
                    printf(" nghin  ");
                    break;
                    }  
                }
                
                }
        break;
        
        case 1:
           for (uint8_t  i = 0; 0 < num; i++)
        {
                
                arr[i]= num %10;

                num /=10;
                if (    i == 3 && arr[3] == 1 )
                {
            printf("mot nghin  ");break;
                }

        }
        break;
        case 2:printf("hai nghin  ");break;
        case 3:printf("ba nghin  ");break;
        case 4:printf("bon nghin  ");break;
        case 5:printf("lam nghin  ");break;
        case 6:printf("sau nghin  ");break;
        case 7:printf("bay nghin  ");break;
        case 8:printf("tam nghin  ");break;
        case 9:printf("chin nghin  ");break;
    default:break;
    } 
}


void readTenThousands (uint32_t num)
{
    uint32_t a = (num % 1000000) / 1000; //  chuc nghin
    switch ((a%100)/10) 
    {   
        case 1:printf("muoi  ");break;
        case 2:printf("hai muoi  ");break;
        case 3:printf("ba muoi  ");break;
        case 4:printf("bon muoi  ");break;
        case 5:printf("nam muoi  ");break;
        case 6:printf("sau muoi  ");break;
        case 7:printf("bay muoi  ");break;
        case 8:printf("tam muoi  ");break;
        case 9:printf("chin muoi  ");break;
    default:break;
    } 
}

void readHundedThousands(uint32_t num)
{
   uint32_t a = (num % 1000000) / 1000;
    switch (a/100) // tram nghin
    {   
        case 1:printf("mot tram  ");break;
        case 2:printf("hai tram  ");break;
        case 3:printf("ba tram  ");break;
        case 4:printf("bon tram  ");break;
        case 5:printf("nam tram  ");break;
        case 6:printf("sau tram  ");break;
        case 7:printf("bay tram  ");break;
        case 8:printf("tam tram  ");break;
        case 9:printf("chin tram  ");break;
    default:break;
    } 
}

void readMilions (uint32_t num)
{
    uint32_t a = num / 1000000; // hàng triệu
    switch (a) 
    {   
    case 1:printf("mot trieu ");break;
    case 2:printf("hai trieu ");break;
    case 3:printf("ba trieu ");break;
    case 4:printf("bon trieu ");break;
    case 5:printf("nam trieu ");break;
    case 6:printf("sau trieu ");break;
    case 7:printf("bay trieu ");break;
    case 8:printf("tam trieu ");break;
    case 9:printf("chin trieu ");break;
    case 10:printf("muoi trieu ");break;
    default:break;
    }
}


void readnum(uint32_t num)
{
    readMilions(num);
    readHundedThousands(num);
    readTenThousands(num);
    readThousands(num);
    readhundres(num);
    readTens(num);
    readOnes(num);
}
int main() {
    uint32_t num ;
    printf("Nhap vao mot so <= 10trieu \n");
    scanf("%d", &num); 
    if (num == 0) {
        printf("Khong\n");
        return 0;
    }
    readnum(num);
}