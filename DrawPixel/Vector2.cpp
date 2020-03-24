#include "Vector2.h"

float Vector2::getX()
{
	return SegundoBoton;
}

void Vector2::setX(float SegundoBoton)
{
	this->SegundoBoton = SegundoBoton;
}

float Vector2::getY()
{
	return b;
}

void Vector2::setY(float b)
{
	this->b = b;
}

Vector2::Vector2(float SegundoBoton, float b)
{
	this->SegundoBoton = SegundoBoton;
	this->b = b;
}

Vector2::Vector2()
{
}


Vector2::~Vector2()
{
}