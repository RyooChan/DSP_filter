#include "pch.h"
#include "Adj_MAX.h"
#define Total_No 1024

Adj_MAX::Adj_MAX(void)
{
	AdMax = new double[Total_No]; //�����޸��Ҵ�
	for (int i = 0; i < Total_No; i++)
	{
		AdMax[i] = 0; //���� �ʱ�ȭ
	}
}
Adj_MAX::~Adj_MAX(void)
{
	delete[] AdMax; //�����Ҵ� �޸� ����
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
