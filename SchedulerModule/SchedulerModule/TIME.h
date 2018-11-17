#pragma once
#include "global.h"
class TIME//singleton
{
	static TIME* instance;
	TIME(void);
public:
	double time;
	static TIME* getInstance();
	~TIME(void);
};

