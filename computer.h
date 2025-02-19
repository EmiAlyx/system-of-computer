#pragma once
#include<iostream>
using namespace std;
class computer {
public:
	int m_roomid;//机房id
	int m_maxnum;//最大容量
	computer() {
		m_maxnum = 0;
		m_roomid = 0;
	}
};