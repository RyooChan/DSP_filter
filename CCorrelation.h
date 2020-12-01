#pragma once
#define DATA_no 1024
#include <math.h>

class CCorrelation
{
public:
	CCorrelation(void);
	~CCorrelation(void);
	void Correlation(void);

	double m_xn[1024];
	double m_hn[1024];
	double Conrrelation_data[1024];
};

/*

#include "pch.h"
#include "CCorrelation.h"

CCorrelation::CCorrelation(void)
{
	for (int i = 0; i < 1024; i++)
		m_xn[i] = m_hn[i] = Conrrelation_data[i] = 0;
}


CCorrelation::~CCorrelation(void)
{
}

void CCorrelation::Correlation(void)
{
	for (int k = 0; k < 1024; k++)
	{
		Conrrelation_data[k] = 0;
		for (int n = k; n < 1024; n++) {
			Conrrelation_data[k] += m_xn[n] * m_hn[n - k];
		}

	}

}

*/