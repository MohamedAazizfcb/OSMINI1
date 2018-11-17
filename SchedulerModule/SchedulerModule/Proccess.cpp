#include "Proccess.h"


Proccess::Proccess(ProccessTable t)
{
	Time = TIME::getInstance();
	p_table.arrival_time = t.arrival_time;
	p_table.burst_time = t.burst_time;
	p_table.priority = t.priority;
	p_table.proccess_number = t.proccess_number;
	p_table.remaining_time = t.burst_time;
	p_table.state = away;
	p_table.start = 0;
	p_table.end = 0;
	TA=0;
	WTA=0;
	waittime=-1;
}
Proccess::Proccess()
{
	Time = TIME::getInstance();
	p_table.arrival_time = 0;
	p_table.burst_time = 0;
	p_table.priority = 0;
	p_table.proccess_number = 0;
	p_table.remaining_time = 0;
	p_table.state = away;
	p_table.start = 0;
	p_table.end = 0;
	TA=0;
	WTA=0;
	waittime=-1;
}
double Proccess::Get_pnum()
{
	return p_table.proccess_number;
}
void Proccess::Finish()
{
	p_table.state = done;
	p_table.end = Time->time;
	TA = p_table.end-p_table.arrival_time;
	WTA = TA/p_table.burst_time;
}
void Proccess::Arrive()
{
	p_table.state = ready;
}
proccess_state Proccess::Get_state()
{
	return p_table.state;

}
double Proccess::Get_Arrival()
{
	return p_table.arrival_time;
}
double Proccess::Get_Num()
{
	return p_table.proccess_number;
}
double Proccess::Get_Priority()
{
	return p_table.priority;
}
double Proccess::Get_Remaining_Time()
{
	return p_table.remaining_time;
}


double Proccess::Get_TA()
{
	return TA;
}
double Proccess::Get_WTA()
{
	return WTA;
}
double Proccess::Get_waittime()
{
	return waittime;
}

ProccessTable* Proccess::Load_Proccess_Table()
{
	return &p_table;
}

void Proccess::Run()
{
	if(waittime == -1)
		waittime = Time->time - p_table.arrival_time;
	//proccess code is here
	p_table.remaining_time--;

}

void Proccess::start()
{
	p_table.state = running;
}

void Proccess::pause()
{
	p_table.state = ready;
}

Proccess::~Proccess(void)
{
}
