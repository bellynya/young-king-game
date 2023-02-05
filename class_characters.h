//---------------------------------------------------------------------------

#ifndef class_charactersH
#define class_charactersH
#include <vector>
#include "advisor_type.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class Advisor;
class MilitaryAdvisor;
class PeopleAdvisor;
class ReligionAdvisor;
class TreasuryAdvisor;


class Questions
{
	public:
	AnsiString quest;
	bool is_positive;
	Questions(AnsiString s, bool reaction)
	{
		quest = s;
		is_positive = reaction;
	}

	AnsiString GetQuestion()
	{
		return quest;
	}

	bool GetQuestionResult()
	{
		return this->is_positive;
    }
};

class King
{
	public:
	AnsiString name;
    int year_count;
};

class Advisor
{
	public:
	static TImage *im;
	static AdvisorType adv;
	int current_question;
	std::vector<Questions*> quest;
	AnsiString GetRandomQuestion()
	{
		int question_number = rand()%9;
		current_question = question_number;
		return quest[question_number]->GetQuestion();
	}
	virtual void LoadImg(){};
	virtual AdvisorType CheckAdvisorType(){};
};

class MilitaryAdvisor : public Advisor
{
	public:

	MilitaryAdvisor()
	{
		quest.push_back(new Questions("Нам потрібно збільшити фінансування!", true));
		quest.push_back(new Questions("Королівства півночі напали! \nДати їм бою??", false));
		quest.push_back(new Questions("Ми випробували новітню зброю. \nЗакуповуємо?", true));
		quest.push_back(new Questions("Генерали планують змову. \nМені вирішити це питання?", false));
		quest.push_back(new Questions("У військової поліції немає керівника. \nазначимо його?", true));
		quest.push_back(new Questions("Ми винайшли скарбницю з грошима. \nВідправити військо його привезти?", false));
		quest.push_back(new Questions("Нашій кінниці необхідна додаткова їжа! \nВидасте додаткове фінансування?", true));
		quest.push_back(new Questions("На одне з наших селищ нападає стая вовків. \nНадіслати патруль?", false));
		quest.push_back(new Questions("Один із старійшин не хоче платити данину.\nНадіслати дружину?", false));
		quest.push_back(new Questions("Інша країна виконує провокацію у наших кордонів. \nНадіслати військо?", true));

	}
	void LoadImg() override
	{
		im->Picture->LoadFromFile("photo\\army.bmp");
	}

	AdvisorType CheckAdvisorType() override
	{
		return adv = MILITARY;
	}

};

class PeopleAdvisor : public Advisor
{
	public:
	PeopleAdvisor()
	{
		quest.push_back(new Questions("В амбарі закінчується їжа.\nВиділите ще гроші на закупівлю?", true));
		quest.push_back(new Questions("Чума розійшлася містом.\nЧи варто нам винищувати хворих?", false));
		quest.push_back(new Questions("Податки занадто високі! \nВи мусите їх знизити!", true));
		quest.push_back(new Questions("В місті не вистачає осель.\nЧи ми можемо збудувати нові?", true));
		quest.push_back(new Questions("Люди відмовляються платити податки! \nМені вирішити це питання?", false));
		quest.push_back(new Questions("Ми зібрали великого врожаю! \nВлаштуємо пір!?", true));
		quest.push_back(new Questions("В місті немає каналізації. \nОблаштуємо її?", true));
		quest.push_back(new Questions("Схоже анахрісти пройшли до міста, \nта збираються влаштувати акції протесту.\nМені винищити їх?", false));
		quest.push_back(new Questions("Ми збираємося перебудувати міську стіну. \nВи виділите кошти?", true));
		quest.push_back(new Questions("Хочете подарунок?", true));
	}
	void LoadImg() override
	{
		im->Picture->LoadFromFile("photo\\people.bmp");
	}

	AdvisorType CheckAdvisorType() override
	{
		return adv = PEOPLE;
	}
};

