#include"student.h"
student::student(string name, string pwd, int id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->p_id = id;
	this->initcomputer();
}
void student::applyorder() {//申请预约
	cout << "机房的开放时间为周一至周五!" << endl;
	cout << "请选择你的预约日期1.周一 2.周二 3.周三 4.周四 5.周五" << endl;
	int select=0;
	int interval = 0;
	int room = 0;
	while (1) {
		cin >>select;
		if (select > 5 && select < 1) {
			cout << "输入有误！请重新输入" << endl;
			continue;
		}
		break;
	}
	cout << "选择你的时间段 1.上午 2.下午" << endl;
	while (1) {
		cin >> interval;
		if (select > 2 && select < 1) {
			cout << "输入有误！请重新输入" << endl;
			continue;
		}
		break;
	}
	cout << "现有机房：" << endl;
	for (int i = 0; i < vcom.size(); i++) {
		cout << "机房编号：" << vcom[i].m_roomid << "\t最大容量：" << vcom[i].m_maxnum << endl;

	}
	cout << "请选择你要预约的机房编号：" << endl;
	
	while (1) {
		cin >> room;
		if (select > 3 && select < 1) {
			cout << "输入有误！请重新输入" << endl;
			continue;
		}
		break;
	}
	ofstream ofs(APPLY_FILE, ios::app);
	//1代表状态为审核中
	ofs << "date:" << select << " " << "interval:" << interval << " " << "stuid:" << this->p_id
		<< " " << "stuname:" << this->m_name << " " << "computerRoomId:" << room << " " << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}
void student::initcomputer() {
	ifstream ifs(COMPUTER_FILE, ios::in);
	computer c;
	while (ifs >> c.m_roomid && ifs >> c.m_maxnum) {
		vcom.push_back(c);
	}
	ifs.close();
}
	void student::opermenu(){
		system("cls");
		cout << "欢迎," << this->m_name << endl;
		cout << "\t\t*************选择你的操作************" << endl;
		cout << "\t\t|-----------------------------------|\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          1.申请预约               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          2.查看个人预约           |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          3.查看所有预约           |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          4.取消预约               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|          5.注销登入               |\n";
		cout << "\t\t|                                   |\n";
		cout << "\t\t|-----------------------------------|\n";
}
	void student::ShowmyApply() {
		/*ifstream ifs(APPLY_FILE, ios::in);
		string st1;
		string st2;
		string st3;
		string st4;
		string st5;
		string st6;
		int num = 0;
		while (ifs >> st1 && ifs >> st2 && ifs >> st3 && ifs >> st4 && ifs >> st5 && ifs >> st6) {
			if (st3 == "stuid:" + to_string(this->p_id)) {
				cout << st1 << " " << st2 << " " << st3 << " " << st4 << " " << st5 << " " << st6 << endl;
				num++;
		 }
		}
		ifs.close();
		if (num == 0) {
			cout << "当前学生无预约记录" << endl;
		}
		system("pause");
		system("cls");*/
		apply a;
		
		if(a.m_size == 0) {
			cout << "当前无预约记录" << endl;
			system("pause");
			//system("cls");
			return;
		}
		int num = 0;
		for (int i = 0; i < a.m_size; i++) {

			if (atoi(a.mapply[i]["stuid"].c_str()) == this->p_id) {
				num++;
			}
		}
		if(num == 0) {
			cout << "当前该账户无预约记录" << endl;
			system("pause");
			//system("cls");
			return;
		}
		cout << "您拥有以下预约：" << endl;
		for (int i = 0; i < a.m_size; i++) {
			
			if (atoi(a.mapply[i]["stuid"].c_str())== this->p_id) {
				cout <<" 预约日期：周" << a.mapply[i]["date"];
				cout << "\t时间：" << (a.mapply[i]["interval"]=="1" ?"上午":"下午");
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
				cout << status<<endl;
				
			}
		}
		system("pause");
		//system("cls");
}
	void student::ShowAllApply() {
		apply a;

		if (a.m_size == 0) {
			cout << "当前无预约记录" << endl;
			system("pause");
			//system("cls");
			return;
		}
		cout << "有预约：" << endl;
		for (int i = 0; i < a.m_size; i++) {
			
			
				cout << "预约日期：周" << a.mapply[i]["date"];
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
		//system("cls");
}
	void student::cancelOrder() {
		apply a;

		if (a.m_size == 0) {
			cout << "当前无预约记录" << endl;
			system("pause");
			//system("cls");
			return;
		}
		int num = 0;
		for (int i = 0; i < a.m_size; i++) {

			if (atoi(a.mapply[i]["stuid"].c_str()) == this->p_id) {
				num++;
			}
		}
		if (num == 0) {
			cout << "当前该账户无预约记录" << endl;
			system("pause");
			//system("cls");
			return;
		}
		int index=0;
		vector<int> v;
		cout << "您拥有以下预约：" << endl;
		for (int i = 0; i < a.m_size; i++) {

			if (atoi(a.mapply[i]["stuid"].c_str()) == this->p_id) {
				v.push_back(i);
				index++;
				cout << index << " 预约日期：周" << a.mapply[i]["date"];
				cout << "\t时间：" << (a.mapply[i]["interval"] == "1" ? "上午" : "下午");
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
		
		cout << "选择你要取消的预约编号" << endl;
		int select = 0;
		cin >> select;
	
		if (select > a.m_size || a.mapply[v[select - 1]]["stuid"]!=to_string(this->p_id)||select<0) {
			cout << "你无权对该预约进行操作" << endl;
			system("pause");
			return;
		}
		a.mapply[v[select-1]]["status"] = "0";
		a.refresh();
		cout << "取消成功" << endl;
		system("pause");
}