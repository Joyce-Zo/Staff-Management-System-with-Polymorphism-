#include<iostream>
using namespace std;
#include"employee.h"

	// ���캯��
employee::employee(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
	// չʾ������Ϣ
void employee:: showInfo()
{
	cout << "Ա����ţ�" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\tԱ����λ��" << this->getDeptName()
		<< "\tԱ��ְ����ɾ����ŵ�����" << endl;
}
	// ��ȡ���˸�λ
string employee::getDeptName()
{
	return string("Ա��");
}

