#ifndef INHERITANCE2_HPP
#define INHERITANCE2_HPP

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
	string name;
	string cc;

public:
	User(string _name, string _cc);
	virtual ~User();
	void print();
	string get_cc();
};

class Admin : public User {
public:
	Admin(string _name, string _cc);
	virtual ~Admin();
};

class Normal : public User {
public:
	Normal(string _name, string _cc);
	virtual ~Normal();
};

// Motor

class Motor {
	int temp;

public:
	Motor();
	virtual ~Motor();

	virtual bool run() = 0;
	virtual bool stop() = 0;
	virtual bool start() = 0;

	bool warn_temp();
};

class CombustionMotor : public Motor {
public:
	CombustionMotor();
	virtual ~CombustionMotor();

	virtual bool run();
	virtual bool stop();
	virtual bool start();
};

#endif // INHERITANCE2_HPP
