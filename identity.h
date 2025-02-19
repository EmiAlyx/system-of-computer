#pragma once
#include<iostream>
using namespace std;
class identity {
	//操作菜单
	//子类重写纯虚函数才可以实例化
public:
	virtual void opermenu() = 0;
	string m_name;
	string m_pwd;//密码
};