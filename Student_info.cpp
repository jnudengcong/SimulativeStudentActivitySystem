#include "Student_info.h"
#include "Dorm_info.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Student_info::init(vector<Student_info>& vecStudent)
{
	extern iptData configData;
	for (vector<Student_info>::size_type i = 0; i < vecStudent.size(); i++)
	{
		vecStudent[i].assignWeight(configData.WEIGHT);
		vecStudent[i].assignMoney(configData.MONEY);
		vecStudent[i].assignKnowledge(configData.KNOWLEDGE);
		vecStudent[i].assignCharm(configData.CHARM);
	}
}

ifstream& Student_info::readDorm(ifstream& is)
{
	char ch;
	is >> name >> sex >> floor >> ch >> room;

	return is;
}

ifstream& Student_info::changeDorm(ifstream& is, Dorm_info& dorm)
{
	string tempStr;
	int tempInt;
	char tempCh;

	is >> tempStr;					//FROM
	is >> tempInt;					//previous floor
	is >> tempCh;					//-
	is >> tempInt;					//previous room
	is >> tempStr;					//TO
	is >> floor;
	is >> tempCh;					//-
	is >> room;

	return is;
}

void Student_info::dropOut()
{
	isEnrol = false;
}

void Student_info::enrol(ifstream& is)
{
	char tempCh;
	string tempStr;
	is >> tempStr;					//ENROL
	is >> floor;
	is >> tempCh;					//-
	is >> room;
	isEnrol = true;
}

void Student_info::love(ifstream& is, vector<Student_info>& vecStudent)
{
	string beLoveName;
	is >> beLoveName;

	Student_info *pst = NULL;
	bool found = false;
	for (vector<Student_info>::size_type i = 0; i < vecStudent.size() && found == false; i++)
	{
		if (vecStudent[i].getName() == beLoveName)
		{
			pst = &vecStudent[i];
			found = true;
		}
	}
	if (pst == NULL)
	{
		cout << "can not find the student about love" << endl;
		exit(1);
	}

	extern iptData configData;
	double Delta;
	Delta = abs(getCharm() - pst->getCharm()) / max(getCharm(), pst->getCharm());
	//Delta = 0;
	/*
	if (getHaveCP() == true || pst->getHaveCP() == true)
	{
	cout << "wrong instruction about love" << endl;
	exit(1);
	}
	*/

	if (pst->getHaveCP() == true)
	{
		if (pst->pursueTimes[getName()] < 0 || pst->pursueTimes[getName()] > 3)
		{
			pst->pursueTimes[getName()] = 0;
		}
		pst->pursueTimes[getName()] += 1;

		Student_info *preCP = NULL;
		bool isFound = false;
		for (vector<Student_info>::size_type i = 0; i < vecStudent.size() && isFound == false; i++)
		{
			if (vecStudent[i].getName() == pst->getCPname())
			{
				preCP = &vecStudent[i];
				isFound = true;
			}
		}
		if (preCP == NULL)
		{
			cout << "can not find the student about previous CP" << endl;
			exit(1);
		}

		if (pst->pursueTimes[getName()] == 3 && getCharm() > preCP->getCharm() + configData.LOVE_RECONSTUCT_STANDARD)
		{
			assignHaveCP(true);
			assignCPname(beLoveName);
			pst->exCPname.push_back(pst->getCPname());
			pst->assignCPname(getName());
		}
	}

	if (pst->getHaveCP() == false && getHaveCP() == false && Delta <= configData.LOVE_STANDARD)
	{
		assignHaveCP(true);
		assignCPname(beLoveName);
		pst->assignHaveCP(true);
		pst->assignCPname(getName());
	}


}

void Student_info::breakUp(ifstream& is, vector<Student_info>& vecStudent)
{
	string tempCh;
	is >> tempCh;	//UP

	exCPname.push_back(CPname);
	assignHaveCP(false);

	Student_info *pst = NULL;
	bool found = false;
	for (vector<Student_info>::size_type i = 0; i < vecStudent.size() && found == false; i++)
	{
		if (vecStudent[i].getName() == getCPname())
		{
			pst = &vecStudent[i];
			found = true;
		}
	}
	if (pst == NULL)
	{
		cout << "can not find the student about break up" << endl;
		exit(1);
	}

	pst->exCPname.push_back(pst->getCPname());
	pst->assignHaveCP(false);
}

