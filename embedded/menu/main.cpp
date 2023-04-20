/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 02/04/2023
 * Description: Chương trình gọi món
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define enterInformatiom(thongtin,dinhdang,bien,dieukien)\
do{\
    printf(thongtin);scanf(dinhdang,bien);} \
    while (dieukien);                              

/*----------------------------------------------Begin Class Dish------------------------------------------------- */
/* 
 * Function: Class món ăn
 * Description: Chứa thông tin của món ăn và các hàm nhập thông tin của món ăn
*/
class Dish {
    private:
    uint8_t id;
    char name[20];
    double price;

    public:
    Dish( uint8_t id,  char name[],  double price);
    void setName(char name[]);
    void setPrice(double price);

    uint8_t getId();
    char *getName();
    double getPrice(); 
};

/*
 * Function: Constructer of Dish 
 * Description: khởi tao dữ liệu cho món ăn
 * Input: 
 *       id - unsigned integer
 *       NAME - char
 *       PRICE - double
 * output:
 *       none
 */
Dish::Dish( uint8_t id,  char name[],  double price)
{
    this->id = id;
    strcpy(this->name,name);
   this->price = price;
}
/*
 * Function: setName
 * Description: Nhập tên của món ăn
 * Input: 
 *      NAME - char
 * output:
 *      none
 */
void Dish::setName(char name[])
{
    strcpy(this->name,name);
}
/*
 * Function: setPrice
 * Description: Nhập giá của món ăn
 * Input:
 *      PRICE - double
 * Output:
 *      none
 */
void Dish::setPrice(double price)
{
    this->price=price;
}
/*
 * Function: getName
 * Description: lấy tên món ăn
 * Input: 
 *      none
 * Output:
 *      name of Dish
 */
char *Dish::getName()
{
    return this->name;
}
/*
 * Function: getPrice
 * Description: lấy giá của món ăn
 * Input: 
 *      none
 * output:
 *      price of dish
 */
double Dish::getPrice()
{
    return this->price;
}
/*
 * Function: getId
 * Description: lấy id của món ăn
 * Input: 
 *      none
 * output:
 *      id of dish
 */
uint8_t Dish::getId()
{
    return this->id;
}
/*----------------------------------------------END Class Dish------------------------------------------------- */

/*----------------------------------------------Begin sutrct numberOfDishes-------------------------------------*/
/* 
 * Function: sutrct numberOfDishes
 * Description: Chứa thông tin của món ăn đã oder
*/
typedef struct 
{
    uint8_t id;
    char name [20];
    double  price;
    uint8_t amount;
}oderedDishList;
/*----------------------------------------------End sutrct numberOfDishes-------------------------------------*/


/*----------------------------------------------Begin Class Table-------------------------------------*/
/* 
 * Function: Class Table
 * Description: Chứa thông tin của món ăn và các hàm nhập thông tin của món ăn
*/
class Table
{
    private:
    uint8_t numberOfTable;
    bool status;
    vector<oderedDishList> oderedDishListOnTable;


    public:
    Table (uint8_t numberOfTable);

    void setStatus(bool status);
    void addDishOnTable(oderedDishList oderedDishList);
    bool getStatus();

    vector<oderedDishList> &getOderedDishListOnTable(){return oderedDishListOnTable;}
 
};
/**
 * Function: constructer table
 * Description: khởi tạo thông tin và trạng thái của bàn
 * Input: 
 *      numberOfTable -  uint8_t
 * Output:
 *      none
*/
Table::Table(uint8_t numberOfTable)
{
    this->numberOfTable = numberOfTable;
    this->status = false;
}
/**
 * Function: addDishOnTable
 * Description: thêm món ăn dã oder vào struct oderedDishList
 * Input: 
 *      oderedDishList - struct oderedDishList
 * Output:
 *      none
*/
void Table::addDishOnTable(oderedDishList oderedDishList)
{
   this->oderedDishListOnTable.push_back(oderedDishList);
}
/**
 * Function: setStatus
 * Description: thiết lập trạng thái của bàn ăn
 * Input: 
 *      oderedDishList - struct oderedDishList
 * Output:
 *      none
*/
void Table::setStatus(bool status)
{
    this->status =  status;
}
/**
 * Function: getStatus
 * Description: láy thông tin trạng thái của bàn ăn
 * Input: 
 *      None
 * Output:
 *      status of table
*/
bool Table::getStatus( )
{
    return this->status;
}
/*----------------------------------------------End Class Table-------------------------------------*/



