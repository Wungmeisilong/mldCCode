
/*
使用使用cin,cout完成下面对话框内容：

   What’s you name?

   Xiajiashan(需要从键盘输入)

   Your name is xiajiashan.
*/
#if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name;
    cout << "What's your name?" << endl;
    cin >>name;
    cout << "Your name is " << name << "." <<endl;
    return 0;
}
#endif

#if 0
/*
定义一个无符号短整数变量shortsmall，
并赋值为shortsmall = 65535，++两次，每次++输出结果，并观察现象
*/
#include <iostream>
using namespace std;

int main()
{
    unsigned short shortsmall = 65535;
    cout << "初始值：" << shortsmall << endl;
    shortsmall++;
    cout << "第一次++后值：" << shortsmall << endl;//溢出变为0
    shortsmall++;
    cout << "第二次++后值：" << shortsmall << endl;//变为1
    return 0;
}
#endif

#if 0
/*
定一个结构体student，
包含name(字符串类型),age(整型),address(字符串类型),score（浮点型）
三个成员，从键盘录入数据进行初始化，并打印输出。
*/

#include <iostream>
#include <string>
using namespace std;
typedef struct student
{
    string name;
    int age;
    string address;
    float score;
}student;

int main()
{
    student stud;
    cout << "请输入学生姓名：";
    cin >> stud.name;
    cout << "请输入学生年龄：";
    cin >> stud.age;
    cout << "请输入学生地址：";
    cin >> stud.address;
    cout << "请输入学生成绩：";
    cin >> stud.score;

    cout << "学生信息如下：" << endl;
    cout << "姓名\t年龄\t地址\t成绩" << endl;
    cout << stud.name << "\t" << stud.age << "\t" << stud.address << "\t" << stud.score << endl;
    return 0;
}
#endif

#if 0
/*
设计一个学生类，要求该类有姓名、成绩、性别三个属性以及自我介绍的成员函数
*/
#include <iostream>
#include <string>
using namespace std;
class Student{
    
    public:
        Student(string n, float s, string g):name(n),score(s),gender(g){
        }
        ~Student(){
        }
        void introduce(){
            cout << "大家好，我叫" << name <<"，性别" << gender <<"，成绩"<<score << "分。" << endl;
        }
    private:
        string name;
        float score;
        string gender;

};

int main()
{
    Student stud = Student("小明", 95.5, "男");
    stud.introduce();
    return 0;
}
#endif

#if 0
/*
建立一个对象数组，内放n(<10)个学生的数据(学号、成绩)，设立一个函数max，用指向对象的指针作函数参数，在max函数中找出n个学生中成绩最高者，并输出其学号。
*/
#include <iostream>
using namespace std;
static int  N =  4;
class Student{
    public:
        Student():id(0),score(0.0f){

        }
        Student(int i, float s):id(i),score(s){

        }
        ~Student(){

        }
        int getId();
        float getScore();
    private:
        int id;
        float score;
};
class StudentInfo{
    public:
        StudentInfo(int n ){
            for(int i=0; i< n - 1; i++){
                students[i] = Student(100+i+1, (i+1)*10.0f);
            }
        };
        ~StudentInfo(){};
        Student students[9];
        void max(Student* student,int n);
};

int Student::getId(){
    return Student::id;
}

float Student::getScore(){
    return score;
}

void StudentInfo::max(Student* student,int n){
    float maxScore = student[0].getScore();
    int maxId = student[0].getId();
    for(int i=0; i<n; i++){
        if(student[i].getScore() > maxScore){
            maxScore = student[i].getScore();
            maxId = student[i].getId();
        }
    }
    cout<<"成绩最高的学生学号是：" << maxId << "，成绩是：" << maxScore << endl;
}
int main()
{
    StudentInfo info = StudentInfo(N);
    info.max(info.students,N);
    return 0;
}
#endif

#if 0

/*
自定义类表示分数（Fraction）。

要求：

1、有成员属性denominator（分母，整型），numerator（分子，整型）

2、将denominator，numerator设为私有属性，并提供公开的get，set函数。

3、有合理的构造函数
*/
#include <iostream>
using namespace std;
class Fraction{
    public:
    Fraction(int num, int den):numertor(0),denominator(1){
        setNumerator(num);
        setDenominator(den);
    }
    ~Fraction(){

    }
    int setNumerator(int num){
        numertor = num;
        return numertor;
    }
    int setDenominator(int den){
        if(den != 0){
            denominator = den;
        }
        return denominator;
    }
    void getnumerator(){
        cout << "分子是：" << numertor << endl;
    }
    void getdenominator(){
        cout << "分母是：" << denominator << endl;
    }
    void printFraction(){
        cout << "分数是：" << numertor << "/" << denominator << endl;
    }
    private:
        int numertor;
        int denominator;
};
int main()
{
    Fraction frac = Fraction(3,4);
    frac.printFraction();
    return 0;
}
#endif

