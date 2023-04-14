/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình thông tin con người
 */
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;



/**
 * Function: Class Humans
 * Description: Chứa các thuộc tính của con người
*/
class Humans
{
    private:
    string name;
    uint8_t age;
    string addr;
    uint8_t id;
    public:
    Humans(string name, uint8_t age, string addr);
    string getName();
    uint8_t getAge();
    string getAddr();
    uint8_t getId();

};
/**
 * Function: constructer humans
 * Description: khởi tạo thông tin cho con người
 * Input:
 *      name -  name
 *      age - uint8_t
 *      addr - string
 * Ouput:
 *      none
*/
Humans::Humans(string name, uint8_t age, string addr)
{
    static uint8_t id = 100;
    this->id = id;
    this->name = name;
    this->age = age;
    this->addr = addr;
    id ++;
}
/**
 * Function: getName
 * Description: lấy tên của người
 * Input: None
 * Output: 
 *      return name
*/
string Humans::getName()
    {
        return this->name;
    }
/**
 * Function: getAge
 * Description: lấy tuổi của người
 * Input: None
 * Output: 
 *      return age
*/
uint8_t Humans::getAge()
        {
        return this->age;
    }
/**
 * Function: getAddr
 * Description: lấy địa chỉ của người
 * Input: None
 * Output: 
 *      return addr
*/
string Humans::getAddr()
        {
        return this->addr;
    }
/**
 * Function: getId
 * Description: lấy id của người trong danh sách
 * Input: None
 * Output: 
 *      return id
*/
uint8_t Humans::getId()
        {
        return this->id;
    }

/**
 * Function: class Option
 * Description: chứa phương thức hiển thị danh sách người
*/
class Option
{
    private:
    vector<Humans> humans;
    public:
    void addHumans(string name, uint8_t age, string addr);
    void displayHumans();
};
/**
 * Function: addHumans
 * Description: thêm thông tin người vào danh sách
 * Input:
 *      name - string
 *      age - uint8_t
 *      addr - string
 * Output:
 *      none
*/
void Option::addHumans(string name, uint8_t age, string addr)
{
    Humans x(name,age,addr);
    humans.push_back(x);
}
/**
 * Function: displayHumans
 * Description: hiển thị thông tin người trong danh sách
 * Input:
 *      none
 * Output:
 *      none
*/
void Option::displayHumans()
{
    printf("Id\tName\tAge\tAdrr\n");
    for (Humans dhumans :humans)
    {
        printf("%d\t%s\t%d\t%s\n",dhumans.getId(),(dhumans.getName()).c_str(),dhumans.getAge(),(dhumans.getAddr()).c_str());
    }
}

int main(int argc, char const *argv[])
{
    Option hm;
    hm.addHumans("dat",22,"tayNinh");
    hm.addHumans("dat1",22,"taythanh");
    hm.displayHumans();

    return 0;
}
