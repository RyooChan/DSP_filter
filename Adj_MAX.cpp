#include "pch.h"
#include "Adj_MAX.h"
#define Total_No 1024

Adj_MAX::Adj_MAX(void)
{
	AdMax = new double[Total_No]; //동적메모리할당
	for (int i = 0; i < Total_No; i++)
	{
		AdMax[i] = 0; //변수 초기화
	}
}
Adj_MAX::~Adj_MAX(void)
{
	delete[] AdMax; //동적할당 메모리 삭제
}
void Adj_MAX::Sort_Max(void)
{
	m_Max = AdMax[0];
	for (int i = 0; i < m_Data_No; i++)
	{
		if (m_Max < AdMax[i])
			m_Max = AdMax[i];
	}
	for (int i = 0; i < m_Data_No; i++)
	{
		AdMax[i] = AdMax[i] / m_Max;
	}

}
