#include "SRTN.h"

/*
ASSUMPTIONS:
1-Context switching is not considered part from running time and the os is considered blind during this interval
	for example if:
	p1 arrives at 0 with running time 100 and cst is 1 and p2 arrives at 1 with running time 3 then p2 will be monitored at time 2
*/
SRTN::SRTN()
{
}
void SRTN::insert(Proccess* p)
{
	Ready.procs.push_back(p);
	//now insert in the right place
	int i=Ready.procs.size()-1;
	while(i>0 && Ready.procs[i]->Get_Remaining_Time()<Ready.procs[i-1]->Get_Remaining_Time())
	{
		swap(Ready.procs[i],Ready.procs[i-1]);
		if(i==1)
			Ready.procs[1]->Load_Proccess_Table()->state = ready;
		i--;
	}
}
void SRTN::remove(Proccess*& p)//process is finished
{
	if(Ready.procs.size()==0)
		p=NULL;
	else
	{
		p=Ready.procs[0];
		Ready.procs.erase(Ready.procs.begin());
	}
}
void SRTN::addready(Proccess*p)//process arrive
{
	insert(p);
}
void SRTN::Schedule()
{
	if (Ready.procs.size() > 0)
	{
		proc = Ready.procs[0];
		run();
		return;
	}
	Time->time++;
}
bool SRTN::readyiszero()
{
	if(Ready.procs.size()==0)
		return true;
	return false;
}
void SRTN::run()
{
	if(proc->Load_Proccess_Table()->state == ready)
		Time->time += Context_Switching_time;
	proc->start();
	if (proc->Load_Proccess_Table()->remaining_time > 0)
	{
		proc->Run();
		Time->time++;
		if (proc->Load_Proccess_Table()->remaining_time <= 0)
		{
			proc->Finish();	
			cout<<proc->Load_Proccess_Table()->proccess_number<<"  "<<proc->Load_Proccess_Table()->end<<endl;
			remove(proc);
			proc=NULL;
		}
	}
	else//runtime = 0
	{
		proc->Finish();	
		cout<<proc->Load_Proccess_Table()->proccess_number<<"  "<<proc->Load_Proccess_Table()->end<<endl;
		remove(proc);
		proc=NULL;
	}
	
}

void SRTN::pause()
{
	//No preemtion here
}

SRTN::~SRTN(void)
{
	//no thing to do here as the scheduler has already removed all processes from the queue
}
