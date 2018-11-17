#pragma once
#include"Scheduler.h"
class HPF : public Scheduler
{	struct LinkedList
	{
		vector<Proccess*> procs;
	};
	LinkedList Ready;
private: void insert(Proccess*);
private: void remove(Proccess*&);
public:
	HPF();
	virtual void Schedule();
	virtual void run();
	virtual void pause();
	virtual void addready(Proccess*);
	virtual bool readyiszero();
	~HPF(void);
};

