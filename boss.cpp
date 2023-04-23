
#include"boss.h"

	// 构造函数
boss::boss(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
	// 展示个人信息
void boss::showInfo()
{
	cout << "员工编号：" << this->m_id
		<< "\t员工姓名：" << this->m_name
		<< "\t员工岗位：" << this->getDeptName()
		<< "\t员工职责：安排所有任务" << endl;
}
	// 获取个人岗位
string boss::getDeptName()
{
	return ("老板");
}
