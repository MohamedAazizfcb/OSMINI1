#include "HPF.h"

/*
insert the process into ready list with the right order of priority
if a higher priority process arrives then it is the first in the list but not running until the current finishes
*/
HPF::HPF()
{
}
void HPF::insert(Proccess* p)
{
	Ready.procs.push_back(p);
	//now insert in the right place
	int i=Ready.procs.size()-1;
	while(i>0 && Ready.procs[i]->Get_Priority()<Ready.procs[i-1]->Get_Priority())
	{
		swap(Ready.procs[i],Ready.procs[i-1]);
		i--;
	}
}
void HPF::remove(Proccess*& p)//process is finished
{
	if(Ready.procs.size()==0)
		p=NULL;
	else
	{
		for(int i=0;i<Ready.procs.size();i++)
		{
			if (p->Get_Num()==Ready.procs[i]->Get_Num())
			{
				for(int k=i+1;k<Ready.procs.size();k++)
				{
					Ready.procs[k-1] = Ready.procs[k];
				}
				Ready.procs.pop_back();
				break;
			}

		}
	}
}
void HPF::addready(Proccess*p)//process arrive
{
	insert(p);
}
void HPF::Schedule()
{
	if(proc!=NULL)//no interrupt
	{
		run();
		return;
	}

	if (Ready.procs.size() > 0)
	{
		proc = Ready.procs[0];
		run();
		return;
	}
	Time->time++;
}
bool HPF::readyiszero()
{
	if(Ready.procs.size()==0)
		return true;
	return false;
}
void HPF::run()
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

void HPF::pause()
{
	//No preemtion here
}

HPF::~HPF(void)
{
	//no thing to do here as the scheduler has already removed all processes from the list
}
