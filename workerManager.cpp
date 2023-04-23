#include<iostream>
using namespace std;
#include"workerManager.h"


// 构造函数
WorkerManager::WorkerManager()
{
	// 1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
			// 初始化属性
		this->worker_num = 0;
		this->worker_array = NULL;
		this->m_FileIsEmpty = true;// 初始为空
		ifs.close();
		return;
	}

	// 2、文件存在，无数据
	char ch = 0;
	ifs >> ch; // 取1个字符
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
			// 初始化属性
		this->worker_num = 0;
		this->worker_array = NULL;
		this->m_FileIsEmpty = true;// 初始为空
		ifs.close();
	}

	// 3、文件存在，有数据
	// 先获取员工的个数
	int num = get_WorkerNum();
	cout << "共有" << num << "个员工" << endl;
	this->worker_num = num;

	// 根据个数创建空间
	this->worker_array = new Worker * [this->worker_num];
	// 初始化员工
	this->Init();

	//// 测试：
	//for (int i=0; i < this->worker_num; i++)
	//{
	//	cout << "员工编号：" << this->worker_array[i]->m_id <<
	//		"\t员工名字：" << this->worker_array[i]->m_name <<
	//		"\t部门为" << this->worker_array[i]->m_Did << endl;
	//}
}

int WorkerManager::get_WorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int Did;
	int number = 0;
	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		number++;
	}
	return number;
}

void WorkerManager::Init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int Did;
	int number = 0;

	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		Worker* worker = NULL;
		// 根据不同的部门创建不同的对象
		if (Did == 1)
		{
			worker = new employee(id,name,Did);
		}
		else if (Did == 2)
		{
			worker = new manager(id, name, Did);
		}
		else
		{
			worker = new boss(id, name, Did);
		}
		this->worker_array[number] = worker;// 将对象放在数组中维护
		number++;
	}
	ifs.close();
}

void WorkerManager:: Show_Menu()
{
	cout << "***************************************" << endl;
	cout << "******** 欢迎使用教工管理系统！********" << endl;
	cout << "************ 1、添加员工 **************" << endl;
	cout << "************ 2、删除员工 **************" << endl;
	cout << "************ 3、显示员工 **************" << endl;
	cout << "************ 4、修改员工 **************" << endl;
	cout << "************ 5、查找员工 **************" << endl;
	cout << "************ 6、排序员工 **************" << endl;
	cout << "************ 7、清空员工 **************" << endl;
	cout << "************ 0、退出系统 **************" << endl;
	cout << "***************************************" << endl;
}

void WorkerManager::save()
{
	ofstream	ofs;
	ofs.open("WorkerFile.txt", ios::out);
	for (int i = 0; i < this->worker_num; i++)
	{
		ofs << this->worker_array[i]->m_id<<" "
			<< this->worker_array[i]->m_name << " "
			<< this->worker_array[i]->m_Did << endl;
	}
	ofs.close();
}

