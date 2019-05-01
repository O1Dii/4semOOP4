#include "Patient.h"


Patient Patient::operator=(Patient person)
{
	char ch = 0, E[50], P[50], Tel[20], N[20], SN[20], Pat[20], Addr[50];
	int num, korp, kv;
	strcpy_s(E, 50, person.getEmail());
	strcpy_s(P, 50, person.getPassword());
	strcpy_s(N, 20, person.getName());
	strcpy_s(SN, 20, person.getSecName());
	strcpy_s(Pat, 20, person.getPatronymic());
	strcpy_s(Tel, 20, person.getTel());
	strcpy_s(Addr, 50, person.getAddr().addr);
	num = person.getAddr().num;
	korp = person.getAddr().korpus;
	kv = person.getAddr().kv;
	this->setValues(*E, *P, *Tel, *N, *SN, *Pat, *Addr, num, korp, kv);
	this->setIssue(person.getIssue());
	this->setCurrentState(person.getCurrentState());
	return *this;
}

std::ostream & operator<<(std::ostream & stream, Patient obj)
{
	stream << "���: " << obj.getName() << "\n";
	stream << "�������: " << obj.getSecName() << "\n";
	stream << "��������: " << obj.getPatronymic() << "\n";
	stream << "�������: " << obj.getTel() << "\n";
	stream << "�����: " << obj.getAddr().addr << ", ";
	stream << "��� " << obj.getAddr().num << ", ";
	if(obj.getAddr().korpus != 0)
		stream << "������ " << obj.getAddr().korpus << ", ";
	stream << "��. " << obj.getAddr().kv << "\n";
	stream << "�������: " << obj.getIssue() << "\n";
	stream << "������� ���������: " << obj.getCurrentState();
	return stream;
}

void Patient::setIssue(std::string issue)
{
	strcpy_s(this->issue, 50, issue.c_str());
}

char * Patient::getIssue()
{
	return this->issue;
}

void Patient::setCurrentState(std::string currentState)
{
	strcpy_s(this->currentState, 200, currentState.c_str());
}

char * Patient::getCurrentState()
{
	return this->currentState;
}
