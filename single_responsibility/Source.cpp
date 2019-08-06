//Single responsibilty principle(SRP)

#include<iostream>
#include<string>

using namespace std;

//bad example
//class IEmail {
//public:
//	virtual void set_sender(string)=0;
//	virtual void set_reciever(string)=0;
//	virtual void set_content(string)=0;
//};
//
//class Email :public IEmail {
//public:
//	void set_sender(string sender) { cout << "sender\n"; }
//	void set_reciever(string reciever) { cout << "reciever\n"; }
//	void set_content(string content) { cout << "content\n"; }
//};

//Good Example

class IContent {
public:
	virtual void set_content() = 0;
};

class HtmlContent :public IContent {
public:
	virtual void set_content() { cout << "html conent\n"; }
};

class JsonContent :public IContent {
public:
	virtual void set_content() { cout<<"json content\n"; }
};

class IEmail {
public:
	virtual void set_sender(string) = 0;
	virtual void set_reciever(string) = 0;
	virtual void set_content(IContent* ) = 0; //Decoupeld
};

class Email :public IEmail {
public:
	void set_sender(string sender) { cout << "sender\n"; }
	void set_reciever(string reciever) { cout << "reciever\n"; }
	void set_content(IContent* content) { content->set_content(); }
};

int main()
{
	Email email;
	
	HtmlContent html_obj;
	JsonContent json_obj;

	email.set_content(&html_obj);
	email.set_content(&json_obj);

	return 0;
}