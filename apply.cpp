#include"apply.h"
apply::apply() {
	m_size = 0;
	this->initapply();
}
void apply::initapply() {
	string date;
	string interval;
	string stuid;
	string computer;
	string stuname;
	string status;
	string key;
	string value;
	int pos=0;

	ifstream ifs(APPLY_FILE, ios::in);
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname &&
		ifs >> computer && ifs >> status) {
		map<string, string> m;
		//DATE 日期
		 pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos-1);
			m.insert(make_pair(key, value));
			
		}
		//interval 时间
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos-1);
			m.insert(make_pair(key, value));
		
		}
		//stuid 编号
		pos = stuid.find(":");
		if (pos != -1) {
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size()-pos-1);
			m.insert(make_pair(key, value));
		
		}
		//stuname 名字
		pos = stuname.find(":");
		if (pos != -1) {
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos-1);
			m.insert(make_pair(key, value));
	
		}
		//computer 机房
		pos = computer.find(":");
		if (pos != -1) {
			key = computer.substr(0, pos);
			value = computer.substr(pos + 1, computer.size() - pos-1);
			m.insert(make_pair(key, value));
	
		}
		//status 状态
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos-1);
			m.insert(make_pair(key, value));
	
		}
	
		mapply.insert(make_pair(m_size, m));
		m_size++;
	}

}
void apply::refresh() {
	if (this->m_size == 0) {
		return;
	}
	ofstream ofs(APPLY_FILE, ios::trunc);
		for (int i = 0; i < m_size; i++) {
			ofs << "date:" << this->mapply[i]["date"] << " " << "interval:" << this->mapply[i]["interval"] << " " << "stuid:" << this->mapply[i]["stuid"]
				<< " " << "stuname:" << this->mapply[i]["stuname"] << " " << "computerRoomId:" << this->mapply[i]["computerRoomId"] << " " << "status:" << this->mapply[i]["status"] << endl;
		}
		ofs.close();
}