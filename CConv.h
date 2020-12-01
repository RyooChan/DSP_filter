#pragma once
#define DATA_no 1024
#include <math.h>
class Cconv
{
public:
	Cconv(void);
	~Cconv(void);
	void Convolution(void);

	double m_xn[1024];
	double m_hn[1024];
	double Convolution_Data[1024];
};

