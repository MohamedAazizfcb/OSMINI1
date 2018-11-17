#pragma once
#include"Scheduler.h"
class FCFS : public Scheduler
{
	struct Queue
	{
		vector<Proccess*> procs;
	};
	Queue Ready;
private: void enqueue(Proccess*);
private: void dequeue(Proccess*&);
public:
	FCFS();
	virtual void Schedule();
	virtual void run();
	virtual void pause();
	virtual void addready(Proccess*);
	virtual bool readyiszero();
	~FCFS(void);
};

