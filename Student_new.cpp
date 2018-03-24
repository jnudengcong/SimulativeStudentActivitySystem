#include "Student_new.h"
#include <iostream>

using namespace std;

void Student_new::readConfig(char* config, iptData& configData)
{
	string tempStr;
	char tempCh;
	ifstream in;
	vector<string> configVecStr;
	in.open(config);
	if (!in.is_open())
	{
		cout << "Error opening file config.txt" << endl;
		exit(1);
	}
	cout << "以下为文件config.txt中的重要信息：" << endl;
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

	//创建out_config_new.txt，将从config.txt解析出来的重要信息存于其中
	ofstream out("d:\\out_config_new.txt");
	if (out.is_open())
	{
		for (vector<string>::size_type i = 0; i < configVecStr.size(); i++)
		{
			out << configVecStr[i] << endl;
		}
	}
	out.close();

	in.open("d:\\out_config_new.txt");
	in >> tempStr >> configData.FLOOR;
	in >> tempStr >> configData.ROOM;
	in >> tempStr >> configData.CAPACITY;
	in >> tempStr >> configData.WEIGHT;
	in >> tempStr >> configData.MONEY;
	in >> tempStr >> configData.KNOWLEDGE;
	in >> tempStr >> configData.CHARM;
	in >> tempStr >> configData.HEALTH;
	in >> tempStr >> configData.LOOKS;
	in >> tempStr >> configData.FOOD_WEIGHT;
	in >> tempStr >> configData.FOOD_COST;
	in >> tempStr >> configData.STUDY_WEIGHT;
	in >> tempStr >> configData.STUDY_KNOWLEDGE;
	in >> tempStr >> configData.WORK_MONEY;
	in >> tempStr >> configData.WORK_WEIGHT;
	in >> tempStr >> configData.EXERCISE_WEIGHT;
	in >> tempStr >> configData.EXERCISE_HEALTH;
	in >> tempStr >> configData.MAKEUP_MONEY;
	in >> tempStr >> configData.MAKEUP_LOOKS;

	//i = 0, knowledge增量公式; i = 1, 男weight增量公式;
	//i = 2, 男money增量公式; i = 3, 男health增量公式;
	//i = 4, 女money增量公式; i = 5, 女weight增量公式;
	//i = 6, 女looks增量公式; i = 7, 男charm增量公式;
	//i = 8, 女charm增量公式;
	for (vector<string>::size_type i = 0; i < 7; i++)
	{
		string expStr;
		in >> tempStr >> tempCh;
		in.get();
		getline(in, expStr);
		configData.iptConfigVecStr.push_back(expStr);
	}

	string charmStr[6];
	in >> tempStr >> tempCh;
	in.get();
	getline(in, charmStr[0]);
	getline(in, charmStr[1]);
	getline(in, charmStr[2]);
	//男生魅力增量公式
	configData.iptConfigVecStr.push_back(charmStr[0] + charmStr[1] + charmStr[2]);

	in >> tempStr >> tempCh;
	in.get();
	getline(in, charmStr[3]);
	getline(in, charmStr[4]);
	getline(in, charmStr[5]);
	//女生魅力增量公式
	configData.iptConfigVecStr.push_back(charmStr[3] + charmStr[4] + charmStr[5]);

	in >> tempStr >> configData.LOVE_STANDARD;
	in >> tempStr >> configData.LOVE_RECONSTUCT_STANDARD;
	in >> tempStr >> configData.SAVE_FILE_NAME;
	in.close();
}

