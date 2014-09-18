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
class Vector
{
protected:
	T mVector[N];

public:

	//Default contructor
	inline Vector()
	{
	}

	//Copy constructor
	template<class T2>
	inline Vector(const Vector<T2, N>& cpy)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mVector[inc] = static_cast<T>(cpy[inc]);
		}
	}

	//Non-Const Operator[]
	inline T& operator[] (const ax& axi)
	{
		return mVector[axi];
	}

	//Const Operator[]
	inline const T& operator[] (const ax& axi) const
	{
		return mVector[axi];
	}

	//Non-Const Operator[]
	inline T& operator[] (const unsigned& i)
	{
		return mVector[i];
	}

	//Const Operator[]
	inline const T& operator[] (const unsigned& i) const
	{
		return mVector[i];
	}

	//Operator=
	inline const Vector<T, N>& operator= (const Vector<T, N>& vec)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mVector[inc] = vec.mVector[inc];
		}
		return *this;
	}

	//Operator==
	inline bool operator == (const Vector<T, N>& vec) const
	{
		for(int inc = 0; inc < N; ++inc)
		{
			if(mVector[inc] != vec.mVector[inc])
				return false;
		}
		return true;
	}

	//Operator!=
	inline bool operator != (const Vector<T, N>& vec) const
	{
		for(int inc = 0; inc < N; ++inc)
		{
			if(mVector[inc] == vec.mVector[inc])
				return false;
		}
		return true;
	}

	//Operator+=
	inline const Vector<T, N>& operator += (const Vector<T, N>& vec)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mVector[inc] += vec.mVector[inc];
		}
		return *this;
	}

	//Operator-=
	inline const Vector<T, N>& operator -= (const Vector<T, N>& vec)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mVector[inc] -= vec.mVector[inc];
		}
		return *this;
	}

	//Operator*=
	inline const Vector<T, N>& operator*= (const T k)
	{
		for(int inc = 0; inc < N; ++inc)
		{
			mVector[inc] *= k;
		}
		return *this;
	}

	//Operator/=
	inline const Vector<T, N>& operator/= (const T k)
	{
		if((T)k == 0) return Vector<T, N>();
		for(int inc = 0; inc < N; ++inc)
		{
			mVector[inc] /= k;
		}
		return *this;
	}

	//Operator+ with vector
	inline Vector<T, N> operator+ (const Vector<T, N>& vec) const
	{
		Vector<T, N> cpy(*this);
		cpyr += vec;
		return cpy;
	}

	//Operator+ with scalar
	inline Vector<T, N> operator+ (const T k) const
	{
		Vector<T, N> cpy(*this);
		for(int inc = 0; inc < N; ++inc)
		{
			cpy[inc] += k;
		}
		return cpy;
	}

	//Operator-
	inline Vector<T, N> operator- (const Vector<T, N>& vec) const
	{
		Vector<T, N> cpy(*this);
		cpy -= vec;
		return cpy;
	}

	//Operator- with scalar
	inline Vector<T, N> operator- (const T k) const
	{
		Vector<T, N> cpy(*this);
		for(int inc = 0; inc < N; ++inc)
		{
			cpy[inc] -= k;
		}
		return cpy;
	}

	//Unary Operator-
	inline Vector<T, N> operator- () const
	{
		Vector<T, N> vec;
		for(int inc = 0; inc < N; ++inc)
		{
			vec[inc] = -(*this)[inc];
		}
		return vec;
	}

	//Operator*
	inline Vector<T, N> operator* (const T k) const
	{
		Vector<T, N> cpy(*this);
		cpy *= k;
		return cpy;
	}

	//Friend Operator*
	inline friend Vector<T, N> operator* (const T k, const Vector<T, N>& vec)
	{
		return vec * k;
	}

	//Operator/
	inline Vector<T, N> operator/ (const T k) const
	{
		Vector<T, N> cpy(*this);
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
			comp = mVector[inc];
			norme += (comp *= comp);
		}
		return sqrt(norme);
	}

	//Test if vector is null
	inline bool isNull() const
	{
		for(int inc = 0; inc < N; ++inc)
		{
			if(mVector[inc] != (T)0) return false;
		}
		return true;
	}

	//Normalize the vector
	inline void normalize()
	{
		T n = norme();
		if(n != (T)0)
			(*this) /= n;
	}

	//Scalar product or DOT
	//Scalar product between *this and "vec"
	inline T dot(const Vector<T, N>& vec) const
	{
		T temp = 0;
		for(int inc = 0; inc < N; ++inc)
		{
			temp += mVector[inc] * vec.mVector[inc];
		}
		return temp;
	}

	//Projection of vectors
	//*this is projected onto the direction "dir"
	inline Vector<T, N> project(const Vector<T, N>& dir) const
	{
		T coeff = dot(dir) / dir.dot(dir);
		Vector<T, N> vec(dir);
		vec *= coeff;
		return vec;
	}

	//Reflection of vectors
	//*this is reflected according to the surface normal "normal"
	//"normal" must be normalized
	inline Vector<T, N> reflect(const Vector<T, N>& normal) const
	{
		return mVector - normal * (2 * dot(normal));
	}

	//Change size of vectors
	template <const int N2>
	inline Vector<T, N2> convert() const
	{
		ExVector<T, N2> vec;
		if(N2 <= N)
		{
			for(int inc = 0; inc < N2; ++inc)
				vec[inc] = mVector[inc];
		}
		else
		{
			int inc;
			for(inc = 0; inc < N; ++inc)
				vec[inc] = mVector[inc];
			for(inc = N; inc < N2; ++inc)
				vec[inc] = 0;
		}
		return vec;
	}

	//Change type of vectors
	template <class T2>
	inline Vector<T2, N> convert() const
	{
		ExVector<T2, N> vec;
		for(int inc = 0; inc < N; ++inc)
		{
			vec[inc] = static_cast<T2>(mVector[inc]);
		}
		return vec;
	}

	//Change size and type of vectors
	template <class T2, const int N2>
	inline Vector<T2, N2> convert() const
	{
		ExVector<T2, N2> vec;
		if(N2 <= N)
		{
			for(int inc = 0; inc < N2; ++inc)
				vec[inc] = static_cast<T2>(mVector[inc]);
		}
		else
		{
			int inc;
			for(inc = 0; inc < N; ++inc)
				vec[i] = static_cast<T2>(mVector[i]);
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
			vec[inc] = abs(mVector[inc]);
		}
	}

};

