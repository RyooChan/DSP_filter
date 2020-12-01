
// convolutionView.cpp: CconvolutionView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "convolution.h"
#endif

#include "convolutionDoc.h"
#include "convolutionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CconvolutionView

IMPLEMENT_DYNCREATE(CconvolutionView, CView)

BEGIN_MESSAGE_MAP(CconvolutionView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CONx, &CconvolutionView::OnConx)
	ON_COMMAND(ID_CONh, &CconvolutionView::OnConh)
	ON_COMMAND(ID_CONVOLUTION, &CconvolutionView::OnConvolution)
	ON_COMMAND(ID_FSIN_1HZ, &CconvolutionView::OnFsin1hz)
	ON_COMMAND(ID_FSIN_10HZ, &CconvolutionView::OnFsin10hz)
	ON_COMMAND(ID_FCOS_1HZ, &CconvolutionView::OnFcos1hz)
	ON_COMMAND(ID_FCOS_10HZ, &CconvolutionView::OnFcos10hz)
	ON_COMMAND(ID_FWN, &CconvolutionView::OnFwn)
	ON_COMMAND(ID_FWS, &CconvolutionView::OnFws)
	ON_COMMAND(ID_FWC, &CconvolutionView::OnFwc)
	ON_COMMAND(ID_SSIN_1HZ, &CconvolutionView::OnSsin1hz)
	ON_COMMAND(ID_SSIN_10HZ, &CconvolutionView::OnSsin10hz)
	ON_COMMAND(ID_SCOS_1HZ, &CconvolutionView::OnScos1hz)
	ON_COMMAND(ID_SCOS_10HZ, &CconvolutionView::OnScos10hz)
	ON_COMMAND(ID_SWN, &CconvolutionView::OnSwn)
	ON_COMMAND(ID_SWS, &CconvolutionView::OnSws)
	ON_COMMAND(ID_SWC, &CconvolutionView::OnSwc)
	ON_COMMAND(ID_COR, &CconvolutionView::OnCor)
	ON_COMMAND(Auto, &CconvolutionView::OnAuto)
	ON_COMMAND(CROSS, &CconvolutionView::OnCross)
	ON_COMMAND(ID_FSinc_1hz, &CconvolutionView::OnFsinc1hz)
	ON_COMMAND(ID_FSinc_10hz, &CconvolutionView::OnFsinc10hz)
	ON_COMMAND(ID_SSinc_1hz, &CconvolutionView::OnSsinc1hz)
	ON_COMMAND(ID_SSinc_10hz, &CconvolutionView::OnSsinc10hz)
	ON_COMMAND(ID_FRamp, &CconvolutionView::OnFramp)
	ON_COMMAND(ID_FStep, &CconvolutionView::OnFstep)
	ON_COMMAND(ID_FImpulse, &CconvolutionView::OnFimpulse)
	ON_COMMAND(ID_SRamp, &CconvolutionView::OnSramp)
	ON_COMMAND(ID_SStep, &CconvolutionView::OnSstep)
	ON_COMMAND(ID_SImpulse, &CconvolutionView::OnSimpulse)
	ON_COMMAND(ID_Fourier_1, &CconvolutionView::OnFourier1)
	ON_COMMAND(ID_Fourier_1A10, &CconvolutionView::OnFourier1a10)
	ON_COMMAND(ID_Fourier_1A10A20, &CconvolutionView::OnFourier1a10a20)
	ON_COMMAND(ID_Fourier_first, &CconvolutionView::OnFourierfirst)
	ON_COMMAND(ID_Fourier_second, &CconvolutionView::OnFouriersecond)
	ON_COMMAND(ID_Fourier_third, &CconvolutionView::OnFourierthird)
	ON_COMMAND(ID_Filter_1A10A100, &CconvolutionView::OnFilter1a10a100)
	ON_COMMAND(ID_Filter_H, &CconvolutionView::OnFilterH)
	ON_COMMAND(ID_FILTER_FILTER, &CconvolutionView::OnFilterFilter)
END_MESSAGE_MAP()

// CconvolutionView 생성/소멸

CconvolutionView::CconvolutionView() noexcept
{
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = 0;
		m_signal2[i] = 0;
		m_result[i] = 0;
		m_four1_time[i] = m_four2_time[i] = m_four3_time[i] = 0;
		m_four1_freq[i] = m_four2_freq[i] = m_four3_freq[i] = 0;
		m_filterIn[i] = m_filterHn[i] = m_filterOut[i] = 0;
		m_signal4[i] = m_signal5[i] = m_signal6[i] = 0;
	}
	maximum = 0;
	view_state = "";
}

