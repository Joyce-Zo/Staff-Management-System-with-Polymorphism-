
#include"boss.h"

	// ���캯��
boss::boss(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
	// չʾ������Ϣ
void boss::showInfo()
{
	cout << "Ա����ţ�" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\tԱ����λ��" << this->getDeptName()
		<< "\tԱ��ְ�𣺰�����������" << endl;
}
	// ��ȡ���˸�λ
string boss::getDeptName()
{
	return ("�ϰ�");
}
