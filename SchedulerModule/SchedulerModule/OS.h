#pragma once
#include"global.h"
#include"Memory.h"
#include"HPF.h"
#include"FCFS.h"
#include"SRTN.h"
#include"RR.h"
#include"TIME.h"
class OS//Singleton Contoller
{	
	////////////////////////////////////////////////
	private: OS(void);//private constructor	   ////
	private: static OS* Instance;			  ////
	/////////////////////////////////////////////

	private: Memory HardDesk;//Contains proccesses that hasnot arrived yet (Code that isnot put to run)
	double Quantum;
	double Context_Switching_time;

	private: string infile;
	private: void ReadFile();
	Scheduler* scheduler;
	TIME* Time;
public:
	static OS* Get_Instance();
	void Welcome_Screen();
	void Check_Arrival();
	bool AllIsFinished();
	void Finish();
	~OS(void);
};

