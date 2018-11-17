#pragma once
#include"global.h"
#include"Proccess.h"

class Scheduler
{
	protected:Proccess* proc;//for current proccess
	double Quantum;
	double remaining_of_qntm;
	double Context_Switching_time;
	TIME* Time;
public:
	Scheduler();
	void setCon_Qntm(double,double);
	virtual void Schedule()=0;//sorting selection
	virtual void run()=0;
	virtual void pause()=0;
	virtual void addready(Proccess*)=0;
	virtual bool readyiszero()=0;
	~Scheduler(void);
};

