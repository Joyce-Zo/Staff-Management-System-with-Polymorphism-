#include<iostream>
using namespace std;
#include"employee.h"

	// 构造函数
employee::employee(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}
	// 展示个人信息
void employee:: showInfo()
{
	cout << "员工编号：" << this->m_id
		<< "\t员工姓名：" << this->m_name
		<< "\t员工岗位：" << this->getDeptName()
		<< "\t员工职责：完成经理安排的任务" << endl;
}
	// 获取个人岗位
string employee::getDeptName()
{
	return string("员工");
}