void Student_info::doSth(double workTime, double studyTime, double eatTaken)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	extern iptData configData;
	double WEIGHT_INC;
	double MONEY_INC;
	double KNOWLEDGE_INC;
	double CHARM_INC;

	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;

	symbol_table.add_variable("FOOD_TAKEN", eatTaken);
	symbol_table.add_variable("STUDY_TIME", studyTime);
	symbol_table.add_variable("WORK_TIME", workTime);
	symbol_table.add_variable("FOOD_WEIGHT", configData.FOOD_WEIGHT);
	symbol_table.add_variable("STUDY_WEIGHT", configData.STUDY_WEIGHT);
	symbol_table.add_variable("WORK_WEIGHT", configData.WORK_WEIGHT);

	symbol_table.add_variable("WORK_MONEY", configData.WORK_MONEY);
	symbol_table.add_variable("FOOD_COST", configData.FOOD_COST);
	symbol_table.add_variable("STUDY_KNOWLEDGE", configData.STUDY_KNOWLEDGE);

	symbol_table.add_variable("KNOWLEDGE_INC", KNOWLEDGE_INC);
	symbol_table.add_variable("WEIGHT_INC", WEIGHT_INC);

	symbol_table.add_constants();
	expression.register_symbol_table(symbol_table);

	parser.compile(configData.iptConfigVecStr[0], expression);
	WEIGHT_INC = expression.value();
	parser.compile(configData.iptConfigVecStr[1], expression);
	MONEY_INC = expression.value();
	parser.compile(configData.iptConfigVecStr[2], expression);
	KNOWLEDGE_INC = expression.value();
	parser.compile(configData.iptConfigVecStr[3], expression);
	CHARM_INC = expression.value();

	assignWeight(getWeight() + WEIGHT_INC);
	if (getWeight() < 0)
		assignWeight(0);

	assignMoney(getMoney() + MONEY_INC);
	assignKnowledge(getKnowledge() + KNOWLEDGE_INC);

	assignCharm(getCharm() + CHARM_INC);
	if (getCharm() < 1)
		assignCharm(1);
	else if (getCharm() > 100)
		assignCharm(100);
}

ifstream& Student_info::readInstruct(ifstream& is, vector<Student_info>& vecStudent, Dorm_info& dorm)
{
	string str;
	is >> str;
	if (str == "ADD")
	{
		readAddDorm(is, dorm);
	}
	else
	{
		Student_info::readDoSth(is, vecStudent, str, dorm);
	}

	return is;
}

ifstream& Student_info::readDoSth(ifstream& is, vector<Student_info>& vecStudent, const string& str, Dorm_info& dorm)
{
	Student_info *pst = NULL;
	bool found = false;
	for (vector<Student_info>::size_type i = 0; i < vecStudent.size() && found == false; i++)
	{
		if (vecStudent[i].getName() == str)
		{
			pst = &vecStudent[i];
			found = true;
		}
	}

	double workTime = 0;
	double studyTime = 0;
	double eatTaken = 0;

	while (is)
	{
		string doStr;
		is >> doStr;
		if (doStr == "ADD")
		{
			readAddDorm(is, dorm);
		}
		else if (doStr == "WORK")
		{
			is >> workTime;
		}
		else if (doStr == "STUDY")
		{

			is >> studyTime;
		}
		else if (doStr == "EAT")
		{

			is >> eatTaken;
		}
		else if (doStr == "MOVE")
		{
			pst->changeDorm(is, dorm);
		}
		else if (doStr == "WOO")
		{
			pst->love(is, vecStudent);
		}
		else if (doStr == "男" || doStr == "女")
		{
			pst->enrol(is);
		}
		else if (doStr == "QUIT")
		{
			pst->dropOut();
		}
		else if (doStr == "BREAK")
		{
			pst->breakUp(is, vecStudent);
		}
		else
		{
			pst->doSth(workTime, studyTime, eatTaken);
			Student_info::readDoSth(is, vecStudent, doStr, dorm);		//此时doStr为姓名
		}
	}

	return is;
}

