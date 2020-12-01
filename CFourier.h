#pragma once

class CFourier
{
public:
	int	m_Data;
	double *m_FInData, *m_OutData;

public:
	CFourier(void);
	~CFourier(void);

	void	Fourier_Fun(void);
};
