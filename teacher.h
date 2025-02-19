#pragma once
#include<iostream>
#include<string>
#include"vector"
#include"apply.h"
#include"identity.h"
using namespace std;
class teacher :public identity {
public:
	int m_Tid;
	teacher() {};
	teacher(string name, string pwd, int id);
	void ShowAllApply();
	void vailApply();
	virtual void opermenu();
};