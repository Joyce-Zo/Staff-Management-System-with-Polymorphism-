#pragma once
#include<iostream>
using namespace std;
#include<string>

// Ա��������_����

class Worker
{
public:
	// չʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ȡ���˸�λ
	virtual string getDeptName() = 0;

	int m_id;		// Ա�����
	string m_name;// Ա������
	int m_Did;	// �������ű��
};