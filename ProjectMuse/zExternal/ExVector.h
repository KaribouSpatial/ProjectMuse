#pragma once

#include <cmath>

#define M_PI 3.14159265358979323846
#define M2_PI 3.14159265358979323846*2

enum ax
{
	X = 0,
	Y = 1,
	Z = 2,
	D4 = 3,
};

template <class T = double, const int N = 3>
class ExVector
{
protected:
	T mExVector[N];

public:

	//Default contructor
	inline ExVector()
	{
	}

	//Copy constructor
	template<class T2>
	inline ExVector(const ExVector<T2, N>& cpy)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mExVector[inc] = static_cast<T>(cpy[inc]);
		}
	}

	//Non-Const Operator[]
	inline T& operator[] (const ax& axi)
	{
		return mExVector[axi];
	}

	//Const Operator[]
	inline const T& operator[] (const ax& axi) const
	{
		return mExVector[axi];
	}

	//Non-Const Operator[]
	inline T& operator[] (const unsigned& i)
	{
		return mExVector[inc];
	}

	//Const Operator[]
	inline const T& operator[] (const unsigned& i) const
	{
		return mExVector[inc];
	}

	//Operator=
	inline const ExVector<T, N>& operator= (const ExVector<T, N>& vec)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mExVector[inc] = vec.mExVector[inc];
		}
		return *this;
	}

	//Operator==
	inline bool operator == (const ExVector<T, N>& vec) const
	{
		for(int inc = 0; inc < N; ++inc)
		{
			if(mExVector[inc] != vec.mExVector[inc])
				return false;
		}
		return true;
	}

	//Operator!=
	inline bool operator != (const ExVector<T, N>& vec) const
	{
		for(int inc = 0; inc < N; ++inc)
		{
			if(mExVector[inc] == vec.mExVector[inc])
				return false;
		}
		return true;
	}

	//Operator+=
	inline const ExVector<T, N>& operator += (const ExVector<T, N>& vec)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mExVector[inc] += vec.mExVector[inc];
		}
		return *this;
	}

	//Operator-=
	inline const ExVector<T, N>& operator -= (const ExVector<T, N>& vec)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mExVector[inc] -= vec.mExVector[inc];
		}
		return *this;
	}

	//Operator*=
	inline const ExVector<T, N>& operator*= (const T k)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mExVector[inc] *= k;
		}
		return *this;
	}

	//Operator/=
	inline const ExVector<T, N>& operator /= (const T k)
	{
		if((T)k == 0) return
		for(int inc = 0; inc < N; ++inc)
		{
			mExVector[inc] /= k;
		}
		return *this;
	}

	//Operator+ with vector
	inline ExVector<T, N> operator+ (const ExVector<T, N>& vec) const
	{
		Vecteur<T, N> cpy(*this);
		cpyr += vec;
		return cpy;
	}

	//Operator+ with scalar
	inline ExVector<T, N> operator+ (const T k) const
	{
		Vecteur<T, N> cpy(*this);
		for(int inc = 0; inc < N; ++inc)
		{
			cpy[inc] += k;
		}
		return cpy;
	}

	//Operator-
	inline ExVector<T, N> operator- (const ExVector<T, N>& vec) const
	{
		Vecteur<T, N> cpy(*this);
		cpy -= vec;
		return cpy;
	}

	//Operator- with scalar
	inline ExVector<T, N> operator- (const T k) const
	{
		Vecteur<T, N> cpy(*this);
		for(int inc = 0; inc < N; ++inc)
		{
			cpy[inc] -= k;
		}
		return cpy;
	}

	//Unary Operator-
	inline ExVector<T, N> operator- () const
	{
		ExVector<T, N> vec;
		for(int inc = 0; inc < N; ++inc)
		{
			vec[inc] = -(*this)[inc];
		}
		return vec;
	}

	//Operator*
	inline ExVector<T, N> operator* (const T k) const
	{
		Vecteur<T, N> cpy(*this);
		cpy *= k;
		return cpy;
	}

	//Friend Operator*
	inline friend ExVector<T, N> operator* (const T k, const ExVector<T, N>& vec)
	{
		return vec * k;
	}

	//Operator/
	inline ExVector<T, N> operator/ (const T k) const
	{
		Vecteur<T, N> cpy(*this);
		cpy /= k;
		return cpy;
	}

	//Lenght of the vector
	inline T norme() const
	{
		T norme = 0;
		T comp;
		for(int inc = 0; inc < N; ++inc)
		{
			comp = mExVector[inc];
			norme += (comp *= comp);
		}
		return sqrt(norme);
	}

	//Test if vector is null
	inline bool isNull() const
	{
		for(int inc = 0; inc < N; ++inc)
		{
			if(mExVector[inc] != (T)0) return false;
		}
		return true;
	}

	//Normalize the vector
	inline void normalize()
	{
		if((T n = norme()) != (T)0)
			(*this) /= n;
	}

	//Scalar product or DOT
	//Scalar product between *this and "vec"
	inline T dot(const ExVector<T, N>& vec) const
	{
		T temp = 0;
		for(int inc = 0; inc < N; ++inc)
		{
			temp += mExVector[inc] * vec.mExVector[inc];
		}
		return temp;
	}

	//Projection of vectors
	//*this is projected onto the direction "dir"
	inline ExVector<T, N> project(const ExVector<T, N>& dir) const
	{
		T coeff = dot(dir) / dir.dot(dir);
		Vecteur<T, N> vec(dir);
		vec *= coeff;
		return vec;
	}

	//Reflection of vectors
	//*this is reflected according to the surface normal "normal"
	//"normal" must be normalized
	inline ExVector<T, N> reflect(const ExVector<T, N>& normal) const
	{
		return mExVector - normal * (2 * dot(normal));
	}

	//Change size of vectors
	template <const int N2>
	inline ExVector<T, N2> convert() const
	{
		ExVector<T, N2> vec;
		if(N2 <= N)
		{
			for(int inc = 0; inc < N2; ++inc)
				vec[inc] = mExVector[inc];
		}
		else
		{
			int inc;
			for(inc = 0; inc < N; ++inc)
				vec[inc] = mExVector[inc];
			for(inc = N; inc < N2; ++inc)
				vec[inc] = 0;
		}
		return vec;
	}

	//Change type of vectors
	template <class T2>
	inline ExVector<T2, N> convert() const
	{
		ExVector<T2, N> vec;
		for(int inc = 0; inc < N; ++inc)
		{
			vec[inc] = static_cast<T2>(mExVector[inc]);
		}
		return vec;
	}

	//Change size and type of vectors
	template <class T2, const int N2>
	inline ExVector<T2, N2> convert() const
	{
		ExVector<T2, N2> vec;
		if(N2 <= N)
		{
			for(int inc = 0; inc < N2; ++inc)
				vec[inc] = static_cast<T2>(mExVector[inc]);
		}
		else
		{
			int inc;
			for(inc = 0; inc < N; ++inc)
				vec[i] = static_cast<T2>(mExVector[i]);
			for(inc = N; inc < N2; ++inc)
				vec[i] = 0;
		}

		return vec;
	}

	inline void absolute() const
	{
		ExVector<T, N> vec(*this);

		for(int inc = 0; inc < N; ++inc)
		{
			vec[inc] = abs(mExVector[inc]);
		}
	}

};