/*----------------------------------------------Begin Class Table-------------------------------------*/
/* 
 * Function: Class Manage
 * Description: Chứa thông tin của món ăn và bàn, các phương thức để khởi tạo hoặc chỉnh sửa món ăn và bàn
*/
class Manage
{
    private:
    vector<Table> tableList;
    vector<Dish>  dishList;
    uint8_t id;

    public:

    Manage();
    void setNumberOfTable();
    void setDishes();
    void deleteDishes();
    void repairDishes();
    void displayListDish();
 
    vector<Table>&getTableList();
    vector<Dish>&getDishList();
};
/**
 * Function: constructer Manage
 * Description: Gán ID cho món ăn
 * Input: 
 *      None
 * Output:
 *      None
*/
Manage::Manage()
{
    static uint8_t id=100;
    this->id = id;
}
/**
 * Function: getTableList
 * Description: lấy thông tin của bàn
 * Input: 
 *      None
 * Output:
 *      tableList 
*/
vector <Table>&Manage::getTableList()
{
    return this->tableList;
}
/**
 * Function: getDishList
 * Description: lấy thông tin của món ăn
 * Input: 
 *      None
 * Output:
 *      dishList 
*/
vector <Dish>& Manage::getDishList()
{
    return this->dishList;
}
/**
 * Function: setNumberOfTable
 * Description: khởi tạo số bàn ăn
 * Input: 
 *      numberOfTable -  int
 * Output:
 *      none 
*/
void Manage::setNumberOfTable( )
{

    int numberOfTable;
    enterInformatiom("Nhap vao so ban\nNhap vao:__","%d",&numberOfTable,numberOfTable<=0);
    for (int i = 0; i < numberOfTable; i++)     // vòng lặp tạo danh sách bàn
    {
        this->tableList.push_back(Table(i));  //  danh sách bàn được lưu vào vector tableList
    }
}
/**
 * Function: setDishes
 * Description: khởi tạo món ăn
 * Input: 
 *      name - char
 *      price - double
 * Output:
 *      none 
*/
void Manage::setDishes()
{
    char name[20];double price; uint8_t key;
    do
    {
    enterInformatiom("Nhap ten mon an\nNhap vao:__","%s",&name,0);  // nhâp tên cho món ắn
    enterInformatiom("Nhap gia mon an\nNhap vao:__","%lf",&price,price <= 0); // nhập giá cho món ăn
    this->dishList.push_back(Dish(id,name,price));id++; // lưu món ăn vào vector dishList
    enterInformatiom("1. Tiep tuc them mon\n0. Quay Lai\nNhap vao:__","%d",&key,0);
    } while (key != 0);
}
/**
 * Function: deleteDishes
 * Description: xóa món ăn theo ID
 * Input: 
 *      id - uint8_t
 * Output:
 *      none 
*/
void Manage::deleteDishes()
{
    uint8_t id;
    enterInformatiom("Nhap id can xoa\nNhap vao:__","%d",&id,id <100)
    for (int i = 0; i < dishList.size(); i++)   // duyệt danh sách món ăn
    {
        if (dishList[i].getId() == id) // tìm kím món ăn theo id
        {
            dishList.erase(dishList.begin()+i); // nếu tìm thấy, tiến hành xóa món ăn tại vị trí i 
            printf("............................Complete!!.............................\n");
            return;
        }
    }printf("ID not found!!\n"); 
}
/**
 * Function: repairDishes
 * Description: sửa món ăn
 * Input: 
 *      id - uint8_t
 * Output:
 *      none 
*/

void Manage::repairDishes()
{
    uint8_t id;
    enum repairDishes
{
    exit,reprice,rename
};
    char name[20];
    double price;
    int key;
    enterInformatiom("Nhap id can sua\nNhap vao:__","%d",&id,id <= 100);
    for (Dish &dish: getDishList())  // duyệt danh sách món ăn
    {
        if (dish.getId()== id)
        {
            do
            {
                enterInformatiom("2. Ten mon an\n1. Gia mon an\n0. Thoat\nNhap vao:__","%d",&key,0);
                switch (key)
                {
            case exit:
                printf("............................Da Thoat!!.............................\n");
                break;
            case reprice:
                enterInformatiom("Ban dang sua gia mon an\nNhap vao:__","%lf",&price,0);dish.setPrice(price); // sửa giá món ăn
                printf("............................Complete!!.............................\n");
                break;
            case rename:
                enterInformatiom("Ban dang sua ten mon an\nNhap vao:__","%s",&name,0);dish.setName(name); // sửa tên món ăn
                printf("............................Complete!!.............................\n");
                break;
            default:printf("Error!!!");
                break;
            }
            } while (key != 0);
            return;
        }
    }printf("ID not found!!\n");
}
/**
 * Function: displayListDish
 * Description: Hiển thị thông tin món ăn đã thêm
 * Input: 
 *      none
 * Output:
 *      stt, id, name, price 
*/
void Manage::displayListDish()
{
    printf("STT\tID\tTenMon\tGiaMon\n");
    int stt = 1;
    for ( Dish dish: dishList) // duyệt danh sách món ăn
    {
        printf("%d\t%d\t%s\t%lf\n",stt,dish.getId(),dish.getName(),dish.getPrice());  // in ra thông tin món ăn đã được thêm vào danh sách
        stt++;
    }
    
}


