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
	// ���캯��
	WorkerManager();
	// �˵�չʾ
	void Show_Menu();
	
	// ��¼Ա������
	int worker_num;

	// ����Ա��������
	Worker** worker_array;
	
	// ���Ա������
	void Add();

	// ����Ա�����ļ�
	void save();

	// �ж��ļ��Ƿ����
	bool m_FileIsEmpty;

	// ͳ��Ա������
	int get_WorkerNum();

	// ��ʼ��Ա��
	void Init();

	// ��ʾԱ��
	void show_worker();

	// �ж�Ա���Ƿ����
	int worker_isExit(int id);

	// ɾ��Ա��
	void del_worker();

	// �޸�Ա��
	void mod_worker();

	// ����Ա��
	void find_worker();

	// ����Ա��
	void sort_worker();

	// ����ļ�
	void cleam_worker();

	// �˳�ϵͳ
	void Exit_System();

	// ��������
	~WorkerManager();
};