void WorkerManager::Add()
{
	cout << "请输入要添加员工的个数："<< endl;
	int Add_num = 0;
	cin >> Add_num;
	if (Add_num > 0)
	{
		// 计算添加后员工的总数
		int newSize = this->worker_num + Add_num;
		
		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];

		// 将原来空间的数据拷贝到新空间
		if (this->worker_array != NULL)
		{
			for (int i = 0; i < this->worker_num; i++)
			{
				newSpace[i] = this->worker_array[i];
			}
		}
		// 将新数据添加至新空间的后面
		for (int j = 0; j < Add_num; j++)
		{
			int id;
			string name;
			int Did;
			cout << "请输入第" << j + 1 << "个新员工的编号" << endl;
			while (true)
			{
				cin >> id;
				int ret = this->worker_isExit(id);
				if (ret != -1)
				{
					cout << "用户编号已存在！请重新输入：" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "请输入第" << j + 1 << "个新员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << j + 1 << "个新员工的部门：" << 
				"1、普通员工 "
				"2、经理 "
				"3、老板"<<endl;
			cin >> Did;

			// 根据部门编号创建不同的职位
			Worker* worker = NULL;
			switch (Did)
			{
				case 1:
					worker = new employee(id, name, Did);
					break;
				case 2:
					worker = new manager(id, name, Did);
					break;
				case 3:
					worker = new boss(id, name, Did);
					break;
				default:
					cout << "输入错误" << endl;
					break;
			}
			// 将创建的员工指针，保存至数组中
			newSpace[this->worker_num + j] = worker;
		}
		// 释放原有数组的空间
		delete[] this->worker_array;
		// 更新新空间的指向
		this->worker_array = newSpace;
		// 更新新空间的人数
		this->worker_num = newSize;
		cout << "成功添加" << Add_num << "名新员工！" << endl;
		this->m_FileIsEmpty = false;// 初始不为空
		// 保存员工到文件中
		this->save();
		Sleep(1000); // 暂停1000毫秒
		system("pause");// 按任意键继续
		system("cls"); // 清屏
	}
	else
	{
		cout << "输入错误！" << endl;
	}
}

void WorkerManager::show_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在！" << endl;
		Sleep(1000);
	}
	else
	{
		for (int i = 0; i < this->worker_num; i++)
		{
			this->worker_array[i]->showInfo();
			Sleep(50); 
		}
	}	
		system("pause");// 按任意键继续
		system("cls"); // 清屏
}

int WorkerManager::worker_isExit(int id)
{
	for (int i = 0; i < this->worker_num; i++)
	{
		if (this->worker_array[i]->m_id == id)
			return i;
	}
	return -1;
}

void WorkerManager::del_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空！" << endl;
	}
	else
	{
		cout << "请输入要删除的员工id：" << endl;
		int input = 0;
		cin >> input;
		int ret = worker_isExit(input);
		if (ret == -1)
		{
			cout << "删除失败，员工不存在！" << endl;
		}
		else
		{
			if (input == this->worker_num) // 如果输入的是末尾员工的id，数组直接 - 1即可
			{
				this->worker_num--;
			}
			else
			{
					// 数据前移，数组中后一个数据覆盖到前一个
				for (int i = ret; i < this->worker_num - 1; i++)
				{
					this->worker_array[i] = this->worker_array[i + 1];
				}
				this->worker_num--;
			}
			this->save();
			cout << "删除成功！" << endl;
		}
	}
	Sleep(1000);
	system("pause");// 按任意键继续
	system("cls"); // 清屏
}