void Student_new::readConfig(iptData& configData)
{
	string tempStr;
	char tempCh;
	ifstream in;
	vector<string> configVecStr;
	in.open("D:\\大学\\大二上\\C++2017\\config.txt");
	if (!in.is_open())
	{
		cout << "Error opening file config.txt" << endl;
		exit(1);
	}
	cout << "以下为文件config.txt中的重要信息：" << endl;
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

	//创建out_config_new.txt，将从config.txt解析出来的重要信息存于其中
	ofstream out("d:\\out_config_new.txt");
	if (out.is_open())
	{
		for (vector<string>::size_type i = 0; i < configVecStr.size(); i++)
		{
			out << configVecStr[i] << endl;
		}
	}
	out.close();

	in.open("d:\\out_config_new.txt");
	in >> tempStr >> configData.FLOOR;
	in >> tempStr >> configData.ROOM;
	in >> tempStr >> configData.CAPACITY;
	in >> tempStr >> configData.WEIGHT;
	in >> tempStr >> configData.MONEY;
	in >> tempStr >> configData.KNOWLEDGE;
	in >> tempStr >> configData.CHARM;
	in >> tempStr >> configData.HEALTH;
	in >> tempStr >> configData.LOOKS;
	in >> tempStr >> configData.FOOD_WEIGHT;
	in >> tempStr >> configData.FOOD_COST;
	in >> tempStr >> configData.STUDY_WEIGHT;
	in >> tempStr >> configData.STUDY_KNOWLEDGE;
	in >> tempStr >> configData.WORK_MONEY;
	in >> tempStr >> configData.WORK_WEIGHT;
	in >> tempStr >> configData.EXERCISE_WEIGHT;
	in >> tempStr >> configData.EXERCISE_HEALTH;
	in >> tempStr >> configData.MAKEUP_MONEY;
	in >> tempStr >> configData.MAKEUP_LOOKS;

	//i = 0, knowledge增量公式; i = 1, 男weight增量公式;
	//i = 2, 男money增量公式; i = 3, 男health增量公式;
	//i = 4, 女money增量公式; i = 5, 女weight增量公式;
	//i = 6, 女looks增量公式; i = 7, 男charm增量公式;
	//i = 8, 女charm增量公式;
	for (vector<string>::size_type i = 0; i < 7; i++)
	{
		string expStr;
		in >> tempStr >> tempCh;
		in.get();
		getline(in, expStr);
		configData.iptConfigVecStr.push_back(expStr);
	}

	string charmStr[6];
	in >> tempStr >> tempCh;
	in.get();
	getline(in, charmStr[0]);
	getline(in, charmStr[1]);
	getline(in, charmStr[2]);
	//男生魅力增量公式
	configData.iptConfigVecStr.push_back(charmStr[0] + charmStr[1] + charmStr[2]);
	
	in >> tempStr >> tempCh;
	in.get();
	getline(in, charmStr[3]);
	getline(in, charmStr[4]);
	getline(in, charmStr[5]);
	//女生魅力增量公式
	configData.iptConfigVecStr.push_back(charmStr[3] + charmStr[4] + charmStr[5]);
	
	in >> tempStr >> configData.LOVE_STANDARD;
	in >> tempStr >> configData.LOVE_RECONSTUCT_STANDARD;
	in >> tempStr >> configData.SAVE_FILE_NAME;
	in.close();

}

