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
		quest.push_back(new Questions("��� ������� �������� ������������!", true));
		quest.push_back(new Questions("���������� ������ ������! \n���� �� ���??", false));
		quest.push_back(new Questions("�� ����������� ������ �����. \n����������?", true));
		quest.push_back(new Questions("�������� �������� �����. \n��� ������� �� �������?", false));
		quest.push_back(new Questions("� �������� ������ ���� ��������. \n�������� ����?", true));
		quest.push_back(new Questions("�� �������� ��������� � �������. \n³�������� ������ ���� ��������?", false));
		quest.push_back(new Questions("����� ������ ��������� ��������� ���! \n������� ��������� ������������?", true));
		quest.push_back(new Questions("�� ���� � ����� ����� ������ ���� �����. \n�������� �������?", false));
		quest.push_back(new Questions("���� �� �������� �� ���� ������� ������.\n�������� �������?", false));
		quest.push_back(new Questions("���� ����� ������ ���������� � ����� �������. \n�������� ������?", true));

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
		quest.push_back(new Questions("� ����� ���������� ���.\n������� �� ����� �� ��������?", true));
		quest.push_back(new Questions("���� ��������� �����.\n�� ����� ��� ���������� ������?", false));
		quest.push_back(new Questions("������� ������� �����! \n�� ������ �� �������!", true));
		quest.push_back(new Questions("� ��� �� ������� �����.\n�� �� ������ ��������� ���?", true));
		quest.push_back(new Questions("���� ������������ ������� �������! \n��� ������� �� �������?", false));
		quest.push_back(new Questions("�� ������ �������� ������! \n�������� ��!?", true));
		quest.push_back(new Questions("� ��� ���� ����������. \n��������� ��?", true));
		quest.push_back(new Questions("����� �������� ������� �� ����, \n�� ���������� ���������� ����� ��������.\n��� �������� ��?", false));
		quest.push_back(new Questions("�� ��������� ������������ ����� ����. \n�� ������� �����?", true));
		quest.push_back(new Questions("������ ���������?", true));
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
		quest.push_back(new Questions("������� ����� ��� �� ����� �����?", true));
		quest.push_back(new Questions("�� ��������� ���������� ��������� �����.\n�� ������ ������������ �������?", true));
		quest.push_back(new Questions("��� ��������� ���������� ������! \n̳�����, ������� �� �� �����?", false));
		quest.push_back(new Questions("� ���� ������ ���! �� ���������� � ��������� ����.\n��������� �������� ����������?", true));
		quest.push_back(new Questions("���� ����� ���������� ����� ��������� � ����������. \n�� ������ �� �������?", false));
		quest.push_back(new Questions("����� ������ ���������! \n��� ��������� ���� ��������!", true));
		quest.push_back(new Questions("��� �������, �� �� ���������� ��������� ������� �������.. \n������ ��� ��������� ��� �������!", false));
		quest.push_back(new Questions("�� ������� � ������� �������� ������ �������, �� ����. \n�� ��� �����. ��� ���������� ��?", false));
		quest.push_back(new Questions("� ������� ���� ������! \n��������� ������ ��������� ��� �����, ��� ����������� �����!", true));
		quest.push_back(new Questions("� ��� � ������. �� ������� �� ���� ���� �����?", false));
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
		quest.push_back(new Questions("��� ��������� ������ �������.", true));
		quest.push_back(new Questions("� ��� �� ����� ��������� �����! \n �������� �������� ������ �� �����!", false));
		quest.push_back(new Questions("��� ��������� ��������� ������ �����, \n��� �� ����� �������� ����� ������ � ������!", true));
		quest.push_back(new Questions("����� ������� ��� ��������� ���������! \n �� �������� ��� �����!", false));
		quest.push_back(new Questions("������ �������� ���� ��������� �� ������, \n��� ���������� ��� ������� ��������?", true));
		quest.push_back(new Questions("������� ������ ����?", true));
		quest.push_back(new Questions("³������ ��������� � ���� ����������� \n������������, ����������?", false));
		quest.push_back(new Questions("������ ��������� � ���� ����������� \n������������, ����������?", false));
		quest.push_back(new Questions("���� ������ �����! \n������� �� �� �����?", false));
		quest.push_back(new Questions("��� ��������� �������� ��������� ������!", true));
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
