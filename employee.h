#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"

class employee :public Worker
{
public:
	// ���캯��
	employee(int id, string name, int Did);
	// չʾ������Ϣ
	virtual void showInfo();
	// ��ȡ���˸�λ
	virtual string getDeptName();
};