void Student_new::doSth(double workTime, double studyTime,
	double eatTaken, double exerciseTime, double makeupTime)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	extern iptData configData_new;
	double WEIGHT_INC;
	double MONEY_INC;
	double KNOWLEDGE_INC;
	double CHARM_INC;
	double HEALTH_INC;
	double LOOKS_INC;

	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;

	symbol_table.add_variable("FOOD_TAKEN", eatTaken);
	symbol_table.add_variable("STUDY_TIME", studyTime);
	symbol_table.add_variable("WORK_TIME", workTime);
	symbol_table.add_variable("EXERCISE_TIME", exerciseTime);
	symbol_table.add_variable("MAKEUP_TIME", makeupTime);
	
	symbol_table.add_variable("FOOD_WEIGHT", configData_new.FOOD_WEIGHT);
	symbol_table.add_variable("STUDY_WEIGHT", configData_new.STUDY_WEIGHT);
	symbol_table.add_variable("WORK_WEIGHT", configData_new.WORK_WEIGHT);
	symbol_table.add_variable("EXERCISE_WEIGHT", configData_new.EXERCISE_WEIGHT);
	
	symbol_table.add_variable("WORK_MONEY", configData_new.WORK_MONEY);
	symbol_table.add_variable("FOOD_COST", configData_new.FOOD_COST);
	symbol_table.add_variable("MAKEUP_MONEY", configData_new.MAKEUP_MONEY);
	symbol_table.add_variable("MAKEUP_LOOKS", configData_new.MAKEUP_LOOKS);
	symbol_table.add_variable("STUDY_KNOWLEDGE", configData_new.STUDY_KNOWLEDGE);
	symbol_table.add_variable("EXERCISE_HEALTH", configData_new.EXERCISE_HEALTH);

	symbol_table.add_variable("KNOWLEDGE_INC", KNOWLEDGE_INC);
	symbol_table.add_variable("WEIGHT_INC", WEIGHT_INC);
	symbol_table.add_variable("HEALTH_INC", HEALTH_INC);
	symbol_table.add_variable("LOOKS_INC", LOOKS_INC);

	symbol_table.add_constants();
	expression.register_symbol_table(symbol_table);

	parser.compile(configData_new.iptConfigVecStr[0], expression);
	KNOWLEDGE_INC = expression.value();
	if (getSex() == "男")
	{
		parser.compile(configData_new.iptConfigVecStr[1], expression);
		WEIGHT_INC = expression.value();
		parser.compile(configData_new.iptConfigVecStr[2], expression);
		MONEY_INC = expression.value();
		parser.compile(configData_new.iptConfigVecStr[3], expression);
		HEALTH_INC = expression.value();
		parser.compile(configData_new.iptConfigVecStr[7], expression);
		CHARM_INC = expression.value();

		assignWeight(getWeight() + WEIGHT_INC);
		if (getWeight() < 0)
			assignWeight(0);
		assignMoney(getMoney() + MONEY_INC);
		assignKnowledge(getKnowledge() + KNOWLEDGE_INC);
		assignHealth(getHealth() + HEALTH_INC);
		if (getHealth() < 1)
			assignHealth(1);
		else if (getHealth() > 100)
			assignHealth(100);
	}
	else if (getSex() == "女")
	{
		parser.compile(configData_new.iptConfigVecStr[5], expression);
		WEIGHT_INC = expression.value();
		parser.compile(configData_new.iptConfigVecStr[4], expression);
		MONEY_INC = expression.value();
		parser.compile(configData_new.iptConfigVecStr[6], expression);
		LOOKS_INC = expression.value();
		parser.compile(configData_new.iptConfigVecStr[8], expression);
		CHARM_INC = expression.value();

		assignWeight(getWeight() + WEIGHT_INC);
		if (getWeight() < 0)
			assignWeight(0);
		assignMoney(getMoney() + MONEY_INC);
		assignKnowledge(getKnowledge() + KNOWLEDGE_INC);
		assignLooks(getLooks() + LOOKS_INC);
		if (getLooks() < 1)
			assignLooks(1);
		else if (getLooks() > 100)
			assignLooks(100);
	}

	assignCharm(getCharm() + CHARM_INC);
	if (getCharm() < 1)
		assignCharm(1);
	else if (getCharm() > 100)
		assignCharm(100);
}

ifstream& Student_new::readDoSth(ifstream& is, vector<Student_new>& vecStudNew,
	const string& str, Dorm_info& dorm)
{
	Student_new *pst = NULL;
	bool found = false;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size() && found == false; i++)
	{
		if (vecStudNew[i].getName() == str)
		{
			pst = &vecStudNew[i];
			found = true;
		}
	}

	double workTime = 0;
	double studyTime = 0;
	double eatTaken = 0;
	double exerciseTime = 0;
	double makeupTime = 0;

	while (is)
	{
		string doStr;
		is >> doStr;
		if (doStr == "ADD")
		{
			readAddDorm_new(is, dorm);
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
		else if (doStr == "EXERCISE")
		{
			is >> exerciseTime;
		}
		else if (doStr == "MAKEUP")
		{
			is >> makeupTime;
		}
		else if (doStr == "MOVE")
		{
			pst->changeDorm(is, dorm);
		}
		else if (doStr == "WOO")
		{
			pst->love(is, vecStudNew);
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
			pst->breakUp(is, vecStudNew);
		}
		else
		{
			pst->doSth(workTime, studyTime, eatTaken, exerciseTime, makeupTime);
			Student_new::readDoSth(is, vecStudNew, doStr, dorm);		//此时doStr为姓名
		}
	}

	return is;
}

