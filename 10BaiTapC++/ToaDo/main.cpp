/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình tính toán trong hệ  tọa độ 2d
 */
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;






/*----------------------------------------------Begin Class Poin------------------------------------------------- */
/* 
 * Function: Class Poin
 * Description: Chứa thông tin của 1 điểm trong hệ tọa độ 2 d, gồm trục tung và hoành
*/
class Poin
{
    private:
    double x;
    double y;
    public:
    Poin(double x = 0,double y= 0);
    double getX();
    double getY();
};
/*
 * Function: Constructer của Poin 
 * Description: khởi tao 1 diểm tọa độ (0,0)
 * Input: 
 *       x -  double
 *       y -  double
 * output:
 *       none
 */
Poin::Poin(double x ,double y )
    {
        this->x = x;
        this->y = y;
    }
/*
 * Function: getX
 * Description: lấy hoành độ của 1 điểm
 * Input: 
 * output:
 *       x
 */
double  Poin::getX()
    {
        return this->x;
    }
/*
 * Function: getY
 * Description: lấy tung độ của 1 điểm
 * Input: 
 * output:
 *       y
 */
double  Poin::getY()
    {
        return this->y;
    }
/*----------------------------------------------End Class Poin------------------------------------------------- */


/*----------------------------------------------Begin Class SpaceMath------------------------------------------------- */
/* 
 * Function: Class SpaceMath
 * Description: Chứa các phương thức tính toán khoảng cách giữa 2 điểm, diện tích hình tam giác được tạo bởi 3 điểm
*/
class SpaceMath
{
    private:
    Poin one;
    Poin two;
    Poin three;
    enum math
    {
        distance ,area

    }math;
    public:
    SpaceMath(Poin one, Poin two);
    SpaceMath(Poin one, Poin two, Poin three);

    double distanceBetweenTwoPoints();
    double areaOfTriangle();
};
/*
 * Function: Constructer SpacMath
 * Description: khởi tạo giá trị của các điểm để tính khoảng cách giữa 2 điểm
 * Input: 
 *      one - poin
 *      two - poin
 * output:
 *       none
 */
SpaceMath::SpaceMath(Poin one, Poin two)
    {
        math = distance;
        this->one = one;
        this->two = two;
    }
/*
 * Function: Constructer SpaceMath
 * Description: khởi tạo giá trị của các điểm để tính diện tích tam giác được tạo bởi 3 điểm
 * Input: 
 *      one - poin
 *      two - poin
 *      three - poin
 * output:
 *       none
 */
SpaceMath::SpaceMath(Poin one, Poin two, Poin three)
    {
        math = area;
        this->one = one;
        this->two = two;
        this ->three = three;
    }
/*
 * Function: distanceBetweenTwoPoints
 * Description: Tính khoảng cách giữa 2 điểm
 * Input: 
 *      none
 * output:
 *       return d
 */
double SpaceMath::distanceBetweenTwoPoints()
    {
        double d1,d2,d;
        if (math == distance)
        {
           d1 =  pow((two.getX() - one.getX()),2);
           d2 =  pow((two.getY() - one.getY()),2);
           d =  sqrt((d1+d2));
           return d;
        }
    }
/*
 * Function: areaOfTriangle
 * Description: Tính diện tích hình tam giác dựa trên 3 điểm
 * Input: 
 *      none
 * output:
 *       return s
 */
double SpaceMath::areaOfTriangle()
    {
        if (math = area)
        {
                double s,s1,s2,s3;
                s1 = (one.getX()*(two.getY() - three.getY()));
                s2 = (two.getX()*(three.getY() - one.getY()));
                s3 = (three.getX()*(one.getY()-two.getY()));
                s = 0.5*abs(s1+s2+s3);
                return s;
        }
        
    }
int main(int argc, char const *argv[])
{
    Poin a(0,1);
    Poin b(1,0);
    Poin c(1,2);
    SpaceMath x(a,b);

    printf("Khoang cach giua diem (%lf,%lf) va (%lf,%lf) la %lf\n",a,b,x.distanceBetweenTwoPoints());
    SpaceMath x1(a,b,c);
    printf("Dien tich cua tam giac duoc tao boi 3 diem la: %lf\n",x1.areaOfTriangle());
    return 0;
}
