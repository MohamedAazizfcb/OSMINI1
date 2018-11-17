#include "FCFS.h"


FCFS::FCFS()
{
}
void FCFS::enqueue(Proccess* p)
{
	Ready.procs.push_back(p);
}
void FCFS::dequeue(Proccess*& p)//process is finished
{
	if(Ready.procs.size()==0)
		p=NULL;
	else
	{
		p=Ready.procs[0];
		Ready.procs.erase(Ready.procs.begin());
	}
}
void FCFS::addready(Proccess*p)//process arrive
{
	enqueue(p);
}
void FCFS::Schedule()
{
	if (Ready.procs.size() > 0)
	{
		proc = Ready.procs[0];
		run();
		return;
	}
	Time->time++;
}
bool FCFS::readyiszero()
{
	if(Ready.procs.size()==0)
		return true;
	return false;
}
void FCFS::run()
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
			dequeue(proc);
		}
	}
	else//runtime = 0
	{
		proc->Finish();	
			cout<<proc->Load_Proccess_Table()->proccess_number<<"  "<<proc->Load_Proccess_Table()->end<<endl;
		dequeue(proc);
	}
	
}

void FCFS::pause()
{
	//No preemtion here
}

FCFS::~FCFS(void)
{
	//no thing to do here as the scheduler has already removed all processes from the queue
}
