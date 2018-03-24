#include "Student_info.h"
#include "Student_new.h"
#include "Dorm_info.h"
#include "search.h"
#include <vector>
#include <iostream>
#include <fstream> 

using namespace std;

iptData configData;
iptData configData_new;

//int main()
int main(int argt, char* argv[])
{
	vector<Student_new> vecStudNew;
	Student_new student;
	Dorm_info dorm;
	ifstream in;

	//�xȡ������Ϣ
	Student_new::readConfig(argv[1], configData_new);
	//Student_new::readConfig(configData_new);		//Ϊ�˷�����Զ���д�Ķ�ȡconfig.txt�ļ��ĺ������˺���ֱ�Ӵ�config.txt������Ҫ��ò���argv[1]
	cout << "������Ϣ��ʾ��ϣ�������������ɽ����ѯ����" << endl;
	system("pause");
	system("cls");

	//�����ʼ��
	dorm.floorNum = configData_new.FLOOR;
	for (int i = 0; i < configData_new.FLOOR; i++)
	{
		Dorm_floor dFloor;
		for (int j = 0; j < configData_new.ROOM; j++)
		{
			Dorm_room dRoom;
			dRoom.bedNum = configData_new.CAPACITY;
			dFloor.room.push_back(dRoom);
		}
		dFloor.roomNum = configData_new.ROOM;
		dorm.floor.push_back(dFloor);
	}

	//��dispatch.txt
	in.open(argv[2]);
	//in.open("D:\\��ѧ\\�����\\C++2017\\dispatch.txt");		//�����ҵ�����dispatch.txt��·��
	if (!in.is_open())
	{
		cout << "Error opening file dispatch.txt" << endl;
		exit(1);
	}
	while (!in.eof())
	{
		if (student.readDorm(in))
		{
			vecStudNew.push_back(student);
		}
	}

	Student_new::init(vecStudNew);
	in.close();

	//��instruction.txt
	in.open(argv[3]);
	//in.open("D:\\��ѧ\\�����\\C++2017\\instructions.txt");		//�����ҵ�����instructions.txt��·��
	if (!in.is_open())
	{
		cout << "Error opening file instruction.txt" << endl;
		exit(1);
	}
	while (!in.eof())
	{
		Student_new::readInstruct(in, vecStudNew, dorm);		//�xȡ���Nָ��
	}
	in.close();

	Student_new::putStudentInRoom(vecStudNew, dorm);		//���W�������롱�����ٵķ��g
	
	//���F����ԃ����
	search(vecStudNew, dorm);
	system("cls");
	cout << "��ѯ��ϣ��������������ʵ��Save����" << endl;
	system("pause");

	//���FSave����
	Student_new::saveData(vecStudNew, dorm);
	cout << "ʵ��Save���ܳɹ���" << endl;
	cout << "������ϣ��������������ʵ��Load���ܣ�" << endl;
	system("pause");

	vector<Student_new> vecStudNewLoad;
	Dorm_info dormLoad;
	iptData configLoad;
	//ʵ��Load����
	Student_new::loadData(vecStudNewLoad, dormLoad, configLoad);
	cout << "ʵ��Load���ܳɹ���" << endl;
	return 0;
}

/*
���ҵ����ϵ����������������²�������ȷ���д˳���
D:\\��ѧ\\�����\\C++2017\\CirDesign2017\\Debug\\CirDesign2017.exe D:\\��ѧ\\�����\\C++2017\\config.txt D:\\��ѧ\\�����\\C++2017\\dispatch.txt D:\\��ѧ\\�����\\C++2017\\instructions.txt
*/