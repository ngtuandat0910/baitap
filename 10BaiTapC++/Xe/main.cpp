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
 * Function: Class car
 * Discription: Chứa các thuộc tính của xe và các phương thức tính toán chi phí báo trì, kiểm tra số km và hiện thông tin xe
*/
class Car
{
    private:
    string color;
    string engineType;
    int km;
    public:
    Car(string color, string engineType, int km);
    float calculateMaintenanceCost();
    bool checkKmDriven(int kmToCheck);
    void displayCarInfo();
};

/**
 * Function: constructer Car
 * Discription: khởi tạo thông tin cho xe
 * Input:
 *      color - string
 *      engineType - string
 *      km  -   int
 * Output:
 *      none
*/
Car::Car(string color, string engineType, int km)
{
        this->color = color;
        this->engineType = engineType;
        this->km = km;
}
/**
 * Function: calculateMaintenanceCost
 * Discription: Tính toán chi phí bảo trì xe theo số km đã đi
 * Input:
 *      none
 * Output:
 *      return cost
*/
float Car::calculateMaintenanceCost() 
{
    // tính toán chi phí bảo trì dựa trên km đã đi
    float cost = 0.05 * this->km;
    return cost;
}
/**
 * Function: checkKmDriven
 * Discription: kiểm tra số km của xe với số km muốn kiểm tra
 * Input:
 *      none
 * Output:
 *      return true - false 
*/
bool Car::checkKmDriven(int kmToCheck) {
        // kiểm tra xem km đã đi có nhỏ hơn km đầu vào không
        if (kmToCheck > km) {
            return false;
        } else {
            return true;
        }
    }
/**
 * Function: displayCarInfo
 * Discription: In thông tin xe
 * Input:
 *      none
 * Output:
 *      none
*/
void Car::displayCarInfo() 
{
        // in thông tin của xe
        printf(".............Thong Tin Xe...............\n1. Mau Sac: %s\n2.Loai dong co: %s\n3.So Km da di: %d\n4.Chi phi bao tri: %0.3lf\n",
        this->color.c_str(),this->engineType.c_str(),this->km,this->calculateMaintenanceCost()  );

}



int main(int argc, char const *argv[])
{
    Car car1("blue", "diesel", 50000);
    // xuất thông tin xe
    car1.displayCarInfo();

    // kiểm tra số km đã đi
    int kmToCheck = 40000;
    if (car1.checkKmDriven(kmToCheck))
    {
        printf("so km xe da di > %d ", kmToCheck);
    }else
    {
        printf("so km xe da di < %d ", kmToCheck);
    }
    return 0;
}
