#include <stdio.h>

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa
void  ReverseString(char *str, int len)
{
    char temp;
    int i,end,start;
    // Đảo ngược từng kí tự
    // Đổi chỗ 2 phần tử đầu và cuối của chuỗi 
    for (i = 0; i < len / 2; i++) {  
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }


     // Đảo ngược từng từ trong chuỗi
    start = 0; // Đánh dấu vị trí bắt đầu của một từ
    end = 0;   // Đánh dấu vị trí kết thúc của một từ
    while (end < len) {
        if (str[end] == ' ') {
            // Đảo ngược các kí tự khi gặp dấu cách
            for (i = start; i < (start + end) / 2; i++) {
                temp = str[i];
                str[i] = str[start + end - i - 1];
                str[start + end - i - 1] = temp;
            }
            
            // Chuyển sang từ tiếp theo
            start = end + 1;
        }
        
        end++;
    }
        // đảo ngược từ cuối cùng trong chuỗi
            for (i = start; i < (start + end) / 2; i++) {
                temp = str[i];
                str[i] = str[start + end - i - 1];
                str[start + end - i - 1] = temp;
            }
    
}



void CapPoint (char *str, int len)
{
    int i,check = -1;
    for ( i = 0; i < len; i++)
    {
        if (str[i] == '.'  )
        {
          check = i ; // đánh dấu vị trí của dấu chấm
          continue; // tiếp tục duyệt chuỗi
        }
        if (check != -1 && (str[i]>= 'a' && str[i]<= 'z'))
        {
            str[i] -= 32;   // In hoa phần tử thứ i nếu phần tử đó là chữ
            check = -1; // xoá vị trí dấu chấm
        }
        
        
    }
    
}


void normal (char *str, int len)
{
    int i;
    for ( i = 0; i < len; i++)
    {
        
        if (str[i]>='A'&& str[i]<='Z')
        {
            str[i]+=32;
        }
        
    }
    
}

void CapAll(char *str, int len)
{
     int i;
    for ( i = 0; i < len; i++)
    {
        
        if (str[i]>='a'&& str[i]<='z')
        {
            str[i]-=32;
        }
        
    }
}






int main(int argc, char const *argv[])
{
    // printf("chu thuong: %c, chu hoa: %c\n", 'a', 'a'-32);
    // printf("chu thuong: %c, chu hoa: %c\n", 'i', 'i'-32);
    // printf("chu thuong: %d, chu hoa: %d\n", 'e', 'E');
    char arr[] = "The Grammy award-winning singer. Who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
    int len = sizeof(arr)/sizeof(char);
    printf("Chuoi ban dau \n%s\n",arr);


    ReverseString(arr, len -1);
    printf("Chuoi sau khi dao nguoc \n %s \n",arr);

    CapPoint(arr,len-1);
    printf("Chuoi sau khi dao nguoc + in hoa sau dau cham\n%s\n",arr);

    normal(arr,len -1);
    printf("Chuoi sau khi dao nguoc + chu thuong\n%s\n",arr);


    CapAll(arr,len-1);
    printf("Chuoi sau khi dao nguoc + toan bo in hoa\n%s\n",arr);
    return 0;
}
