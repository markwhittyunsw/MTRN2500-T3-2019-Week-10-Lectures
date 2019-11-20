// Interfaces explores the concept of writing interface classes
// by which public methods are used to call private virtual methods
// thereby making the class more easily extendable
// Mark Whitty
// V0.1 
// 20191121
#include <iostream>
#include <memory>  // For shared_ptr
#include <typeinfo>  // For showing the type info
#include <cassert>  // For using assertions
class IShape {
// IShape is the interface for a shape class
public: 
    void move_shape_to_(double x, double y) {
        // Do any checking in here before calling the virtual function
        assert(x>0);
        assert(y>0);
        move_shape_to_impl(x, y);
    }
    void draw_shape_() {
        // Do any checking in here before calling the virtual function
        draw_shape_impl();
    }
    virtual ~IShape() {}
private:
    // Here are the pure virtual functions which will be used in derived
    // classes to do the implementing (hence post-pended by "impl")
    virtual void move_shape_to_impl(double x, double y) = 0;
    virtual void draw_shape_impl() = 0;   
};

class Shape : public IShape {
    // Shape class, with common parameters x_ and y_ for all shapes
private:
    double x_, y_;
protected: 
    void move_shape_to_impl(double x, double y) {
        std::cout << "Moving a shape from (" << x_ << ", " << y_
        << ") to (" << x << ", " << y << ")" << std::endl;
        x_ = x; y_ = y;
    }
    double getX() {return x_;};
    double getY() {return y_;};
    virtual void draw_shape_impl() = 0;  // Ensures Shape itself cannot be instantiated
public:
    Shape(double x, double y):x_{x}, y_{y} {};
};

class Circle:public Shape {
private:
    double radius_;
protected:
    void draw_shape_impl() {
        std::cout << "Drawing a circle at (" << this->getX() << ", " 
            << this->getY() << "), radius = " << this->getRadius() << std::endl;
    }
    double getRadius() {return radius_;};
public:
    Circle(double x, double y, double radius):Shape(x, y), radius_{radius} {};
};

class Square:public Shape {
private:
    double side_length_;
protected: 
    void draw_shape_impl() {
        std::cout << "Drawing a square at (" << this->getX() << ", " 
            << this->getY() << "), side_length = " << this->getSideLength() << std::endl;
    }
    double getSideLength() {return side_length_;};
public:
    Square(double x, double y, double side_length):Shape(x, y), side_length_{side_length} {};       
};

int main() {
    Circle c(1.0, 2.0, 3.0);
    Square s(4.0, 5.0, 6.0);
    Shape *shpPtr = &c;
    // Shape *shpPtr2 = new Square(7, 8, 9);  // Allocate memory using new (commonly on the heap)
    // auto shpPtr3 = std::make_shared<Square>(10, 11, 12);  // Allocate a shared_pointer, to safely handle destructing
    shpPtr->draw_shape_();
    // shpPtr2->draw_shape_();
    // shpPtr3->draw_shape_();
    shpPtr->move_shape_to_(-1, -2);
    shpPtr->draw_shape_();
    // shpPtr3->move_shape_to_(-3, -4);
    // shpPtr3->draw_shape_();

    return 0;
}



