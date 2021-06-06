//---------------------------------------------------------------------------

#ifndef PackOfCardsH
#define PackOfCardsH
//---------------------------------------------------------------------------
#endif
#include "ÑardClass.h"

#include "Windows.h"


class PackOfCards{

	private:
	CardClass* packArr[36];
	public:
	int myMoney, rivalMoney;
		PackOfCards()
		{
				myMoney = 100; rivalMoney = 100;
				packArr[0] = new CardClass(6, (char)60);
				packArr[1] = new CardClass(7, (char)60);
				packArr[2] = new CardClass(8, (char)60);
				packArr[3] = new CardClass(9, (char)60);
				packArr[4] = new CardClass(10, (char)60);
				packArr[5] = new CardClass(11, (char)60);
				packArr[6] = new CardClass(12, (char)60);
				packArr[7] = new CardClass(13, (char)60);
				packArr[8] = new CardClass(14, (char)60);
				packArr[9] = new CardClass(6, (char)61);
				packArr[10] = new CardClass(7, (char)61);
				packArr[11] = new CardClass(8, (char)61);
				packArr[12] = new CardClass(9, (char)61);
				packArr[13] = new CardClass(10, (char)61);
				packArr[14] = new CardClass(11, (char)61);
				packArr[15] = new CardClass(12, (char)61);
				packArr[16] = new CardClass(13, (char)61);
				packArr[17] = new CardClass(14, (char)61);
				packArr[18] = new CardClass(6, (char)62);
				packArr[19] = new CardClass(7, (char)62);
				packArr[20] = new CardClass(8, (char)62);
				packArr[21] = new CardClass(9, (char)62);
				packArr[22] = new CardClass(10, (char)62);
				packArr[23] = new CardClass(11, (char)62);
				packArr[24] = new CardClass(12, (char)62);
				packArr[25] = new CardClass(13, (char)62);
				packArr[26] = new CardClass(14, (char)62);
				packArr[27] = new CardClass(6, (char)63);
				packArr[28] = new CardClass(7, (char)63);
				packArr[29] = new CardClass(8, (char)63);
				packArr[30] = new CardClass(9, (char)63);
				packArr[31] = new CardClass(10, (char)63);
				packArr[32] = new CardClass(11, (char)63);
				packArr[33] = new CardClass(12, (char)63);
				packArr[34] = new CardClass(13, (char)63);
				packArr[35] = new CardClass(14, (char)63);
		}

		void ShowCard(int cardNum);
		void UseImage (int cardNum, TImage* TImage1);
		String CombinationCheck (int num1, int num2, int num3, int num4, int num5, int num6, int num7);
		static int CombinationNum (String combination);
		static bool NoMatches (int num1, int num2, int num3, int num4,
		 int num5, int num6, int num7, int num8, int num9);
};


