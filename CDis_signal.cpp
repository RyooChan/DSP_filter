#include "pch.h"
#include "CDis_signal.h"


CDis_signal::CDis_signal(void)
{
	for (int i = 0; i < 1024; i++) {
		Disp_Data[i] = 0;
	}

	max_char = "";
}

CDis_signal::~CDis_signal(void)
{
}

void CDis_signal::Display_signal(CDC* pDC, int start_x, int start_y)
{
	CPen pen(PS_SOLID, 1, RGB(200, 10, 100)); //PEN 加己, 祸
	CPen *pOldPen = pDC->SelectObject(&pen); //PEN加己汲沥
//	pDC->Rectangle(20, 20, start_x, start_y + 200);
	for (int t = 0; t < No_Total + 10; t ++)
	{
		pDC->MoveTo(start_x + 10 + t, start_y);
		pDC->LineTo(start_x + 10 + t, start_y - Disp_Data[t] * 50);
	}
	pDC->SelectObject(pOldPen); //Pen 加己汗盔
}

void CDis_signal::Display_signal(CDC* pDC, CPoint CP)
{
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //PEN 加己, 祸
	CPen *pOldPen = pDC->SelectObject(&pen); //PEN加己汲沥
//	pDC->Rectangle(20, 20, CP.x, CP.y + 200);
	for (int t = 0; t < No_Total; t ++)
	{
		pDC->MoveTo(CP.x + t, CP.y);
		pDC->LineTo(CP.x + t, CP.y - Disp_Data[t] * M);
	}
	pDC->SelectObject(pOldPen); //Pen 加己汗盔
}
void CDis_signal::Display_signal(CDC* pDC, double max, CString state)
{
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //PEN 加己, 祸
	CPen *pOldPen = pDC->SelectObject(&pen); //PEN加己汲沥

	max_char.Format(_T("%f"), max);
	pDC->TextOut(30, 620, state);
	pDC->TextOut(150, 620, max_char);

	pDC->SelectObject(pOldPen); //Pen 加己汗盔
}