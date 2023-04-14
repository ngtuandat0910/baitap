/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình tinh toan phan so
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
/**
 * Function: Class Fraction
 * Description: Chứa các thông tin tử số và mẫu số của phân số
*/
class Fraction {
private:
    int numerator;   // Tử số
    int denominator; // Mẫu số
public:
    Fraction(int numerator = 0, int denominator = 1);
    int getNumerator();
    int getDenominator();

};
/**
 * Function: constructer Fraction
 * Description: khởi tạo phân số
 * Input:
 *      numerator - int
 *      denominator - int
 * Output:
 *      none
*/
  Fraction:: Fraction(int numerator, int denominator ) 
    {
        static int id = 1;
        this->id = id;
        this->numerator = numerator;
        this->denominator = denominator;
        id++;
    }
/**
 * Function: getNumerator
 * Description: lấy tử số của phân số
 * Input:
 *      none
 * Output:
 *      return numerator
*/
    int Fraction::getNumerator()  
    {
        return  this->numerator;
    }
/**
 * Function: getDenominator
 * Description: lấy mẫu số của phân số
 * Input:
 *      none
 * Output:
 *      return Denominator
*/
    int Fraction::getDenominator()  
    {
        return  this->denominator;
    }



/**
 * Function: class Calculate
 * Discriptiom: tính toán 2 phân số
*/
class Calculate
{
    private:
    Fraction one;
    Fraction two;
    public:
    Calculate(Fraction one,Fraction two);
    float addition();
    float subtraction();
    float multiplication();
    float division();
    // void display();
};
/**
 * Function: constructer Calculate
 * Description: khởi tạo thông tin để tính toán
 * Input:
 *      one - Fraction
 *      two - Fraction
 * Output:
 *      none
*/
Calculate::Calculate(Fraction one,Fraction two)
{
    this->one = one;
    this ->two = two;
}
/**
 * Function: addition
 * Description: phep cộng 2 phân số
 * Input:
 *      none
 * Output:
 *      return addition of Fraction
*/
float Calculate::addition()
{
    float a = one.getNumerator();
    float b = one.getDenominator();
    float c = two.getNumerator();
    float d = two.getDenominator();
    float f = ((a*d) + (b*c))/(b*d);
    return f;
}
/**
 * Function: subtraction
 * Description: phep trừ 2 phân số
 * Input:
 *      none
 * Output:
 *      return subtraction of Fraction
*/
float Calculate::subtraction()
{
    float a = one.getNumerator();
    float b = one.getDenominator();
    float c = two.getNumerator();
    float d = two.getDenominator();
    float f = ((a*d) - (b*c))/(b*d);
    return f;
}
/**
 * Function: multiplication
 * Description: phep nhân 2 phân số
 * Input:
 *      none
 * Output:
 *      return multiplication of Fraction
*/
float Calculate::multiplication()
{
    float a = one.getNumerator();
    float b = one.getDenominator();
    float c = two.getNumerator();
    float d = two.getDenominator();
    float f = (a*c)/(b*d);
    return f;
}
/**
 * Function: division
 * Description: phep chia 2 phân số
 * Input:
 *      none
 * Output:
 *      return division of Fraction
*/
float Calculate::division()
{
    float a = one.getNumerator();
    float b = one.getDenominator();
    float c = two.getNumerator();
    float d = two.getDenominator();
    float f = (a*d)/(b*c);
    return f;
}


int main(int argc, char const *argv[])
{
    Fraction one(1,2);
    Fraction two(3,4);
    Calculate cal(one,two);
    // cal.display();
    printf("COng 2 phan so %f\n",cal.addition());
    printf("Tru 2 phan so %f\n",cal.subtraction());
    printf("Nhan 2 phan so %f\n",cal.multiplication());
    printf("Chia 2 phan so %f\n",cal.division());
    return 0;
}
