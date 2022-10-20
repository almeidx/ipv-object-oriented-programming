#include "inheritance2.hpp"

Motor::Motor() { cout << "Motor::Motor()" << endl; }
Motor::~Motor() { cout << "Motor::~Motor()" << endl; }

bool Motor::run() {
	cout << "Motor::run()" << endl;
	return true;
}

bool Motor::stop() {
	cout << "Motor::stop()" << endl;
	return true;
}

bool Motor::start() {
	cout << "Motor::start()" << endl;
	return true;
}

bool Motor::warn_temp() { return true; }

CombustionMotor::CombustionMotor() {}

CombustionMotor::~CombustionMotor() {}

bool CombustionMotor::run() {
	cout << "CombustionMotor::run()" << endl;
	return true;
}

bool CombustionMotor::stop() {
	cout << "CombustionMotor::stop()" << endl;
	return true;
}

bool CombustionMotor::start() {
	cout << "CombustionMotor::start()" << endl;
	return true;
}
