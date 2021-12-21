# C++/DSP 활용 디지털 신호 처리 필터 설계

## 설계 배경
* C++언어를 사용하는 디지털 필터를 설계한다.
* DSP를 사용하여 사용자 UI를 구성할 수 있도록 한다.

## 개발목표 및 내용
* 기본 정현파 함수 작성
    * Sin / Cos Wave 등
* 실제 환경과 유사하도록 White Noise 생성
* 정현파, White Noise가 가미된 정현파 간 Correlation기능 구현
* Impulse간의 Convolution기능 작성

## 개발 내용
![](https://i.imgur.com/vRleYsM.png)
* white Nose가 가미된 두 개의 다른 sin wave(10hz)를 생성하여 cross correlaton한 결과값
---
![](https://i.imgur.com/FKk3kfS.png)
* White Noise가 가미된 cos wave(10hz)를 Auto Correlation한 결과값
---
![](https://i.imgur.com/QZiXT5X.png)
* 여러 종류의 값들에 대한 fourier변환 값

## 고찰
* Correlation, Convolution시 Result값이 너무 크게 출력되어 이전 signal범위를 침범하는 경우가 생겼다.
    * 최대값을 1로 만드는 함수를 추가하여 Result크기를 조절하여 해결함.
* White Noise정현파를 Auto Correlation하는 경우 시작점에 함수에서 impulse가 출력되는데 이 impulse가 frame에 막혀 보이지 않는 경우가 생겼다.
    * 함수의 시작 위치를 DSP에서 조정하여 해결함.

## 결과 파일
* 결과로 만든 파일은 [exe파일](https://github.com/RyooChan/DSP_filter/blob/main/convolution.exe)로 만들어져 있어, 이를 다운받으면 실습 가능하다.
