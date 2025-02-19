#pragma once
#include<iostream>
#include"identity.h"
#include"computer.h"
#include"globalfile.h"
#include"apply.h"
#include<vector>
#include<fstream>
#include<string>
#include<map>
using namespace std;
class student :public identity {
public:
	vector<computer> vcom;
	int p_id;
	student() {};
	student(string name, string pwd, int id);
	void applyorder();//…Í«Î‘§‘º
	virtual void opermenu();
	void ShowmyApply();
	void ShowAllApply();
	void cancelOrder();
	void initcomputer();
};