#include <stdio.h>
#include "Lab2_C_header.h"

struct Tariff
{
    float free_talkTime_toTheSameNetwork;
    float free_talkTime_toOtherNetwork;
    float free_talkTime_toUrbanNetwork;
    float free_SMScount;
    float minPrice;
    float totalPrice;
};


int main()
{
	
    float talkTime_toTheSameNetwork;
	float talkTime_toOtherNetwork;
	float talkTime_toUrbanNetwork;
	float SMScount;
	char unswer = ' ';

	while (unswer != 'n')
	{
		printf("Do you wanna choose tariff? (y/n) \n");
		scanf("%c", unswer);
		if (unswer == 'y')
		{
			printf("Tariff info: \n");
			printf("Enter your characteristics: \n");

			printf("talk time to the same network = ");
			scanf("%e", &talkTime_toTheSameNetwork);
			if (talkTime_toTheSameNetwork >= 0)
			{
				printf("talk time to other network = ");
				scanf("%e", &talkTime_toOtherNetwork);
				if (talkTime_toOtherNetwork >= 0)
				{
					printf("talk time to urban network = ");
					scanf("%e", &talkTime_toUrbanNetwork);
					if (talkTime_toUrbanNetwork >= 0)
					{
						printf("number of SMS = ");
						scanf("%e", &SMScount);
						if (SMScount >= 0)
						{
							/*---------------------------------------------------------------------*/

							struct Tariff business; /*all inclusive*/
							business.minPrice = 100;
							business.totalPrice = business.minPrice;

							/*---------------------------------------------------------------------*/


							struct Tariff empty = { 0, 0, 0, 0, 0, 0 };
							empty.totalPrice = empty.minPrice
								+ SMSprice(SMScount)
								+ TheSameNetworkCallPrice(talkTime_toTheSameNetwork)
								+ OtherNetworkCallPrice(talkTime_toOtherNetwork)
								+ UrbanNetworkCallPrice(talkTime_toUrbanNetwork);

							/*---------------------------------------------------------------------*/

							struct Tariff medium = { 80, 20, 70, 10, 50 };
							if (talkTime_toTheSameNetwork < medium.free_talkTime_toTheSameNetwork)
							{
								talkTime_toTheSameNetwork = 0;
								medium.free_talkTime_toTheSameNetwork = 0;
							}

							if (talkTime_toOtherNetwork < medium.free_talkTime_toOtherNetwork)
							{
								talkTime_toOtherNetwork = 0;
								medium.free_talkTime_toOtherNetwork = 0;
							}

							if (talkTime_toUrbanNetwork < medium.free_talkTime_toUrbanNetwork)
							{
								talkTime_toUrbanNetwork = 0;
								medium.free_talkTime_toUrbanNetwork = 0;
							}

							medium.totalPrice = medium.minPrice
								+ SMSprice(SMScount)
								+ TheSameNetworkCallPrice(talkTime_toTheSameNetwork - medium.free_talkTime_toTheSameNetwork)
								+ OtherNetworkCallPrice(talkTime_toOtherNetwork - medium.free_talkTime_toOtherNetwork)
								+ UrbanNetworkCallPrice(talkTime_toUrbanNetwork - medium.free_talkTime_toUrbanNetwork);

							/*---------------------------------------------------------------------*/
							struct Tariff minimum = { 50, 5, 50, 0, 20 };
							if (talkTime_toTheSameNetwork < minimum.free_talkTime_toTheSameNetwork)
							{
								talkTime_toTheSameNetwork = 0;
								minimum.free_talkTime_toTheSameNetwork = 0;
							}

							if (talkTime_toOtherNetwork < minimum.free_talkTime_toOtherNetwork)
							{
								talkTime_toOtherNetwork = 0;
								minimum.free_talkTime_toOtherNetwork = 0;
							}

							if (talkTime_toUrbanNetwork < minimum.free_talkTime_toUrbanNetwork)
							{
								talkTime_toUrbanNetwork = 0;
								minimum.free_talkTime_toUrbanNetwork = 0;
							}

							minimum.totalPrice = minimum.minPrice
								+ SMSprice(SMScount)
								+ TheSameNetworkCallPrice(talkTime_toTheSameNetwork - minimum.free_talkTime_toTheSameNetwork)
								+ OtherNetworkCallPrice(talkTime_toOtherNetwork - minimum.free_talkTime_toOtherNetwork)
								+ UrbanNetworkCallPrice(talkTime_toUrbanNetwork - minimum.free_talkTime_toUrbanNetwork);

							/*---------------------------------------------------------------------*/

							if (business.totalPrice < empty.totalPrice)
							{
								if (business.totalPrice < medium.totalPrice)
								{
									if (business.totalPrice < minimum.totalPrice)
									{
										printf(" 11111111111111111 \n \n");
									}
									else
									{
										printf(" 44444444444444444444 \n \n");
									}
								}
								else
								{
									if (medium.totalPrice < minimum.totalPrice)
									{
										printf(" 3333333333333333333333 \n \n");
									}
									else
									{
										printf(" 44444444444444444444 \n \n");
									}
								}

							}
							else
							{
								if (empty.totalPrice < medium.totalPrice)
								{
									if (empty.totalPrice < minimum.totalPrice)
									{
										printf(" 2222222222222222222222 \n \n");
									}
									else
									{
										printf(" 44444444444444444444 \n \n");
									}
								}
								else
								{
									if (medium.totalPrice < minimum.totalPrice)
									{
										printf(" 3333333333333333333333 \n \n");
									}
									else
									{
										printf(" 44444444444444444444 \n \n");
									}
								}
							}
						}
						else
						{
							printf("wrong input, try again \n \n");
							continue;
						}
					}
					else
					{
						printf("wrong input, try again \n \n");
						continue;
					}
				}
				else
				{
					printf("wrong input, try again \n \n");
					continue;
				}
			}
			else
			{
				printf("wrong input, try again \n \n");
				continue;
			}
		}
		else if (unswer == 'n')
		{
		printf("Ok, bye \n");
		}
		else
		{
		printf("wrong input, try again \n \n");
		}
	}
}


float SMSprice(float _SMScount)
{
	return _SMScount * 0.2;
}

float TheSameNetworkCallPrice(float _talkTime_toTheSameNetwork)
{
	return _talkTime_toTheSameNetwork * 0.5;
}

float OtherNetworkCallPrice(float _talkTime_toOtherNetwork)
{
	return _talkTime_toOtherNetwork * 1;
}

float UrbanNetworkCallPrice(float _talkTime_toUrbanNetwork)
{
	return _talkTime_toUrbanNetwork * 0.1;
}
