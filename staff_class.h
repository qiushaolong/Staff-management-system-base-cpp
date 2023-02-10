#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include"worker.h"
using namespace std;

#define FILENAME "emFile.txt"

class staff
{
public:

	staff();

	void show_Menu();
	void sxit_system();

	int m_StaffNum;//记录职工人数
	worker** m_StaffArray;//职工数组指针

	void Add_staff();

	void save();//保存文件

	bool m_FileIsEmpty;//文件是否为空

	int get_EmpNum();//读取文件人数

	void init_Emp();//初始化员工

	void show_Emp();//显示员工

	int IsExist(int id);//判断职工是否存在

	void del_Emp();//删除职工

	void mod_Emp();//修改职工
	void mod_Menu();

	void Find_Emp();//查找职工

	void sort_Emp();//职工排序

	void clear_Emp();//职工排序

	~staff();

};
