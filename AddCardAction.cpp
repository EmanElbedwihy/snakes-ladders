#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
//#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
//#include "CardNine.h"
//#include "CardTen.h"
//#include "CardEleven.h"
//#include "CardTwelve.h"


AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp), cardNumber(0), cardPosition(-1, -1)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("New Card:Type the card number ...");
	cardNumber = pIn->GetInteger(pOut);
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("New Card:Click on the card cell, Click to continue . . .");
	cardPosition = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters

	//get integer needs to be edited
	//cardNumber validation (to be edited if needed) 
	if ((int)cardNumber != cardNumber || cardNumber <= 0 || cardNumber > 12)
		do
		{
			pGrid->PrintErrorMessage("invalid cardNumber, type the card number again, Click to continue . . .");
			cardNumber = pIn->GetInteger(pOut);

		} while ((int)cardNumber != cardNumber || cardNumber <= 0 || cardNumber > 12);


		//cardPosition validation
	else
	{
		if (cardPosition.IsValidCell())
		{
			if (!(pGrid->emptyCell(&cardPosition)))
				pGrid->PrintErrorMessage("The card can't be added, the cell has another game object, Click to continue ");
			else if (cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99)
				pGrid->PrintErrorMessage("You cannot place game objects in the first or last cell, Click to continue");
		}
		else
			pGrid->PrintErrorMessage("Invalid Cell, Click to continue . . .");
	}


	// 5- Clear status bar
	pOut->ClearStatusBar();

}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	//case 5:
		//pCard = new CardFive(cardPosition);
		//break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	/*case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;*/
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

		//parameter to be added bokra after i set the attributes of each cardNumber 

		switch (cardNumber)
		{
		case 1:  pCard->ReadCardParameters(pGrid);
			break;
		case 2:  pCard->ReadCardParameters(pGrid);
			break;
		case 3:  pCard->ReadCardParameters(pGrid);
			break;
		case 4:  pCard->ReadCardParameters(pGrid);
			break;
		case 5:  pCard->ReadCardParameters(pGrid);
			break;
		case 6:  pCard->ReadCardParameters(pGrid);
			break;
		case 7:  pCard->ReadCardParameters(pGrid);
			break;
		case 8:  pCard->ReadCardParameters(pGrid);
			break;
		case 9:  pCard->ReadCardParameters(pGrid);
			break;
		case 10: pCard->ReadCardParameters(pGrid);
			break;
		case 11: pCard->ReadCardParameters(pGrid);
			break;
		case 12: pCard->ReadCardParameters(pGrid);
			break;
		}

		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
			pGrid->PrintErrorMessage("Error: Card Couldn't be added ! Click to continue ...");

	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
