
#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

class Object {
private:
  int mass;
  int rapidity;
  std::vector<float> direction;
  std::vector<int> center;

public:
  int getMass() { return mass; }
  int getRapidiy() { return rapidity; }
  std::vector<float> setDirection() { return direction; }
  std::vector<int> getCenter() { return center; }

  void setMass(int mass) { this->mass = mass; }
  void setRapidity(int rapidity) { this->rapidity = rapidity; }
  void setCenter(int x, int y) {
    center[0] = x;
    center[1] = y;
  };
  void setDirection(int x, int y) {
    float n = std::sqrt(x * x + y * y);
    direction[0] = x / n;
    direction[1] = y / n;
  }
};
