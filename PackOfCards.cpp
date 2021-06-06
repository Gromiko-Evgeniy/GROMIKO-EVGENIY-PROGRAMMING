//---------------------------------------------------------------------------

#pragma hdrstop

#include "PackOfCards.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


String PackOfCards:: CombinationCheck (int num1, int num2, int num3, int num4, int num5, int num6, int num7)
{
	CardClass* TempPackArr[7];
	TempPackArr[0] = packArr [num1];
	TempPackArr[1] = packArr [num2];
	TempPackArr[2] = packArr [num3];
	TempPackArr[3] = packArr [num4];
	TempPackArr[4] = packArr [num5];
	TempPackArr[5] = packArr [num6];
	TempPackArr[6] = packArr [num7];
	

	//---------------------------------------------------

	CardClass* temp;                             // sort
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6 - i; j++) {
			if (TempPackArr[j]->cardRang > TempPackArr[j + 1]->cardRang) {
				temp = TempPackArr[j];
				TempPackArr[j] = TempPackArr[j + 1];
				TempPackArr[j + 1] = temp;
			}
		}
	}
	//---------------------------------------------------


	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		int tempNum = TempPackArr[i]->cardRang;
		for (int j = 0; j < 7; j++) {

			if (tempNum == TempPackArr[j]->cardRang) {count++;}
		}
		if (count == 4) {count = 0; return "Four of a king";}
		count = 0;
	}
	count = 0;

	//---------------------------------------------------

	for (int i = 0; i < 7; i++)
	{
		String tempNum = TempPackArr[i]->cardSuit;
		for (int j = 0; j < 7; j++) {

			if (tempNum == TempPackArr[j]->cardSuit) {count++;}
		}

		if (count >= 5) {

			count = 0; return "Flush";
		}
		count = 0;
	}
	//---------------------------------------------------

	count = 0;
	for (int i = 1; i < 7; i++) {

		if (TempPackArr[i - 1]->cardRang + 1 == TempPackArr[i]->cardRang) {

			count++;
		}
		else{
            count = 0;
        }

		if (count>=4) {
			count = 0;
			return "Straight";
		}
	}
    count = 0;
	//---------------------------------------------------

	for (int i = 0; i < 7; i++)
	{
		int tempNum = TempPackArr[i]->cardRang;
		for (int j = 0; j < 7; j++) {

			if (tempNum == TempPackArr[j]->cardRang) {count++;}
		}
		if (count == 3) {count = 0; return "Three of a king";}
		count = 0;
	}
    count = 0;
	//---------------------------------------------------

	for (int i = 1; i < 7; i++)
	{
		if (TempPackArr[i - 1]->cardRang == TempPackArr[i]->cardRang) {
			count++;
		}

		if (count == 2) {
			count = 0;
			return "Two pair";
		}
	}
	//---------------------------------------------------

	for (int i = 0; i < 7; i++)
	{
		int tempNum = TempPackArr[i]->cardRang;
		for (int j = 0; j < 7; j++) {

			if (tempNum == TempPackArr[j]->cardRang) {count++;}
		}
		if (count == 2) {count = 0; return "Pair";}
		count = 0;
	}
	//---------------------------------------------------

	return IntToStr(TempPackArr[6]->cardRang);
}

void PackOfCards:: UseImage (int cardNum, TImage* Image1)
{
	Image1->Picture->LoadFromFile(IntToStr(cardNum)+ ".png");
}

int PackOfCards:: CombinationNum (String combination){

	if (combination == "Pair") {return 15;}
	if (combination == "Two pair") {return 16;}
	if (combination == "Three of a king") {return 17;}
	if (combination == "Straight") {return 18;}
	if (combination == "Flush") {return 19;}
	if (combination == "Full house") {return 20;}
	if (combination == "Four of a king") {return 21;}
	if (combination == "Straight Flush") {return 22;}
	return StrToInt(combination);
}

bool PackOfCards:: NoMatches (int num1, int num2, int num3,
 int num4, int num5, int num6, int num7, int num8, int num9)
{
	srand(time(0));
	int tempArr[9] = {num1, num2, num3, num4, num5, num6, num7, num8, num9};
	int count;
	for (int i = 0; i < 9; i++)
	{
		int tempNum = tempArr[i];
		for (int j = 0; j < 9; j++) {

			if (tempNum == tempArr[j]) {count++;}
		}
		if (count >= 2) {count = 0; return false;}
		count = 0;
	}
	return true;
}

