#include "pch.h"
#include "CConv.h"

Cconv::Cconv(void)
{
	for (int i = 0; i < 1024; i++)
		 m_xn[i] =  m_hn[i] =  Convolution_Data[i] = 0;
}


Cconv::~Cconv(void)
{
}

void Cconv::Convolution(void)
{
		for (int x = 0; x < 1024; x ++)
		{
			for (int n = 0; n <= x; n ++) {
				Convolution_Data[x] += m_xn[n] * m_hn[x - n];
			}
			Convolution_Data[x] /= 5;
		}
	
}