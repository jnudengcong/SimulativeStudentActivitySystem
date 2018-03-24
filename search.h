#ifndef GUARD_search_h
#define GUARD_search_h

#include "Student_new.h"

void search_prompt();
void search(vector<Student_new>& vecStudNew, Dorm_info& dorm);
void accordingNameGetRoom(vector<Student_new>& vecStudNew);
void getMaxAndMin_weight(vector<Student_new>& vecStudNew);
void getMaxAndMin_charm(vector<Student_new>& vecStudNew);
void getMaxAndMin_money(vector<Student_new>& vecStudNew);
void getMaxAndMin_knowledge(vector<Student_new>& vecStudNew);
void getLove(vector<Student_new>& vecStudNew);
void accordingRoomGetName(Dorm_info& dorm);
void loveTimesMost(vector<Student_new>& vecStudNew);
void range_weight(vector<Student_new>& vecStudNew);
void range_charm(vector<Student_new>& vecStudNew);
void range_money(vector<Student_new>& vecStudNew);
void range_knowledge(vector<Student_new>& vecStudNew);
void allLoveMost(vector<Student_new>& vecStudNew);

#endif