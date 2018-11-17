#include"OS.h"
int main()
{
	OS* os = OS::Get_Instance();
	os->Welcome_Screen();
	while(!os->AllIsFinished())
	{
		os->Check_Arrival();
	}
	os->Finish();
	int a;
	cin >>a;
	return 0;
}