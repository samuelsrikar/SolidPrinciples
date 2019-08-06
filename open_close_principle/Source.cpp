//Open Close Principle
#include<iostream>
#include<string>

using namespace std;

//bad example

//class BsCode {
//public:
//	void calc_wind_speed() { cout << "bs speed\n"; };
//};
//
//class EuroCode {
//public:
//	void calc_wind_speed() { cout << "euro speed\n"; };
//};
//
//
//class WindMonitor {
//public:
//
//	void calc_bs_wind_speed(BsCode bs_code_obj) { bs_code_obj.calc_wind_speed(); }
//	void calc_euro_wind_speed(EuroCode eruo_code_obj) { eruo_code_obj.calc_wind_speed(); }
//};

//Good example

class IWindCalc {
public:
	virtual void calc_wind_speed() = 0;
};

class BsCode:public IWindCalc {
public:
	void calc_wind_speed() { cout << "bs speed\n"; };
};

class EuroCode :public IWindCalc{
public:
	void calc_wind_speed() { cout << "euro speed\n"; };
};


class WindMonitor {
public:

	void calc_wind_speed(IWindCalc& wind_obj) { wind_obj.calc_wind_speed(); }
};

int main()
{
	BsCode bs_code;
	EuroCode euro_code;

	WindMonitor wind_monitor;

	wind_monitor.calc_wind_speed(bs_code);
	wind_monitor.calc_wind_speed(euro_code);
	return 0;
}