// mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
//  sap xep mang theo thu tu tang dan
//  liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                              7 xuat hien 2 lan
//                                              8 xuat hien 3 lan
/*
 * File: array.c
 * Author: Nguyễn Tuấn Đạt
 * Date: 08/03/2023
 * Description: Chương trình sắp xếp mảng
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/**
 * Function: struct typeArray
 * Description: chứa kích thước và địa chỉ bắt đầu của mảng dùng để tạo mảng động
*/
typedef struct
{
    uint8_t size;          // kích thước của mảng
    uint8_t *firstAdd;  // con trỏ trỏ đến địa chỉ của phần tử đầu tiên trong mảng
} typeArray;
/**
 * Function: randomA
 * Description: dùng để tạo các số nguyên tự nhiên trong phạm vi minN -> maxN
 * Input:
 *      minN - int
 *      maxN - int
 * Output:
 *      random number - int 
*/
int randomA(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);  //được sử dụng để sinh ra một số nguyên ngẫu nhiên trong phạm vi từ minN đến maxN.
}

/**
 * Function: randomArray
 * Description: Dùng để tạo để tạo ra một mảng ngẫu nhiên
 * Input:
 *      *value - typeArray
 *      length - uint8_t
 * Output:
 *      value->firstAddr[i]
*/
void randomArray(typeArray *value, uint8_t length)
{
    // Khởi tạo bộ sinh số ngẫu nhiên với giá trị thời gian hiện tại
    srand((int)time(0));
    // Lưu thông tin kích thước của mảng vào biến size trong struct typeArray
    value->size = length;
    // Cấp phát bộ nhớ động cho mảng, kích thước của mảng là length * size của kiểu uint8_t
    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t) * value->size);
    // Tạo giá trị ngẫu nhiên cho mỗi phần tử trong mảng
    for (int i = 0; i < value->size; ++i)
    {
        // Sử dụng hàm randomA để tạo giá trị ngẫu nhiên trong phạm vi từ 0 đến 10
        value->firstAdd[i] = randomA(0, 10);
    }
}
void printArray(typeArray *arr)
{
    // Duyệt qua từng phần tử của mảng và in giá trị của nó ra màn hình
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->firstAdd[i]);
    }
    printf("\n\n");
}


/**
 * Function: sortArray
 * Description: Dùng để tạo sắp xếp các phần tử trong mảng từ bé đến lớn
 * Input:
 *      &arr - typeArray
 * 
 * Output:
 *      none
*/
void sortArray(typeArray *arr)
{
    // Biến tạm để lưu giá trị khi swap
    uint8_t temp;
    // Duyệt qua từng phần tử của mảng trừ phần tử cuối cùng
    for (int i = 0; i < (arr->size)-1; i++)
    {
         // Duyệt qua từng phần tử còn lại của mảng để so sánh với phần tử thứ i
        for (int j = i+1; j < arr->size; j++)
        {
             // Nếu phần tử j lớn hơn phần tử i, ta hoán đổi giá trị của 2 phần tử
            if (arr->firstAdd[i] > arr->firstAdd[j])
            {
               temp = arr->firstAdd[i];
               arr->firstAdd[i] = arr->firstAdd[j];
               arr->firstAdd[j] = temp;
            }
        }
    }
}
/**
 * Function: countArray
 * Description: Hàm có chức năng đếm số lần phần tử xuất hiện
 * Input:
 *      &arr - typeArray
 * 
 * Output:
 *      none
*/
void countArray(typeArray *arr)
{
    // khởi tạo mảng count có kích thước theo arr
   uint8_t count[arr->size];
   // duyệt qua các phần tử của arr
   for (int i = 0; i < arr->size; i++)
   {
    // Giá trị của các phần tử trong mảng count bằng 0
     count[i]=0;
   }
   
    // duyệt qua các phần tử của arr
   for (int  j = 0; j < arr->size; j++)
   {
    // giá trị của mỗi phần tử arr sẽ các phần tử trong mảng count và tại vị trí phần tử đó giá trị của nó trong mảng count sẽ tăng len 1
     count[arr->firstAdd[j]]++;
   }

   for (int z = 0; z < arr->size; z++)
   {
        if (count[z]>0)
        {
           printf("%d xuat hien %d lan\n",z,count[z]);
        }
   }
}
int main(int argc, char const *argv[])
{
    typeArray arr;
    randomArray(&arr,20);
    printf("Mang ban dau\n");
    printArray(&arr);
    sortArray(&arr);
    printf("Mang sau khi sap xep\n");
    printArray(&arr);
    printf("Liet ke so lan xuat hien\n");
    countArray(&arr);
    return 0;
}
