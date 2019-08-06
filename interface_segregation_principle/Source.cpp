//Interface Segregation Principle (ISP)
#include<iostream>
#include<string>

using namespace std;

//bad example
class ILicence {
public:
	virtual void validate_licence() = 0;
	virtual void check_online() = 0;
};

class CloudLicence :public ILicence {
public:
	void validate_licence() {};
	void check_online() {};
};

class StandaloneLicence :public ILicence {
public:
	void validate_licence() {};
	void check_online() {}; //forcing to implement online for standalone
};

//good example
class ILicence {
public:
	virtual void validate_licence() = 0;
};

class IInternet {
public:
	virtual void check_online() = 0;
};


class CloudLicence :public ILicence ,IInternet{
public:
	void validate_licence() {};
	void check_online() {};
};

class StandaloneLicence :public ILicence {
public:
	void validate_licence() {};
};
