#include "OS.h"

OS* OS::Instance = NULL;
OS::OS(void)
{
	scheduler = NULL;
	Time = TIME::getInstance();
	infile = "";
	Context_Switching_time = 0;
	Quantum = 0;
}
OS *OS::Get_Instance()
{
	if (Instance==NULL)
		Instance = new OS();
	return Instance;
}
void OS::Welcome_Screen()
{
	cout<<"						Welcome To M&M OS"<<endl<<endl;
	cout<<"Please,Enter The Name Of Proccesses File(WITH EXTENTION!!)! : "<<endl;
	cin>>infile;
	system("cls");
	cout<<"						Welcome To M&M OS"<<endl<<endl;
	cout<<"WOW,What A Good Name.\nCertainly You Will Be The One That Name My Baby :)"<<endl<<endl;
	cout<<"Now,Please,Enter The Index Of The Algorithm You Want Us To Use To Finish Your Proccesses! :"<<endl;
	cout<<"1-Non-Preemptive Highest Priority First(HPF) 'El-Bashawat First'"<<endl
		<<"2-First Come First Served(FCFS) 'Wahda Wahda Kolo hatnafez'"<<endl
		<<"3-Round Robin with fixed time quantum(RR) '7ta hena betlefaha ya robben :)'"<<endl
		<<"4-Preemptive Shortest Remaining Time Next(SRTN) 'elly less than 160 cm'"<<endl;
	int alg_num;
	while(true)
	try{
		cin >> alg_num;
		break;
		}catch(exception ex){cout<<"Da5al Raqam Ya Zareef"<<endl;}
	switch (alg_num)
	{
	case 1:
		cout<<"El First Class Tasks Teghaz Yalla!"<<endl;
		scheduler = new HPF();
		break;
	case 2:
		cout<<"Who Is Next?!"<<endl;
		scheduler = new FCFS();
		break;
	case 3:
		cout<<"Shaklak Betshag3 El Bayern M3aya!"<<endl;
		scheduler = new RR();
		break;
	case 4:
		cout<<"Yalla Ya 2osyreen 3shan tro7o badry"<<endl;
		scheduler = new SRTN();
		break;
	default:
		cout<<"Ro7 Eshrab kobaya nesqafe w t3ala e5tar 3shan shaklak nayem :):"<<endl;
		cin>>alg_num;
		break;
	}
	Sleep(3000);
	system("cls");
	cout<<"						Welcome To M&M OS"<<endl<<endl;
	while (true)
		try{
		cout<<"Please,Enter Context-Switching Time! :\n";
		cin>>Context_Switching_time;
		break;
		}catch(exception ex){cout<<"Da5al Raqam Ya Zareef"<<endl;}
	if(Context_Switching_time>=.5)
		{
			cout<<"Shkalak hatrun 3la intel 8086 3shan ykon kol da bs h3melholak 3shan ent sadeky el sadok"<<endl;
		}
	Sleep(3000);
	system("cls");
	cout<<"						Welcome To M&M OS"<<endl<<endl;
	if(alg_num == 3)
	{
		while (true)
		try{
		cout<<"Please,Enter The Time Quantum :"<<endl;
		cin>>Quantum;
		break;
		}catch(exception ex){cout<<"Da5al Raqam Ya Zareef"<<endl;}
	}
	scheduler->setCon_Qntm(Context_Switching_time,Quantum);
	ReadFile();
}
void OS::ReadFile()
{
	ifstream myfile (infile);
	while (!myfile.is_open())
	{
		system("cls");
	    cout<<"						Welcome To M&M OS"<<endl<<endl;
		cout<<"Momken Tet2ked Men 2sm El file 3shan Badawar 3leh w mesh la2eh :("<<endl;
		cin>>infile;
		myfile.open(infile);
		cout<<"Shokaran :)"<<endl;
	}

	{
	int a;
	myfile>>a;
	}
	ProccessTable temp;
	while(!myfile.eof())
		{
			myfile >> temp.proccess_number;
			myfile >> temp.arrival_time;
			myfile >> temp.burst_time;
			myfile >> temp.priority;
			Proccess t(temp);
			HardDesk.insert_to_memory(t);
		}
	myfile.close();
	system("cls");
	cout<<"						Welcome To M&M OS"<<endl<<endl;
}
void OS::Check_Arrival()//check for arrival and start scheduling for one time unit
{
	int i=0;
	int n=HardDesk.Get_size();
	while(i<n)
	{
		Proccess* tmp = HardDesk.get_from_memory(i);
		if(tmp->Get_Arrival()<=Time->time && tmp->Get_state()==away)
		{
			tmp->Arrive();
			scheduler->addready(tmp);
		}
		i++;
	}
	scheduler->Schedule();
}
bool OS::AllIsFinished()
{
	if(!scheduler->readyiszero())
		return false;
	for(int i=0;i<HardDesk.Get_size();i++)
	{
		Proccess* tmp = HardDesk.get_from_memory(i);
		if(tmp->Load_Proccess_Table()->remaining_time > 0)
			return false;
	}
	return true;
}

void OS::Finish()
{
	ofstream out("Statistics.txt");
	double AVG_TA=0;
	double AVG_WTA=0;
	for(int i=0;i<HardDesk.Get_size();i++)
	{
		Proccess* tmp = HardDesk.get_from_memory(i);
		out << "For Process "<<tmp->Get_Num()<<" :"<<endl;
		out << "	Turnaround Time = "<<tmp->Get_TA()<<endl;
		out << "	Weighted Turnaround Time = "<<tmp->Get_WTA()<<endl;
		out << "	Waiting Time = "<<tmp->Get_waittime()<<endl<<endl;;
		AVG_TA += tmp->Get_TA();
		AVG_WTA +=tmp->Get_WTA();
	}
	AVG_TA /= HardDesk.Get_size();
	AVG_WTA /= HardDesk.Get_size();
	out<<"Average Turnaround Time = "<< AVG_TA<<endl;
	out<<"Average Weighted Turnaround Time = "<< AVG_WTA<<endl;
}
OS::~OS(void)
{
	delete scheduler;
}