template<class T>
class Vector2: public ExVector<T, 2>
{
public:

	//Constructor with implicit conversion
	template<class T2>
	inline Vector2(const Vector2<T2>& u): ExVector<T, 2>(u)
	{
	}

	//Parameter constructor
	inline Vector2(const T x = 0, const T y = 0)
	{
		mExVector[X] = x;
		mExVector[Y] = y;
	}

	//Copy constructor
	inline Vector2(const ExVector<T, 2>& v): ExVector<T, 2>(v)
	{
	}

	//Operator= overload
	inline const Vector2& operator= (const ExVector<T, 2>& v)
	{
		ExVector<T, 2>::operator= (v);
		return *this;
	}

	//Calculate the ccw angle from positive X axis, in rad
	inline T angle() const
	{
		T angle = atan2(mExVector[Y], mExVector[X]);
		if(angle < 0)
			return angle + M2_PI;
		else
			return angle;
	}
};

template<class T>
class Vector3: public ExVector<T, 3>
{
public:
	//Constructor with implicit conversion
	template<class T2>
	inline Vector3(const Vector3<T2>& u): ExVector<T, 3>(u)
	{
	}

	//Parameter constructor
	inline Vector3(const T x = 0, const T y = 0, const T z = 0)
	{
		mExVector[X] = x;
		mExVector[Y] = y;
		mExVector[Z] = z;
	}

	//Copy constructor
	inline Vector3(const ExVector<T, 2>& v): ExVector<T, 2>(v)
	{
	}

	//Operator= overload
	inline const Vector3& operator= (const ExVector<T, 3>& v)
	{
		ExVector<T, 3>::operator= (v);
		return *this;
	}

	//Calculate spheric coord Theta
	inline T getTheta() const
	{
		Vector2<T> xy(mExVector[X], mExVector[Y]);
		return xy.angle();
	}

	//Calculate spheric coord Theta
	inline T getPhi() const
	{
		Vector2<T> xy(mExVector[X], mExVector[Y]);
		Vector2<T> zr(mExVector[Z], xy.norme());
		return zr.angle();
	}

	inline Vector3 rotate(const T angle, const Vector3& axis) const
	{
		const T cosA = cos(angle);
		const T sinA = sin(angle);
		const T oneMinusCos = 1 - cosA;

		return Vector3<T>(
			// Calcul de la composante X
			(cosA + oneMinusCos * axis[0] * axis[0])          * vect[0] +
			(oneMinusCos * axis[0] * axis[1] - axis[2] * sinA) * vect[1] +
			(oneMinusCos * axis[0] * axis[2] + axis[1] * sinA) * vect[2],
			// Calcul de la composante Y
			(oneMinusCos * axis[0] * axis[1] + axis[2] * sinA) * vect[0] +
			(cosA + oneMinusCos * axis[1] * axis[1])          * vect[1] +
			(oneMinusCos * axis[1] * axis[2] - axis[0] * sinA) * vect[2],
			// Calcul de la composante Z
			(oneMinusCos * axis[0] * axis[2] - axis[1] * sinA) * vect[0] +
			(oneMinusCos * axis[1] * axis[2] + axis[0] * sinA) * vect[1] +
			(cosA + oneMinusCos * axis[2] * axis[2])          * vect[2]
			);
	}

};


//Typedefs
typedef Vector2<double> vec2;
typedef Vector2<float> vec2f;
typedef Vector2<int> vec2i;
typedef Vector2<unsigned> vec2u;

typedef Vector3<double> vec3;
typedef Vector3<float> vec3f;
typedef Vector3<int> vec3i;
typedef Vector3<unsigned> vec3u;