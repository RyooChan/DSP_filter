#include "pch.h"
#include "CGen_sig.h"

CGen_sig::CGen_sig(void)
{
}


CGen_sig::~CGen_sig(void)
{
}

void CGen_sig::Gen_signal(CString Nsignal, int m_frq)
{
	
	if ((Nsignal) == "sin")
	{
		for (int x = 0; x < DATA_no; x++)
		{
			Sin_Data[x] = sin((2 * Pi*m_frq / DATA_no)*x);
		}
	}
	else if ((Nsignal) == "cos")
	{
		for (int x = 0; x < DATA_no; x++)
		{
			Cos_Data[x] = cos((2 * Pi*m_frq / DATA_no)*x);
		}
	}
	else if ((Nsignal) == "unit")
	{
		int num;
		for (int x = 0; x < DATA_no; x++)
		{
			num = x * 50;
			if (num < m_frq)
				Unit_Data[num] = 1;
		}
	}
	else if ((Nsignal) == "white")
	{
		for (int x = 0; x < DATA_no; x++)
		{
			WhiteNoise[x] = rand() % 100 - 50;
			WhiteNoise[x] = (double)WhiteNoise[x] / 50;
		}
	}
	else if ((Nsignal) == "sinWN")
	{
		for (int x = 0; x < DATA_no; x++)
		{
			SinWN[x] = sin((2 * Pi*m_frq / DATA_no)*x) + ((double)(rand() % 100 - 50)/50);
		}
	}

	else if ((Nsignal) == "cosWN")
	{
		for (int x = 0; x < DATA_no; x++)
		{
			CosWN[x] = cos((2 * Pi*m_frq / DATA_no)*x) + ((double) (rand() % 100 - 50) / 50);
		}
	}

	else if ((Nsignal) == "sinc")
	{
		for (int x = 0; x < DATA_no; x++)
		{
			sinc[x] = (double)sin((2 * Pi * m_frq / DATA_no)*x)/((Pi * x) / DATA_no)/m_frq/2; 
		}

		sinc[0] = 1;
	}

	else if ((Nsignal) == "ramp")
	{
		for (int x = 0; x < DATA_no; x += 50)
		{
			if (x >= m_frq)
				Ramp[x] = 1;
			else
				Ramp[x] = 0;
		}
	}

	else if ((Nsignal) == "step")
	{
		for (int x = 0; x < DATA_no; x += 50)
		{
			if (x >= m_frq)
				step[x] = (double)x/DATA_no * 2;
			else
				step[x] = 0;
		}
	}


	else if ((Nsignal) == "impulse")
	{
		for (int x = 0; x < DATA_no; x ++)
		{
			if (x == m_frq)
				impulse[x] = 1;
			else
				step[x] = 0;
		}
	}
}