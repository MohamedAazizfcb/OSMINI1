#pragma once
#include"Scheduler.h"
class RR : public Scheduler
{
	struct CircularQueue
	{
		vector<Proccess*> procs;
	};
	CircularQueue Ready;
private: void enqueue(Proccess*);
private: void dequeue(Proccess*&);
public:
	RR();
	virtual void Schedule();
	virtual void run();
	virtual void pause();
	virtual void addready(Proccess*);
	virtual bool readyiszero();
	~RR(void);
};

