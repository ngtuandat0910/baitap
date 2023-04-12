#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <fstream> 
#include <iostream> 
using namespace std;

// macro nhập thông tin
#define enter_information(content,format,variable,condition)    \
    printf("%s\n",content);                                \
    scanf(format,variable);                               \
    while (condition){                                        \
        printf("error!! The information entered is incorrect\n");\
        printf("retype!!!\n");\
        scanf(format,variable);\
        }                                                         


class Student
{
private:
 uint8_t id;
 char name [20];
 char gender[4];
 uint8_t math_score;
 uint8_t physics_score;
 uint8_t chemistry_score;
 uint8_t age;
 uint8_t gpa;
 char rank [11] ;
public:
    Student(const char NAME [], const uint8_t AGE, const char GENDER[], const double MATH , const double PHYSICS, const double CHEMISTRY  );
    void setName(const char  NAME[]);
    void setAge(uint8_t AGE);
    void setGender(const char GENDER[]);
    void setMath(uint8_t MATH);
    void setPhysics(uint8_t PHYSICS);
    void setChemistry(uint8_t CHEMISTRY);
    uint8_t getID();
    char *getName ();
    char *getGender();
    uint8_t getAge();
    double getMath();
    double getPhysics();
    double getChemistry();
    double getGPA();
    char *getrank();
};

 Student::Student(const char NAME [], const uint8_t AGE, const char GENDER[], const double MATH , const double PHYSICS, const double CHEMISTRY ){
    static uint8_t id = 100;
    Student::id = id;
    strcpy(Student::name, NAME);
    Student::age = AGE;
    strcpy(Student::gender,GENDER);
    Student::math_score = MATH;
    Student::physics_score = PHYSICS;
    Student::chemistry_score = CHEMISTRY;
    id ++;
 }

//lấy id
uint8_t Student::getID(){
    return id;
 }
// nhập/lấy tên
void Student::setName(const char NAME[])
{
    strcpy(name,NAME);
}
char *Student::getName(){
    return name;
}
// nhập/lấy giới tính
void Student::setGender(const char GENDER[])
{
        strcpy(gender,GENDER);
}
char *Student::getGender()
{
    return gender;
}
// nhập/lấy tuổi
void Student::setAge(uint8_t AGE)
{
    Student::age = AGE;
}
uint8_t Student::getAge()
{
    return age;
}
// nhập/lấy điểm toán
void Student::setMath(uint8_t MATH)
{
    Student::math_score = MATH;
}
double Student::getMath()
{
    return math_score;
}
// nhập/lấy điểm lý
void Student::setPhysics(uint8_t PHYSICS)
{
    Student::physics_score = PHYSICS;
}
double Student::getPhysics()
{
    return physics_score;
}
// nhập/lấy điểm hóa
void Student::setChemistry(uint8_t CHEMISTRY)
{
    Student::chemistry_score = CHEMISTRY;
}
double Student::getChemistry( )
{
    return chemistry_score;
}
// lấy gpa
double Student::getGPA()
{
    return  (math_score + physics_score + chemistry_score)/3;
     
}
// lấy loại
char *Student::getrank()
{
    if (getGPA()< 4.00)
    {
        strcpy(rank,"Weak");
    }else if (getGPA() < 6.50)
    {
        strcpy(rank,"Average");
    }else if (getGPA()  < 8.00)
    {
        strcpy(rank,"Good");
    }else
        strcpy(rank,"Very_good");
    
    return rank;
}




class Menu
{
    private:
    vector <Student> student_list;
    public:
    void add_students();
    
    void update_students_by_id();
    void delete_students_by_id();
    void search_students_by_name();
    void sort_students_by_gpa();
    void sort_students_by_name();
    void show_students();
    void write_infor_to_file();
};

