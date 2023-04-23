#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h" 
#include"windows.h"
#include<fstream>


#define	FILENAME "WorkerFile.txt"







class WorkerManager
{
public:
	// 构造函数
	WorkerManager();
	// 菜单展示
	void Show_Menu();
	
	// 记录员工数量
	int worker_num;

	// 储存员工的数组
	Worker** worker_array;
	
	// 添加员工功能
	void Add();

	// 保存员工到文件
	void save();

	// 判断文件是否存在
	bool m_FileIsEmpty;

	// 统计员工个数
	int get_WorkerNum();

	// 初始化员工
	void Init();

	// 显示员工
	void show_worker();

	// 判断员工是否存在
	int worker_isExit(int id);

	// 删除员工
	void del_worker();

	// 修改员工
	void mod_worker();

	// 查找员工
	void find_worker();

	// 排序员工
	void sort_worker();

	// 清空文件
	void cleam_worker();

	// 退出系统
	void Exit_System();

	// 析构函数
	~WorkerManager();
};
