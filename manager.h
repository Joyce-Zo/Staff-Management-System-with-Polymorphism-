#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"

// ��������
class manager :public Worker
{
public:
	// ���캯��
	manager(int id, string name, int Did);
	// չʾ������Ϣ
	virtual void showInfo();
	// ��ȡ���˸�λ
	virtual string getDeptName();
};