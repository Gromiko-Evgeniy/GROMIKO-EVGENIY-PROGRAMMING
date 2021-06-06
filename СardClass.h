//---------------------------------------------------------------------------

#ifndef ÑardClassH
#define ÑardClassH
//---------------------------------------------------------------------------
#endif

class CardClass
{
	public:
	String cardSuit;  //mast
	int cardRang;  //rang

	CardClass(int _cardRang, char _cardSuit)
	{
		cardSuit = _cardSuit;
		cardRang = _cardRang;
	}
};