CconvolutionView::~CconvolutionView()
{
}

BOOL CconvolutionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CconvolutionView 그리기

#include "CDraw_xy.h"
#include"CDis_signal.h"
#include"CGen_sig.h"
#include"CConv.h"
#include"CCorrelation.h"
#include"Adj_MAX.h"

void CconvolutionView::OnDraw(CDC* pDC)
{
	CconvolutionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDraw_xy DR;
	DR.Disp_Coor(pDC);

	Adj_MAX AM;
	

	CDis_signal DS;
	for (int i = 0; i < 1024; i++) {
		DS.Disp_Data[i] = m_signal1[i];
	}
	DS.Display_signal(pDC, 20, 170);


	for (int i = 0; i < 1024; i++) {
		DS.Disp_Data[i] = m_signal2[i];
	}
	DS.Display_signal(pDC, 20, 470);


	for (int i = 0; i < 1024; i++) {
		DS.Disp_Data[i] = m_result[i];
	}
	DS.Display_signal(pDC, 20, 770);

	for (int i = 0; i < 1024; i++) {
		DS.Disp_Data[i] = m_signal4[i];
	}
	DS.Display_signal(pDC, 1052, 170);


	for (int i = 0; i < 1024; i++) {
		DS.Disp_Data[i] = m_signal5[i];
	}
	DS.Display_signal(pDC, 1052, 470);


	for (int i = 0; i < 1024; i++) {
		DS.Disp_Data[i] = m_signal6[i];
	}
	DS.Display_signal(pDC, 1052, 770);


	if (maximum != 0)
		DS.Display_signal(pDC, maximum, view_state);

}


// CconvolutionView 인쇄

BOOL CconvolutionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CconvolutionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CconvolutionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CconvolutionView 진단

#ifdef _DEBUG
void CconvolutionView::AssertValid() const
{
	CView::AssertValid();
}

void CconvolutionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CconvolutionDoc* CconvolutionView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CconvolutionDoc)));
	return (CconvolutionDoc*)m_pDocument;
}
#endif //_DEBUG


// CconvolutionView 메시지 처리기


void CconvolutionView::OnConx()
{

	CGen_sig GS;
	GS.Gen_signal(_T("unit"), 200);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.Unit_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnConh()
{

	CGen_sig GS;
	GS.Gen_signal(_T("unit"), 300);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.Unit_Data[i];
	}
	Invalidate();
}




void CconvolutionView::OnFsin1hz()
{

	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 1);
	
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.Sin_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnFsin10hz()
{

	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.Sin_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnFcos1hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("cos"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.Cos_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnFcos10hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("cos"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.Cos_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnFwn()
{
	CGen_sig GS;
	GS.Gen_signal(_T("white"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.WhiteNoise[i];
	}
	Invalidate();
}


void CconvolutionView::OnFws()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinWN"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.SinWN[i];
	}
	Invalidate();
}


void CconvolutionView::OnFwc()
{
	CGen_sig GS;
	GS.Gen_signal(_T("cosWN"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.CosWN[i];
	}
	Invalidate();
}


void CconvolutionView::OnSsin1hz()
{

	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.Sin_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnSsin10hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.Sin_Data[i];
	}
	Invalidate(); 
}


void CconvolutionView::OnScos1hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("cos"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.Cos_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnScos10hz()
{

	CGen_sig GS;
	GS.Gen_signal(_T("cos"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.Cos_Data[i];
	}
	Invalidate();
}


void CconvolutionView::OnSwn()
{
	CGen_sig GS;
	GS.Gen_signal(_T("white"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.WhiteNoise[i];
	}
	Invalidate();
}


void CconvolutionView::OnSws()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinWN"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.SinWN[i];
	}
	Invalidate();
}


void CconvolutionView::OnSwc()
{
	CGen_sig GS;
	GS.Gen_signal(_T("cosWN"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.CosWN[i];
	}
	Invalidate();
}


void CconvolutionView::OnCor()
{
	CCorrelation CR;
	Adj_MAX AM;
	AM.m_Data_No = 1024;


	for (int i = 0; i < 1024; i++) {
		CR.m_xn[i] = m_signal1[i];
		CR.m_hn[i] = m_signal2[i];
	}
	CR.Correlation();

	for (int i = 0; i < 1024; i++)
		m_result[i] = CR.Conrrelation_data[i];

	for (int n = 0; n < 1024; n++)
		AM.AdMax[n] = m_result[n];

	AM.Sort_Max();

	for (int k = 0; k < 1024; k++)
		m_result[k] = AM.AdMax[k];

	Invalidate();
}




void CconvolutionView::OnFsinc1hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinc"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.sinc[i];
	}
	Invalidate();
}


void CconvolutionView::OnFsinc10hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinc"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.sinc[i];
	}
	Invalidate();
}