void Student_info::readConfig(char* config, iptData& configData)
{
	string tempStr;
	char tempCh;
	ifstream in;
	vector<string> configVecStr;
	in.open(config);
	if (!in.is_open())
	{
		cout << "Error opening file " + *config << endl;
		exit(1);
	}
	while (!in.eof())
	{
		getline(in, tempStr);
		if (tempStr[0] != '/'&& tempStr[0] != '\0')
		{
			cout << tempStr << endl;
			configVecStr.push_back(tempStr);
		}
	}
	in.close();

	//创建out_config.txt，将从config.txt解析出来的重要信息存于其中
	ofstream out("d:\\out_config.txt");
	if (out.is_open())
	{
		for (vector<string>::size_type i = 0; i < configVecStr.size(); i++)
		{
			out << configVecStr[i] << endl;
		}
	}
	out.close();

	in.open("d:\\out_config.txt");
	in >> tempStr >> configData.FLOOR;
	in >> tempStr >> configData.ROOM;
	in >> tempStr >> configData.CAPACITY;
	in >> tempStr >> configData.WEIGHT;
	in >> tempStr >> configData.MONEY;
	in >> tempStr >> configData.KNOWLEDGE;
	in >> tempStr >> configData.CHARM;
	in >> tempStr >> configData.FOOD_WEIGHT;
	in >> tempStr >> configData.FOOD_COST;
	in >> tempStr >> configData.STUDY_WEIGHT;
	in >> tempStr >> configData.STUDY_KNOWLEDGE;
	in >> tempStr >> configData.WORK_MONEY;
	in >> tempStr >> configData.WORK_WEIGHT;
	for (vector<string>::size_type i = 0; i < 4; i++)
	{
		string expStr;
		in >> tempStr >> tempCh;
		in.get();
		getline(in, expStr);
		configData.iptConfigVecStr.push_back(expStr);
	}
	in >> tempStr >> configData.LOVE_STANDARD;
	in >> tempStr >> configData.SAVE_FILE_NAME;
	in.close();
}

void Student_info::putStudentInRoom(vector<Student_info>& vecStudent, Dorm_info& dorm)
{
	extern iptData configData;
	for (int i = 1; i <= configData.FLOOR; i++)
	{
		for (int j = 1; j <= configData.ROOM; j++)
		{
			for (unsigned int n = 0; n < vecStudent.size(); n++)
			{
				if (vecStudent[n].getFloor() == i && vecStudent[n].getRoom() == j)
				{
					dorm.floor[i - 1].room[j - 1].roomStudent.push_back(vecStudent[n].getName());
				}
			}
		}
	}
}



