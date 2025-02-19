#pragma once
#include<iostream>
#include<vector>
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computer.h"
using namespace std;
class manager :public identity {
public:
	vector<computer> vcom;
	vector<student> vstu;
	vector<teacher> vtea;
	manager() ;
	manager(string name, string pwd);
	virtual void opermenu();
	void addaccount();//添加账户
	void showaccount();//查看账户
	void showcomputer();//查看机房
	void clearApply();//查看申请
	void initvector();
	void initcomputer();
	bool if_repeat(int id, int type);
};