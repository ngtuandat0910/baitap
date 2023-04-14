

/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình quan li ngay thang nam
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;


/**
 * Function: Class Date
 * Discription: chứa thông tin ngày tháng năm
*/
class Date {
private:
    int day;
    int month;
    int year;
public:
    // Constructor
    Date(int day, int month, int year);
    // Getter methods
    int getDay();
    int getMonth();
    int getYear();
    // Other methods
    int getAge();
    bool isHoliday();
};
/**
 * Function: constructer date
 * Discription: khởi tạo ngày tháng năm cho đối tượng
 * Input:
 *      day - int
 *      month - int
 *      year - int
 * Output:
 *      none
*/
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}
/**
 * Function: getDay
 * Discription: lấy thông tin ngày của đối tượng
 * Input:
 *      none
 * Output:
 *      return day
*/
int Date::getDay() {
    return this->day;
}
/**
 * Function: getMonth
 * Discription: lấy thông tin tháng của đối tượng
 * Input:
 *      none
 * Output:
 *      return month
*/
int Date::getMonth() {
    return this->month;
}
/**
 * Function: getYear
 * Discription: lấy thông tin năm của đối tượng
 * Input:
 *      none
 * Output:
 *      return year
*/
int Date::getYear() {
    return this->year;
}
/**
 * Function: getAge
 * Discription: có chức năng tính tuổi của đối tượng hiện tại
 * Input:
 *      none
 * Output:
 *      return year
*/
int Date::getAge() {
    // lấy ngày giờ hiện tại bằng thư viện ctime
    time_t now = time(0);
    tm *local_time = localtime(&now);
    
    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;
    // Tính tuổi của đối tượng Date
    int age = current_year - this->year;
    // Kiểm tra nếu chưa đến sinh nhật trong năm thì giảm tuổi đi 1
    if (current_month < this->month || (current_month == this->month && current_day < this->day)) {
        age--;
    }

    return age;
}
/**
 * Function: isHoliday
 * Discription: kiểm tra ngày lễ của đối tượng
 * Input:
 *      none
 * Output:
 *      return true-false
*/
bool Date::isHoliday() 
{
    // lấy ngày giờ hiện tại bằng thư viện ctime
    time_t now = time(0);
    tm *local_time = localtime(&now);

    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;

    // kiểm tra và trả về true nếu ngày đó là lễ
    if (this->month == 1 && this->day == 1) { // Tết Dương lịch
        return true;
    } else if (this->month == 4 && this->day == 30) { // Giỗ Tổ Hùng Vương
        return true;
    } else if (this->month == 5 && this->day == 1) { // Quốc tế Lao động
        return true;
    } else if (this->month == 9 && this->day == 2) { // Quốc khánh 2/9
        return true;
    } else if (this->month == 3 && this->day == 8) { // Quốc tế Phụ nữ
        return true;
    } else if (this->month == 12 && this->day == 25) { // Giáng sinh
        return true;
    } else {
        return false;
    }
}



int main(int argc, char const *argv[])
{
    Date person1(9,10,2001);
    Date holiday(30,4,2023);
    printf("Ngay %d, Thang %d, Nam %d =>Tuoi cua nguoi nay la: %d tuoi\n",person1.getDay(),person1.getMonth(),person1.getYear(),person1.getAge());
    //Kiểm tra ngày lễ
    if (holiday.isHoliday())
    {
        printf("Ngay %d, Thang %d, Nam %d\n",holiday.getDay(),holiday.getMonth(),holiday.getYear());
        printf("La ngay le\n");
    }else{
        printf("Ngay %d, Thang %d, Nam %d\n",holiday.getDay(),holiday.getMonth(),holiday.getYear());
        printf("khong phai ngay le\n");
    }
    

    return 0;
}
