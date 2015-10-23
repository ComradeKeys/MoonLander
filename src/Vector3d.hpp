#pragma once
/*H***********************************************************
 * FILENAME :        Vector3d.hpp
 *
 * DESCRIPTION : Simple class that represents a point in 3D
 *       space
 *
 * PUBLIC FUNCTIONS :
 *       
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    07/23/2015
 *
 *H*/
#include <iostream>
#include <cmath>

class Vector3d {

public:
  float x;
  float y;
  float z;
  Vector3d();
  Vector3d(float a, float b);
  Vector3d(float a, float b, float c);

  float dotProduct(const Vector3d &vec2);
  Vector3d crossProduct(const Vector3d &vec2);
  float length();
  void normalize();

  void change(float a, float b, float c);
  void change(Vector3d &vec2);
  void change(Vector3d  vec2);
  void changeX(float a);
  void changeY(float a);
  void changeZ(float a);

  Vector3d operator+(const Vector3d &vec2);
  Vector3d operator-(const Vector3d &vec2);
  Vector3d operator*(float num);
  Vector3d operator/(float num);

  Vector3d &operator+=(const Vector3d &vec2);
  Vector3d &operator-=(const Vector3d &vec2);
  Vector3d &operator*=(float num);
  Vector3d &operator/=(float num);

  bool operator==(const Vector3d vec2);
  bool operator!=(const Vector3d vec2);
};
  std::ostream &operator <<(std::ostream &out,
				   const Vector3d &vec);