#if 0
/*
使用函数重载，用于计算不同类型的两个数的平方和。

可以参考函数声明： func(int,int);

func(double,double);
*/
#include <iostream>
using namespace std;
int func(int a, int b){
    return a*a + b*b;
}

double func(double a, double b){
    return a*a + b*b;
}
int main(){
    int int1=3, int2=4;
    double double1=2.5, double2=3.5;
    cout << "整数平方和：" << func(int1,int2) << endl;
    cout << "浮点数平方和：" << func(double1,double2) << endl;
    return 0;
}
#endif

#if 0
/*
自定义类表示人（Person）。

要求：

1、有成员属性name（姓名，string），age（年龄，int）。

2、将name，age设为受保护属性。

3、有合理的构造函数，构造函数必须初始化name和age。

自定义类表示学生（Student）继承自人（Peron）。

要求：

1、添加属性score（成绩，int）。

2、将score设置为私有属性，并提供公开的get，set函数。

3、有公开的成员函数describe，可以用string描述学生的姓名，年龄和成绩。

建议describe的函数原型：string Student::describe()const;

4、有合理的构造函数，构造函数必须初始化Person和score。
*/
#include <iostream>
using namespace std;

class Preson{
    protected:
        string name;
        int age;
    public:
        Preson(string n, int a):name(n),age(a){
        };
        ~Preson(){
        };
};

class Studen:public Preson{
    private:
        int score;
    public:
        Studen():Preson(" ",0),score(0){};
        Studen(string n, int a, int s):Preson(n,a),score(s){};
        ~Studen(){};
        int getScore();
        void setScore(int s);
        string describe()const;
};
int Studen::getScore(){
    return score;
}
void Studen::setScore(int s){
    score = s;
}
string Studen::describe()const{
    return "姓名：" + name + "，年龄：" + to_string(age) + "，成绩：" + to_string(score);
}
int main(){
    Studen stud = Studen("小红",20,95);
    cout << stud.describe() << endl;
    return 0;
}
#endif

#if 0
/*
定义一个人员类Person，包含数据成员：姓名、ID。在此基础上派生出学生类Student(增加成绩属性)和老师类Teacher(增加教龄)，主函数测试实现对学生和老师信息的输入输出。
*/
#include <iostream>
using namespace std;
class Preson{
    protected:
        string name;
        int ID;
    public:
        Preson(string n, int a):name(n),ID(a){
        };
        ~Preson(){
        };
};

class Student:public Preson{
    private:
        float score;
    public:
        Student(string n, int i, float s):Preson(n, i),score(s){};
        ~Student(){};
        void showInfo(){
            cout << "学生信息\n学号:" << ID << ",姓名：" << name << ",成绩：" << score << endl;
        }
};


class Teacher:public Preson{
    private:
        int age;
    public:
        Teacher(string n, int i, float s):Preson(n, i),age(s){};
        ~Teacher(){};
        void showInfo(){
            cout << "教师信息\n工号:" << ID << ",姓名：" << name << ",年龄：" << age << endl;
        }
};
int main(){
    Student s = Student("王五", 1001, 12.7);
    Teacher t = Teacher("王老师", 2025, 100);
    s.showInfo();
    t.showInfo();
    return 0;
}
#endif

#if 0
/*
设计一个学生类，要求该类有姓名、成绩、性别三个属性以及自我介绍的成员函数。（要求必须要有构造函数、析构函数、成员姓名是char*类型存储在堆空间）
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Student{
    private:
        char* name;
        float score;
        string sex;
    public:
        Student(char* n,float s, string se){
            name = new char[strlen(n)+1];
            strcpy(name, n);
            score = s;
            sex = se;
        }
        Student(const Student& other):score(other.score), sex(other.sex){
            name = new char[strlen(other.name)+1];
            strcpy(name, other.name);
        }
        Student& operator=(const Student& other){
            if(this != &other) return *this;
            delete[] name;
            name = new char[strlen(other.name)+1];
            strcpy(name, other.name);
            score = other.score;
            sex = other.sex;

            return *this;
        }
        ~Student(){
            delete[] name;
        }
        void introduce(){
            cout << "姓名：" << name << ",成绩：" << score << ",性别：" << sex << endl;
        }
};

int main(){
    Student s = Student("zhangsan", 100, "男");
    s.introduce();
}
#endif

#if 0
/*
练习：定义一个员工类Employee

要求：1，有工行，名字，员工总人数（static）

      2，构造函数

      3，输出函数print，输出工号，姓名

      4，静态成员函数void count();负责输出总人数；

      5，在main函数中定义3个员工，每构造一个对象，打印姓名和工号，总人数
*/
#include <iostream>

