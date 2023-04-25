/*
 * File: array.c
 * Author: Nguyễn Tuấn Đạt
 * Date: 08/03/2023
 * Description: Chương trình xử lí chuỗi
 */
//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa



#include <stdio.h>

/**
 * Function: ReverseString
 * Description: đảo ngược chuỗi
 * Input:
 *      *str - char
 *       len - int
 * Output:
 *      none
*/
void  ReverseString(char *str, int len)
{
    char temp;
    int i,end,start;



    // Đảo ngược chuỗi bằng cách hoán đổi ký tự từ hai đầu của chuỗi,
    // bắt đầu từ ký tự đầu tiên và ký tự cuối cùng và di chuyển về phía
    // giữa chuỗi cho đến khi đến điểm giữa.
    // Vòng lặp này lặp qua nửa đầu của chuỗi. (len/2)
    for (i = 0; i < len / 2; i++) 
    {  
        // Một biến tạm thời "temp" được sử dụng để hoán đổi các ký tự ở cả hai đầu.
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }


    // Thiết lập biến bắt đầu và kết thúc chuỗi ban đầu.
    start = 0; 
    end = 0;  
    // Lặp lại cho đến khi đến cuối chuỗi.
    while (end < len) {
        // Nếu ký tự hiện tại là khoảng trắng, đảo ngược các ký tự từ vị trí bắt đầu đến vị trí kết thúc.
        if (str[end] == ' ') {
            // Lặp lại để đảo ngược các ký tự từ vị trí bắt đầu đến vị trí kết thúc.
            for (i = start; i < (start + end) / 2; i++) {
                temp = str[i];
                str[i] = str[start + end - i - 1];
                str[start + end - i - 1] = temp;
            }
            
          // Cập nhật lại vị trí bắt đầu cho vòng lặp kế tiếp.
            start = end + 1;
        }
        // Tăng biến kết thúc lên để tiếp tục kiểm tra ký tự tiếp theo.
        end++;
    }
            // Đảo ngược các ký tự còn lại của chuỗi sau khi đã duyệt hết vòng lặp.
            for (i = start; i < (start + end) / 2; i++) {
                temp = str[i];
                str[i] = str[start + end - i - 1];
                str[start + end - i - 1] = temp;
            }
    
}


/**
 * Function: CapPoint
 * Description: Đổi các chữ cái đứng sau dấu chấm thành chữ in hoa
 * Input:
 *      *str - char
 *      len  -  int
 * Output:
 *      none
*/
void CapPoint (char *str, int len)
{
    int i,check = -1;
    // Vòng lặp kiểm tra từng ký tự của chuỗi str
    for (i = 0; i < len; i++) 
    {
    // Nếu ký tự hiện tại là dấu chấm thì lưu vị trí đó vào biến check
    if (str[i] == '.') {
        check = i;
        continue; // Chuyển sang kiểm tra ký tự tiếp theo
    }
    
    // Nếu đã gặp dấu chấm và ký tự hiện tại là chữ thường
    if (check != -1 && (str[i] >= 'a' && str[i] <= 'z')) {
        // Đổi ký tự đó sang chữ in hoa
        str[i] -= 32;
        // Đặt lại giá trị của biến check để bắt đầu kiểm tra từ dấu chấm tiếp theo
        check = -1;
    }
}

    
}

/**
 * Function: normal
 * Description:  Chuyển tất cả các ký tự trong chuỗi về dạng chữ thường.
 * Input:
 *      *str - char
 *      len  -  int
 * Output:
 *      none
*/
void normal (char *str, int len)
{
    int i;
    // Vòng lặp kiểm tra từng ký tự của chuỗi str
    for (i = 0; i < len; i++)
    {
        // Nếu ký tự là chữ in hoa
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // Chuyển ký tự đó sang chữ thường
            str[i] += 32;
        }
    }
}

/**
 * Function: CapAll
 * Description: Chuyển tất cả các ký tự trong chuỗi về dạng chữ in hoa.
 * Input:
 *      *str - char
 *      len  -  int
 * Output:
 *      none
*/
void CapAll(char *str, int len)
{
     int i;
    // Vòng lặp kiểm tra từng ký tự của chuỗi str
    for (i = 0; i < len; i++)
    {
        // Nếu ký tự là chữ thường
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Chuyển ký tự đó sang chữ in hoa
            str[i] -= 32;
        }
    }
}


int main(int argc, char const *argv[])
{

    // Khai báo và khởi tạo một chuỗi kí tự
    char arr[] = "The Grammy award-winning singer. Who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
    // Tính độ dài của chuỗi
    int len = sizeof(arr)/sizeof(char);
    // In ra chuỗi ban đầu
    printf("Chuoi ban dau \n%s\n",arr);

    // Gọi hàm ReverseString để đảo ngược chuỗi arr
    ReverseString(arr, len -1);
    // In ra chuỗi sau khi đảo ngược
    printf("Chuoi sau khi dao nguoc \n %s \n",arr);

    // Gọi hàm CapPoint để in hoa chữ sau dấu chấm trong chuỗi arr
    CapPoint(arr,len-1);
    // In ra chuỗi sau khi đảo ngược và in hoa chữ sau dấu chấm
    printf("Chuoi sau khi dao nguoc + in hoa sau dau cham\n%s\n",arr);

    // Gọi hàm normal để chuyển tất cả các chữ hoa trong chuỗi arr thành chữ thường
    normal(arr,len -1);
    // In ra chuỗi sau khi đảo ngược, in hoa chữ sau dấu chấm và chuyển tất cả các chữ hoa thành chữ thường
    printf("Chuoi sau khi dao nguoc + chu thuong\n%s\n",arr);

    // Gọi hàm CapAll để chuyển tất cả các chữ thường trong chuỗi arr thành chữ hoa
    CapAll(arr,len-1);
    // In ra chuỗi sau khi đảo ngược, in hoa chữ sau dấu chấm, chuyển tất cả các chữ hoa thành chữ thường và chuyển tất cả các chữ thường thành chữ hoa
    printf("Chuoi sau khi dao nguoc + toan bo in hoa\n%s\n",arr);

    return 0;
}