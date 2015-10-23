#include "Vector3d.hpp"

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Vector3d::Vector3d() {
  x = 0;
  y = 0;
  z = 0;
}

/*F***********************************************************
 * CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Vector3d::Vector3d(float a, float b) {

  x = a;
  y = b;
  z = 0;
}

/*F***********************************************************
 * CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Vector3d::Vector3d(float a, float b, float c) {

  x = a;
  y = b;
  z = c;
}

/*F***********************************************************
 * dotProduct(const Vector3d &vec2);
 * 
 * PURPOSE : Tutorial did not care to explain
 *           
 *           
 * RETURN :  float | the dot product
 *
 * NOTES :   
 *F*/
inline float Vector3d::dotProduct(const Vector3d &vec2) {

  return (x * vec2.x + y * vec2.y + z * vec2.z);
}

/*F***********************************************************
 * crossProduct(const Vector3d &vec2)
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  Vector3d
 *
 * NOTES :   
 *F*/
inline Vector3d Vector3d::crossProduct(const Vector3d &vec2) {

  return (Vector3d(y*vec2.z-z*vec2.y,
		   x*vec2.z-z*vec2.x,
		   x*vec2.y-y*vec2.x));
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : Performs Pythagorus theorom on the vector
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline float Vector3d::length() {
  return sqrt(x * x + y * y + z * z);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::normalize() {

  float len = length();

  //protect against divide by zero
  if(len != 0) {
    x/=len;
    y/=len;
    z/=len;
  }
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::change(float a, float b, float c) {

  x = a;
  y = b;
  z = c;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::change(Vector3d &vec2) {

  x = vec2.x;
  y = vec2.y;
  z = vec2.z;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::change(Vector3d vec2) {

  x = vec2.x;
  y = vec2.y;
  z = vec2.z;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::changeX(float a) {
  x = a;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::changeY(float a) {
  y = a;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
inline void Vector3d::changeZ(float a) {
  z = a;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d Vector3d::operator+(const Vector3d &vec2) {

  return Vector3d(x + vec2.x, y + vec2.y, z + vec2.z);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d Vector3d::operator-(const Vector3d &vec2) {

  return Vector3d(x - vec2.x, y - vec2.y, z - vec2.z);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d Vector3d::operator*(float num) {

  return Vector3d(x * num, y * num, z * num);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d Vector3d::operator/(float num) {

  if(num != 0) {
    return Vector3d(x / num, y / num, z / num);
  }
  return Vector3d();
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d& Vector3d::operator+=(const Vector3d &vec2) {

  x += vec2.x;
  y += vec2.y;
  z += vec2.z;
  return *this;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d& Vector3d::operator-=(const Vector3d &vec2) {

  x -= vec2.x;
  y -= vec2.y;
  z -= vec2.z;
  return *this;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d& Vector3d::operator*=(float num) {

  x *= num;
  y *= num;
  z *= num;
  return *this;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
Vector3d& Vector3d::operator/=(float num) {

  if(num != 0) {
    x /= num;
    y /= num;
    z /= num;
  }
  return *this;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
bool Vector3d::operator==(const Vector3d vec2) {

  return (x == vec2.x &&
	  y == vec2.y &&
	  z == vec2.z);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
bool Vector3d::operator!=(const Vector3d vec2) {

  return !(*this == vec2);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *           
 *           
 * RETURN :  
 *
 * NOTES :   
 *F*/
std::ostream& operator <<(std::ostream &out, const Vector3d &vec) {

  out << vec.x << ' ' << vec.y << ' ' << vec.z;
  return out;
}