void Student_new::love(ifstream& is, vector<Student_new>& vecStudNew)
{
	string beLoveName;
	is >> beLoveName;

	Student_new *pst = NULL;
	bool found = false;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size() && found == false; i++)
	{
		if (vecStudNew[i].getName() == beLoveName)
		{
			pst = &vecStudNew[i];
			found = true;
		}
	}
	if (pst == NULL)
	{
		cout << "can not find the student about love" << endl;
		exit(1);
	}

	extern iptData configData_new;
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

		Student_new *preCP = NULL;
		bool isFound = false;
		for (vector<Student_new>::size_type i = 0; i < vecStudNew.size() && isFound == false; i++)
		{
			if (vecStudNew[i].getName() == pst->getCPname())
			{
				preCP = &vecStudNew[i];
				isFound = true;
			}
		}
		if (preCP == NULL)
		{
			cout << "can not find the student about previous CP" << endl;
			exit(1);
		}

		if (pst->pursueTimes[getName()] == 3 && getCharm() > preCP->getCharm() + configData_new.LOVE_RECONSTUCT_STANDARD)
		{
			assignHaveCP(true);
			assignCPname(beLoveName);
			pst->exCPname.push_back(pst->getCPname());
			pst->assignCPname(getName());
		}
	}

	if (pst->getHaveCP() == false && getHaveCP() == false && Delta <= configData_new.LOVE_STANDARD)
	{
		assignHaveCP(true);
		assignCPname(beLoveName);
		pst->assignHaveCP(true);
		pst->assignCPname(getName());
	}
}