void CconvolutionView::OnSsinc1hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinc"), 1);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.sinc[i];
	}
	Invalidate();
}


void CconvolutionView::OnSsinc10hz()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinc"), 10);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.sinc[i];
	}
	Invalidate();
}


void CconvolutionView::OnFramp()
{
	CGen_sig GS;
	GS.Gen_signal(_T("ramp"), 0);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.Ramp[i];
	}
	Invalidate();
}


void CconvolutionView::OnFstep()
{
	CGen_sig GS;
	GS.Gen_signal(_T("step"), 0);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.step[i];
	}
	Invalidate();
}


void CconvolutionView::OnFimpulse()
{
	CGen_sig GS;
	GS.Gen_signal(_T("impulse"), 0);
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = GS.impulse[i];
	}
	Invalidate();
}


void CconvolutionView::OnSramp()
{
	CGen_sig GS;
	GS.Gen_signal(_T("ramp"), 0);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.Ramp[i];
	}
	Invalidate();
}


void CconvolutionView::OnSstep()
{
	CGen_sig GS;
	GS.Gen_signal(_T("step"), 0);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.step[i];
	}
	Invalidate();
}


void CconvolutionView::OnSimpulse()
{
	CGen_sig GS;
	GS.Gen_signal(_T("impulse"), 0);
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = GS.impulse[i];
	}
	Invalidate();
}

// 구현부

void CconvolutionView::OnConvolution()
{
	Cconv CV;

	for (int i = 0; i < 1024; i++) {
		CV.m_xn[i] = m_signal1[i];
		CV.m_hn[i] = m_signal2[i];
	}
	CV.Convolution();

	for (int i = 0; i < 1024; i++)
		m_result[i] = CV.Convolution_Data[i];

	view_state = "Convolution";


	Invalidate();
}


void CconvolutionView::OnAuto()
{
	CCorrelation CR;
	Adj_MAX AM;

	AM.m_Data_No = 1024;

	for (int i = 0; i < 1024; i++) {
		CR.m_xn[i] = m_signal1[i];
		CR.m_hn[i] = m_signal1[i];
	}
	CR.Correlation();

	for (int i = 0; i < 1024; i++)
		m_result[i] = CR.Conrrelation_data[i];

	for (int n = 0; n < 1024; n++)
		AM.AdMax[n] = m_result[n];

	AM.Sort_Max();
	maximum = AM.m_Max;
	view_state = "Auto Correlation";

	for (int k = 0; k < 1024; k++)
		m_result[k] = AM.AdMax[k];

	Invalidate();
}


void CconvolutionView::OnCross()
{
	CCorrelation CR;
	Adj_MAX AM;
	AM.m_Data_No = 1024;
	//	double coe;


	for (int i = 0; i < 1024; i++) {
		CR.m_xn[i] = m_signal1[i];
		CR.m_hn[i] = m_signal2[i];
	}
	CR.Correlation();

	for (int i = 0; i < 1024; i++) {
		//		coe = double(1024) / double(1024 - i);
		m_result[i] = CR.Conrrelation_data[i];
		//		m_result[i] *= coe;
	}

	for (int n = 0; n < 1024; n++)
		AM.AdMax[n] = m_result[n];

	AM.Sort_Max();
	maximum = AM.m_Max;
	view_state = "Cross Correlation";

	for (int k = 0; k < 1024; k++)
		m_result[k] = AM.AdMax[k];

	Invalidate();
}

void CconvolutionView::OnFourier1()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 1);
	for (int i = 0; i < 1024; i++) {
		m_four1_time[i] = GS.Sin_Data[i];
	}
	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = m_four1_time[i];
	}
	Invalidate();
}


void CconvolutionView::OnFourier1a10()
{


	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 1);
	for (int i = 0; i < 1024; i++) {
		m_four1_time[i] = GS.Sin_Data[i];
	}

	GS.Gen_signal(_T("sin"), 10);
	for (int i = 0; i < 1024; i++) {
		m_four2_time[i] = GS.Sin_Data[i];
	}

	for (int i = 0; i < 1024; i++) {
		m_four2_time[i] = m_four1_time[i] + m_four2_time[i];
	}

	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = m_four2_time[i];
	}
	Invalidate();
	
}


