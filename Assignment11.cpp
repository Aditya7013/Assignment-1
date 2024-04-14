#include <iostream>
#include <cmath>

class Shape {
public:
  // This function calculates the area of a shape 
  virtual double area() const = 0;
  
  // This function calculates the perimeter of a shape 
  virtual double perimeter() const = 0;
};

class Circle : public Shape {
private:
  double m_radius; 
public:
  Circle(double radius) : m_radius(radius) {}
  
  double area() const override {
    return M_PI * m_radius * m_radius;
  }
    
  double perimeter() const override {
    return 2 * M_PI * m_radius;
  }
};

class Rectangle : public Shape {
private:
  double m_length; 
  double m_width;  
public:
  Rectangle(double length, double width) : m_length(length), m_width(width) {}
  
  double area() const override {
    return m_length * m_width;
  }
    
  double perimeter() const override {
    return 2 * (m_length + m_width);
  }
};

class Triangle : public Shape {
private:
  double m_side1; 
  double m_side2;  
  double m_side3;  
public:
  Triangle(double side1, double side2, double side3) : m_side1(side1), m_side2(side2), m_side3(side3) {}
  
  double area() const override {
    double s = (m_side1 + m_side2 + m_side3) / 2;
    return sqrt(s * (s - m_side1) * (s - m_side2) * (s - m_side3));
  }
    
  double perimeter() const override {
    return m_side1 + m_side2 + m_side3;
  }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 3.0);
    Triangle triangle(3.0, 4.0, 5.0);

    std::cout << "Circle area: " << circle.area() << std::endl;
    std::cout << "Circle perimeter: " << circle.perimeter() << std::endl;

    std::cout << "Rectangle area: " << rectangle.area() << std::endl;
    std::cout << "Rectangle perimeter: " << rectangle.perimeter() << std::endl;

    std::cout << "Triangle area: " << triangle.area() << std::endl;
    std::cout << "Triangle perimeter: " << triangle.perimeter() << std::endl;

    return 0;
}