template<class T>
class Vector2: public Vector<T, 2>
{
public:

	//Constructor with implicit conversion
	template<class T2>
	inline Vector2(const Vector2<T2>& u): Vector<T, 2>(u)
	{
	}

	//Parameter constructor
	inline Vector2(const T x = 0, const T y = 0)
	{
		mVector[X] = x;
		mVector[Y] = y;
	}

	//Copy constructor
	inline Vector2(const Vector<T, 2>& v): Vector<T, 2>(v)
	{
	}

	//Operator= overload
	inline const Vector2& operator= (const Vector<T, 2>& v)
	{
		ExVector<T, 2>::operator= (v);
		return *this;
	}

	//Calculate the ccw angle from positive X axis, in rad
	inline T angle() const
	{
		T angle = atan2(mVector[Y], mVector[X]);
		if(angle < 0)
			return angle + M2_PI;
		else
			return angle;
	}
};

template<class T>
class Vector3: public Vector<T, 3>
{
public:
	//Constructor with implicit conversion
	template<class T2>
	inline Vector3(const Vector3<T2>& u): Vector<T, 3>(u)
	{
	}

	//Parameter constructor
	inline Vector3(const T x = 0, const T y = 0, const T z = 0)
	{
		mVector[X] = x;
		mVector[Y] = y;
		mVector[Z] = z;
	}

	//Copy constructor
	inline Vector3(const Vector<T, 2>& v): Vector<T, 2>(v)
	{
	}

	//Operator+ with vector3
	inline Vector3<T> operator+ (const Vector3<T>& vec) const
	{
		Vector3<T> cpy(*this);
		cpy += vec;
		return cpy;
	}

	//Operator+ with vector3
	inline Vector3<T> operator- (const Vector3<T>& vec) const
	{
		Vector3<T> cpy(*this);
		cpyr -= vec;
		return cpy;
	}

	//Operator= overload
	inline const Vector3& operator= (const Vector<T, 3>& v)
	{
		ExVector<T, 3>::operator= (v);
		return *this;
	}

	//Calculate spheric coord Theta
	inline T getTheta() const
	{
		Vector2<T> xy(mVector[X], mVector[Y]);
		return xy.angle();
	}

	//Calculate spheric coord Theta
	inline T getPhi() const
	{
		Vector2<T> xy(mVector[X], mVector[Y]);
		Vector2<T> zr(mVector[Z], xy.norme());
		return zr.angle();
	}

	//Rotate the vector, angle in rad
	inline Vector3 rotate(const T angle, Vector3 axis) const
	{
		const T cosA = std::cos(angle);
		const T sinA = std::sin(angle);
		const T oneMinusCos = 1 - cosA;

		axis.normalize();

		Vector3<T> vec(
			// Calcul de la composante X
			(cosA + oneMinusCos * axis[X] * axis[X])          * mVector[X] +
			(oneMinusCos * axis[X] * axis[Y] - axis[Z] * sinA) * mVector[Y] +
			(oneMinusCos * axis[X] * axis[Z] + axis[Y] * sinA) * mVector[Z],
			// Calcul de la composante Y
			(oneMinusCos * axis[X] * axis[Y] + axis[Z] * sinA) * mVector[X] +
			(cosA + oneMinusCos * axis[Y] * axis[Y])          * mVector[Y] +
			(oneMinusCos * axis[Y] * axis[Z] - axis[X] * sinA) * mVector[Z],
			// Calcul de la composante Z
			(oneMinusCos * axis[X] * axis[Z] - axis[Y] * sinA) * mVector[X] +
			(oneMinusCos * axis[Y] * axis[Z] + axis[X] * sinA) * mVector[Y] +
			(cosA + oneMinusCos * axis[Z] * axis[Z])          * mVector[Z]
			);
		return vec;
	}

	//Set coordinates
	inline void setSphericCoord(const T r, const T theta, const T phi)
	{
		// Calcul de la position à partir des coordonnées sphériques
		mVector[X] = r * std::sin(phi) * std::cos(theta);
		mVector[Z] = r * std::sin(phi) * std::sin(theta);
		mVector[Y] = r * std::cos(phi);

	}

	inline Vector3 cross(const Vector3& B)
	{
		return Vector3(
			(*this)[Y] * B[Z] - (*this)[Z] * B[Y],
			(*this)[Z] * B[X] - (*this)[X] * B[Z],
			(*this)[X] * B[Y] - (*this)[Y] * B[X]
			);
	}

	inline friend Vector3 cross(const Vector3& A, const Vector3& B)
	{
		return Vector3(
			A[Y] * B[Z] - A[Z] * B[Y],
			A[Z] * B[X] - A[X] * B[Z],
			A[X] * B[Y] - A[Y] * B[X]
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