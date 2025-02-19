#include<iostream>
#include<fstream>
#include<vector>
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include"manager.h"
#include"globalfile.h"
#include"apply.h"
using namespace std;
void menu() {
	
	cout << "\t\t***********这是机房预约系统**********" << endl;
	cout << "\t\t|-----------------------------------|\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          1.学生登入               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          2.教师登入               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          3.管理员登入             |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|          0.退出系统               |\n";
	cout << "\t\t|                                   |\n";
	cout << "\t\t|-----------------------------------|\n";

}
void managermenu(identity*& managerz) {
	manager* man = (manager*)managerz;
	while (1) {
		man->opermenu();

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			man->addaccount();//添加账号
			break;
		case 2:
			man->showaccount();
			break;
		case 3:
			man->showcomputer();

			break;
		case 4:
			man->clearApply();//清空预约
			break;
		case 5:
			delete man;
			cout << "注销账户成功" << endl;
			system("pause");
			system("cls");
			return;
			break;

		default:
			cout << "输入错误！！" << endl;
			system("cls");
			continue;
			break;

		}
	}
}
void studentmenu(identity*& studentz) {
	student* man = (student*)studentz;
	while (1) {
		man->opermenu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			man->applyorder();//申请预约
			break;
		case 2:
			man->ShowmyApply();//查看自己预约
			break;
		case 3:
			man->ShowAllApply();//查看所有预约

			break;
		case 4:
			man->cancelOrder();//取消预约
			break;
		case 5:
			delete man;
			cout << "注销账户成功" << endl;
			system("pause");
			system("cls");
			return;
			break;

		default:
			cout << "输入错误！！" << endl;
			system("cls");
			continue;
			break;

		}
	}
}
void teachermenu(identity*& teacherz) {
	teacher* man = (teacher*)teacherz;
	while (1) {
		system("cls");
		man->opermenu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			man->ShowAllApply();//查看所有预约
			break;
		case 2:
			man->vailApply();//审核预约
			break;
		case 3:
			delete man;
			cout << "注销账户成功" << endl;
			system("pause");
			system("cls");
			return;
			break;

		default:
			cout << "输入错误！！" << endl;
			system("cls");
			continue;
			break;

		}
	}
}
void loginIn(string filename, int type) {
	identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		system("pause");
		ifs.close();
		return;
	}
	ifs.close();
	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入你的学号：" ;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" ;
		cin >> id;
	}
	
	cout << "请输入你的用户名:";
	cin >> name;
	cout << "请输入你的密码:";
	cin >> pwd;
	string z_name="";
	string z_pwd="";
	int z_id=0;
	ifs.open(filename, ios::in);
	if (type == 1) {
		while (ifs >> z_id && ifs >> z_name && ifs >> z_pwd) {
			if (z_id == id && z_name == name && z_pwd == pwd) {
				cout << "学生登入成功！欢迎！" << endl;
				system("pause");
				system("cls");
				person = new student(name, pwd,id);
				studentmenu(person);
				return;
			}
			
		}
	}
	else if (type == 2) {
		while (ifs >> z_id && ifs >> z_name && ifs >> z_pwd) {
			if (z_id == id && z_name == name && z_pwd == pwd) {
				cout << "教师登入成功！欢迎！" << endl;
				system("pause");
				system("cls");
				person = new teacher(name, pwd, id);
				teachermenu(person);
				return;
			}

		}
	}
	else if (type == 3) {
		while (ifs >> z_name && ifs >> z_pwd) {
			if (z_name == name && z_pwd == pwd) {
				cout << "管理员登入成功！欢迎！" << endl;
				system("pause");
				system("cls");
				person = new manager(name, pwd);
				managermenu(person);
				return;
			}

		}
	}
	cout << "登入失败，用户名或密码不正确" << endl;
	system("pause");
	system("cls");
	return;
}

int main() {
	int select;
	while (1) {
		menu();
		cout << "选择你的身份:";
		cin >> select;
		switch (select) {
		case 1://学生
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;

			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误！！" << endl;
			
			system("cls");
			continue;
		}
		
	}
}
