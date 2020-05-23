#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
// ----------------------------
using namespace std;
int exit_val,num,all,errcode,pause;
clock_t startTime,endTime;

signed main()
{
	try
	{
		SetConsoleOutputCP(437);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
		cout<<"please input number of tests: ";
		cin>>all; all=(all==-1?1201201201:all);
		cout<<"please pause time: ";
		cin>>pause;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
		cout<<"-------- start tests --------"<<endl<<endl;
		system("echo unknown>tmp/my.out");
		system("echo unknown>tmp/ans.out");
		system("echo unknown>tmp/compare.log");
		
		for(num=1;num<=all;++num)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			printf("\n------ test %04d ------\n",num);
			
			startTime=clock();
			exit_val=system("make >tmp/test.in");
			endTime=clock();
			if(exit_val) {errcode=1; break;}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<"\'make\'    ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout<<"exited normally";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<" with time used: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			printf("%.4lfs\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
			
			startTime=clock();
			exit_val=system("program\\ans <tmp/test.in >tmp/ans.out");
			endTime=clock();
			if(exit_val) {errcode=3; break;}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<"\'ans\'     ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout<<"exited normally";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<" with time used: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			printf("%.4lfs\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
			
			startTime=clock();
			exit_val=system("program\\my <tmp/test.in >tmp/my.out");
			endTime=clock();
			if(exit_val) {errcode=2; break;}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<"\'my\'      ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout<<"exited normally";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<" with time used: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			printf("%.4lfs\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
			
			startTime=clock();
			exit_val=system("compare >tmp/compare.log");
			endTime=clock();
			if(exit_val) {errcode=4; break;}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<"\'compare\' ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout<<"exited normally";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<" with time used: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			printf("%.4lfs\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
			
			Sleep(pause);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
		cout<<endl<<endl<<"-------- tests over --------"<<endl;
		if(!errcode)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			cout<<"All tests passed!"<<endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"Failed at test "<<num<<" :"<<endl;
		}
		if(errcode==1) cout<<"Err while running \'make\' with exit val: "<<exit_val<<endl;
		if(errcode==2) cout<<"Err while running \'my\' with exit val: "<<exit_val<<endl;
		if(errcode==3) cout<<"Err while running \'ans\' with exit val: "<<exit_val<<endl;
		if(errcode==4) cout<<"Err while running \'compare\' with exit val: "<<exit_val<<endl<<"LOG file: tmp/compare.log"<<endl;
		cout<<endl;
	}
	catch(...)
	{
		system("color 0a");
		cout<<"Unknown Error!"<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
	cout<<"Press any key to exit";
	getch();
	return 0;
}
// ----------------------------
// by imzzy