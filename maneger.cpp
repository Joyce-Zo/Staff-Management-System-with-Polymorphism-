
#include"manager.h"

	// ���캯��
manager::manager(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
	// չʾ������Ϣ
void manager::showInfo()
{
	cout << "Ա����ţ�" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\tԱ����λ��" << this->getDeptName()
		<< "\tԱ��ְ������ϰ尲�ŵ�����" << endl;
}
	// ��ȡ���˸�λ
string manager::getDeptName() 
{
	return string("����");
}
