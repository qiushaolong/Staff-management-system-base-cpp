#pragma once
#include<iostream>
#include<string>

using namespace std;


class worker
{
public:

	virtual void showInfo() = 0;

	string getDepName(int dId);
	string getJob(int dId);

	int m_ID;
	string m_name;
	int m_DepID;

};

class Employee :public worker
{
public:

	Employee(int id,string name, int dId);

	void showInfo();

	//string getDepName();

};

class manager :public worker
{
public:

	manager(int id, string name, int dId);

	void showInfo();

	//string getDepName();

};
class boss :public worker
{
public:

	boss(int id, string name, int dId);

	void showInfo();

	//string getDepName();


};