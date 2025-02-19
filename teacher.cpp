#include"teacher.h"
teacher::teacher(string name, string pwd, int id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->m_Tid = id;
}
void teacher::ShowAllApply() {
	apply a;

	if (a.m_size == 0) {
		cout << "当前无预约记录" << endl;
		system("pause");
		//system("cls");
		return;
	}
	cout << "有预约：" << endl;
	for (int i = 0; i < a.m_size; i++) {


		cout << i + 1 << " 预约日期：周" << a.mapply[i]["date"];
		cout << "\t时间：" << (a.mapply[i]["interval"] == "1" ? "上午" : "下午");
		cout << "\t学生编号：" << a.mapply[i]["stuid"];
		cout << "\t学生姓名：" << a.mapply[i]["stuname"];
		cout << "\t机房编号：" << a.mapply[i]["computerRoomId"];
		string status = "\t状态";
		if (a.mapply[i]["status"] == "1") {
			status += "审核中";
		}
		if (a.mapply[i]["status"] == "2") {
			status += "预约成功";
		}
		if (a.mapply[i]["status"] == "0") {
			status += "已取消预约";
		}
		if (a.mapply[i]["status"] == "-1") {
			status += "预约失败";
		}
		cout << status << endl;


	}
	system("pause");
//	system("cls");
}
void teacher::vailApply() {
	apply a;

	if (a.m_size == 0) {
		cout << "当前无预约记录" << endl;
		system("pause");
		//system("cls");
		return;
	}
	vector<int> v;
	int index = 0;
	cout << "有以下预约需要审核：" << endl;
	for (int i = 0; i < a.m_size; i++) {
		if (a.mapply[i]["status"] == "1") {
			v.push_back(i);
			index++;
			cout << index << " 预约日期：周" << a.mapply[i]["date"];
			cout << "\t时间：" << (a.mapply[i]["interval"] == "1" ? "上午" : "下午");
			cout << "\t学生编号：" << a.mapply[i]["stuid"];
			cout << "\t学生姓名：" << a.mapply[i]["stuname"];
			cout << "\t机房编号：" << a.mapply[i]["computerRoomId"];
			string status = "\t状态";
			if (a.mapply[i]["status"] == "1") {
				status += "审核中";
			}
			if (a.mapply[i]["status"] == "2") {
				status += "预约成功";
			}
			if (a.mapply[i]["status"] == "0") {
				status += "已取消预约";
			}
			if (a.mapply[i]["status"] == "-1") {
				status += "预约失败";
			}
			cout << status << endl;
		}

	}

	cout << "选择要审核的预约编号" << endl;
	int select = 0;
	cin >> select;
	
	if (select > a.m_size || select<0) {
		cout << "无该预约编号" << endl;
		system("pause");
		return;
	}
	while (1) {
		cout << "选择对该申请的操作" <<  "\n1.通过 2.不通过" << endl;
		int select2;
		cin >> select2;
		if (select2 == 1) {
			a.mapply[v[select - 1]]["status"] = "2";
			a.refresh();
			cout << "操作成功" << endl;
			system("pause");
			return;
		}
		if (select2 == 2) {
			a.mapply[v[select - 1]]["status"] = "-1";
			a.refresh();
			cout << "操作成功" << endl;
			system("pause");
			return;
		}
		cout << "输入操作有误，请重新操作" << endl;
		system("pause");
	}
}
void teacher::opermenu() {
	cout << "欢迎," << this->m_name << endl;
	cout << "\t\t*************选择你的操作************" << endl;
	cout << "\t\t|-----------------------------------|\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          1.查看所有预约           |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          2.审核预约               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          3.注销登入               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|-----------------------------------|\n";
}