/*----------------------------------------------Begin Class Staff-------------------------------------*/
/**
 * Function: class Staff
 * Description: Chứa thông tin của bàn đã oder
*/
class Staff
{
    private:
    Manage manage;
    public:
    Staff(Manage &manage);
    void statusTableLish();
    void odered(uint8_t table);
    
    void inforTable(uint8_t table);
    void cash(uint8_t table);

};
/**
 * Function: constructer Staff
 * Description: Cập nhật thông tin món ăn và danh sách bàn từ quản lí
 * Input: 
 *      manage -  Manage
 * Output:
 *      none
*/
Staff::Staff(Manage &manage)
{
    this->manage = manage;
}
/**
 * Function: statusTableLish
 * Description: Hiển thị trạng thái các bàn
 * Input: 
 *      none
 * Output:
 *      stt, id, name, price 
*/
void Staff::statusTableLish()
{

    int i = 1;
    printf("Danh sach ban:");
    for (Table &statusTable: manage.getTableList()) // duyệt danh sách bàn ăn đã được tạo
        {
    printf(" %d |", i);  
    i++;
        }
    printf("\n");
    printf("Trang thai:   ");
    for (Table &statusTable: manage.getTableList())// duyệt danh sách bàn ăn đã được tạo
        {
            if (statusTable.getStatus()==true)   // check trạng thái của bàn 
            {
                printf(" X |");    // set trạng thái bàn đã được oder
            }else{
                printf("   |");  
            }
        }
    printf("\n");
            

}
/*
 * Function: odered
 * Description: hàm gọi món 
 * Input:
 *      table - uint8_t 
 *      id - uint8_t
 *      amount -uint8_t
 * Output:
 *      stt, id, name, price 
*/
void Staff::odered(uint8_t table)
{

    uint8_t id; uint8_t amount; uint8_t key; bool found = false;
    Table &tableList = manage.getTableList()[table - 1];    // lấy thông tin của bàn đã nhập vào
do
{
    enterInformatiom("ID mon\nNhap vao:__","%d",&id,0);
    for (Dish &dishOnTable: manage.getDishList())   // duyệt qua danh sách món ăn đã tạo
    {
        if (dishOnTable.getId() == id)     // tìm kím món ăn theo id
            {       
                    printf("Mon %s\n",dishOnTable.getName());   // in tên món ăn theo id
                    oderedDishList mn;    // tạo một biến mang thông tin các món đã oder          
                    mn.id = id;
                    strcpy(mn.name,dishOnTable.getName());
                    mn.price = dishOnTable.getPrice();
                    enterInformatiom("So lUong \nNhap vao:__","%d",&amount,0);
                    mn.amount = amount;
                    tableList.addDishOnTable(mn); // thêm thông tin các món đã oder vào bàn 
                    tableList.setStatus(true);  
                    found = true;
                    enterInformatiom("1. tiep tuc them mon\n0. ket thuc\nNhap vao:__","%d",&key,0);
                    if (key == 1){
                        continue;
                        }else{
                            return;}    
            }
    }
    if(!found)
    {
        enterInformatiom("khong tim thay id mon an\nCo muon nhap lai khon\n1. tiep tuc them mon\n0. ket thuc\nNhap vao:__","%d",&key,0); 
    }found = false;
} while (key != 0);
}
/*
 * Function: inforTable
 * Description: hàm xem thông tin bàn 
 * Input:
 *      table - uint8_t 
 * Output:
 *      stt, id, name, price 
*/
void Staff::inforTable(uint8_t table)
{
    uint8_t stt = 1;

    for (oderedDishList &dishLish : manage.getTableList()[table - 1 ].getOderedDishListOnTable()) // duyệt và in thông tin món ăn đã oder của bàn
    {
        printf("%d\t%d\t%s\t%lf\t%d\n",stt,dishLish.id,dishLish.name,dishLish.price,dishLish.amount);
        stt++;
    }   
}
/*
 * Function: cash
 * Description: hàm xem thông tin bàn và thanh toán
 * Input:
 *      table - uint8_t 
 * Output:
 *      stt, id, name, price, total
*/
void Staff::cash(uint8_t table)
{
    Table &tablee = manage.getTableList()[table - 1];
    tablee.getStatus();
    uint8_t stt;
    double total=0;
    for (oderedDishList &dishLish : manage.getTableList()[table - 1 ].getOderedDishListOnTable())   // duyệt và tính tiền các món đã oder
    {
    printf("%d\t%d\t%s\t%lf\t%d\n",stt,dishLish.id,dishLish.name,dishLish.price,dishLish.amount);
        total = total + (dishLish.amount * dishLish.price);
        stt++;
    } 
    printf("so tien phai thanh toan: %lf\n",total);
    tablee.setStatus(false);

}
/*---------------------------------------------------class Menu-------------------------------------------------------------*/
/*
 * Function: Class Menu
 * Description: chứa các thuộc tính và phương thức quản lý + nhân viên
 * Input:
 *      none
 * Output:
 *      none
*/
class Menu
{
    private:
    Manage manage;
    public:

    void manageFuntion();
    void staffFuntion();
};
/*
 * Function: manageFuntion
 * Description: Hàm quản lý, chứa các chức năng của quản lý
 * Input:
 *      none
 * Output:
 *      none
*/
void Menu::manageFuntion()
{
    uint8_t key;
    uint8_t table;
    char name[20];
    double price;
    enum managecmd
    {
        exit,numOfTable,setDish,deleteDish,repairDish,displayDish

    };

        do
        {
        printf("0. Thoat\n");
        printf("1. Dat so luong ban\n");
        printf("2. Them mon an\n");
        printf("3. Xoa mon an\n");
        printf("4. Sua mon an\n");
        printf("5. Hien thi danh sach mon\n");
        printf("Nhap vao:__");
        scanf("%d",&key);
        switch (key)
        {
        case exit:
        printf("Thoat\n");
        break;
        case numOfTable:
            manage.setNumberOfTable();
            break;
        case setDish:
            manage.setDishes();
            break;
        case deleteDish:
            manage.displayListDish();
            manage.deleteDishes();
            break;
        case repairDish:
            manage.displayListDish();
            manage.repairDishes();
            break;
        case displayDish:
            printf("Danh sach mon an \n");
            manage.displayListDish();
            break;
        default:printf("Error");
            break;
        }
    } while (key != 0 );

}
/*
 * Function: staffFuntion
 * Description: Hàm nhân viên, chứa các chức năng của nhân viên
 * Input:
 *      manager - Manage
 * Output:
 *      none
*/
void Menu::staffFuntion()
{
    Staff stf(manage);
    static uint8_t table;
    uint8_t id;
    uint8_t amount;
    static uint8_t key;
    enum staffcmd
    {
        exit,oder,infor,cash
    };
    if ((manage.getTableList().empty() || manage.getDishList().empty()) == 0 ){      // kiểm tra đối tượng đã có dữ liệu bàn và món chưa, nếu chưa
                                                                                    // sẽ yêu cầu người dùng setup món ăn và bàn
        do
        {
            stf.statusTableLish();
            enterInformatiom("Chon ban:__","%d",&table,0);
            if (table == 0){
                return;
            }
            enterInformatiom("1. Goi mon\n2. Hien Thi thong tin ban\n3. Tinh tien \nNhap vao:__","%d",&key,0);
            switch (key)
            {
            case oder:
                manage.displayListDish();
                stf.odered(table);
                break;
            case infor:
                stf.inforTable(table);
                break;
            case cash:
                stf.cash(table);
                break;
            default:
                break;
            }
        } while (key != 0 ) ;
    }printf("chua co du lieu ban hoac mon an\n");
}

int main(int argc, char const *argv[])
{
    Menu mn;
    static uint8_t key;
    enum runProgram
    {
        exit,manage,staff
    };
    do
    {
        enterInformatiom("2. Nhan vien\n1. Quan Li\n0. Thoat\nNhap vao:__","%d",&key,0);
        switch (key)
        {
        case exit:
            printf("Exit!!!\n");
            break;
        case manage:
            mn.manageFuntion();
            break;

        case staff:
            mn.staffFuntion();
            break;

        default:printf("ERROR!!");
            break;
        } 
    } while (key!=0);
    return 0;
}