using namespace std;

class Employee{
    private:
        int id;
        string name;
        static int countNumber;
    public:
        Employee(string n):name(n),id(100){
            countNumber++;
            id += countNumber;
            print();
            count();
        }
        ~Employee(){}
        static void count(){
            cout << "员工总人数：" << countNumber << endl;
        }
        void print(){
            cout << "工号：" << id << ",姓名：" << name << endl;
        }
};
int Employee::countNumber = 0; //静态成员变量必须在类外初始化

int main(){
    Employee e1 = Employee("张三");
    Employee e2 = Employee("李四");
    Employee e3 = Employee("王五");
    return 0;
}
#endif

#if 0
/*
定义一个交通工具类（Vehicle）属性：速度(speed)，体积(size)  

函数：构造函数初始化speed和size,

移动：move()，

设置速度setSpeed(int speed)，加速speedUp(),

减速speedDown()

最后在main()中实例化一个交通工具对象，并通过方法给它初始化speed,size的值，
并且通过打印出来。另外，调用加速，减速的方法对速度进行改变。
【4分，构造函数初始 化成员1分，方法的定义1分，主函数测试+代码规范1分】
*/

#include <iostream>

using namespace std;
class Vehicle{
    private:
        float speed;
        float size;
    public:
        Vehicle(float sp, float si):speed(sp), size(si){
            cout << "速度：" << speed << ",体积：" << size << endl;
        }
        ~Vehicle(){}
        void move(){
            cout << "移动中..." << endl;
        }
        void setSpeed(float sp){
            speed = sp;
            cout << "速度设置为：" << speed << endl;
        }
        void speedUp(){
            speed += 10;
            cout << "加速后速度为：" << speed << endl;
        }
        void speedDown(){
            speed -= 10;
            cout << "减速后速度为：" << speed << endl;
        }
};
int main(){
    Vehicle v = Vehicle(100.0, 2000.0);
    v.move();
    v.setSpeed(200.0);
    v.speedUp();
    v.speedDown();
    return 0;

}
#endif

#if 0

/*
编写程序，调用传递引用的参数，实现两个字符串变量的交换。

例如开始：
char* ap = "hello";
char* bp = "how are you?";
交换的结果使得ap和bp指向的内容分别为：
ap: "how are you?"
bp: "hello"
*/
#include <iostream>
using namespace std;

void swap(const char*& a, const char*& b){
    const char* temp = a;
    a = b;
    b = temp;
}
int main()
{
    const char* ap = "hello";
    const char* bp = "how are you?";
    cout << "ap: " << ap << endl;
    cout << "bp: " << bp << endl;
    swap(ap, bp);
    cout << "ap: " << ap << endl;
    cout << "bp: " << bp << endl;
    return 0;
}
#endif

#if 0

/*
需求：

定义一个Person类，包含属性：
姓名，年龄，性别；写好相关的方法，能够构造的时候初始化或者后续修改属性值

定义一个Employee类继承于Person类，包含新的属性：
职位；写好相关的方法，能够构造的时候初始化或者后续修改属性值，重载＝＝，
比较规则：当两个对象的姓名，年龄，性别，职位都相等时返回true,否则返回false。

进行相关测试（要求可以打印对象的信息，能够进行对象的比较是否"相等”中等：
*/

#include <iostream>
#include <string>
using namespace std;
class Person{
    protected:
        string name;
        int age;
        string sex;
    public:
        Person(string n, int a, string s):name(n), age(a), sex(s){}
        ~Person(){}
        void setName(string n){
            name = n;
        }
        void setAge(int a)
        {
            age = a;
        }
        void setSex(string s){
            sex = s;
        }

};

class Employee:public Person{
    private:
        string position;
    public:
        Employee(string n, int a, string s, string p):Person(n, a, s), position(p){}
        ~Employee(){}
        void setPosition(string p){
            position = p;
        }
        bool operator==(const Employee& e){
            return  name == e.name && age == e.age && 
                    sex == e.sex && position == e.position;
        }
};
int main(){
    Employee e1 = Employee("zhangsan", 20, "男", "manager");
    Employee e2 = Employee("lisi", 20, "男", "manager");
    if(e1 == e2){
        cout << "e1和e2相等" << endl;
    }else{
        cout << "e1和e2不相等" << endl;
    }
    e2.setName("zhangsan");
    if(e1 == e2){
        cout << "e1和e2相等" << endl;
    }else{
        cout << "e1和e2不相等" << endl;
    }

    return 0;
}
#endif

