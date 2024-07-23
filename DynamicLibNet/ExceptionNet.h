using namespace System;

public ref class HeroHPNet: public System::Exception {
	String^ message;

public:
	HeroHPNet() :message("hp: 0") {}
	HeroHPNet(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};

public ref class WallEx : public System::Exception {
	String^ message;

public:
	WallEx() :message("ay") {}
	WallEx(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};

public ref class  WinnerHero : public System::Exception {
	String^ message;

public:
	WinnerHero() :message("uraa") {}
	WinnerHero(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};