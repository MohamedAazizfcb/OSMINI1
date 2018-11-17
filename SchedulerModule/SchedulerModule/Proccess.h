#pragma once
#include"global.h"
#include"TIME.h"
class Proccess
{
private:
	ProccessTable p_table;
	TIME* Time;
	double TA;
	double WTA;
	double waittime;
public:
	Proccess(ProccessTable);
	Proccess();
	double Get_pnum();
	void Run();
	void Arrive();
	void pause();
	void start();
	proccess_state Get_state();
	void Finish();
    double Get_Arrival();
	double Get_Num();
	double Get_Priority();
	double Get_Remaining_Time();
	double Get_TA();
	double Get_WTA();
	double Get_waittime();
	ProccessTable* Load_Proccess_Table();
	~Proccess(void);
};