//为了方便调试而编写的读取config.txt文件的函数，此函数直接打开config.txt，不需要获得参数argv[1]
void Student_info::readConfig(iptData& configData)
{
	string tempStr;
	char tempCh;
	ifstream in;
	vector<string> configVecStr;
	in.open("D:\\大学\\大二上\\C++2017\\sample_config.txt");
	if (!in.is_open())
	{
		cout << "Error opening file config.txt" << endl;
		exit(1);
	}
	while (!in.eof())
	{
		getline(in, tempStr);
		if (tempStr[0] != '/'&& tempStr[0] != '\0')
		{
			cout << tempStr << endl;
			configVecStr.push_back(tempStr);
		}
	}
	in.close();

	//创建out_config.txt，将从config.txt解析出来的重要信息存于其中
	ofstream out("d:\\out_config.txt");
	if (out.is_open())
	{
		for (vector<string>::size_type i = 0; i < configVecStr.size(); i++)
		{
			out << configVecStr[i] << endl;
		}
	}
	out.close();

	in.open("d:\\out_config.txt");
	in >> tempStr >> configData.FLOOR;
	in >> tempStr >> configData.ROOM;
	in >> tempStr >> configData.CAPACITY;
	in >> tempStr >> configData.WEIGHT;
	in >> tempStr >> configData.MONEY;
	in >> tempStr >> configData.KNOWLEDGE;
	in >> tempStr >> configData.CHARM;
	in >> tempStr >> configData.FOOD_WEIGHT;
	in >> tempStr >> configData.FOOD_COST;
	in >> tempStr >> configData.STUDY_WEIGHT;
	in >> tempStr >> configData.STUDY_KNOWLEDGE;
	in >> tempStr >> configData.WORK_MONEY;
	in >> tempStr >> configData.WORK_WEIGHT;
	for (vector<string>::size_type i = 0; i < 4; i++)
	{
		string expStr;
		in >> tempStr >> tempCh;
		in.get();
		getline(in, expStr);
		configData.iptConfigVecStr.push_back(expStr);
	}
	in >> tempStr >> configData.LOVE_STANDARD;
	in >> tempStr >> configData.LOVE_RECONSTUCT_STANDARD;
	in >> tempStr >> configData.SAVE_FILE_NAME;
	in.close();
}

void Student_info::saveData(vector<Student_info>& vecStudent, Dorm_info& dorm)
{
	extern iptData configData;
	ofstream out;
	ifstream in;
	in.open("d:\\out_config.txt");
	if (!in.is_open())
	{
		cout << "Error opening file out_config.txt" << endl;
		exit(1);
	}
	out.open("d:\\" + configData.SAVE_FILE_NAME);
	if (!out.is_open())
	{
		cout << "Error opening file " << configData.SAVE_FILE_NAME << endl;
		exit(1);
	}
	out << "//以下为config.txt中各参数与公式" << endl;
	while (!in.eof())
	{
		string tempStr;
		getline(in, tempStr);
		out << tempStr << endl;
	}
	out << "**********************************************" << endl;
	out << "//以下为学生的数据" << endl;

	for (vector<Student_info>::size_type i = 0; i < vecStudent.size(); i++)
	{
		out << vecStudent[i].getName() << "\t"
			<< vecStudent[i].getSex() << "\t"
			<< vecStudent[i].getFloor() << "\t"
			<< vecStudent[i].getRoom() << "\t"
			<< vecStudent[i].getMoney() << "\t"
			<< vecStudent[i].getCharm() << "\t"
			<< vecStudent[i].getWeight() << "\t"
			<< vecStudent[i].getKnowledge() << "\t"
			<< vecStudent[i].getIsEnrol() << "\t"
			<< vecStudent[i].getHaveCP() << "\t";
		if (vecStudent[i].getHaveCP() == true)
		{
			out << vecStudent[i].getCPname() << "\t";
		}
		out << vecStudent[i].exCPname.size() << "\t";
		for (vector<string>::size_type j = 0; j < vecStudent[i].exCPname.size(); j++)
		{
			out << vecStudent[i].exCPname[j] << "\t";
		}
		out << endl;
	}
	out << "**********************************************" << endl;
	out << "//以下为宿舍的数据" << endl;
	out << configData.FLOOR << "\t" << configData.ROOM << "\t" << configData.CAPACITY << endl;
	for (int m = 0; m < configData.FLOOR; m++)
	{
		for (int n = 0; n < configData.ROOM; n++)
		{
			out << m + 1 << "-" << n + 1 << ":\t" << dorm.floor[m].room[n].roomStudent.size() << "\t";
			for (unsigned int k = 0; k < dorm.floor[m].room[n].roomStudent.size(); k++)
			{
				out << dorm.floor[m].room[n].roomStudent[k] << "\t";
			}
			out << endl;
		}
	}


	out.close();
	in.close();
}

