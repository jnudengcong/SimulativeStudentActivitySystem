#include "Student_new.h"
#include "search.h"
#include <iostream>

using namespace std;

void search_prompt()
{
	cout << "欢迎进入查询界面，输入0退出查询界面，输入-1清空屏幕，输入-2显示菜单" << endl;
	cout << "输入1：根據學生姓名（有可能已經退學，亦即不住在宿舍樓中）查找他（她）所在的房間號" << endl;
	cout << "输入2：根據房間號（有可能該房間號不存在）查找該房間中入住的所有學生的姓名" << endl;
	cout << "输入3：查詢某個學生的戀愛歷史" << endl;
	cout << "输入4：查詢所有學生中戀愛次數最多的人" << endl;
	cout << "输入5：查詢所有學生中歷任戀人魅力值最高的人" << endl;
	cout << "输入6：查询所有學生中体重的最大值和最小值" << endl;
	cout << "输入7：查询所有學生中金钱的最大值和最小值" << endl;
	cout << "输入8：查询所有學生中知识的最大值和最小值" << endl;
	cout << "输入9：查询所有學生中魅力的最大值和最小值" << endl;
	cout << "输入10：查询符合指定范围体重的所有学生" << endl;
	cout << "输入11：查询符合指定范围金钱的所有学生" << endl;
	cout << "输入12：查询符合指定范围知识的所有学生" << endl;
	cout << "输入13：查询符合指定范围魅力的所有学生" << endl;
}

void search(vector<Student_new>& vecStudNew, Dorm_info& dorm)
{
	int select;
	search_prompt();
	bool selectOut = false;
	while (selectOut == false)
	{
		cin >> select;
		switch (select)
		{
		case -2:
			search_prompt();
			break;
		case -1:
			system("cls");
			cout << "输入0退出查询界面，输入-1清空屏幕，输入-2显示菜单" << endl;
			break;
		case 0:
			selectOut = true;
			break;
		case 1:
			accordingNameGetRoom(vecStudNew);
			break;
		case 2:
			accordingRoomGetName(dorm);
			break;
		case 3:
			getLove(vecStudNew);
			break;
		case 4:
			loveTimesMost(vecStudNew);
			break;
		case 5:
			allLoveMost(vecStudNew);
			break;
		case 6:
			getMaxAndMin_weight(vecStudNew);
			break;
		case 7:
			getMaxAndMin_money(vecStudNew);
			break;
		case 8:
			getMaxAndMin_knowledge(vecStudNew);
			break;
		case 9:
			getMaxAndMin_charm(vecStudNew);
			break;
		case 10:
			range_weight(vecStudNew);
			break;
		case 11:
			range_money(vecStudNew);
			break;
		case 12:
			range_knowledge(vecStudNew);
			break;
		case 13:
			range_charm(vecStudNew);
			break;
		default:
			cout << "输入指令错误！" << endl;
		}
	}
}
	

void getMaxAndMin_weight(vector<Student_new>& vecStudNew)
{
	double max = vecStudNew[0].getWeight();
	double min = vecStudNew[0].getWeight();
	unsigned int max_i = 0;
	unsigned int min_i = 0;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getWeight() > max)
		{
			max = vecStudNew[i].getWeight();
			max_i = i;
		}
		if (vecStudNew[i].getWeight() < min)
		{
			min = vecStudNew[i].getWeight();
			min_i = i;
		}
	}

	cout << "所有学生中体重最大值为" << max << endl;
	cout << "所有学生中体重最小值为" << min << endl;
}

void getMaxAndMin_money(vector<Student_new>& vecStudNew)
{
	double max = vecStudNew[0].getMoney();
	double min = vecStudNew[0].getMoney();
	unsigned int max_i = 0;
	unsigned int min_i = 0;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getMoney() > max)
		{
			max = vecStudNew[i].getMoney();
			max_i = i;
		}
		if (vecStudNew[i].getMoney() < min)
		{
			min = vecStudNew[i].getMoney();
			min_i = i;
		}
	}

	cout << "所有学生中金钱最大值为" << max << endl;
	cout << "所有学生中金钱最小值为" << min << endl;
}

void getMaxAndMin_charm(vector<Student_new>& vecStudNew)
{
	double max = vecStudNew[0].getCharm();
	double min = vecStudNew[0].getCharm();
	unsigned int max_i = 0;
	unsigned int min_i = 0;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getCharm() > max)
		{
			max = vecStudNew[i].getCharm();
			max_i = i;
		}
		if (vecStudNew[i].getCharm() < min)
		{
			min = vecStudNew[i].getCharm();
			min_i = i;
		}
	}

	cout << "所有学生中魅力最大值为" << max << endl;
	cout << "所有学生中魅力最小值为" << min << endl;
}

void getMaxAndMin_knowledge(vector<Student_new>& vecStudNew)
{
	double max = vecStudNew[0].getKnowledge();
	double min = vecStudNew[0].getKnowledge();
	unsigned int max_i = 0;
	unsigned int min_i = 0;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getKnowledge() > max)
		{
			max = vecStudNew[i].getKnowledge();
			max_i = i;
		}
		if (vecStudNew[i].getKnowledge() < min)
		{
			min = vecStudNew[i].getKnowledge();
			min_i = i;
		}
	}

	cout << "所有学生中知识最大值为" << max << endl;
	cout << "所有学生中知识最小值为" << min << endl;
}