class ReligionAdvisor : public Advisor
{
	public:
	ReligionAdvisor()
	{
		quest.push_back(new Questions("Виділите гроші нам на новий собор?", true));
		quest.push_back(new Questions("Ми збираємося влаштувати хрестовий похід.\nВи будете постачатинам ресурси?", true));
		quest.push_back(new Questions("Нам необхідно влаштувати банкет! \nМілорде, виділите на це кошти?", false));
		quest.push_back(new Questions("В країні замало віри! Ми занепадаємо в духовному плані.\nДозволите провести шестування?", true));
		quest.push_back(new Questions("Пара наших священників війшла суперечка з військовими. \nВи вірішите це питання?", false));
		quest.push_back(new Questions("Башта церкви руйнується! \nНам необхідна ваша допомога!", true));
		quest.push_back(new Questions("Мені здається, що за монахинями починають стежити бандити.. \nВиділіть нам військових для охорони!", false));
		quest.push_back(new Questions("Всі монахині в жіночому монастирі почали мяукати, як кішки. \nЦе йде містом. Нам приборкати їх?", false));
		quest.push_back(new Questions("В столиці синя холера! \nНеобхідно швидко відкривати нові храми, аби виліковувати людей!", true));
		quest.push_back(new Questions("У вас є бастрд. Чи визнаєте ви його своїм сином?", false));
	}
	void LoadImg() override
	{
		im->Picture->LoadFromFile("photo\\church.bmp");
	}

	AdvisorType CheckAdvisorType() override
	{
		return adv = RELIGION;
	}
};

class TreasuryAdvisor : public Advisor
{
	public:
	TreasuryAdvisor()
	{
		quest.push_back(new Questions("Нам необхідно підняти податки.", true));
		quest.push_back(new Questions("У нас на порозі фанансова криза! \n Необхідні вливання грошей до ринку!", false));
		quest.push_back(new Questions("Нам необхідно поновоити міський ринок, \nаби ми могли приймати більше товарів і купців!", true));
		quest.push_back(new Questions("Зніміть пошлину для мадруючих торговців! \n Це стимулює наш ринок!", false));
		quest.push_back(new Questions("Бажаєте надіслати нашу делегацію на південь, \nаби домовитися про торгівлю спеціями?", true));
		quest.push_back(new Questions("Збудуємо міський банк?", true));
		quest.push_back(new Questions("Військові попросили в мене додаткового \nфінансування, дозволяєте?", false));
		quest.push_back(new Questions("Церква попросила в мене додаткового \nфінансування, дозволяєте?", false));
		quest.push_back(new Questions("Люди хочуть свята! \nВиділити на це гроші?", false));
		quest.push_back(new Questions("Нам необхідно підвищити видобуток золота!", true));
	}
	void LoadImg() override
	{
		im->Picture->LoadFromFile("photo\\treasury.bmp");
	}

    AdvisorType CheckAdvisorType() override
	{
		return adv = TREASURY;
	}
};

class Game
{
	public:
	TImage *im;
	Advisor *a_current;
	Questions *q_current;
	TProgressBar *pbPep;
	TProgressBar *pbMil;
	TProgressBar *pbTre;
	TProgressBar *pbRel;
	TGroupBox *gbUp;
	TGroupBox *gbDw;
	TLabel *lQuest;
	void (*StartUpFunc)();


	Game()
	{
		adv.push_back(new MilitaryAdvisor());
		adv.push_back(new PeopleAdvisor());
		adv.push_back(new ReligionAdvisor());
		adv.push_back(new TreasuryAdvisor());
	}

	std::vector<Advisor*> adv;

	AnsiString GenerateRandomQuestion()
	{
		int k = rand()%4;
		adv[k]->LoadImg();

		a_current = adv[k];

		return adv[k]->GetRandomQuestion();
	}

	bool CheckQuestion()
	{
		return a_current->quest[a_current->current_question]->GetQuestionResult();
	}

	void LevelInitialization()
	{
		pbMil->Position = 50;
		pbPep->Position = 50;
		pbTre->Position = 50;
		pbRel->Position = 50;
		(*StartUpFunc)();

	}
};

#endif
