/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình tính quan li đông vật
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;



/**
 * Function: Class Animal
 * Description: Chứa các thông tin và các phương thúc khởi tạo con vật
*/
class Animal
{
    private:
    char name [20];
    uint8_t age;
    double weight;
    double height;
    uint8_t id;
    public:
    Animal(char name[], uint8_t age, double height, double weight);
    char *getName();
    uint8_t getAge();
    double getheight();
    double getWeight();
    double getBMI();
    uint8_t getId();
};
/**
 * Function: constructer Animal
 * Description: khởi tạo thông tin con vật
 * Input: 
 *      name - char
 *      age - uint8_t
 *      height - double
 *      weight - double
 * Output:
 *      none
*/
Animal::Animal( char name[], uint8_t age, double height,double weight)
{
    static uint8_t id = 100;
    this->id = id;
    strcpy(this->name,name);
    this->age= age;
    this->height = height;
    this->weight = weight;
    id++;
}
/**
 * Function: getName
 * Description: lấy tên của con vật
 * Input: 
 *      none
 * Output:
 *      return name
*/
char *Animal::getName(){
    return this->name;
    }
/**
 * Function: getAge
 * Description: lấy tuổi của con vật
 * Input: 
 *      none
 * Output:
 *      return age
*/
uint8_t Animal::getAge(){
    return this->age;
    }
/**
 * Function: getheight
 * Description: lấy chiều cao của con vật
 * Input: 
 *      none
 * Output:
 *      return height
*/
double Animal::getheight(){
       return this->height;
    }
/**
 * Function: getWeight
 * Description: lấy cân nặng của con vật
 * Input: 
 *      none
 * Output:
 *      return weight
*/
double Animal::getWeight(){
       return this->weight;
    }
/**
 * Function: getBMI
 * Description: lấy bmi của con vật
 * Input: 
 *      none
 * Output:
 *      return bmi
*/
double Animal::getBMI()
{
    return this ->weight /( this ->height * this ->height) ;
}
/**
 * Function: getId
 * Description: lấy id của con vật
 * Input: 
 *      none
 * Output:
 *      return id
*/
uint8_t Animal::getId()
{
    return this->id;
}





/**
 * Function: Class Menu
 * Description: Chứa các phương thức so sánh cân nặng tuổi tác của con vật
*/
class Menu
{
    private:
    vector<Animal> animalListT;
    public:

    void addAnimal(char name[], uint8_t age, double height,double weight);
    void display();
    void cmpWeightAnimal();
    void cmpAgeAnimal();

};

/**
 * Function: addAnimal
 * Description: thêm con vật
 * Input:
 *      name - char
 *      age - uint8_t
 *      height - double
 *      weight - double
 * Output:
 *      none
*/
void Menu::addAnimal(char name[], uint8_t age, double height,double weight)
    {
        Animal Animal(name,age,height,weight);
        animalListT.push_back(Animal);
    }
/**
 * Function: cmpWeightAnimal
 * Description: so sánh cân nặng giữa các con vật với nhau
 * Input:
 *      none
 * Output:
 *      none
*/
void Menu::cmpWeightAnimal()
    {
        vector<Animal> animalList;
        animalList.assign(animalListT.begin(),animalListT.end()); // copy vector animalLisT sang animalList
        // sáp xếp các con vật theo cân nặng từ bé đến lớn
        for (int i = 0; i < animalList.size()- 1; i++)
        {
            for (int j = i + 1 ; j < animalList.size(); j++)
            {
            
               if (animalList[i].getWeight() > animalList[j].getWeight() )  // so sánh cân nặng các con vật
               {
                   Animal temp = animalList[i];
                   animalList[i] = animalList[j];
                   animalList[j] = temp;
               }
               
            }
            
        }
        printf("Con %s nang nhat\n", animalList[animalList.size() - 1].getName()); // lấy thông tin con vật nặng nhất
        
    }
/**
 * Function: cmpAgeAnimal
 * Description: so sánh tuoi tac giữa các con vật với nhau
 * Input:
 *      none
 * Output:
 *      none
*/
void Menu::cmpAgeAnimal()
    {
        vector<Animal> animalList;
        animalList.assign(animalListT.begin(),animalListT.end());  // copy vector animalLisT sang animalList
        // sáp xếp các con vật theo tuổi tác từ bé đến lớn
        for (int i = 0; i < animalList.size()- 1; i++)
        {
            for (int j = i + 1 ; j < animalList.size(); j++)
            {
            
               if (animalList[i].getAge() > animalList[j].getAge() ) // so sánh tuổi các con vật
               {
                   Animal temp = animalList[i];
                   animalList[i] = animalList[j];
                   animalList[j] = temp;
               }
               
            }
            
        }
        printf("Con %s gia nhat\n", animalList[animalList.size() - 1].getName()); // lấy thông tin con vật già nhất
        
    }
/**
 * Function: display
 * Description: xuất thông tin các con vật ra màn hình
 * Input:
 *      none
 * Output:
 *      none
*/
void Menu::display()
    {
           printf("id\tTen\t\tTuoi\tChieuCao\tCanNang\tBMI\n");
        for (Animal &s:animalListT)
        {
           printf("%d\t%s\t%d\t%lf\t%lf\t%d\n",s.getId(),s.getName(),s.getAge(),s.getheight(),s.getWeight(),s.getBMI());
           
        }
    }
int main(int argc, char const *argv[])
{
    Menu mn;
    mn.addAnimal((char*)"bo",10,25,29);
    mn.addAnimal((char*)"heo",20,27,27);
    mn.addAnimal((char*)"ga",35,27,27);
    mn.addAnimal((char*)"vit",40,27,27);
    mn.addAnimal((char*)"cho",45,27,27);
    mn.addAnimal((char*)"trau",20,27,31);
    mn.display();

    mn.cmpWeightAnimal();
    mn.cmpAgeAnimal();

    return 0;
}