// hàm thêm sinh viên, khi được gọi sẽ tạo thêm 1 đối tượng mang các thuộc tính của lớp sinh viên
void Menu::add_students()
{
    
    char NAME[20];
    char GENDER [4];
    uint8_t AGE;
    double MATH;
    double PHYSICS;
    double CHEMISTRY;
    int key ;
    

    do{

    printf("Enter_student_information\n");

    enter_information("Enter name","%s",&NAME,0);
    enter_information("Enter age","%d",&AGE, AGE < 10 || AGE >50);
    enter_information("Enter gender","%s",&GENDER,strcmp((char*)"Nam",GENDER) !=0 && strcmp((char*)"Nu",GENDER) !=0 );
    enter_information("Enter math score","%lf",&MATH, MATH < 0 || MATH >10);
    enter_information("Enter physics score","%lf",&PHYSICS, PHYSICS < 0 || PHYSICS >10);
    enter_information("Enter chemistry score","%lf",&CHEMISTRY, CHEMISTRY < 0 || CHEMISTRY >10);

    Student sv (NAME,AGE,GENDER,MATH,PHYSICS,CHEMISTRY); // khai báo thuộc tính cho đối tượng sv
    student_list.push_back(sv); // đưa đối tượng sv vào danh sách student list


    printf("Press 1 to continue\n");
    printf("Press 0 to exit\n");
    scanf("%d",&key);

    }while(key == 1 );


}

void Menu::show_students()
{
    printf("Show list of students\n");
    printf("ID\t Name\t Gender\t Age\t Math score\t Physics score\t Chemistry score\t GPA\t Rank\t \n");
    
    for (Student sv : student_list) // sử dụng vòng lặp foreach, các phần tử trong student list sẽ được sao chép vào đổi tượng sv
    {
        printf("%d\t %s\t %s\t %d\t    %.2lf\t        %.2lf\t        %.2lf\t         %.2lf\t%s\t \n",sv.getID(),sv.getName(),sv.getGender(),sv.getAge(),sv.getMath(),
        sv.getPhysics(),sv.getChemistry(),sv.getGPA(),sv.getrank());
    }   
}
// hàm cập nhật thông tin sinh viên sử dụng id
void Menu::update_students_by_id()
{
    printf("Enter the ID to update\n");
    uint8_t id;
    int i = 0 ;
    scanf("%d",&id);
    for (Student &sv : student_list)   // lặp qua danh sách sinh viên để tìm id tương ứng
    {
        printf("%d\n",sv.getID () );   // Nếu tìm thấy sinh viên có ID trùng với ID cần cập nhật
        if (sv.getID () == id)
        {
            // Khai báo các biến để lưu thông tin cập nhật
            char NAME[20];
            char GENDER [4];
            uint8_t AGE;
            double MATH;
            double PHYSICS;
            double CHEMISTRY;
            int key;
            // Hiển thị menu tùy chọn thông tin cần cập nhật
            do
            {
            printf("Please enter your option\n1.Name\n2.Age\3.Gender\n4.Math score\n5.Physics score\n6.Chemistry score\n7.Exit\n");
            scanf("%d",&key);
            switch (key)
            {
            case 1:
        
                enter_information("Enter name","%s",&NAME,0);
                sv.setName(NAME);
            
                break;
            case 2:
                
                enter_information("Enter age","%d",&AGE, AGE < 10 || AGE >50);
                sv.setAge(AGE);
                break;
            case 3:
            enter_information("Enter gender","%s",&GENDER,strcmp((char*)"Nam",GENDER) !=0 && strcmp((char*)"Nu",GENDER) !=0 );
                sv.setGender(GENDER);
                break;
                
            case 4:
                
                enter_information("Enter math score","%lf",&MATH, MATH < 0 || MATH >10);
                sv.setMath(MATH);
                break;
            case 5:
                enter_information("Enter physics score","%lf",&PHYSICS, PHYSICS < 0 || PHYSICS >10);
                sv.setMath(PHYSICS);
                break;
            case 6:
                
                enter_information("Enter chemistry score","%lf",&CHEMISTRY, CHEMISTRY < 0 || CHEMISTRY >10);
                sv.setMath(CHEMISTRY);
                break;
            case 7:
                
                printf("exit!!!\n");
                break;
            default:printf("Error please enter again!!\n");
            
                break;
            }
            } while (key != 7);
        }
        i++;
    }
    
}
// Hàm này cho phép người dùng nhập vào một ID sinh viên cần xóa trong danh sách sinh viên.
// Nếu sinh viên có ID tương ứng trong danh sách thì hàm sẽ xóa sinh viên đó khỏi danh sách và in ra thông báo "Da xoa".
// Nếu không tìm thấy sinh viên có ID tương ứng thì hàm sẽ không làm gì cả.
void Menu::delete_students_by_id()
{
    int id = 0;
    printf("Enter the ID to delete\n");
    scanf("%d", &id);
    for (int i = 0; i < student_list.size(); i++)
    { 
        Student& sv = student_list[i];      
        if (sv.getID () == id )
        {
            student_list.erase(student_list.begin() + i);
            printf("............................Complete!!.............................\n");
            return;
        }printf("Not found ID!!");
    }
}

