#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include"globalfile.h"
using namespace std;
class apply {
public:
	map<int, map<string, string>> mapply;
	int m_size;
		apply();
		void initapply();
		void refresh();
};