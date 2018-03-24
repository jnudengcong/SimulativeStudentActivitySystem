#include "Student_new.h"
#include "search.h"
#include <iostream>

using namespace std;

void search_prompt()
{
	cout << "��ӭ�����ѯ���棬����0�˳���ѯ���棬����-1�����Ļ������-2��ʾ�˵�" << endl;
	cout << "����1�������W���������п����ѽ��ˌW���༴��ס��������У����������������ڵķ��g̖" << endl;
	cout << "����2���������g̖���п���ԓ���g̖�����ڣ�����ԓ���g����ס�����ЌW��������" << endl;
	cout << "����3����ԃĳ���W���đِۚvʷ" << endl;
	cout << "����4����ԃ���ЌW���Бِ۴Δ�������" << endl;
	cout << "����5����ԃ���ЌW���Кv�Α�������ֵ��ߵ���" << endl;
	cout << "����6����ѯ���ЌW�������ص����ֵ����Сֵ" << endl;
	cout << "����7����ѯ���ЌW���н�Ǯ�����ֵ����Сֵ" << endl;
	cout << "����8����ѯ���ЌW����֪ʶ�����ֵ����Сֵ" << endl;
	cout << "����9����ѯ���ЌW�������������ֵ����Сֵ" << endl;
	cout << "����10����ѯ����ָ����Χ���ص�����ѧ��" << endl;
	cout << "����11����ѯ����ָ����Χ��Ǯ������ѧ��" << endl;
	cout << "����12����ѯ����ָ����Χ֪ʶ������ѧ��" << endl;
	cout << "����13����ѯ����ָ����Χ����������ѧ��" << endl;
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
			cout << "����0�˳���ѯ���棬����-1�����Ļ������-2��ʾ�˵�" << endl;
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
			cout << "����ָ�����" << endl;
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

	cout << "����ѧ�����������ֵΪ" << max << endl;
	cout << "����ѧ����������СֵΪ" << min << endl;
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

	cout << "����ѧ���н�Ǯ���ֵΪ" << max << endl;
	cout << "����ѧ���н�Ǯ��СֵΪ" << min << endl;
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

	cout << "����ѧ�����������ֵΪ" << max << endl;
	cout << "����ѧ����������СֵΪ" << min << endl;
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

	cout << "����ѧ����֪ʶ���ֵΪ" << max << endl;
	cout << "����ѧ����֪ʶ��СֵΪ" << min << endl;
}

void accordingNameGetRoom(vector<Student_new>& vecStudNew)
{
	string name;
	cout << "������ѧ�����֣�" << endl;
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

	cout << name << "�ķ����Ϊ" << pst->getFloor() << "-" << pst->getRoom() << endl;
}

void getLove(vector<Student_new>& vecStudNew)
{
	string name;
	cout << "������ѧ�����֣�" << endl;
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

	cout << "��" << name << "����������(��������û������)��" << endl;
	for (unsigned int j = 0; j < pst->exCPname.size(); j++)
	{
		cout << pst->exCPname[j] << endl;
	}

	if(pst->getHaveCP() == true)
		cout << "����Ů��Ϊ" << pst->getCPname() << endl;
}

void accordingRoomGetName(Dorm_info& dorm)
{
	int floor;
	int room;
	cout << "����������¥���뷿��ţ�" << endl;
	cin >> floor >> room;

	cout << "ס�ڴ˷������Ϊ��" << endl;
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
	
	cout << "������������ѧ��Ϊ" << vecStudNew[max_i].getName() << endl;
}

void range_weight(vector<Student_new>& vecStudNew)
{
	cout << "������ָ���ķ�Χ������������Сֵ�����ֵ��" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "����ѧ�������ط���ָ����Χ����(û�������ʾû��ѧ������)��" << endl;
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
	cout << "������ָ���ķ�Χ������������Сֵ�����ֵ��" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "����ѧ���н�Ǯ����ָ����Χ����(û�������ʾû��ѧ������)��" << endl;
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
	cout << "������ָ���ķ�Χ������������Сֵ�����ֵ��" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "����ѧ����֪ʶ����ָ����Χ����(û�������ʾû��ѧ������)��" << endl;
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
	cout << "������ָ���ķ�Χ������������Сֵ�����ֵ��" << endl;

	double min;
	double max;
	cin >> min >> max;

	cout << "����ѧ������������ָ����Χ����(û�������ʾû��ѧ������)��" << endl;
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
		cout << "���ЌW���Кv�Α�������ֵ��ߵ�����" << maxName << ",����ֵ��" << max << endl;
	else
		cout << "����ѧ����û����������" << endl;

}