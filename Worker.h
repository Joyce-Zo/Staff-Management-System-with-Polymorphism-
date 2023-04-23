#pragma once
#include<iostream>
using namespace std;
#include<string>

// 员工抽象类_基类

class Worker
{
public:
	// 展示个人信息
	virtual void showInfo() = 0;
	// 获取个人岗位
	virtual string getDeptName() = 0;

	int m_id;		// 员工编号
	string m_name;// 员工姓名
	int m_Did;	// 所属部门编号
};