void Menu::sort_students_by_gpa()

{
    printf("............................Please Wait!!.............................\n");
//Sử dụng hai vòng lặp for để duyệt qua các phần tử trong danh sách sinh viên.
//So sánh GPA của 2 sinh viên ở vị trí i và j trong danh sách sinh viên
//Hoán đổi vị trí của 2 sinh viên nếu GPA của sinh viên i > sinh viên j
for (int i = 0; i < student_list.size() - 1; i++) 
    { 
        for (int j = i +1 ; j < student_list.size() ;j++) 
        {

            if (student_list[i].getGPA() > student_list[j].getGPA() )
            {
                Student sv = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = sv;
            }
            
        }
    
    }
printf("............................Complete!!.............................\n");
}
// Hàm tìm kiếm sinh viên theo tên
void Menu::search_students_by_name()
{
    printf("Enter the name of the student\n"); // yêu cầu nhập tên sinh viên cần tiềm kiếm
    char NAME[20];
    scanf("%s",&NAME);
    for (Student sv : student_list) //lặp qua danh sách sinh viên
    {
        if (strcmp(sv.getName(), NAME) == 0) //nếu tên sinh viên trùng khớp
        {
            // xuất thông tin ra màn hình
            printf("thong tin cua %s\n",NAME);
            printf("ID\t Ten\t gtinh\t tuoi\t toan\t ly\t hoa\t gpa\t Xeploai\t \n");
            printf("%d\t %s\t %s\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\t \n",sv.getID(),sv.getName(),sv.getGender(),sv.getAge(),sv.getMath(),
        sv.getPhysics(),sv.getChemistry(),sv.getGPA(),sv.getrank());

        }printf("Not found Name!!");
    }
}
// hàm này dùng để sắp xếp sinh viên theo tên
void Menu::sort_students_by_name()
{
    printf("............................Please Wait!!.............................\n");
    // dùng 2 vòng lặp để duyệt qua danh sách sinh viên
    for (int i = 0; i < student_list.size() - 1; i++)
    { 
        for (int j = i +1 ; j < student_list.size() ;j++)
        {
            // so sánh giá trị của chuỗi tên sinh viên i và j
            // nếu sinh viên i > j thì đổi chỗ cho nhau
            if (strcmp(student_list[i].getName(), student_list[j].getName()) > 0 ) 
            {
                Student sv = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = sv;
            }
            
        }
    
    }
printf("............................Complete!!.............................\n");
}
void Menu::write_infor_to_file()
{
    // chưa làm được
}

int main(int argc, char const *argv[])
{

    Menu mn;
    int option;
     do
    {
    printf("please_press_your_option!!!\n\n");
    printf("1.add_students\n2.update_students_by_id\n3.delete_students_by_id\n4.search_students_by_name\n5.sort_students_by_gpa\n6.sort_students_by_name\n7.show_students\n8.write_infor_to_file\n9.exit\n");
    scanf("%d",&option);
   
         switch (option)
    {
    case 1:
        mn.add_students();break;
    case 2:
        mn.update_students_by_id();
        break;
    case 3:
        mn.delete_students_by_id();
        break;
    case 4:
        mn.search_students_by_name();
        break;
    case 5:
        mn.sort_students_by_gpa();
        break;
    case 6:
        mn.sort_students_by_name();
        break;
    case 7:
        mn.show_students();
        break;
    case 8:
        mn.write_infor_to_file();
        break;
    case 9:
        printf("Exit!!!!!!!!!!!\n");
        break;
    
    default: printf("Error please enter\n");
        break;
    }
    } while (option != 9);
    return 0;
}
