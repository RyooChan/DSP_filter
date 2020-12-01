
// convolutionView.h: CconvolutionView 클래스의 인터페이스
//

#pragma once


class CconvolutionView : public CView
{
protected: // serialization에서만 만들어집니다.
	CconvolutionView() noexcept;
	DECLARE_DYNCREATE(CconvolutionView)

// 특성입니다.
public:
	CconvolutionDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CconvolutionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnConx();
	afx_msg void OnConh();
	afx_msg void OnConvolution();

	double m_signal1[1024];
	double m_signal2[1024];
	double m_result[2048];

	double m_signal4[1024], m_signal5[1024], m_signal6[1024];

	double m_four1_time[1024], m_four2_time[1024], m_four3_time[1024];
	double m_four1_freq[1024], m_four2_freq[1024], m_four3_freq[1024];

	double m_filterIn[1024], m_filterHn[1024], m_filterOut[1024];

	double maximum;
	CString view_state;
	afx_msg void OnFsin1hz();
	afx_msg void OnFsin10hz();
	afx_msg void OnFcos1hz();
	afx_msg void OnFcos10hz();
	afx_msg void OnFwn();
	afx_msg void OnFws();
	afx_msg void OnFwc();
	afx_msg void OnSsin1hz();
	afx_msg void OnSsin10hz();
	afx_msg void OnScos1hz();
	afx_msg void OnScos10hz();
	afx_msg void OnSwn();
	afx_msg void OnSws();
	afx_msg void OnSwc();
	afx_msg void OnCor();
	afx_msg void OnAuto();
	afx_msg void OnCross();
	afx_msg void OnFsinc1hz();
	afx_msg void OnFsinc10hz();
	afx_msg void OnSsinc1hz();
	afx_msg void OnSsinc10hz();
	afx_msg void OnFramp();
	afx_msg void OnFstep();
	afx_msg void OnFimpulse();
	afx_msg void OnSramp();
	afx_msg void OnSstep();
	afx_msg void OnSimpulse();
	afx_msg void OnFourier1();
	afx_msg void OnFourier1a10();
	afx_msg void OnFourier1a10a20();
	afx_msg void OnFourierfirst();
	afx_msg void OnFouriersecond();
	afx_msg void OnFourierthird();
	afx_msg void OnFilter1a10a100();
	afx_msg void OnFilterH();
	afx_msg void OnFilterFilter();
};

#ifndef _DEBUG  // convolutionView.cpp의 디버그 버전
inline CconvolutionDoc* CconvolutionView::GetDocument() const
   { return reinterpret_cast<CconvolutionDoc*>(m_pDocument); }
#endif

