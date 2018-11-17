#pragma once
#include"Proccess.h"
#include"global.h"
class Memory
{
	private:vector<Proccess> proccesses;
public:
	Memory(void);
	bool insert_to_memory(Proccess);
	Proccess* extract_from_memory(double);//get the proccess and remove it from the memory
	Proccess* get_from_memory(int);//copy the proccess
	proccess_state Get_state(int ind);
	double Get_Arrival(int ind);
	int Get_size();
	~Memory(void);
};