#include "framework.h"
#include "pch.h"
#include <WINDOWS.H>
#include <string.h>
#include <stdio.h>
#include <STDLIB.H>
#include <MATH.H>
#include <tchar.h>
#include<iostream>
#define maxn 10000
#define DllExport extern "C" _declspec(dllexport)
//该函数计算成本
double num[maxn];
DllExport void MYUSER(int* NumArgs, double* x, double* dResult)
{
    int theta;
    int L;
    if (*NumArgs < 2) {
        MessageBox(NULL, _T("输入变量不足2个"), _T("输入错误"), MB_OK);
        *dResult = -1;
        exit(0);
    }
    theta = x[0];
    L = x[1];
    if (theta < 0) {
        MessageBox(NULL, _T("Theta输入错误"), _T("输入错误"), MB_OK);
        *dResult = -1;
        exit(0);
    }
    if (L < 0) {
        MessageBox(NULL, _T("L输入错误"), _T("输入错误"), MB_OK);
        *dResult = -1;
        exit(0);
    }
    if (*NumArgs != L + 2) {
        MessageBox(NULL, _T("输入变量不足，输入格式:Theta+L+L维向量"), _T("输入错误"), MB_OK);
        *dResult = -1;
        exit(0);
    }
   // std::cerr << x[2] << std::endl;
    //产品A的成本计算
    for (int i = 0; i < L; ++i)
        num[i] = x[i + 2];
    double alpha = 1.0 / (theta + 1);
    double res = 1;
    for (int i = 0; i < L; ++i) {
        res *= pow(num[i], alpha);
        alpha = 1 - alpha;
    }
    *dResult = res;
}
