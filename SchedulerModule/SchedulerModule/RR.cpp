#include "RR.h"
/*
ASSUMPTIONS:
1-if a process arrives it will be put at the end of the queue
2-if a process arrives and the quantum is up at the same time then the new process will
	be enqueued first the the old process after the quantum for more interaction
3-if a process finishes at the middle of the quantum then quantum is reinitialized
4-if the cpu is free then quantum is reinitialize so that the coming process will have full quantum
5-for the last process ever with remaining time larger than quantum ->it leaves the cpu then return to it after each quantum so
	there is cst
6-Context switching is not considered part from running time nor quantum and the os is considered blind during this interval
	for example if:
	p1 arrives at 0 and cst is 1 and p2 arrives at 1 then p2 will be monitored at time 2
*/

RR::RR()
{
}
void RR::enqueue(Proccess* p)
{
	Ready.procs.push_back(p);
}
void RR::dequeue(Proccess*& p)//process is finished or quantum is up
{
	if(Ready.procs.size()==0)
		p=NULL;
	else
	{
		p=Ready.procs[0];
		Ready.procs.erase(Ready.procs.begin());
	}
}
void RR::addready(Proccess*p)//process arrive
{
	enqueue(p);
}
void RR::Schedule()
{
	if (Ready.procs.size() > 0)
	{
		if(remaining_of_qntm==0)
		{
			dequeue(proc);
			enqueue(proc);
			remaining_of_qntm = Quantum;
		}
		proc = Ready.procs[0];
		run();
		return;
	}
	Time->time++;
}
bool RR::readyiszero()
{
	if(Ready.procs.size()==0)
		return true;
	return false;
}
void RR::run()
{
	if(proc->Load_Proccess_Table()->state==ready)
		Time->time += Context_Switching_time;
	proc->start();
	if (proc->Load_Proccess_Table()->remaining_time > 0)
	{
		proc->Run();
		Time->time++;
		remaining_of_qntm--;
		if (proc->Load_Proccess_Table()->remaining_time <= 0)
		{
			proc->Finish();	
			cout<<proc->Load_Proccess_Table()->proccess_number<<"  "<<proc->Load_Proccess_Table()->end<<endl;
			dequeue(proc);
			remaining_of_qntm = Quantum;
			proc = NULL;
			return;
		}
	}
	else//runtime = 0
	{
		proc->Finish();	
		cout<<proc->Load_Proccess_Table()->proccess_number<<"  "<<proc->Load_Proccess_Table()->end<<endl;
		dequeue(proc);
		remaining_of_qntm = Quantum;
		proc = NULL;
		return;
	}
	if(remaining_of_qntm==0)
		proc->pause();
}

void RR::pause()
{
	//No preemtion here
}

RR::~RR(void)
{
	//no thing to do here as the scheduler has already removed all processes from the queue
}
