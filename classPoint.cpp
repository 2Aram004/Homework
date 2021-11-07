#include <iostream>

class Point
{
 public:
 Point(int x, int y);
 Point() {}
  Point operator+ (const Point&);
  Point operator- (const Point&);
  Point operator* (const Point&);
  Point operator/ (const Point&);
 
 bool operator>  (const Point&) const;
 bool operator<  (const Point&) const;
 bool operator!= (const Point&) const;
 bool operator== (const Point&) const;

 void set_x(int x) {this->x = x;}
 void set_y(int y) {this->y = y;}

 private:
 int x;
 int y;


};

Point::Point(int x, int y)
{
 this->x = x;
 this->y = y;

}



bool Point::operator> (const Point& p) const
{
 return (this->x > p.x || this->y >p.y);

}

bool Point::operator< (const Point& p) const
{
     return !(*this >  p);
}

bool Point::operator==  (const Point& p) const
{
 return (this->x == p.x || this->y == p.y);

}

bool Point::operator!= (const Point& p) const
{
  return !(*this == p);
}



/////////////////////////////////////////////////////
 Point Point::operator+ (const Point& p1)
{
 Point res;
 res.x = p1.x + this->x;
 res.y = p1.y + this->y;
 
 return res;
}
Point Point::operator- (const Point& p1)
{
 Point res;
 res.x = p1.x - this->x;
 res.y = p1.y - this->y;

 return res;
}

Point Point::operator* (const Point& p1)
{
 Point res;
 res.x = p1.x * this->x;
 res.y = p1.y * this->y;

 return res;
}

Point Point::operator/ (const Point& p1)
{
 Point res;
 res.x = p1.x / this->x;
 res.y = p1.y / this->y;

 return res;
}


int main()
{
  

}

