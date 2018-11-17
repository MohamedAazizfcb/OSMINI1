#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include <windows.h>
#include<algorithm>
using namespace std;
enum proccess_state{
		done=4,running=3,ready=2,blocked=1,away=0
	};
struct ProccessTable
	{
		double proccess_number;
		double arrival_time;
		double burst_time;
		double remaining_time;
		double priority;
		proccess_state state;
		double start;//the starting time of first run
		double end;//the ending time of last run
	};


