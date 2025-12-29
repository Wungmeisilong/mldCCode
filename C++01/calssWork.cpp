/*
## 多态

### 多态的实现

- virtual 关键字
- override 关键字

### 多态的使用
父类的指针或者引用，指向子类对象

### 多态原理剖析

- 虚函数表

- 虚函数表指针

### 开闭原则

- 对拓展开放，对修改关闭

### 拓展的好处

- 组织结构清晰；
- 可读性强；
- 拓展和维护性高；

### 纯虚函数和抽象类

- 抽象类：包含纯虚函数的类
   - 特点：无法实例化对象，子类必须重写抽象类中的纯虚函数，否则子类也是抽象类；
- 纯虚函数：在基类中没有实现的虚函数（virtual 返回值类型 函数名（参数列表）= 0）

### 虚析构和纯虚构函数

- 问题：如果基类指针指向子类对象，通过基类指针释放子类对象时，析构函数会不会调用子类的析构函数？
- 解决：基类的析构函数声明为虚析构函数
- 纯虚析构函数的声明和实现
  - 语法：1.virtual ~类名(){}
          2.virtual ~类名()=0;
            类名::~类名(){}
- 目的：抱枕在销毁派生类对象时，能正确执行积累和派生类的清理操作；

### 抽象类无法实例化，那么它的构造函数有什么用？

- 子类对象包含父类对象，当子类对象调用时，会先调用父类的构造函数。
*/

#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

class Figure{
    public:
    virtual void onDraw() = 0;
    virtual ~Figure(){}
};

class Triangle:public Figure{
    protected:
        Point p1;
        Point p2;
        Point p3;
    public:
        Triangle():p1{},p2{},p3{}{}
        Triangle(Point a, Point b, Point c):p1(a),p2(b),p3(c){}
        ~Triangle(){}
        Point getP1()const{
            return p1;
        }
        Point getP2()const{
            return p2;
        }
        Point getP3()const{
            return p3;
        }
        void setP1(Point a){
            p1 = a;
        }
        void setP2(Point b){
            p2 = b;
        }
        void setP3(Point c){
            p3 = c;
        }
        virtual void onDraw() override{
            cout << "绘制三角形,三个点是：(" << p1.x << "," << p1.y << ")、(" << p2.x << "," << p2.y << ")、(" << p3.x << "," << p3.y << ")"<<endl;
        }
};

class Circle:public Figure{
    private:
        Point center;
        int randius;
    public:
        Circle():center{},randius(0){}
        Circle(Point c, int r):center(c), randius(r){}
        Point getCenter()const{
            return center;
        }
        int getRandius()const{
            return randius;
        }
        void setCenter(Point c){
            center = c;
        }
        void setRandius(int r){
            randius = r;
        }
        virtual void onDraw() override{
            cout << "绘制圆形，圆点是：(" << center.x << "," << center.y << "),半径是：" << randius << endl;
        }
};

class Painter{
    public:
        void draw(Figure& fig)
        {
            fig.onDraw();
        }
};
int main(){
    Painter pa;
    Triangle tri{Point{1,2},Point{3,4},Point{5,6}};
    Circle cir{Point{7,8},10};
    tri.setP1(Point{13,14});
    pa.draw(tri);
    pa.draw(cir);

    return 0;
}