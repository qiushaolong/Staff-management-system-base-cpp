#include"worker.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DepID = dId;
}

void Employee::showInfo()//显示xx
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDepName(this->m_DepID)
		<< "\t岗位职责：" << this->getJob(this->m_DepID) << endl;
}

string worker::getDepName(int dId)
{
	switch (dId)
	{
	case 1:
		return string("员工");
	case 2:
		return string("经理");
	case 3:
		return string("总裁");
	}
}

string worker::getJob(int dId)
{
	switch (dId)
	{
	case 1:
		return string("完成经理交给的任务");
	case 2:
		return string("完成老板交给的任务，并下发给普通员工");
	case 3:
		return string("管理公司事物");
	}
}

manager::manager(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DepID = dId;
}

void manager::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDepName(this->m_DepID)
		<< "\t岗位职责："<< this->getJob(this->m_DepID) << endl;
}

//string manager::getDepName()
//{
//	return string("经理");
//}

boss::boss(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DepID = dId;
}

void boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDepName(this->m_DepID)
		<< "\t岗位职责：" << this->getJob(this->m_DepID) << endl;
}

//string boss::getDepName()
//{
//	return string("总裁");
//}
