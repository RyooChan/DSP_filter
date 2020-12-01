#pragma once
#define X_Start 20
#define Y_Start 20
#define X_End X_Start+1024
#define Y_End Y_Start+900
#define Y_Depth 3

#define X_Start2 X_End + 4
#define X_End2 X_Start2 + 1024
class CDraw_xy
{
public:
	CDraw_xy(void);
	~CDraw_xy(void);

	void Disp_Coor(CDC* pDC);

};