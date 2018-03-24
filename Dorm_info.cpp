#include "Dorm_info.h"
#include "Student_info.h"
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;		using std::string;
using std::vector;

void readAddDorm(ifstream& is, Dorm_info& dorm)
{
	extern iptData configData;
	int tempInt;
	int roomInt;
	int addedFloor;
	int addedRoom;
	string doStr;
	string tempStr;
	char tempCh;
	is >> tempInt >> doStr;

	if (doStr == "FLOOR(s)")
	{
		dorm.floorNum += tempInt;
		
		for (int i = configData.FLOOR; i < dorm.floorNum; i++)
		{
			Dorm_floor dFloor;
			for (int j = 0; j < configData.ROOM; j++)
			{
				Dorm_room dRoom;
				dRoom.bedNum = configData.CAPACITY;
				dFloor.room.push_back(dRoom);
			}
			dFloor.roomNum = configData.ROOM;
			dorm.floor.push_back(dFloor);
		}
		configData.FLOOR = dorm.floorNum;
	}
	else if (doStr == "ROOM(s)")
	{
		is >> tempStr;		//TO
		is >> roomInt;
		is >> tempStr;		//FLOOR
		dorm.floor[roomInt - 1].roomNum += tempInt;
	}
	else if (doStr == "BED(s)")
	{
		is >> tempStr;		//TO
		is >> addedFloor;
		is >> tempCh;		//-
		is >> addedRoom;
		dorm.floor[addedFloor - 1].room[addedRoom - 1].bedNum += tempInt;
	}
}

void readAddDorm_new(ifstream& is, Dorm_info& dorm)
{
	extern iptData configData_new;
	int tempInt;
	int roomInt;
	int addedFloor;
	int addedRoom;
	string doStr;
	string tempStr;
	char tempCh;
	is >> tempInt >> doStr;

	if (doStr == "FLOOR(s)")
	{
		dorm.floorNum += tempInt;

		for (int i = configData_new.FLOOR; i < dorm.floorNum; i++)
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
		configData_new.FLOOR = dorm.floorNum;
	}
	else if (doStr == "ROOM(s)")
	{
		is >> tempStr;		//TO
		is >> roomInt;
		is >> tempStr;		//FLOOR
		dorm.floor[roomInt - 1].roomNum += tempInt;
	}
	else if (doStr == "BED(s)")
	{
		is >> tempStr;		//TO
		is >> addedFloor;
		is >> tempCh;		//-
		is >> addedRoom;
		dorm.floor[addedFloor - 1].room[addedRoom - 1].bedNum += tempInt;
	}
}
