#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"

// 经理—子类
class manager :public Worker
{
public:
	// 构造函数
	manager(int id, string name, int Did);
	// 展示个人信息
	virtual void showInfo();
	// 获取个人岗位
	virtual string getDeptName();
};