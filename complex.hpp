/*
 * complex.hpp
 *
 *  Created on: May 5, 2017
 *      Author: Mohammad Reza Mozaffari
 */

#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <iostream>
#include <stdio.h>
#include <cmath>

class Complex
{
public:
	Complex ();
	Complex (double, double);
	Complex (const Complex&);
	~Complex ();

	double get_RealPart ();
	double get_ImagPart ();
	Complex conjugate ();
	Complex conjugate (const Complex&);
	double norm ();
	double norm (const Complex&);
	double argument ();
	double argument (const Complex&);
	Complex power (const int);
	Complex power (const Complex&, const int);
	Complex power (const double);
	Complex power (const Complex&, const double);

	friend Complex exp (const Complex&);	

	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const double);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const double);
	Complex& operator/=(const Complex&);

	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const double);
	friend Complex operator*(const double, const Complex&);
	friend Complex operator/(const Complex&, const double);
	friend Complex operator/(const double, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	void print ();

private:
	double x, y;
};

Complex::Complex ()
{
	x = y = 0.0;
}

Complex::Complex (double _x, double _y)
{
	x = _x; y = _y;
}

Complex::Complex (const Complex& other)
{
	x = other.x; y = other.y;
}

Complex::~Complex()
{

}

double Complex::get_RealPart ()
{
	return x;
}

double Complex::get_ImagPart ()
{
	return y;
}

double Complex::norm ()
{
	return sqrt(x*x + y*y);
}

double Complex::norm (const Complex& other)
{
	return sqrt(other.x*other.x + other.y*other.y);
}

double Complex::argument ()
{
	return atan2(y, x);
}

double Complex::argument (const Complex& other)
{
	return atan2(other.y, other.x);
}

Complex Complex::conjugate ()
{
	x = x;
	y =-y;
	return *this;
}

Complex Complex::conjugate (const Complex& other)
{
	Complex z(other.x,-other.y);
	return z;
}

Complex Complex::power (const int n)
{
	double _norm = norm ();
	double _arg = argument ();
	x = pow (_norm, n)*cos(n*_arg);
	y = pow (_norm, n)*sin(n*_arg);
	return * this;
}

Complex Complex::power (const Complex& other, const int n)
{
	double _norm = norm (other);
	double _arg = argument (other);
	double _x = pow (_norm, n)*cos(n*_arg);
	double _y = pow (_norm, n)*sin(n*_arg);
	Complex z(_x, _y);
	return z;
}

Complex Complex::power (const double alpha)
{
	double _norm = norm ();
	double _arg = argument ();
	x = pow (_norm, alpha)*cos(alpha*_arg);
	y = pow (_norm, alpha)*sin(alpha*_arg);
	return * this;
}

Complex Complex::power (const Complex& other, const double alpha)
{
	double _norm = norm (other);
	double _arg = argument (other);
	double _x = pow (_norm, alpha)*cos(alpha*_arg);
	double _y = pow (_norm, alpha)*sin(alpha*_arg);
	Complex z(_x, _y);
	return z;
}

Complex& Complex::operator=(const Complex& other)
{
	x = other.x; y = other.y;
	return *this;
}

Complex& Complex::operator+=(const Complex& other)
{
	x = x + other.x;
	y = y + other.y;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	x = x - other.x;
	y = y - other.y;
	return *this;
}

Complex& Complex::operator*=(const double scale)
{
	x = x*scale;
	y = y*scale;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	double _x = x*other.x - y*other.y;
	double _y = x*other.y + y*other.x;
	x = _x; y = _y;
	return *this;
}

Complex& Complex::operator/=(const double scale)
{
	x = x/scale;
	y = y/scale;
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	double _norm = sqrt(other.x*other.x + other.y*other.y);
	double _x = (x*other.x + y*other.y)/_norm;
	double _y = (y*other.x - x*other.y)/_norm;
	x = _x; y = _y;
	return *this;
}

Complex operator+(const Complex& z1, const Complex& z2)
{
	Complex z(z1);
	return z+=z2;
}

Complex operator-(const Complex& z1, const Complex& z2)
{
	Complex z(z1);
	return z-=z2;
}

Complex operator*(const Complex& z1, const double scale)
{
	Complex z(z1);
	return z*=scale;
}

Complex operator*(const double scale, const Complex& z1)
{
	Complex z(z1);
	return z*=scale;
}

Complex operator/(const Complex& z1, const double scale)
{
	Complex z(z1);
	return z/=scale;
}

Complex operator/(const double scale, const Complex& z1)
{
	double _norm = sqrt(z1.x*z1.x + z1.y*z1.y);
	double _x = z1.x/_norm;
	double _y =-z1.y/_norm;

	Complex z(_x, _y);
	return z*=scale;
}

Complex operator*(const Complex& z1, const Complex& z2)
{
	Complex z(z1);
	return z*=z2;
}

Complex operator/(const Complex& z1, const Complex& z2)
{
	double _norm = sqrt(z2.x*z2.x + z2.y*z2.y);
	double _x = z2.x/_norm;
	double _y =-z2.y/_norm;

	Complex z(_x, _y);
	return z*=z1;
}

Complex exp (const Complex& z)
{
	double _x = exp(z.x)*cos(z.y);
	double _y = exp(z.x)*sin(z.y);
	Complex w(_x, _y);
	return w;
}

void Complex::print ()
{
	printf("(%.8f,", x);
	printf(" %.8f)\n", y);
}

#endif /* COMPLEX_HPP_ */

