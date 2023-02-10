#include"staff_class.h"


staff::staff()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;

		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;//向后读一个
	if (ifs.eof())
	{
		cout << "文件为空" << endl;

		this->m_StaffNum = 0;
		this->m_StaffArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//记录文件人数
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_StaffNum = num;

	this->m_StaffArray = new worker * [this->m_StaffNum];

	this->init_Emp();

	for (int i = 0; i < this->m_StaffNum; i++)
	{
		cout << "  职工编号： " << this->m_StaffArray[i]->m_ID
			<< "  职工姓名： " << this->m_StaffArray[i]->m_name
			<< "  部门编号： " << this->m_StaffArray[i]->m_DepID << endl;
	}
}

staff::~staff() 
{
	if (this->m_StaffArray != NULL)
	{
		delete[] this->m_StaffArray;
		this->m_StaffArray = NULL;
	}
}


void staff::show_Menu()
{
	cout << "\t        \t" << endl;
	cout << "\t1.增加职工信息\t" << endl;
	cout << "\t2.显示职工信息\t" << endl;
	cout << "\t3.删除离职职工\t" << endl;
	cout << "\t4.修改职工信息\t" << endl;
	cout << "\t5.查找职工信息\t" << endl;
	cout << "\t6.按照编号排序\t" << endl;
	cout << "\t7.清空所有文档\t" << endl;
	cout << "\t8.退出管理程序\t" << endl;
	cout << "\t        \t" << endl;
}

void staff::sxit_system()
{
	cout << "退出程序" << endl;
	system("pause");
	exit(0);
}

void staff::Add_staff()
{
	int add_num = 0;
	cout << "请输入添加职工数量：" << endl;
	cin >> add_num;

	if (add_num > 0)
	{
		int newSize = this->m_StaffNum + add_num ;//新空间大小

		worker ** newSpace = new worker * [newSize + 4];//开辟新空间

		if (this->m_StaffArray != NULL)
		{
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				newSpace[i] = this->m_StaffArray[i];
			}
		}

		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int dSlect;

			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSlect;

			worker* worker = NULL;
			switch (dSlect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_StaffNum + i] = worker;
			

		}
		delete[] this->m_StaffArray;

		this->m_StaffArray = newSpace;

		this->m_StaffNum = newSize;

		cout << "成功添加" << add_num << "名新职工" << endl;

		this->save();

		this->m_FileIsEmpty = false;

	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

void staff::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_StaffNum; i++)
	{
		ofs << this->m_StaffArray[i]->m_ID << " "
			<< this->m_StaffArray[i]->m_name << " "
			<< this->m_StaffArray[i]->m_DepID << endl;
	}

	ofs.close();
}


int staff::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num =  0 ;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}


void staff::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}else if (dId == 2)
		{
			worker = new manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new boss(id, name, dId);
		}

		this->m_StaffArray[index] = worker;
		index++;
	}
	ifs.close();

}

void staff::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_StaffNum; i++)
		{
			this->m_StaffArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}


int staff::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_StaffNum; i++)
	{
		if (this->m_StaffArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
		
	}
	return index;
}

void staff::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要删除职工的编号:" << endl;

		int id = 0;

		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_StaffNum - 1; i++)
			{
				this->m_StaffArray[i] = this->m_StaffArray[i + 1];
			}

			this->m_StaffNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

void staff::mod_Menu()
{
	cout << "\t        \t" << endl;
	cout << "  \t1.修改职工编号\t" << endl;
	cout << "  \t2.修改职工姓名\t" << endl;
	cout << "  \t3.修改职工部门\t" << endl;
	cout << "  \t4.保存\t" << endl;
	cout << "  \t5.退出修改\t" << endl;
	cout << "  \t        \t" << endl;
}
void staff::mod_Emp()
{
	int mod_id;
	string mod_name;
	int mod_dId;
	int mod_choic = 0;
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要修改职工的编号:" << endl;

		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			while (mod_choic != 5)
			{
				this->m_StaffArray[index]->showInfo();
				this->mod_Menu();

				cout << "\t请选择：\t" << endl;
				cin >> mod_choic;

				switch (mod_choic)
				{
				case 1:
				{
					cout << "请输入新的编号:" << endl;
					cin >> mod_id;
					this->m_StaffArray[index]->m_ID = mod_id;
					system("cls");
					break;
				}
				case 2:
				{
					cout << "请输入新的姓名:" << endl;
					cin >> mod_name;
					this->m_StaffArray[index]->m_name = mod_name;
					system("cls");
					break;
				}
				break;
				case 3:
				{
					cout << "请输入新的部门:" << endl;
					cin >> mod_dId;
					this->m_StaffArray[index]->m_DepID = mod_dId;
					system("cls");
					break;
				}
				case 4:
				{
					this->save();
					cout << "保存成功" << endl;
					system("cls");
					break;
				}

				}
			}

		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

void staff::Find_Emp()
{
	int f_id;
	string f_name;

	int f_choice = 0;
	
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查询的方式：1.编号 2.姓名" << endl;
		cin >> f_choice;

		switch (f_choice)
		{
		case 1:
		{
			cout << "请输入编号:" << endl;
			cin >> f_id;
			int index = this->IsExist(f_id);
			if (index != -1)
			{
				this->m_StaffArray[index]->showInfo();
			}
			else
			{
				cout << "查找失败，未找到该职工" << endl;
			}

			break;
		}
		case 2:
		{
			cout << "请输入姓名:" << endl;
			cin >> f_name;

			int index = -1;

			for (int i = 0; i < this->m_StaffNum; i++)
			{
				if (this->m_StaffArray[i]->m_name == f_name)
				{
					index = i;
					break;
				}
			}
			if (index != -1)
			{
				this->m_StaffArray[index]->showInfo();
			}
			else
			{
				cout << "查找失败，未找到该职工" << endl;
			}

			break;
		}

		}

	}
	system("pause");
	system("cls");
}

void staff::sort_Emp()
{
	int s_choice;
	int s_index = 0;
	worker* temp;

	cout << "请输入排序类型：1.编号升序 2.编号降序" << endl;
	cin >> s_choice;

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_StaffNum; i++)
		{
			s_index = i;

			for (int j = i+1; j < this->m_StaffNum; j++)
			{
				if (s_choice == 1)
				{
					if (this->m_StaffArray[s_index]->m_ID > this->m_StaffArray[j]->m_ID)
					{
						s_index = j;
					}
				}
				else
				{
					if (this->m_StaffArray[s_index]->m_ID <  this->m_StaffArray[j]->m_ID)
					{
						s_index = j;
					}
				}
				
			}
			
			temp = this->m_StaffArray[i];
			this->m_StaffArray[i] = this->m_StaffArray[s_index];
			this->m_StaffArray[s_index] = temp;
		}

		this->save();
		this->show_Emp();
	}
	//system("pause");
	system("cls");
}

void staff::clear_Emp()
{
	cout << "确定清空？1.清空 2.返回" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_StaffArray != NULL)
		{
			for (int i = 0; i < this->m_StaffNum; i++)
			{
				delete this->m_StaffArray[i];
				this->m_StaffArray[i] = NULL;
			}

			delete[] this->m_StaffArray;

			this->m_StaffArray = NULL;
			this->m_StaffNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

