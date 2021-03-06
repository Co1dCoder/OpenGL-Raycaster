/**************************************************************
 * functions to handle vectors and points
 **************************************************************/
#include "vector.h"
#include <math.h>
#include <cstdlib>

//
// return length of a vector
//
float vec_len(Vector u) {
  return sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
}

//
// return doc product of two vectors
//
float vec_dot(Vector p, Vector q) {
  return p.x * q.x + p.y * q.y + p.z * q.z;
}

//
// return sum of two vectors
//
Vector vec_plus(Vector p, Vector q) {
  Vector rc;
  rc.x = p.x + q.x;
  rc.y = p.y + q.y;
  rc.z = p.z + q.z;

  return rc;
}

//
// return difference between two vectors
//
Vector vec_minus(Vector p, Vector q) {
  Vector rc;
  rc.x = p.x - q.x;
  rc.y = p.y - q.y;
  rc.z = p.z - q.z;

  return rc;
}

//
// reflect vector p based on normalized vector n
//
Vector vec_reflect(Vector p, Vector n) {
  Vector rc;

  p.x = -(p.x);
  p.y = -(p.y);
  p.z = -(p.z);
  
  normalize(&n);
  rc = vec_minus(p ,vec_scale(n, (float)(2*(vec_dot(p, n)))));

  return rc;
}

//
// make vector p opposite
//
Vector vec_opposite(Vector p) {
  Vector rc;

  rc.x = -(p.x);
  rc.y = -(p.y);
  rc.z = -(p.z);

  return rc;
}

//
// make random reflected vector based on a normal
//
Vector vec_random(Vector p) {
  Vector rc;
  float LO = -1.0;
  float HI = 1.0;
  rc = vec_opposite(p);
  while (vec_dot(rc, p) < 0) {
    rc.x = LO + (float) (rand()) /( (float) (RAND_MAX/(HI-LO)));
    rc.y = LO + (float) (rand()) /( (float) (RAND_MAX/(HI-LO)));
    rc.z = LO + (float) (rand()) /( (float) (RAND_MAX/(HI-LO)));
  }
  normalize(&rc);
  return rc;
}
//
// return vector from point point to another
//
Vector get_vec(Point q, Point p) {
  Vector rc;
  rc.x = p.x - q.x;
  rc.y = p.y - q.y;
  rc.z = p.z - q.z;

  return rc;
}

//
// return point from a point and a vector
// 
Point get_point(Point p, Vector q) {
  Point rc;
  rc.x = p.x + q.x;
  rc.y = p.y + q.y;
  rc.z = p.z + q.z;

  return rc;
}

//
// Shift point in direction of v
//
Point shift_point(Point p, Vector v) {
    float epsilon = 1e-4;
    normalize(&v);
    return get_point(p, vec_scale(v,epsilon));
}

//
// return whether points are equal
// 
bool equal_points(Point p, Point q) {
  if (p.x == q.x && p.y == q.y && p.z == q.z) return true;
  else return false;
}

//
// normalize a vector
//
void normalize(Vector *u) {
  float p;

  p = vec_len(*u);
  (*u).x = (*u).x / p;
  (*u).y = (*u).y / p;
  (*u).z = (*u).z / p;
}

//
// return a scaled vector
//
Vector vec_scale(Vector p, float scale) {
  Vector ret;

  ret.x = scale * p.x;
  ret.y = scale * p.y;
  ret.z = scale * p.z;

  return ret;
}

//
// add two RGB colors
//
RGB_float clr_add(RGB_float p, RGB_float q) {
  RGB_float ret;

  ret.r = p.r + q.r;
  ret.g = p.g + q.g;
  ret.b = p.b + q.b;

  return ret;
}

// apply scalar to color
RGB_float clr_scale(RGB_float p, float s) {
  RGB_float ret;

  ret.r = s * p.r;
  ret.g = s * p.g;
  ret.b = s * p.b;

  return ret;
}

// multiply two colors
RGB_float clr_times(RGB_float p, RGB_float q) {
  RGB_float ret;

  ret.r = p.r * q.r;
  ret.g = p.g * q.g;
  ret.b = p.b * q.b;

  return ret;
}