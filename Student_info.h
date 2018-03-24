#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include "Dorm_info.h"
#include "exprtk.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct iptData
{
	int FLOOR;
	int ROOM;
	int CAPACITY;
	double WEIGHT;
	double MONEY;
	double KNOWLEDGE;
	double CHARM;
	double FOOD_WEIGHT;
	double FOOD_COST;
	double STUDY_WEIGHT;
	double STUDY_KNOWLEDGE;
	double WORK_MONEY;
	double WORK_WEIGHT;
	double LOVE_STANDARD;
	double LOVE_RECONSTUCT_STANDARD;

	double HEALTH;
	double LOOKS;
	double EXERCISE_WEIGHT;
	double EXERCISE_HEALTH;
	double MAKEUP_MONEY;
	double MAKEUP_LOOKS;

	string SAVE_FILE_NAME;
	vector<string> iptConfigVecStr;
}iptData;

class Student_info
{
private:
	string name;
	string sex;
	string CPname;
	int floor;
	int room;
	int bed;
	double money;
	double charm;
	double knowledge;
	double weight;
	bool isEnrol = true;
	bool haveCP = false;


public:
	vector<string> exCPname;
	map<string, int> pursueTimes;

	static void init(vector<Student_info>& vecStudent);
	static ifstream& readInstruct(ifstream& is, vector<Student_info>& vecStudent, Dorm_info& dorm);
	static ifstream& readDoSth(ifstream& is, vector<Student_info>& vecStudent, const string& str, Dorm_info& dorm);
	static void readConfig(char* config, iptData& configData);
	static void readConfig(iptData& configData);
	static void putStudentInRoom(vector<Student_info>& vecStudent, Dorm_info& dorm);
	static void saveData(vector<Student_info>& vecStudent, Dorm_info& dorm);
	static void loadData(vector<Student_info>& vecStudent, Dorm_info& dorm, iptData& configLoad);
	ifstream& readDorm(ifstream&);

	ifstream& changeDorm(ifstream& is, Dorm_info& dorm);
	void dropOut();
	void enrol(ifstream& is);
	void love(ifstream& is, vector<Student_info>& vecStudent);
	void doSth(double WORK_TIME, double STUDY_TIME, double FOOD_TAKEN);
	void breakUp(ifstream& is, vector<Student_info>& vecStudent);

	string getName() { return name; };
	string getSex() { return sex; };
	string getCPname() { return CPname; };
	int getFloor() { return floor; };
	int getRoom() { return room; };
	int getBed() { return bed; };
	double getMoney() { return money; };
	double getCharm() { return charm; };
	double getKnowledge() { return knowledge; };
	double getWeight() { return weight; };
	bool getIsEnrol() { return isEnrol; };
	bool getHaveCP() { return haveCP; };
	vector<string> getExCPname() { return exCPname; };
	map<string, int> getPursueTimes() { return pursueTimes; };

	void assignName(string name) { this->name = name; };
	void assignSex(string sex) { this->sex = sex; };
	void assignCPname(string CPname) { this->CPname = CPname; };
	void assignFloor(int floor) { this->floor = floor; };
	void assignRoom(int room) { this->room = room; };
	void assignBed(int bed) { this->bed = bed; };
	void assignMoney(double money) { this->money = money; };
	void assignCharm(double charm) { this->charm = charm; };
	void assignWeight(double weight) { this->weight = weight; };
	void assignKnowledge(double knowledge) { this->knowledge = knowledge; };
	void assignIsEnrol(bool isEnrol) { this->isEnrol = isEnrol; };
	void assignHaveCP(bool haveCP) { this->haveCP = haveCP; };

};

#endif