#include "Vec3.h"

//Vec3::Vec3()
//{
//   m_x = m_y = m_z = 0.0f;
//}

Vec3::Vec3(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

Vec3::~Vec3()
{

}

Vec3 Vec3::operator+(const Vec3& vec)
{
    Vec3 temp = *this;


    this->m_x += vec.m_x;
    this->m_y += vec.m_y;
    this->m_z += vec.m_z;

    return temp;

}

Vec3 Vec3::operator+=(const Vec3& vec)
{
    this->m_x += vec.m_x;
    this->m_y += vec.m_y;
    this->m_z += vec.m_z;

    return *this;
}

Vec3 Vec3::operator-(const Vec3& vec)
{
    Vec3 temp = *this;


    this->m_x -= vec.m_x;
    this->m_y -= vec.m_y;
    this->m_z -= vec.m_z;

    return temp;
}

Vec3 Vec3::operator-=(const Vec3& vec)
{
    this->m_x -= vec.m_x;
    this->m_y -= vec.m_y;
    this->m_z -= vec.m_z;

    return *this;
}


Vec3 Vec3::operator*(const Vec3& vec)
{
    Vec3 temp = *this;


    this->m_x *= vec.m_x;
    this->m_y *= vec.m_y;
    this->m_z *= vec.m_z;

    return temp;
}

Vec3 Vec3::operator*=(const Vec3& vec)
{
    this->m_x *= vec.m_x;
    this->m_y *= vec.m_y;
    this->m_z *= vec.m_z;

    return *this;
}

Vec3 Vec3::operator*(const float& scalar)
{
    Vec3 temp = *this;


    this->m_x *= scalar;
    this->m_y *= scalar;
    this->m_z *= scalar;

    return temp;
}

Vec3 Vec3::operator*=(const float& scalar)
{
    this->m_x *= scalar;
    this->m_y *= scalar;
    this->m_z *= scalar;

    return *this;
}

const float& Vec3::GetX() const
{
    return m_x;
}

const float& Vec3::GetY() const
{
    return m_y;
}

const float& Vec3::GetZ() const
{
    return m_z;
}

void Vec3::Set(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

void Vec3::SetZ(float x)
{
    m_x = x;
}

void Vec3::SetX(float y)
{
    m_y = y;
}

void Vec3::SetY(float z)
{
    m_z = z;
}