#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"

// �ϰ塪����
class boss :public Worker
{
public:
	// ���캯��
	boss(int id, string name, int Did);
	// չʾ������Ϣ
	virtual void showInfo();
	// ��ȡ���˸�λ
	virtual string getDeptName();
};