/*
 * File: main.cpp
 * Author: Nguyễn Tuấn Đạt
 * Date: 12/04/2023
 * Description: Chương trình quản lí tài khoản ngân hàng
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
 * Function: class BankAccounts
 * Description: chứa thuộc tính và các phương thức để sử dụng thẻ ngân hàng
*/
class BankAccounts
{
    private:
    string accountName;
    int accountNum;
    double balance;
    public:
    BankAccounts(string accountName, int accountNum, double balance);
    string getAccountName();
    int getAccountNum();
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void displayAccount();
};
/**
 * Function: Constructer BankAccounts
 * Description: khởi tạo tài khoản ngân hàng
 * Input:
 *      accountName - string
 *      accountNum - uint8_t
 *      balance - double
 * Output:
 *      none
*/
BankAccounts::BankAccounts(string accountName, int accountNum, double balance)
{
    this->accountName = accountName;
    this->accountNum = accountNum;
    this->balance = balance;
}
/**
 * Function: getAccountName
 * Description: lấy tên tài khoản
 * Input:
 *      none
 * Output:
 *      return accountName
*/
string BankAccounts::getAccountName()
    {
        return this->accountName;
    }
/**
 * Function: getAccountNum
 * Description: lấy số tài khoản
 * Input:
 *      none
 * Output:
 *      return accountNum
*/
int BankAccounts::getAccountNum() 
{
        return this->accountNum;
}
/**
 * Function: getBalance
 * Description: lấy tên của tài đối tượng
 * Input:
 *      none
 * Output:
 *      return getBalance
*/
double BankAccounts::getBalance() 
{
        return this->balance;
}
/**
 * Function: deposit
 * Description: nộp tiền vào tài khoản
 * Input:
 *      amount - double
 * Output:
 *      none
*/
void BankAccounts::deposit(double amount)
{
    this->balance += amount;
}
/**
 * Function: withdraw
 * Description: rút tiền vào tài khoản
 * Input:
 *      amount - double
 * Output:
 *      none
*/
void BankAccounts::withdraw(double amount)
{
    this->balance -= amount;
}
/**
 * Function: displayAccount
 * Description: hiển thị thông tin và số dư của tài khoản
 * Input:
 *      none
 * Output:
 *      none
*/
void BankAccounts::displayAccount()
{
    printf("Ten tai khoan la: %s\n So tai khoan la: %d\n So du tai khoan la: %0.3lf\n",
   getAccountName().c_str(),getAccountNum(),getBalance());
}
int main(int argc, char const *argv[])
{
    BankAccounts acc1("Dat",123,100.0);
    BankAccounts acc2("Tuan",456,120.0);
    acc1.displayAccount();
    acc1.deposit(200.0);
    acc1.displayAccount();
    acc1.withdraw(150.0);
    acc1.displayAccount();

    acc2.displayAccount();
    return 0;
}
