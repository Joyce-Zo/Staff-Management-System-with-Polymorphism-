#include<iostream>
using namespace std;
#include"workerManager.h"


// ���캯��
WorkerManager::WorkerManager()
{
	// 1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
			// ��ʼ������
		this->worker_num = 0;
		this->worker_array = NULL;
		this->m_FileIsEmpty = true;// ��ʼΪ��
		ifs.close();
		return;
	}

	// 2���ļ����ڣ�������
	char ch = 0;
	ifs >> ch; // ȡ1���ַ�
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
			// ��ʼ������
		this->worker_num = 0;
		this->worker_array = NULL;
		this->m_FileIsEmpty = true;// ��ʼΪ��
		ifs.close();
	}

	// 3���ļ����ڣ�������
	// �Ȼ�ȡԱ���ĸ���
	int num = get_WorkerNum();
	cout << "����" << num << "��Ա��" << endl;
	this->worker_num = num;

	// ���ݸ��������ռ�
	this->worker_array = new Worker * [this->worker_num];
	// ��ʼ��Ա��
	this->Init();

	//// ���ԣ�
	//for (int i=0; i < this->worker_num; i++)
	//{
	//	cout << "Ա����ţ�" << this->worker_array[i]->m_id <<
	//		"\tԱ�����֣�" << this->worker_array[i]->m_name <<
	//		"\t����Ϊ" << this->worker_array[i]->m_Did << endl;
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
		// ���ݲ�ͬ�Ĳ��Ŵ�����ͬ�Ķ���
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
		this->worker_array[number] = worker;// ���������������ά��
		number++;
	}
	ifs.close();
}

void WorkerManager:: Show_Menu()
{
	cout << "***************************************" << endl;
	cout << "******** ��ӭʹ�ý̹�����ϵͳ��********" << endl;
	cout << "************ 1�����Ա�� **************" << endl;
	cout << "************ 2��ɾ��Ա�� **************" << endl;
	cout << "************ 3����ʾԱ�� **************" << endl;
	cout << "************ 4���޸�Ա�� **************" << endl;
	cout << "************ 5������Ա�� **************" << endl;
	cout << "************ 6������Ա�� **************" << endl;
	cout << "************ 7�����Ա�� **************" << endl;
	cout << "************ 0���˳�ϵͳ **************" << endl;
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
	cout << "������Ҫ���Ա���ĸ�����"<< endl;
	int Add_num = 0;
	cin >> Add_num;
	if (Add_num > 0)
	{
		// ������Ӻ�Ա��������
		int newSize = this->worker_num + Add_num;
		
		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ���ռ�����ݿ������¿ռ�
		if (this->worker_array != NULL)
		{
			for (int i = 0; i < this->worker_num; i++)
			{
				newSpace[i] = this->worker_array[i];
			}
		}
		// ��������������¿ռ�ĺ���
		for (int j = 0; j < Add_num; j++)
		{
			int id;
			string name;
			int Did;
			cout << "�������" << j + 1 << "����Ա���ı��" << endl;
			while (true)
			{
				cin >> id;
				int ret = this->worker_isExit(id);
				if (ret != -1)
				{
					cout << "�û�����Ѵ��ڣ����������룺" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "�������" << j + 1 << "����Ա��������" << endl;
			cin >> name;
			cout << "�������" << j + 1 << "����Ա���Ĳ��ţ�" << 
				"1����ͨԱ�� "
				"2������ "
				"3���ϰ�"<<endl;
			cin >> Did;

			// ���ݲ��ű�Ŵ�����ͬ��ְλ
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
					cout << "�������" << endl;
					break;
			}
			// ��������Ա��ָ�룬������������
			newSpace[this->worker_num + j] = worker;
		}
		// �ͷ�ԭ������Ŀռ�
		delete[] this->worker_array;
		// �����¿ռ��ָ��
		this->worker_array = newSpace;
		// �����¿ռ������
		this->worker_num = newSize;
		cout << "�ɹ����" << Add_num << "����Ա����" << endl;
		this->m_FileIsEmpty = false;// ��ʼ��Ϊ��
		// ����Ա�����ļ���
		this->save();
		Sleep(1000); // ��ͣ1000����
		system("pause");// �����������
		system("cls"); // ����
	}
	else
	{
		cout << "�������" << endl;
	}
}

void WorkerManager::show_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴��ڣ�" << endl;
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
		system("pause");// �����������
		system("cls"); // ����
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
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա��id��" << endl;
		int input = 0;
		cin >> input;
		int ret = worker_isExit(input);
		if (ret == -1)
		{
			cout << "ɾ��ʧ�ܣ�Ա�������ڣ�" << endl;
		}
		else
		{
			if (input == this->worker_num) // ����������ĩβԱ����id������ֱ�� - 1����
			{
				this->worker_num--;
			}
			else
			{
					// ����ǰ�ƣ������к�һ�����ݸ��ǵ�ǰһ��
				for (int i = ret; i < this->worker_num - 1; i++)
				{
					this->worker_array[i] = this->worker_array[i + 1];
				}
				this->worker_num--;
			}
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
	}
	Sleep(1000);
	system("pause");// �����������
	system("cls"); // ����
}

