#include "Scheduler.h"


Scheduler::Scheduler()
{
	Time = TIME::getInstance();
	proc=NULL;
}
void Scheduler::setCon_Qntm(double con_time,double quntm)
{
	Context_Switching_time = con_time;
	Quantum = quntm;
	remaining_of_qntm=Quantum;
}

Scheduler::~Scheduler(void)
{
}