void Student_info::loadData(vector<Student_info>& vecStudent, Dorm_info& dorm, iptData& configLoad)
{
	extern iptData configData;
	string tempStr;
	char tempCh;
	int tempInt;
	double tempDou;
	bool tempBo;
	ifstream in;

	in.open("d:\\" + configData.SAVE_FILE_NAME);
	if (!in.is_open())
	{
		cout << "can not open the file " + configData.SAVE_FILE_NAME << endl;
		exit(1);
	}
	in >> tempStr;
	in >> tempStr >> configLoad.FLOOR;
	in >> tempStr >> configLoad.ROOM;
	in >> tempStr >> configLoad.CAPACITY;
	in >> tempStr >> configLoad.WEIGHT;
	in >> tempStr >> configLoad.MONEY;
	in >> tempStr >> configLoad.KNOWLEDGE;
	in >> tempStr >> configLoad.CHARM;
	in >> tempStr >> configLoad.FOOD_WEIGHT;
	in >> tempStr >> configLoad.FOOD_COST;
	in >> tempStr >> configLoad.STUDY_WEIGHT;
	in >> tempStr >> configLoad.STUDY_KNOWLEDGE;
	in >> tempStr >> configLoad.WORK_MONEY;
	in >> tempStr >> configLoad.WORK_WEIGHT;
	for (vector<string>::size_type i = 0; i < 4; i++)
	{
		string expStr;
		in >> tempStr >> tempCh;
		in.get();
		getline(in, expStr);
		configLoad.iptConfigVecStr.push_back(expStr);
	}
	in >> tempStr >> configLoad.LOVE_STANDARD;
	in >> tempStr >> configLoad.LOVE_RECONSTUCT_STANDARD;
	in >> tempStr >> configLoad.SAVE_FILE_NAME;

	in >> tempStr;
	//cout << tempStr << endl;
	in >> tempStr;
	//cout << tempStr << endl;

	bool isLastStudent = false;
	while (!isLastStudent)
	{
		Student_info student;
		in >> tempStr;
		student.assignName(tempStr);
		if (student.getName().at(0) == '*')
		{
			isLastStudent = true;
			break;
		}
		in >> tempStr;
		student.assignSex(tempStr);
		in >> tempInt;
		student.assignFloor(tempInt);
		in >> tempInt;
		student.assignRoom(tempInt);
		in >> tempDou;
		student.assignMoney(tempDou);
		in >> tempDou;
		student.assignCharm(tempDou);
		in >> tempDou;
		student.assignWeight(tempDou);
		in >> tempDou;
		student.assignKnowledge(tempDou);
		in >> tempBo;
		student.assignIsEnrol(tempBo);
		in >> tempBo;
		student.assignHaveCP(tempBo);
		if (student.getHaveCP() == true)
		{
			in >> tempStr;
			student.assignCPname(tempStr);
		}
		int exCPsize;
		in >> exCPsize;
		for (int i = 0; i < exCPsize; i++)
		{
			string tempName;
			in >> tempName;
			student.exCPname.push_back(tempName);
		}
		vecStudent.push_back(student);

	}

	//cout << vecStudent[3].knowledge << endl;

	in >> tempStr;
	//cout << tempStr << endl;

	in >> configLoad.FLOOR
		>> configLoad.ROOM
		>> configLoad.CAPACITY;

	//宿舍初始化
	dorm.floorNum = configLoad.FLOOR;
	for (int i = 0; i < configLoad.FLOOR; i++)
	{
		Dorm_floor dFloor;
		for (int j = 0; j < configLoad.ROOM; j++)
		{
			Dorm_room dRoom;
			dRoom.bedNum = configLoad.CAPACITY;
			dFloor.room.push_back(dRoom);
		}
		dFloor.roomNum = configLoad.ROOM;
		dorm.floor.push_back(dFloor);
	}

	for (int floor = 0; floor < configLoad.FLOOR; floor++)
	{
		for (int room = 0; room < configLoad.ROOM; room++)
		{
			in >> tempStr;
			int studentSize;
			in >> studentSize;
			for (int i = 0; i < studentSize; i++)
			{
				string studentName;
				in >> studentName;
				dorm.floor[floor].room[room].roomStudent.push_back(studentName);
			}
		}
	}

	in.close();

	//cout << dorm.floor[8].room[0].roomStudent[2] << endl;
}

