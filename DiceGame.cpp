#include <iostream>

int BankPlayer = 10;

int Choixnombrejoueur()
{
	int playNumb = 0;	//Initiation de la variable avec une valeur à 0

	bool isNumbreValid = true;

	while (isNumbreValid)
	{
		std::cout << "Choisissez un nombre entre 1 et 6 : ";

		std::cin >> playNumb;

		// TODO : si le joueur entre une lettre il y'aura des bug
		if (playNumb <= 0 || playNumb > 6)
		{
			system("cls");
			std::cout << "Entrer pas valide" << std::endl << std::endl;
		}
		else
		{
			isNumbreValid = false;
		}
	}

	system("cls");

	return playNumb;
}
int Choixmoneypari()
{
	int mise = 0; //Initiation de la variable avec une valeur à 10
	bool isMiseValid = true;

	while (isMiseValid)
	{
		std::cout << "Votre Banque : " << BankPlayer << std::endl;
		std::cout << "Choisissez une mise de entre :";
		std::cin >> mise;

		// TODO : si le joueur entre une lettre il y'aura des bug
		if (mise > BankPlayer)
		{
			system("cls");
			std::cout << "Entrer pas valide" << std::endl << std::endl;
		}
		else
		{
			isMiseValid = false;
		}
	}

	system("cls");

	return mise;
}

int LancerDe()
{
	int Dice = std::rand() % 6 + 1;

	return Dice;
}

void ComparaisonResultat(int playerNumber, int resultDice, int mise)
{
	if (playerNumber == resultDice)
	{
		std::cout << "Vous avez gagne : " << mise * 2 << std::endl << std::endl;
		BankPlayer += mise * 2;
	}
	else
	{
		std::cout << "Vous avez perdu : " << mise << std::endl << std::endl;
		BankPlayer -= mise;
	}
}

bool EndRound()
{
	char continu = NULL;
	bool isValideInput = false;

	if (BankPlayer <= 0)
	{
		std::cout << "Vous n'avez plus d'argent" << std::endl;

		while (!isValideInput)
		{
			std::cout << "Voulez vous remetre 10 dans la banque ? (y/n) ";
			std::cin >> continu;

			system("cls");

			if (continu == 'Y' || continu == 'y')
			{
				isValideInput = true;
				BankPlayer += 10;
			}
			else if (continu == 'N' || continu == 'n')
			{
				isValideInput = true;
				std::cout << "Vous avez tout perdu" << std::endl;
				return false;
			}
			else
			{
				system("cls");
				std::cout << "entrer invalid" << std::endl << std::endl;
			}
		}
	}
	else
	{
		while (!isValideInput)
		{
			std::cout << "Voulez-vous continuer ? (y/n) : " << std::endl;
			std::cin >> continu;

			system("cls");

			if (continu == 'Y' || continu == 'y')
			{
				isValideInput = true;
			}
			else if(continu == 'N' || continu == 'n')
			{
				isValideInput = true;
				std::cout << "Vous avez ganger en tout : " << BankPlayer << std::endl;
				return false;
			}
			else
			{
				system("cls");
				std::cout << "entrer invalid" << std::endl << std::endl;
			}
		}
	}
	return true;
}

void main()
{
	std::srand(std::time(nullptr));

	bool gameLoop = true;

	std::cout << "Bienvenue au jeu de de" << std::endl << std::endl;

	while (gameLoop)
	{
		int number = Choixnombrejoueur();

		int mise = Choixmoneypari();

		std::cout << "Nombre du joueur : " << number << std::endl;

		std::cout << "Mise du joueur : " << mise << std::endl << std::endl;

		int resultDice = LancerDe();

		std::cout << "Resultat du de : " << resultDice << std::endl;

		ComparaisonResultat(number, resultDice, mise);

		std::cout << "Votre Banque : " << BankPlayer << std::endl;

		gameLoop = EndRound();
	}

	system("pause");
}