#if 0
/*
定义一个复数类Complex，默认初始化为0，重载运算符“＋”，“－”，
使之能用于复数的加，减运算，运算符重载函数作为Complex类的成员函数。
编程序，分别求出两个复数之和，差。（复数的输出格式比如：3+2i）
*/
#include <iostream>
using namespace std;

class Complex{
private:
    /* data */
    int real;
    int imag;
public:
    Complex(int r, int i):real(r), imag(i){}
    ~Complex(){}
    friend ostream& operator<<(ostream& os,const Complex& c){
        os << c.real;
        if(c.imag >= 0)
        {
            os << "+";
        }
        os<< c.imag << "i";
        return cout;
    }
    Complex operator+(const Complex& c){
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex& c){
        return Complex(real - c.real, imag - c.imag);
    }
};

int main(){
    Complex c1 = Complex(1, -2);
    Complex c2 = Complex(5, 8);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2: " << c1 + c2 << endl;
    cout << "c1 - c2: " << c1 - c2 << endl;
    return 0;
}
#endif

#if 1

/*
)实现一个计算器类，可以计算整数和小数的+,-,*,/。（你需要重载这些运算符）
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class Calculator{
    private:
        double da;
    public:
        Calculator(double da):da(da){}
        ~Calculator(){}
        void print(){ cout << da << endl;}
        double getValue(){return da;}
        Calculator operator+(const Calculator& num){
            return Calculator(da + num.da);
        }
        Calculator operator-(const Calculator& num){
            return Calculator(da - num.da);
        }
        Calculator operator*(const Calculator& num){
            return Calculator(da * num.da);
        }
        Calculator operator/(const Calculator& num){
            if(num.da == 0.0){
                throw invalid_argument("Error:除数不能为零！\n");
            }
            return Calculator(da / num.da);
        }
};

int main(){
    Calculator ca1 = Calculator(1);
    Calculator ca2 = Calculator(1);
    Calculator ca3 = Calculator(0);
    for(int i = 0; i < 4; i++){
        cout<<"-----第" << i+1 << "次-----" <<endl;
        ca1 = Calculator(i+4);
        ca2 = Calculator(i*10);
        switch (i%4)
        {
        case 0:
            ca3 = ca1 + ca2;
            break;
        case 1:
            ca3 = ca1 - ca2;
            break;
        case 2:
            ca3 = ca1 * ca2;
            break;
        case 3:
            ca3 = ca1 / ca2;
            break;
        default:
            break;
        }
        cout << ca3.getValue()<< endl;
    }
    
    return 0;
}
#endif

#if 0

/*
自定义一个字符串类MyString，用来存放不定长的字符串，
重载运算符“＝＝”、“+”，用于两个字符串的内容比较，初值自拟。
测试比较两个字符串内容是否相同。
【3分：MyString内部结构1分，运算符重载正确1分，能存放动态字符串，主函数测试正确1分】
*/

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    private:
        char* dataBuffer;
    public:
        MyString(const char* data){
            dataBuffer = new char[strlen(data)+1];
            strcpy(dataBuffer, data);
        }
        MyString(const char* data1, const char* data2){
            int n = strlen(data2);
            dataBuffer = new char[strlen(data1) + strlen(data2) +1];
            strcpy(dataBuffer, data1);
            strncat(dataBuffer,data2,n);
        }

        MyString& operator=(const MyString& ms){
            if( this != &ms) return *this;
            delete[] dataBuffer;
            dataBuffer = new char[strlen(ms.dataBuffer)+1];

            return *this;
        }

        ~MyString(){
            delete[] dataBuffer;
        }
        bool operator==(const MyString& ms){
            if(strcmp(dataBuffer, ms.dataBuffer) !=0){
                return true;
            }
            return false;
        }
        MyString operator+(const MyString& ms){
            return MyString(dataBuffer,ms.dataBuffer);
        }
        friend ostream& operator<<(ostream& os, const MyString& ms){
            return os<< ms.dataBuffer;
        }

};
int main(){
    MyString ms = MyString("你好");
    MyString ms1 = MyString(",张三");
    cout<< ms + ms1 << endl;
    return 0;
}
#endif