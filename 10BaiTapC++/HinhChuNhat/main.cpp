/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình tính toán hình chữ nhật
 */
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


/**
 * Function: Class Rectangle
 * Decsription: Chứa các thông tin dài và rộng của hình chư nhật
*/
class Rectangle
{
    private:
    double length;
    double width;

    public:
    Rectangle(double length = 0,double width = 0);
    double getLength();
    double getWidth();
};
/**
 * Function: Constructer Rectangle
 * Description: Khởi tạo chiều dài và rộng của hình chữ nhật
 * Input:
 *      length -  double
 *      width - double
 * Output:
 *      none
*/
Rectangle::Rectangle(double length,double width)
{
    this->length = length;
    this->width = width;
}
/**
 * Function: getLength
 * Description: lấy thông tin chiều dài của hình chữ nhật
 * Input:
 *      none
 * Output:
 *      return length
*/
double Rectangle::getLength()
{
    return this->length;
}
/**
 * Function: getWidth
 * Description: lấy thông tin chiều rộng của hình chữ nhật
 * Input:
 *      none
 * Output:
 *      return width
*/
double Rectangle::getWidth()
{
    return this->width;
}


/**
 * Function: Class SpaceMath
 * Decsription: Chứa các phương thức tính toán hình chữ nhật
*/
class SpaceMath
{
    private:
    Rectangle rectangle;
    public:
    SpaceMath(Rectangle rectangle);
    double perimeterOfRectangle();
    double areaOfRectangle();
    double diagonalOfRectangle();
    void checkQuare();
};
/**
 * Function: Constructer SpaceMath
 * Discription: Khởi tạo thông tin hình chữ nhật để tính toán
 * Input:
 *      rectangle - Rectangle
 * Output:
 *      none
*/
SpaceMath::SpaceMath(Rectangle rectangle)
{
    this->rectangle = rectangle;
}
/**
 * Function: perimeterOfRectangle
 * Discription: Tính toán chu vi hình chữ nhật
 * Input:
 *      none
 * Output:
 *      return perimeterOfRectangle
*/
double SpaceMath::perimeterOfRectangle()
{
    return (rectangle.getLength() + rectangle.getWidth()) * 2;
}
/**
 * Function: areaOfRectangle
 * Discription: Tính toán diện tích hình chữ nhật
 * Input:
 *      none
 * Output:
 *      return areaOfRectangle
*/
double SpaceMath::areaOfRectangle()
{
    return (rectangle.getLength() * rectangle.getWidth());
}
/**
 * Function: diagonalOfRectangle
 * Discription: Tính toán đường chéo hình chữ nhật
 * Input:
 *      none
 * Output:
 *      return diagonalOfRectangle
*/
double SpaceMath::diagonalOfRectangle()
{
    return sqrt(pow(rectangle.getLength(),2)+pow(rectangle.getWidth(),2));
}
/**
 * Function: checkQuare
 * Discription: kiểm tra hình vuông
 * Input:
 *      none
 * Output:
 *      none 
*/
void SpaceMath::checkQuare()
{
    if (rectangle.getLength() == rectangle.getWidth())
    {
        printf("Day la hinh vuong\n");
        return;
    }printf("Day khong phai la hinh vuong\n");
}
int main(int argc, char const *argv[])
{
    Rectangle rectangle(2,1);
    SpaceMath calculate(rectangle);
    printf("Chu vi hinh chu nhat la %lf\n",calculate.perimeterOfRectangle());
    printf("Dien tich hinh chu nhat la %lf\n",calculate.areaOfRectangle());
    printf("Duong cheo hinh chu nhat la %lf\n",calculate.diagonalOfRectangle());
    printf("kiem tra hinh vuong\nKet qua:");calculate.checkQuare();

    return 0;
}