void accordingNameGetRoom(vector<Student_new>& vecStudNew)
{
	string name;
	cout << "请输入学生名字：" << endl;
	cin >> name;
	
	Student_new *pst = NULL;
	bool found = false;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size() && found == false; i++)
	{
		if (vecStudNew[i].getName() == name)
		{
			pst = &vecStudNew[i];
			found = true;
		}
	}
	if (pst == NULL)
	{
		cout << "can not find the student" << endl;
		return;
	}

	cout << name << "的房间号为" << pst->getFloor() << "-" << pst->getRoom() << endl;
}

void getLove(vector<Student_new>& vecStudNew)
{
	string name;
	cout << "请输入学生名字：" << endl;
	cin >> name;

	Student_new *pst = NULL;
	bool found = false;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size() && found == false; i++)
	{
		if (vecStudNew[i].getName() == name)
		{
			pst = &vecStudNew[i];
			found = true;
		}
	}
	if (pst == NULL)
	{
		cout << "can not find the student" << endl;
		return;
	}

	cout << "与" << name << "恋爱过的人(无名字则没恋爱过)：" << endl;
	for (unsigned int j = 0; j < pst->exCPname.size(); j++)
	{
		cout << pst->exCPname[j] << endl;
	}

	if(pst->getHaveCP() == true)
		cout << "现任女友为" << pst->getCPname() << endl;
}

void accordingRoomGetName(Dorm_info& dorm)
{
	int floor;
	int room;
	cout << "请依次输入楼层与房间号：" << endl;
	cin >> floor >> room;

	cout << "住在此房间的人为：" << endl;
	for (unsigned int i = 0; i < dorm.floor[floor - 1].room[room - 1].roomStudent.size(); i++)
	{
		cout << dorm.floor[floor - 1].room[room - 1].roomStudent[i] << endl;
	}
}

void loveTimesMost(vector<Student_new>& vecStudNew)
{
	unsigned int max = vecStudNew[0].exCPname.size();
	unsigned int max_i = 0;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].exCPname.size() > max)
		{
			max = vecStudNew[i].exCPname.size();
			max_i = i;
		}
	}
	
	cout << "恋爱次数最多的学生为" << vecStudNew[max_i].getName() << endl;
}

void range_weight(vector<Student_new>& vecStudNew)
{
	cout << "请输入指定的范围，依次输入最小值和最大值：" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "所有学生中体重符合指定范围的有(没名字则表示没有学生符合)：" << endl;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getWeight() >= min && vecStudNew[i].getWeight() <= max)
		{
			cout << vecStudNew[i].getName() << " ";
		}
	}
	cout << endl;
}

void range_money(vector<Student_new>& vecStudNew)
{
	cout << "请输入指定的范围，依次输入最小值和最大值：" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "所有学生中金钱符合指定范围的有(没名字则表示没有学生符合)：" << endl;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getMoney() >= min && vecStudNew[i].getMoney() <= max)
		{
			cout << vecStudNew[i].getName() << " ";
		}
	}
	cout << endl;
}

void range_knowledge(vector<Student_new>& vecStudNew)
{
	cout << "请输入指定的范围，依次输入最小值和最大值：" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "所有学生中知识符合指定范围的有(没名字则表示没有学生符合)：" << endl;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getKnowledge() >= min && vecStudNew[i].getKnowledge() <= max)
		{
			cout << vecStudNew[i].getName() << " ";
		}
	}
	cout << endl;
}

void range_charm(vector<Student_new>& vecStudNew)
{
	cout << "请输入指定的范围，依次输入最小值和最大值：" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "所有学生中魅力符合指定范围的有(没名字则表示没有学生符合)：" << endl;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		if (vecStudNew[i].getCharm() >= min && vecStudNew[i].getCharm() <= max)
		{
			cout << vecStudNew[i].getName() << " ";
		}
	}
	cout << endl;
}


void allLoveMost(vector<Student_new>& vecStudNew)
{
	double max = 0;
	string maxName;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		for (vector<string>::size_type j = 0; j < vecStudNew[i].exCPname.size(); j++)
		{
			Student_new *pst = NULL;
			bool found = false;
			for (vector<Student_new>::size_type k = 0; k < vecStudNew.size() && found == false; k++)
			{
				if (vecStudNew[k].getName() == vecStudNew[i].exCPname[j])
				{
					pst = &vecStudNew[k];
					found = true;
				}
			}
			if (pst == NULL)
			{
				cout << "can not find the student" << endl;
				return;
			}
			if (max == 0)
			{
				max = pst->getCharm();
				maxName = pst->getName();
			}
			if (pst->getCharm() > max)
			{
				max = pst->getCharm();
				maxName = pst->getName();
			}
		}
	}
	
	if (max != 0)
		cout << "所有學生中歷任戀人魅力值最高的人是" << maxName << ",魅力值是" << max << endl;
	else
		cout << "所有学生都没有历任恋人" << endl;

}