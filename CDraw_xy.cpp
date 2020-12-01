#include "pch.h"
#include "CDraw_XY.h"
CDraw_xy::CDraw_xy(void)
{
}
CDraw_xy::~CDraw_xy(void)
{
}
void CDraw_xy::Disp_Coor(CDC* pDC)
{
	pDC->Rectangle(X_Start, Y_Start, X_End, Y_End);
	pDC->Rectangle(X_Start2, Y_Start, X_End2, Y_End);
	CString signal1, signal2, signal3, signal4, signal5;
	signal1 = "Signal1 ";
	signal2 = "Signal2 ";
	pDC->TextOut(30, 30, signal1);
	pDC->TextOut(30, Y_Start + 310, signal2);
	//x 축y축그리기
	pDC->MoveTo(X_Start, Y_Start + 150);
	pDC->LineTo(X_End, Y_Start + 150);
	pDC->MoveTo(X_Start, Y_Start + 300);
	pDC->LineTo(X_End, Y_Start + 300);
	pDC->MoveTo(X_Start, Y_Start + 450);
	pDC->LineTo(X_End, Y_Start + 450);
	pDC->MoveTo(X_Start, Y_Start + 600);
	pDC->LineTo(X_End, Y_Start + 600);
	pDC->MoveTo(X_Start, Y_Start + 750);
	pDC->LineTo(X_End, Y_Start + 750);


	signal3 = "Signal1 ";
	signal4 = "Signal2 ";
	signal5 = "Signal3 ";
	pDC->TextOut(X_Start2 + 10, 30, signal3);
	pDC->TextOut(X_Start2 + 10, Y_Start + 310, signal4);
	pDC->TextOut(X_Start2 + 10, Y_Start + 610, signal5);

	pDC->MoveTo(X_Start2, Y_Start + 150);
	pDC->LineTo(X_End2, Y_Start + 150);
	pDC->MoveTo(X_Start2, Y_Start + 300);
	pDC->LineTo(X_End2, Y_Start + 300);
	pDC->MoveTo(X_Start2, Y_Start + 450);
	pDC->LineTo(X_End2, Y_Start + 450);
	pDC->MoveTo(X_Start2, Y_Start + 600);
	pDC->LineTo(X_End2, Y_Start + 600);
	pDC->MoveTo(X_Start2, Y_Start + 750);
	pDC->LineTo(X_End2, Y_Start + 750);
}