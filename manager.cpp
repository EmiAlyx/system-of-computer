#include"manager.h"
#include"globalfile.h"
#include"student.h"
#include"teacher.h"
#include<fstream>
#include<algorithm>
manager::manager() {
	this->initvector();//初始化容器
}
manager::manager(string name,string pwd) {
		this->m_name = name;
		this->m_pwd = pwd;
		this->initvector();//初始化容器
		this->initcomputer();//初始化机房
}
void manager::initcomputer() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computer c;
	while (ifs >> c.m_roomid && ifs >> c.m_maxnum) {
		vcom.push_back(c);
	}
	ifs.close();
}
void manager::opermenu() {
	cout << "欢迎," << this->m_name << endl;
	cout << "\t\t*************选择你的操作************" << endl;
	cout << "\t\t|-----------------------------------|\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          1.添加帐号               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          2.查看账户               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          3.查看机房               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          4.清空预约               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          5.注销登入               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|-----------------------------------|\n";
}
class print {
public:
		void operator()(student& a)const {
			cout << "学号:" << a.p_id << "\t姓名" << a.m_name << "\t密码" << a.m_pwd << endl;
	}
		void operator()(teacher & a)const {
			cout << "职工号:" << a.m_Tid << "\t姓名" << a.m_name << "\t密码" << a.m_pwd << endl;
	}
		void operator()(computer& c)const {	
			cout << "机房编号:" << c.m_roomid << "\t最大容量" << c.m_maxnum<< endl;
		}
};
void manager::addaccount() {//添加账户
	while (1) {
		cout << "选择你添加的账户类型" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.添加教师" << endl;
		string filename;
		ofstream ofs;
		string tip;
		string errortip;
		int select = 0;
		cin >> select;
		if (select == 1) {
			filename = STUDENT_FILE;
			tip = "请输入学号";
			errortip = "学号重复，请重新输入";
		}
		if (select == 2) {
			filename = TEACHER_FILE;
			tip = "请输入职工号";
			errortip = "职工号重复，请重新输入";

		}
		ofs.open(filename, ios::app);
		int s_id;
		string s_name;
		string s_pwd;
		cout << tip << endl;
		cin >> s_id;
		if (this->if_repeat(s_id, select)) {
			cout << errortip << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << "请输入用户名:";
		cin >> s_name;
		cout << "请输入用户密码:";
		cin >> s_pwd;
		
		ofs << s_id << " " << s_name << " " << s_pwd << endl;
		ofs.close();
		cout << "添加成功" << endl;
		this->initvector();//将刚添加的账户加入容器
		system("pause");
		system("cls");
		return;
	}
}
void manager::showaccount(){//查看账户
	cout << "选择查看账号类型" << endl;
	cout << "1.所有的学生帐号" << endl;
	cout << "2.所有的教师帐号" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		for_each(vstu.begin(), vstu.end(), print());
	}
	if (select == 2) {
		for_each(vtea.begin(), vtea.end(), print());
	}
	system("pause");
	system("cls");
}
void manager::showcomputer(){//查看机房
	for_each(vcom.begin(), vcom.end(), print());
	system("pause");
	system("cls");
}
void manager::clearApply() {//清空申请
	
	int select;
	cout << "是否真的清除申请" << endl << "1.确认 2.返回" << endl;
	cin >> select;
	if (select == 1) {
		ofstream ofs(APPLY_FILE, ios::trunc);
		ofs.close();
		cout << "清除成功" << endl;
		system("pause");
		system("cls");
	}
	system("cls");
	return;
}
void manager::initvector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	student stu;
	teacher tea;
	vstu.clear();
	vtea.clear();

	//studnet 读取
	if (!ifs.is_open()) {
		cout << "student文件读取失败" << endl;
		return;
	}
	while (ifs >> stu.p_id && ifs >> stu.m_name && ifs >> stu.m_pwd) {
		vstu.push_back(stu);
	}
	ifs.close();
	//teacher 读取
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "teacher文件读取失败" << endl;
		return;
	}
	while (ifs >> tea.m_Tid && ifs >> tea.m_name && ifs >> tea.m_pwd) {
		vtea.push_back(tea);
	}
	ifs.close();
  
}
bool manager::if_repeat(int id, int type) {
	if (type == 1) {
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
			if (id == it->p_id) {
				return true;
			}
		}
	}	
	if (type == 2) {
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++) {
			if (id == it->m_Tid) {
				return true;
			}
		}
	}
	return false;
}