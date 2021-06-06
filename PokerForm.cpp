//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PokerForm.h"
#include "PackOfCards.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
PackOfCards* packOfCards = new PackOfCards();

#include <iostream>
using namespace std;
#include <iostream>
#include <jpeg.hpp>
#include "PNGImage.hpp"
#include <ctime>
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	int cardNum1, cardNum2, cardNum3, cardNum4, cardNum5, myCardNum1, myCardNum2, rivalCardNum1, rivalCardNum2;
	int cardArr[9], temp;
	srand(time(0));
	cardArr[0] = rand() % 36;
	bool match;
	for (int i = 1; i < 9; i++) {

		match = false;
		do {

			temp = rand() % 36;

			for (int j = 0; j < i; j++) {

				if (cardArr[i] == cardArr[j]) { match = true; }
			}

		} while (match);
		cardArr[i] = temp;
	}
	cardNum1 = cardArr[0]; cardNum2 = cardArr[1]; cardNum3 = cardArr[2];
	cardNum4 = cardArr[3]; cardNum5 = cardArr[4]; myCardNum1 = cardArr[5];
	myCardNum2 = cardArr[6]; rivalCardNum1 = cardArr[7]; rivalCardNum2 = cardArr[8];

	//-----------------------------------------------------------------------
	Memo1->Lines->Clear();
	Memo1->Lines->Add("Hint:");
	Memo1->Lines->Add(packOfCards->CombinationCheck
	(cardNum1, cardNum2, cardNum3, cardNum4, cardNum5, myCardNum1, myCardNum2));
	Memo1->Lines->Add("my money before game = " + IntToStr(packOfCards->myMoney));
	//-----------------------------------------------------------------------
	Memo2->Lines->Clear();
	Memo2->Lines->Add("Hint:");
	Memo2->Lines->Add(packOfCards->CombinationCheck
	(cardNum1, cardNum2, cardNum3, cardNum4, cardNum5, rivalCardNum1, rivalCardNum2));
	Memo2->Lines->Add("rival money before game = " + IntToStr(packOfCards->rivalMoney));
	//-----------------------------------------------------------------------
	packOfCards->UseImage(cardNum1, Image1);
	packOfCards->UseImage(cardNum2, Image2);
	packOfCards->UseImage(cardNum3, Image3);
	packOfCards->UseImage(cardNum4, Image4);
	packOfCards->UseImage(cardNum5, Image5);
	packOfCards->UseImage(myCardNum1, Image6);
	packOfCards->UseImage(myCardNum2, Image7);
	packOfCards->UseImage(rivalCardNum1, Image8);
	packOfCards->UseImage(rivalCardNum2, Image9);
	//-----------------------------------------------------------------------
	int myCombination = packOfCards->CombinationNum(packOfCards->CombinationCheck
	(cardNum1, cardNum2, cardNum3, cardNum4, cardNum5, myCardNum1, myCardNum2));
	//-----------------------------------------------------------------------
	int rivalCombination = packOfCards->CombinationNum(packOfCards->CombinationCheck
	(cardNum1, cardNum2, cardNum3, cardNum4, cardNum5, rivalCardNum1, rivalCardNum2));
	//-----------------------------------------------------------------------
	if (myCombination > rivalCombination) {

		packOfCards->myMoney += 10;
		packOfCards->rivalMoney -= 10;
	}
	else if (myCombination < rivalCombination) {

		packOfCards->myMoney -= 10;
		packOfCards->rivalMoney += 10;
	}
	//-----------------------------------------------------------------------
	Memo1->Lines->Add("my money now = " + IntToStr(packOfCards->myMoney));
	Memo2->Lines->Add("rival money now = " + IntToStr(packOfCards->rivalMoney));

	}
//---------------------------------------------------------------------------