void CconvolutionView::OnFourier1a10a20()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 1);
	for (int i = 0; i < 1024; i++) {
		m_four1_time[i] = GS.Sin_Data[i];
	}

	GS.Gen_signal(_T("sin"), 10);
	for (int i = 0; i < 1024; i++) {
		m_four2_time[i] = GS.Sin_Data[i];
	}

	GS.Gen_signal(_T("sin"), 20);
	for (int i = 0; i < 1024; i++) {
		m_four3_time[i] = GS.Sin_Data[i];
	}

	for (int i = 0; i < 1024; i++) {
		m_four3_time[i] = m_four1_time[i] + m_four2_time[i] + m_four3_time[i]/2;
	}

	for (int i = 0; i < 1024; i++) {
		m_result[i] = m_four3_time[i];
	}
	Invalidate();
}

#include "CFourier.h"
void CconvolutionView::OnFourierfirst()
{
	CFourier FR;
	FR.m_Data = 1024;

	for (int i = 0; i < 1024; i++) {
		FR.m_FInData[i] = m_signal1[i];
	}
	FR.Fourier_Fun();
	for (int i = 0; i < 1024; i++) {
		m_four1_freq[i] = FR.m_OutData[i]/512;
	}
	for (int i = 0; i < 1024; i++) {
		m_signal4[i] = m_four1_freq[i];
	}
	Invalidate();
}


void CconvolutionView::OnFouriersecond()
{
	CFourier FR;
	FR.m_Data = 1024;

	for (int i = 0; i < 1024; i++) {
		FR.m_FInData[i] = m_signal2[i];
	}
	FR.Fourier_Fun();
	for (int i = 0; i < 1024; i++) {
		m_four2_freq[i] = FR.m_OutData[i] / 512;
	}
	for (int i = 0; i < 1024; i++) {
		m_signal5[i] = m_four2_freq[i];
	}
	Invalidate();
}


void CconvolutionView::OnFourierthird()
{
	CFourier FR;
	FR.m_Data = 1024;

	for (int i = 0; i < 1024; i++) {
		FR.m_FInData[i] = m_result[i];
	}
	FR.Fourier_Fun();
	for (int i = 0; i < 1024; i++) {
		m_four3_freq[i] = FR.m_OutData[i] / 512;
	}
	for (int i = 0; i < 1024; i++) {
		m_signal6[i] = m_four3_freq[i];
	}
	Invalidate();
}


void CconvolutionView::OnFilter1a10a100()
{
	double f1[1024], f2[1024], f3[1024];
	for (int i = 0; i < 1024; i++) {
		f1[i] = f2[i] = f3[i] = 0;
	}

	CGen_sig GS;
	GS.Gen_signal(_T("sin"), 1);
	for (int i = 0; i < 1024; i++) {
		f1[i] = GS.Sin_Data[i];
	}

	GS.Gen_signal(_T("sin"), 10);
	for (int i = 0; i < 1024; i++) {
		f2[i] = GS.Sin_Data[i];
	}

	GS.Gen_signal(_T("sin"), 100);
	for (int i = 0; i < 1024; i++) {
		f3[i] = GS.Sin_Data[i];
	}

	for (int i = 0; i < 1024; i++) {
		m_filterIn[i] = f1[i] + f2[i] + f3[i];
	}

	for (int i = 0; i < 1024; i++) {
		m_signal1[i] = m_filterIn[i];
	}
	Invalidate();
}


void CconvolutionView::OnFilterH()
{
	CGen_sig GS;
	GS.Gen_signal(_T("sinc"), 10);
	for (int i = 0; i < 1024; i++) {
		m_filterHn[i] = GS.sinc[i];
	}
	for (int i = 0; i < 1024; i++) {
		m_signal2[i] = m_filterHn[i];
	}
	Invalidate();
}


void CconvolutionView::OnFilterFilter()
{
	Cconv CV;
	Adj_MAX AM;
	AM.m_Data_No = 1024;
	
	for (int i = 0; i < 1024; i++) {
		CV.m_xn[i] = m_filterIn[i];
		CV.m_hn[i] = m_filterHn[i];
	}
	CV.Convolution();

	for (int i = 0; i < 1024; i++)
		m_filterOut[i] = CV.Convolution_Data[i];

	view_state = "Filter out";

	for (int n = 0; n < 1024; n++)
		AM.AdMax[n] = m_filterOut[n];

	AM.Sort_Max();
	maximum = AM.m_Max;

	for (int k = 0; k < 1024; k++)
		m_filterOut[k] = AM.AdMax[k];

	for (int k = 0; k < 1024; k++)
		m_result[k] = m_filterOut[k];

	Invalidate();
}
