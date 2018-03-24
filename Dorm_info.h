#ifndef GUARD_Dorm_info_h
#define GUARD_Dorm_info_h

#include <vector>
#include <fstream>
#include <string>

using std::vector;		using std::ifstream;
using std::string;

struct Dorm_room
{
	vector<string> roomStudent;
	int bedNum ;
};

struct Dorm_floor
{
	vector<Dorm_room> room;
	int roomNum ;
};

struct Dorm_info
{
	vector<Dorm_floor> floor;
	int floorNum ;
};
void readAddDorm(ifstream& is, Dorm_info& dorm);
void readAddDorm_new(ifstream& is, Dorm_info& dorm);

#endif
