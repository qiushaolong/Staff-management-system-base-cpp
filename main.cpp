#include<iostream>
#include<string>

#include"staff_class.h"
#include"worker.h"
using namespace std;


int main()
{
	staff tf;
	int choice = 0;

	while (true)
	{
		tf.show_Menu();
		cout << "请输入指令：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://添加职工
			tf.Add_staff();
			break;

		case 2://添加职工
			tf.show_Emp();
			break;

		case 3://删除职工
			tf.del_Emp();
			break;

		case 4://修改职工
			tf.mod_Emp();
			break;

		case 5://查找职工
			tf.Find_Emp();
			break;

		case 6://职工排序
			tf.sort_Emp();
			break;

		case 7://清空
			tf.clear_Emp();
			break;

		case 8://退出系统
			tf.sxit_system();
			break;
		}
	}

	system("pause");
	return 0;
}

