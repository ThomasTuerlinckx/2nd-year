#include "Object.h"
#include <iostream>

class Circle : public Object {
private:
  int radius;

public:
  int getRadius() { return radius; }
  void getRadius(int radius) { this->radius = radius; }
};