void Student_new::breakUp(ifstream& is, vector<Student_new>& vecStudNew)
{
	string tempCh;
	is >> tempCh;	//UP

	exCPname.push_back(getCPname());
	assignHaveCP(false);

	Student_new *pst = NULL;
	bool found = false;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size() && found == false; i++)
	{
		if (vecStudNew[i].getName() == getCPname())
		{
			pst = &vecStudNew[i];
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

void Student_new::init(vector<Student_new>& vecStudNew)
{
	extern iptData configData_new;
	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		vecStudNew[i].assignWeight(configData_new.WEIGHT);
		vecStudNew[i].assignMoney(configData_new.MONEY);
		vecStudNew[i].assignKnowledge(configData_new.KNOWLEDGE);
		vecStudNew[i].assignCharm(configData_new.CHARM);
		if (vecStudNew[i].getSex() == "男")
		{
			vecStudNew[i].assignHealth(configData_new.HEALTH);
		}
		else if (vecStudNew[i].getSex() == "女")
		{
			vecStudNew[i].assignLooks(configData_new.LOOKS);
		}
	}
}

ifstream& Student_new::readInstruct(ifstream& is,
	vector<Student_new>& vecStudNew, Dorm_info& dorm)
{
	string str;
	is >> str;
	if (str == "ADD")
	{
		readAddDorm(is, dorm);
	}
	else
	{
		Student_new::readDoSth(is, vecStudNew, str, dorm);
	}

	return is;
}

void Student_new::putStudentInRoom(vector<Student_new>& vecStudNew, Dorm_info& dorm)
{
	extern iptData configData_new;
	for (int i = 1; i <= configData_new.FLOOR; i++)
	{
		for (int j = 1; j <= configData_new.ROOM; j++)
		{
			for (unsigned int n = 0; n < vecStudNew.size(); n++)
			{
				if (vecStudNew[n].getFloor() == i && vecStudNew[n].getRoom() == j)
				{
					dorm.floor[i - 1].room[j - 1].roomStudent.push_back(vecStudNew[n].getName());
				}
			}
		}
	}
}

void Student_new::saveData(vector<Student_new>& vecStudNew, Dorm_info& dorm)
{
	extern iptData configData_new;
	ofstream out;
	ifstream in;
	in.open("d:\\out_config_new.txt");
	if (!in.is_open())
	{
		cout << "Error opening file out_config.txt" << endl;
		exit(1);
	}
	out.open("d:\\" + configData_new.SAVE_FILE_NAME);
	if (!out.is_open())
	{
		cout << "Error opening file " << configData_new.SAVE_FILE_NAME << endl;
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
	out << "name\tsex\tfloor\troom\tmoney\tcharm\tweight\t知识\th or l\tisEnrol\thaveCP" << endl;

	for (vector<Student_new>::size_type i = 0; i < vecStudNew.size(); i++)
	{
		out << vecStudNew[i].getName() << "\t"
			<< vecStudNew[i].getSex() << "\t"
			<< vecStudNew[i].getFloor() << "\t"
			<< vecStudNew[i].getRoom() << "\t"
			<< vecStudNew[i].getMoney() << "\t"
			<< vecStudNew[i].getCharm() << "\t"
			<< vecStudNew[i].getWeight() << "\t"
			<< vecStudNew[i].getKnowledge() << "\t";
			if (vecStudNew[i].getSex() == "男")
			{
				out << vecStudNew[i].getHealth() << "\t";
			}
			else if (vecStudNew[i].getSex() == "女")
			{
				out << vecStudNew[i].getLooks() << "\t";
			}
		out	<< vecStudNew[i].getIsEnrol() << "\t"
			<< vecStudNew[i].getHaveCP() << "\t";
		if (vecStudNew[i].getHaveCP() == true)
		{
			out << vecStudNew[i].getCPname() << "\t";
		}
		out << vecStudNew[i].exCPname.size() << "\t";
		for (vector<string>::size_type j = 0; j < vecStudNew[i].exCPname.size(); j++)
		{
			out << vecStudNew[i].exCPname[j] << "\t";
		}
		out << endl;
	}
	out << "**********************************************" << endl;
	out << "//以下为宿舍的数据" << endl;
	out << configData_new.FLOOR << "\t" << configData_new.ROOM << "\t" << configData_new.CAPACITY << endl;
	for (int m = 0; m < configData_new.FLOOR; m++)
	{
		for (int n = 0; n < configData_new.ROOM; n++)
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

void Student_new::loadData(vector<Student_new>& vecStudNew, Dorm_info& dorm,
	iptData& configLoad)
{
	extern iptData configData_new;
	string tempStr;
	char tempCh;
	int tempInt;
	double tempDou;
	bool tempBo;
	ifstream in;

	in.open("d:\\" + configData_new.SAVE_FILE_NAME);
	if (!in.is_open())
	{
		cout << "can not open the file " + configData_new.SAVE_FILE_NAME << endl;
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
	in >> tempStr >> configLoad.HEALTH;
	in >> tempStr >> configLoad.LOOKS;
	in >> tempStr >> configLoad.FOOD_WEIGHT;
	in >> tempStr >> configLoad.FOOD_COST;
	in >> tempStr >> configLoad.STUDY_WEIGHT;
	in >> tempStr >> configLoad.STUDY_KNOWLEDGE;
	in >> tempStr >> configLoad.WORK_MONEY;
	in >> tempStr >> configLoad.WORK_WEIGHT;
	in >> tempStr >> configLoad.EXERCISE_WEIGHT;
	in >> tempStr >> configLoad.EXERCISE_HEALTH;
	in >> tempStr >> configLoad.MAKEUP_MONEY;
	in >> tempStr >> configLoad.MAKEUP_LOOKS;
	for (vector<string>::size_type i = 0; i < 7; i++)
	{
		string expStr;
		in >> tempStr >> tempCh;
		in.get();
		getline(in, expStr);
		configLoad.iptConfigVecStr.push_back(expStr);
	}
	string charmStr[6];
	in >> tempStr >> tempCh;
	in.get();
	getline(in, charmStr[0]);
	getline(in, charmStr[1]);
	getline(in, charmStr[2]);
	configLoad.iptConfigVecStr.push_back(charmStr[0] + charmStr[1] + charmStr[2]);
	in >> tempStr >> tempCh;
	in.get();
	getline(in, charmStr[3]);
	getline(in, charmStr[4]);
	getline(in, charmStr[5]);
	configLoad.iptConfigVecStr.push_back(charmStr[3] + charmStr[4] + charmStr[5]);
	in >> tempStr >> configLoad.LOVE_STANDARD;
	in >> tempStr >> configLoad.LOVE_RECONSTUCT_STANDARD;
	in >> tempStr >> configLoad.SAVE_FILE_NAME;

	in >> tempStr;
	in >> tempStr;
	in.get();
	getline(in, tempStr);

	bool isLastStudent = false;
	while (!isLastStudent)
	{
		Student_new student;
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
		in >> tempDou;
		if (student.getSex() == "男")
		{
			student.assignHealth(tempDou);
		}
		else if (student.getSex() == "女")
		{
			student.assignLooks(tempDou);
		}
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
		vecStudNew.push_back(student);

	}

	//cout << vecStudNew[3].getKnowledge() << endl;

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
