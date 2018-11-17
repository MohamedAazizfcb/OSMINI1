#include "Memory.h"


Memory::Memory(void)
{
}

bool Memory::insert_to_memory(Proccess p)
{
	try{
		proccesses.push_back(p);
		return true;
	}catch(exception ex)
	{
		return false;//memory overflow
	}
}

Proccess* Memory::extract_from_memory(double p_num)
{
		for(int i=0;i<proccesses.size();i++)
		{
				if(proccesses[i].Get_pnum()==p_num)
				{
					Proccess* np = new Proccess(proccesses[i]);
					for(int k=i+1;k<proccesses.size();k++)
					{
						proccesses[k-1] = proccesses[k];
					}
					proccesses.pop_back();
					return np;
				}
		}
		return NULL;//proccess is no longer on memory
}
Proccess* Memory::get_from_memory(int ind)
{
	return &proccesses[ind];
}

proccess_state Memory::Get_state(int ind)
{
	proccess_state pst = proccesses[ind].Get_state();
	return pst;
}
double Memory::Get_Arrival(int ind)
{
	double pst = proccesses[ind].Get_Arrival();
	return pst;
}
int Memory::Get_size()
{
	return proccesses.size();
}
Memory::~Memory(void)
{
}