void WorkerManager::mod_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա��id��" << endl;
		int input = 0;
		cin >> input;
		int ret = worker_isExit(input);
		if (ret == -1)
		{
			cout << "�޸�ʧ�ܣ�Ա�������ڣ�" << endl;
		}
		else
		{
			delete this->worker_array[ret];
			int id = 1;
			string name;
			int Did;
			cout << "�Ѳ��ҵ���������Ա���µı��" << endl;
			while (true)
			{
				cin >> id;
				int ret = this->worker_isExit(id);
				if (ret != -1)
				{
					cout << "�û�����Ѵ��ڣ����������룺" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "������Ա���µ�����" << endl;
			cin >> name;
			cout << "������Ա���µĲ��ţ�" <<
				"1����ͨԱ�� "
				"2������ "
				"3���ϰ�" << endl;
			cin >> Did;

			// ���ݲ��ű�Ŵ�����ͬ��ְλ
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
					cout << "�������" << endl;
					break;
			}
			this->worker_array[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
	}
	Sleep(1000);
	system("pause");
	system("cls");
}

void WorkerManager::find_worker()
{
	cout << "���������ģʽ��" << endl;
	cout << "1����Ų���	2����������	" << endl;
	int input = 0;
	cin >> input;
	// 1����Ų���
	if (input == 1)
	{
		cout << "������Ҫ�����˵ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int ret = this->worker_isExit(id);
		if (ret == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else
		{
			cout << "�Ѳ鵽���Ϊ " << id << " ��Ա������Ϣ���£�" << endl;
			this->worker_array[ret]->showInfo();
		}
	}
	// 2����������
	else if (input == 2)	
	{
		cout << "������Ҫ�����˵�������" << endl;
		string name;
		// �����Ƿ��ҵ�Ա���ı������ҵ�����true������һֱ��false
		bool worker_isFind = false;
		cin >> name;
		for (int i = 0; i < this->worker_num; i++)
		{
			if (name == this->worker_array[i]->m_name)
			{
				cout << "�Ѳ鵽����Ϊ " << name << " ��Ա������Ϣ���£�" << endl;
				this->worker_array[i]->showInfo();
				worker_isFind = true;
			}
		}
		if (worker_isFind == false)// �����Ƿ��ҵ�Ա�������Ƿ���false����������޴���
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	else
	{
		cout << "�������" << endl;
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
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1����������    2���������� " << endl;
		int input = 0;
		cin >> input;
		int minORmax = 0;

		for (int i = 0; i < this->worker_num; i++)
		{
			int minORmax = i; // �趨��Сֵ�����ֵ
			for (int j = i + 1; j < this->worker_num; j++)
			{
				if (input == 1) // ����
				{
					if (this->worker_array[minORmax]->m_id > this->worker_array[j]->m_id)
					{	// ��������趨����Сֵ��������ĳ������С
						minORmax = j; //�����±�
					}
				}
				else // ����
				{
					if (this->worker_array[minORmax]->m_id < this->worker_array[j]->m_id)
					{	// ��������趨����Сֵ��������ĳ��������
						minORmax = j;
					}
				}
			}
			if (i != minORmax) // �±��н��������ԭ����i��ͬ���Ϳ��Խ������ݵĽ���
			{
				swap(this->worker_array[minORmax], this->worker_array[i]);
			}
		}
		this->save();
		cout << "����ɹ���" << endl;
		cout << "�������Ϊ��" << endl;
		this->show_worker();
	}
}

void WorkerManager::cleam_worker()
{

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "ȷ������ļ���" << endl;
		cout << "1��ȷ��   2������" << endl;
		int input = 0;
		cin >> input;
		if (input == 1)
		{
			// 1��������ļ�
			// ֱ��ʹ���ļ��򿪷�ʽ�� trunc���ļ�������ɾ���ٴ���
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			// 2�����������
			if (this->worker_array != NULL)
			{
				// 2.1��ɾ������ÿ��Ա����������ÿ��Ԫ�أ�
				for (int i = 0; i < this->worker_num; i++)
				{
					delete this->worker_array[i];
					this->worker_array[i] = NULL;
				}
			}
			// 2.2���������
			delete[]this->worker_array;
			this->worker_array = NULL;
			this->worker_num = 0;
			this->m_FileIsEmpty = true; // �ļ�Ϊ�յı�־
		}
		cout << "��ճɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void WorkerManager:: Exit_System()
{
	cout << "�˳�ϵͳ��" << endl;
	exit(0);
}

// ��������
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
