#ifndef _COMPLEX_
#define _COMPLEX_

#include <cmath>
#include <iostream>

class Complex
{
private:
	double real, imag;
	double abs, arg;
public:
	Complex()
	{
		real = 0.0;
		imag = 0.0;
		abs = std::sqrtl(real * real + imag * imag);
		arg = std::atanl(imag / real);
	}
	Complex(double real)
	{
		this->real = real;
		imag = 0.0;
		abs = std::sqrtl(real * real + imag * imag);
		arg = std::atanl(imag / real);
	}
	Complex(double real, double imag)
	{
		this->real = real;
		this->imag = imag;
		abs = std::sqrtl(real * real + imag * imag);
		arg = std::atanl(imag / real);
	}
	//
	void setreal(double a)
	{
		this->real = a;
		abs = std::sqrtl(real * real + imag * imag);
		arg = std::atanl(imag / real);
	}
	double getreal()
	{
		return this->real;
	}
	void setimag(double b)
	{
		this->imag = b;
		abs = std::sqrtl(real * real + imag * imag);
		arg = std::atanl(imag / real);
	}
	double getimag()
	{
		return this->imag;
	}
	//
	void setAbs(double c)
	{
		this->abs = c;
		real = abs * std::cos(arg);
		imag = abs * std::sin(arg);
	}
	double getAbs()
	{
		abs = std::sqrtl(real * real + imag * imag);
		return abs;
	}
	void setArg(double d)
	{
		this->arg = d;
		real = abs * std::cos(arg);
		imag = abs * std::sin(arg);
	}
	double getArg()
	{
		arg = std::atanl(imag / real);
		return arg;
	}
	//
	Complex conj()
	{
		Complex res;
		res.real = this->real;
		res.imag = -this->imag;
		return res;
	}
	//
	Complex operator+(Complex b)
	{
		Complex res;
		res.real = this->real + b.getreal();
		res.imag = this->imag + b.getimag();
		return res;
	}
	Complex operator-(Complex b)
	{
		Complex res;
		res.real = this->real - b.getreal();
		res.imag = this->imag - b.getimag();
		return res;
	}
	Complex operator*(Complex b)
	{
		Complex res;
		res.real = this->real * b.getreal() - this->imag * b.getimag();
		res.imag = this->imag * b.getreal() + this->real * b.getimag();
		return res;
	}
	Complex operator/(Complex b)
	{
		Complex res;
		res.real = (this->real * b.getreal() + this->imag * b.getimag()) / (b.getreal() * b.getreal() + b.getimag() * b.getimag());
		res.imag = (this->imag * b.getreal() - this->real * b.getimag()) / (b.getreal() * b.getreal() + b.getimag() * b.getimag());
		return res;
	}
	//
	void operator+=(Complex b)
	{
		this->real = this->real + b.getreal();
		this->imag = this->imag + b.getimag();
	}
	void operator-=(Complex b)
	{
		this->real = this->real - b.getreal();
		this->imag = this->imag - b.getimag();
	}
	void operator*=(Complex b)
	{
		this->real = this->real * b.getreal() - this->imag * b.getimag();
		this->imag = this->imag * b.getreal() + this->real * b.getimag();
	}
	void operator/=(Complex b)
	{
		this->real = (this->real * b.getreal() + this->imag * b.getimag()) / (b.getreal() * b.getreal() + b.getimag() * b.getimag());
		this->imag = (this->imag * b.getreal() - this->real * b.getimag()) / (b.getreal() * b.getreal() + b.getimag() * b.getimag());
	}
	//
	Complex operator+(double a)
	{
		Complex res;
		res.real = this->real + a;
		res.imag = this->imag;
		return res;
	}
	Complex operator-(double a)
	{
		Complex res;
		res.real = this->real - a;
		res.imag = this->imag;
		return res;
	}
	Complex operator*(double a)
	{
		Complex res;
		res.real = this->real * a;
		res.imag = this->imag * a;
		return res;
	}
	Complex operator/(double a)
	{
		Complex res;
		res.real = this->real / a;
		res.imag = this->imag / a;
		return res;
	}
	//
	void operator+=(double a)
	{
		this->real = this->real + a;
		this->imag = this->imag;
	}
	void operator-=(double a)
	{
		this->real = this->real - a;
		this->imag = this->imag;
	}
	void operator*=(double a)
	{
		this->real = this->real * a;
		this->imag = this->imag * a;
	}
	void operator/=(double a)
	{
		this->real = this->real / a;
		this->imag = this->imag / a;
	}
	//
	bool operator==(Complex b)
	{
		double epsilon = 1.0 / (1000000000000000.0); // 1/10^15
		if ((std::abs(this->real - b.getreal()) <= epsilon) && (std::abs(this->real - b.getreal()) <= epsilon))
			return true;
		else
			return false;
	}
	bool operator!=(Complex b)
	{
		double epsilon = 1.0 / (1000000000000000.0); // 1/10^15
		if ((std::abs(this->real - b.getreal()) <= epsilon) && (std::abs(this->real - b.getreal()) <= epsilon))
			return false;
		else
			return true;
	}
	//
	friend std::ostream& operator << (std::ostream& out, Complex a)
	{
		out << a.getreal() << " + (" << a.getimag() << ")*i";
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Complex& a)
	{
		in >> a.real >> a.imag;
		return in;
	}
	//
};

#endif
