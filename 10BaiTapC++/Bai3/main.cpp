/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình tính toán hình tròn
 */

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


#define Pi M_PI
/**
 * Function: Class Circle
 * Discription: Chứa thông tin bán kính và các phương thức tính toán hình tròn
*/
class Circle
{
    private:
    double radius;
    public:
    // Circle(double radius);
    void setRadius(double radius);
    double perimeterOfCircle();
    double areaOfCircle();
};
/**
 * Function: setRadius
 * Discription: Khởi tạo bán kính hình chữ nhật
 * Input:
 *      radius - double
 * Output:
 *      none
*/
void Circle::setRadius(double radius)
{
    this->radius = radius;
}
/**
 * Function: perimeterOfCircle
 * Discription: tính chu vi hình chữ nhật
 * Input:
 *      
 * Output:
 *      return perimeterOfCircle
*/
double Circle::perimeterOfCircle()
{
        return 2*Pi*this->radius;
}
/**
 * Function: areaOfCircle
 * Discription: Tính diện tích hình chữ nhật
 * Input:
 *      
 * Output:
 *      return areaOfCircle
*/
double Circle::areaOfCircle()
{
        return Pi*pow(this->radius,2);
}

int main(int argc, char const *argv[])
{
    Circle circle; double radius;
    printf("Nhap ban kinh\n");
    scanf("%lf",&radius);
    circle.setRadius(radius);
    printf("Chu vi hinh tron la: %lf\n", circle.perimeterOfCircle());
    printf("Dien tich hinh tron la: %lf\n", circle.areaOfCircle());
    return 0;
}
