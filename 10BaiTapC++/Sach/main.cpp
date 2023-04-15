/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình quản lí xe hơi
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;


/**
 * Function: class book
 * Discription: Chứa các thuộc tính của sách và phương thức hiển thị thông tin sách, mượn/trả sách
*/
class Book {
private:
    string title;
    string author;
    int publicationYear;
    int quantity;

public:

    // constructor
    Book(string title, string author, int publicationYear, int quantity);
    //method
    void displayInforBook();
    void borrowBook();
    void returnBook();
};
/**
 * Function: constructer book
 * Discription: Khởi tạo thong tin sách
 * Input:
 *      title - title
 *      author - string
 *      publicationYear - int
 *      quantity - int
 * Output:
 *      none
*/
Book::Book(string title, string author, int publicationYear, int quantity)
{
    this->title = title;
    this->author =  author;
    this->publicationYear = publicationYear;
    this->quantity = quantity;
}
/**
 * Function: displayInforBook
 * Discription: hiển thị thong tin sách
 * Input:
 *      none
 * Output:
 *      none
*/
void Book::displayInforBook()
{
    printf("Ten sach: %s\nTac Gia: %s\nNam xuat ban: %d\nSo luong: %d\n",
    this->title.c_str(),this->author.c_str(),this->publicationYear,this->quantity);
}
/**
 * Function: borrowBook
 * Discription: mượn 1 quyển sách
 * Input:
 *      none
 * Output:
 *      none
*/
void Book::borrowBook()
{
    // kiểm tra số lượng sách
     if (quantity > 0) {
        // giảm số lượng sách xuống 1 đơn vị
            quantity--;
            printf("Chuc mung, ban da muon thanh cong mot cuon sach nay!!\n");
     }else
     {
        printf("Rat tiec, khong con cuon sach nay!!\n");
     }
}
/**
 * Function: returnBook
 * Discription: trả 1 quyển sách
 * Input:
 *      none
 * Output:
 *      none
*/
void Book::returnBook()
{
            // Tăng số lượng sách lên 1 đơn vị
            quantity++;
            printf("Ban da tra thanh cong cuon sach nay!!\n");
}

int main(int argc, char const *argv[])
{
    Book book1("Lap trinh c","ABCD",2023,5);
    // hiển thị thong tin sách
    book1.displayInforBook();
    // mượn sách
    book1.borrowBook();
    // hiển thị thong tin sách
    book1.displayInforBook();
     // trả sách
    book1.returnBook();
    // hiển thị thong tin sách
    book1.displayInforBook();
    return 0;
}