void WorkerManager::mod_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的员工id：" << endl;
		int input = 0;
		cin >> input;
		int ret = worker_isExit(input);
		if (ret == -1)
		{
			cout << "修改失败，员工不存在！" << endl;
		}
		else
		{
			delete this->worker_array[ret];
			int id = 1;
			string name;
			int Did;
			cout << "已查找到，请输入员工新的编号" << endl;
			while (true)
			{
				cin >> id;
				int ret = this->worker_isExit(id);
				if (ret != -1)
				{
					cout << "用户编号已存在！请重新输入：" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "请输入员工新的姓名" << endl;
			cin >> name;
			cout << "请输入员工新的部门：" <<
				"1、普通员工 "
				"2、经理 "
				"3、老板" << endl;
			cin >> Did;

			// 根据部门编号创建不同的职位
			Worker* worker = NULL;
			switch (Did)
			{
				case 1:
					worker = new employee(id, name, Did);
					break;
				case 2:
					worker = new manager(id, name, Did);
					break;
				case 3:
					worker = new boss(id, name, Did);
					break;
				default:
					cout << "输入错误" << endl;
					break;
			}
			this->worker_array[ret] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
	}
	Sleep(1000);
	system("pause");
	system("cls");
}

void WorkerManager::find_worker()
{
	cout << "请输入查找模式：" << endl;
	cout << "1、编号查找	2、姓名查找	" << endl;
	int input = 0;
	cin >> input;
	// 1、编号查找
	if (input == 1)
	{
		cout << "请输入要查找人的编号：" << endl;
		int id = 0;
		cin >> id;
		int ret = this->worker_isExit(id);
		if (ret == -1)
		{
			cout << "查无此人！" << endl;
		}
		else
		{
			cout << "已查到编号为 " << id << " 的员工，信息如下：" << endl;
			this->worker_array[ret]->showInfo();
		}
	}
	// 2、姓名查找
	else if (input == 2)	
	{
		cout << "请输入要查找人的姓名：" << endl;
		string name;
		// 创建是否找到员工的变量，找到返回true，否则一直是false
		bool worker_isFind = false;
		cin >> name;
		for (int i = 0; i < this->worker_num; i++)
		{
			if (name == this->worker_array[i]->m_name)
			{
				cout << "已查到姓名为 " << name << " 的员工，信息如下：" << endl;
				this->worker_array[i]->showInfo();
				worker_isFind = true;
			}
		}
		if (worker_isFind == false)// 根据是否找到员工（即是否是false），输出查无此人
		{
			cout << "查无此人！" << endl;
		}
	}
	else
	{
		cout << "输入错误！" << endl;
		return;
	}
	Sleep(1000);
	system("pause");
	system("cls");
}

void WorkerManager::sort_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1、升序排序    2、降序排序 " << endl;
		int input = 0;
		cin >> input;
		int minORmax = 0;

		for (int i = 0; i < this->worker_num; i++)
		{
			int minORmax = i; // 设定最小值或最大值
			for (int j = i + 1; j < this->worker_num; j++)
			{
				if (input == 1) // 升序
				{
					if (this->worker_array[minORmax]->m_id > this->worker_array[j]->m_id)
					{	// 如果我们设定的最小值比数组中某个数还小
						minORmax = j; //交换下标
					}
				}
				else // 降序
				{
					if (this->worker_array[minORmax]->m_id < this->worker_array[j]->m_id)
					{	// 如果我们设定的最小值比数组中某个数还大
						minORmax = j;
					}
				}
			}
			if (i != minORmax) // 下标有交换，则和原来的i不同，就可以进行数据的交换
			{
				swap(this->worker_array[minORmax], this->worker_array[i]);
			}
		}
		this->save();
		cout << "排序成功！" << endl;
		cout << "排序后结果为：" << endl;
		this->show_worker();
	}
}

void WorkerManager::cleam_worker()
{

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "确认清空文件？" << endl;
		cout << "1、确定   2、返回" << endl;
		int input = 0;
		cin >> input;
		if (input == 1)
		{
			// 1、先清空文件
			// 直接使用文件打开方式的 trunc：文件存在先删除再创建
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			// 2、再清空数组
			if (this->worker_array != NULL)
			{
				// 2.1先删除堆区每个员工对象（数组每个元素）
				for (int i = 0; i < this->worker_num; i++)
				{
					delete this->worker_array[i];
					this->worker_array[i] = NULL;
				}
			}
			// 2.2再清空数组
			delete[]this->worker_array;
			this->worker_array = NULL;
			this->worker_num = 0;
			this->m_FileIsEmpty = true; // 文件为空的标志
		}
		cout << "清空成功！" << endl;
		system("pause");
		system("cls");
	}
}

void WorkerManager:: Exit_System()
{
	cout << "退出系统！" << endl;
	exit(0);
}

// 析构函数
WorkerManager::~WorkerManager()
{
	if (this->worker_array != NULL)
	{
		for (int i = 0; i < this->worker_num; i++)
		{
			delete this->worker_array[i];
			this->worker_array[i] = NULL;
		}
	}
	delete[]this->worker_array;
	this->worker_array = NULL;
}
