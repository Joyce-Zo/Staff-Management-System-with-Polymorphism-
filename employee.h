#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"

class employee :public Worker
{
public:
	// 构造函数
	employee(int id, string name, int Did);
	// 展示个人信息
	virtual void showInfo();
	// 获取个人岗位
	virtual string getDeptName();
};