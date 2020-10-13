#ifndef VEC3_H
#define VEC3_H

class Vec3
{

public:

	//Vec3();
	Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	~Vec3();

	Vec3 operator + (const Vec3& vec);
	Vec3 operator += (const Vec3& vec);
	Vec3 operator - (const Vec3& vec);
	Vec3 operator -= (const Vec3& vec);
	Vec3 operator * (const Vec3& vec);
	Vec3 operator *= (const Vec3& vec);
	Vec3 operator * (const float& scalar);
	Vec3 operator *= (const float& scalar);


	const float& GetX()const;
	const float& GetY()const;
	const float& GetZ()const;

	void Set(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	void SetZ(float x);
	void SetX(float y);
	void SetY (float z);


private:

	float m_x{ 0.0f };
	float m_y{ 0.0f };
	float m_z{ 0.0f };

};

#endif