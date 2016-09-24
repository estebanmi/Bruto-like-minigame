#include <iostream>
#include <string.h>


using namespace std;

struct capability
{
	unsigned short level = 0;
	unsigned short life = 100;
	unsigned short strength = 0;
	unsigned short agility = 0;
	unsigned short speed = 0;
};

// functions ///////////////////////////////

//name
void setName(char*);
char* getName(char*);
void printName(char*);
//disciples
void setDisciples(unsigned short*);
unsigned short getDisciples(unsigned short);
void printDisciples(unsigned short);
//clan name
void setClanName(char*);
char* getClanName(char*);
void printClanName(char*);
//weapons
unsigned short getNumWeapons(unsigned short);
void setWeapon(char*,unsigned short*);
void hasWeapon(char*,unsigned short);
void printAvailableWeapons(unsigned short);
//animals
unsigned short getNumAnimals(unsigned short);
void setAnimal(char*, unsigned short*);
void hasAnimal(char*, unsigned short);
void printAvailableAnimals(unsigned short);
//tournament
void registerNextTournament(bool*);
bool isRegisteredNextTournament(bool);
void printRegisterStatus(bool);
//capabilities
void setLevel(capability*);
void incLevel(capability*);
void decLevel(capability*);

void setStrength(capability*);
void incStrength(capability*);
void decStrength(capability*);

void setAgility(capability*);
void incAgility(capability*);
void decAgility(capability*);

void setSpeed(capability*);
void incSpeed(capability*);
void decSpeed(capability*);

void setAll(capability*);
void incAll(capability*);
void decAll(capability*);


int main()
{
	char* name = new char[10];

	unsigned short disciples = 0;
	unsigned short* disciplesPointer = &disciples;

	char* clanName = new char[20];
	capability capabilites;

	char weaponName[20];
	char animalName[10];
	unsigned short weapons = 0;
	unsigned short numWeapons = 0;
	unsigned short animals = 0;
	unsigned short numAnimals = 0;
	bool registered = 0;

	capability* capabilitiesP;
	capabilitiesP = &capabilites;

	/*setName(name);
	getName(name);
	printName(name);

	setDisciples(&disciples);
	getDisciples(disciples);
	printDisciples(disciples);

	setClanName(clanName);  
	getClanName(clanName);
	printClanName(clanName);
	*/
	cout << "Name of weapon(bitwise " << weapons << ")? ";

	cout << weapons << endl;
	cin >> weaponName;
	setWeapon(weaponName,&weapons);
	numWeapons = getNumWeapons(weapons);
	cout << "Total weapons: " << numWeapons << endl;

	cout << "Name of weapon(bitwise " << weapons << ")? ";

	cout << weapons << endl;
	cin >> weaponName;
	setWeapon(weaponName, &weapons);
	numWeapons = getNumWeapons(weapons);
	cout << "Total weapons: " << numWeapons << endl;

	cout << "Name of weapon(bitwise " << weapons << ")? ";
	cin >> weaponName;
	hasWeapon(weaponName,weapons);
	
	printAvailableWeapons(weapons);
	
	////////////////////////////////////////
	/*
	cout << "Name of animal(bitwise " << animals << ")? ";

	cout << numAnimals << endl;
	cin >> animalName;
	setAnimal(animalName, &animals);
	numAnimals = getNumAnimals(animals);
	cout << "Total animals: " << numAnimals << endl;

	cout << "Name of animal(bitwise " << animals << ")? ";

	cout << animals << endl;
	cin >> animalName;
	setAnimal(animalName, &animals);
	numAnimals = getNumAnimals(animals);
	cout << "Total animals: " << numAnimals << endl;

	cout << "Name of animal(bitwise " << animals << ")? ";
	cin >> animalName;
	hasAnimal(animalName, animals);

	printAvailableAnimals(animals);

	printRegisterStatus(registered);
	getchar();
	registerNextTournament(&registered);
	isRegisteredNextTournament(registered);
	printRegisterStatus(registered);

	setLevel(capabilitiesP);
	incLevel(capabilitiesP);
	decLevel(capabilitiesP);

	setStrength(capabilitiesP);
	incStrength(capabilitiesP);
	decStrength(capabilitiesP);

	setAgility(capabilitiesP);
	incAgility(capabilitiesP);
	decAgility(capabilitiesP);

	setSpeed(capabilitiesP);
	incSpeed(capabilitiesP);
	decSpeed(capabilitiesP);

	setAll(capabilitiesP);
	incAll(capabilitiesP);
	decAll(capabilitiesP);
	*/
	getchar();
	getchar();

	return 0;
}

//name
void setName(char* name)
{
	cin >> name;
}
char* getName(char* name)
{
	return name;
}
void printName(char* name)
{
	cout << name << endl;
}

//disciples
void setDisciples(unsigned short* disciples)
{
	unsigned short numberDisciples = 0;
	cin >> numberDisciples;
	*disciples = numberDisciples;
}
unsigned short getDisciples(unsigned short disciples)
{
	return disciples;
}
void printDisciples(unsigned short disciples)
{
	cout << disciples << endl;
}

//Clan name
void setClanName(char* clanName)                                   /////// strings with espaces should be better
{
	cin >> clanName;
}                         
char* getClanName(char* clanName)
{
	return clanName;
}
void printClanName(char* clanName)
{
	cout << clanName << endl;
}

//weapons
unsigned short getNumWeapons(unsigned short weapons)              /////// sum operator should be better
{
	unsigned short counter = 0;

	for (int i = 0; i < 16; i++)
	{
		if ((weapons >> i) & 0x0001)
		{
			counter++;
		}
	}

	return counter;
}           
void setWeapon(char* weaponName, unsigned short* weapons)          /////// strings with espaces should be better
{
	///////////StoneHammer///////////
	if (strcmp(weaponName, "StoneHammer") == 0)
	{
		if (*weapons & 0x0001)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0001;
		}
	}
	///////////Baton///////////
	else if (strcmp(weaponName, "Baton") == 0)
	{
		if ((*weapons & 0x0002) >> 1)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0002;
		}
	}
	///////////BROADSWORD///////////
	else if(strcmp(weaponName, "Broadsword") == 0)
	{
		if ((*weapons & 0x0004) >> 2)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0004;
		}
	}
	///////////Bumps///////////
	else if (strcmp(weaponName, "Bumps") == 0)
	{
		if ((*weapons & 0x0008) >> 3)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0008;
		}
	}
	///////////Keyboard///////////
	else if (strcmp(weaponName, "Keyboard") == 0)
	{
		if ((*weapons & 0x0010) >> 4)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0010;
		}
	}
	///////////Knife///////////
	else if (strcmp(weaponName, "Knife") == 0)
	{
		if ((*weapons & 0x0020) >> 5)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0020;
		}
	}
	///////////MorningStar///////////
	else if (strcmp(weaponName, "MorningStar") == 0)
	{
		if ((*weapons & 0x0040) >> 6)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0040;
		}
	}
	///////////Lance///////////
	else if (strcmp(weaponName, "Lance") == 0)
	{
		if ((*weapons & 0x0080) >> 7)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0080;
		}
	}
	///////////MammothBone///////////
	else if (strcmp(weaponName, "MammothBone") == 0)
	{
		if ((*weapons & 0x0100) >> 8)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0100;
		}
	}
	///////////Shuriken///////////
	else if (strcmp(weaponName, "Shuriken") == 0)
	{
		if ((*weapons & 0x0200) >> 9)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0200;
		}
	}
	///////////NoodleBowl///////////
	else if (strcmp(weaponName, "NoodleBowl") == 0)
	{
		if ((*weapons & 0x0400) >> 10)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0400;
		}
	}
	///////////PiouPiouz///////////
	else if (strcmp(weaponName, "PiouPiouz") == 0)
	{
		if ((*weapons & 0x0800) >> 11)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0800;
		}
	}
	///////////SWORD///////////
	else if (strcmp(weaponName, "Sword") == 0)
	{
		if ((*weapons & 0x1000) >> 12)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x1000;
		}
	}
	///////////TennisRacket///////////
	else if (strcmp(weaponName, "TennisRacket") == 0)
	{
		if ((*weapons & 0x2000) >> 13)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x2000;
		}
	}
	///////////Trident///////////
	else if (strcmp(weaponName, "Trident") == 0)
	{
		if ((*weapons & 0x4000) >> 14)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x4000;
		}
	}


	///////////Trombone///////////
	else if (strcmp(weaponName, "Trombone") == 0)
	{
		if ((*weapons & 0x8000) >> 15)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x8000;
		}
	}

	/////////WRONG NAME////////////

	else
	{
		cout << "That name does not exists.\n";
	}
}
void hasWeapon(char* weaponName, unsigned short weapons)
{
	///////////SWORD///////////
	if (strcmp(weaponName, "Sword") == 0)
	{
		if ((weapons & 0x1000) >> 8)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			cout << "You don't have " << weaponName << ".\n";
		}
	}


	///////////KNIFE///////////
	else if (strcmp(weaponName, "Knife") == 0)
	{
		if ((weapons & 0x0020) >> 5)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			cout << "You don't have " << weaponName << ".\n";
		}
	}

	/////////WRONG NAME////////////

	else
	{
		cout << "That name does not exists.\n";
	}
}
void printAvailableWeapons(unsigned short weapons)
{
	if (getNumWeapons != 0)
	{
		cout << "Your weapons:\n";
		for (int i = 0; i < 16; i++)
		{
			if (weapons & 0x0001)
			{
				if (i == 0)
				{
					cout << "-Stone Hammer.\n";
				}	
				if (i == 1)
				{
					cout << "-Baton.\n";
				}
				if (i == 2)
				{
					cout << "-BroadSword.\n";
				}
				if (i == 3)
				{
					cout << "-Bumps.\n";
				}
				if (i == 4)
				{
					cout << "-Keyboard.\n";
				}
				if (i == 5)
				{
					cout << "-Knife.\n";
				}
				if (i == 6)
				{
					cout << "-Morning Star.\n";
				}
				if (i == 7)
				{
					cout << "-Lance.\n";
				}
				if (i == 8)
				{
					cout << "-Mammoth's Bone.\n";
				}
				if (i == 9)
				{
					cout << "-Shuriken.\n";
				}
				if (i == 10)
				{
					cout << "-Noodle Bowl.\n";
				}
				if (i == 11)
				{
					cout << "-Piou-Piouz.\n";
				}
				if (i == 12)
				{
					cout << "-Sword.\n";
				}
				if (i == 13)
				{
					cout << "-Tennis Racket.\n";
				}
				if (i == 14)
				{
					cout << "-Trident.\n";
				}
				if (i == 15)
				{
					cout << "-Trombone.\n";
				}
			}
			weapons = weapons >> 1;
		}
	}
	else
	{
		cout << "You have no weapons.\n";
	}
}

//animals
unsigned short getNumAnimals(unsigned short animals)
{
	unsigned short counter = 0;

	for (int i = 0; i < 3; i++)
	{
		if ((animals >> i) & 0x0001)
		{
			counter++;
		}
	}

	return counter;
}
void setAnimal(char* animalName, unsigned short* animals)
{
	///////////DOG///////////
	if (strcmp(animalName, "Dog") == 0)
	{
		if (*animals & 0x0001)
		{
			cout << "You have " << animalName << " already.\n";
		}
		else
		{
			*animals = *animals | 0x0001;
		}
	}

	///////////WOLF///////////
	else if (strcmp(animalName, "Wolf") == 0)
	{
		if ((*animals & 0x0002) >> 1)
		{
			cout << "You have " << animalName << " already.\n";
		}
		else
		{
			*animals = *animals | 0x0002;
		}
	}

	///////////BEAR///////////
	else if (strcmp(animalName, "Bear") == 0)
	{
		if ((*animals & 0x0004) >> 2)
		{
			cout << "You have " << animalName << " already.\n";
		}
		else
		{
			*animals = *animals | 0x0004;
		}
	}

	/////////WRONG NAME////////////
	else
	{
		cout << "That name does not exists.\n";
	}
}
void hasAnimal(char* animalName, unsigned short animals)
{
	///////////DOG///////////
	if (strcmp(animalName, "Dog") == 0)
	{
		if (animals & 0x0001)
		{
			cout << "You have " << animalName << " already.\n";
		}
		else
		{
			cout << "You don't have " << animalName << ".\n";
		}
	}

	///////////WOLF///////////
	else if (strcmp(animalName, "Wolf") == 0)
	{
		if ((animals & 0x0002) >> 1)
		{
			cout << "You have " << animalName << " already.\n";
		}
		else
		{
			cout << "You don't have " << animalName << ".\n";
		}
	}

	///////////BEAR///////////
	else if (strcmp(animalName, "Bear") == 0)
	{
		if ((animals & 0x0004) >> 2)
		{
			cout << "You have " << animalName << " already.\n";
		}
		else
		{
			cout << "You don't have " << animalName << ".\n";
		}
	}

	/////////WRONG NAME////////////
	else
	{
		cout << "That name does not exists.\n";
	}
}
void printAvailableAnimals(unsigned short animals)
{
	if (getNumAnimals != 0)
	{
		cout << "Your animals:\n";
		for (int i = 0; i < 3; i++)
		{
			if (animals & 0x0001)
			{
				if (i == 0)
				{
					cout << "-Dog.\n";
				}
				if (i == 1)
				{
					cout << "-Wolf.\n";
				}
				if (i == 2)
				{
					cout << "-Bear.\n";
				}
				
			}
			animals = animals >> 1;
		}
	}
	else
	{
		cout << "You have no animals.\n";
	}
}

//tournament
void registerNextTournament(bool* registered)
{
	if (*registered)
	{
		cout << "You are registered already.\n";
	}
	else
	{
		cout << "Registered.\n";
		*registered = true;
	}
}
bool isRegisteredNextTournament(bool registered)
{
	return registered;
}
void printRegisterStatus(bool registered)
{
	cout << "Next Tournament Status:\n";

	if (registered)
	{
		cout << "-Registered.\n";
	}
	else
	{
		cout << "-Not registered.\n";
	}
}

// capabilites /////////////////////////////////////////////

//level
void setLevel(capability* capabilitiesP)
{
	short filter;
	cout << "Set level(0-100): ";
	cin >> filter;

	if ((filter >= 0) && (filter <= 100))
	{
		capabilitiesP->level = filter;
		cout << "Your level is " << capabilitiesP->level << " now.\n";
	}
	else
	{
		cout << "You can't set this number (try 0-100).\n";
	}
}
void incLevel(capability* capabilitiesP)
{
	short filter;
	cout << "Increment by(Max total 100): ";
	cin >> filter;

	if (((filter + capabilitiesP->level) >= 0) && ((filter + capabilitiesP->level) <= 100))
	{
		capabilitiesP->level += filter;
		cout << "Your level is " << capabilitiesP->level << " now.\n";
	}
	else
	{
		cout << "You can't increment(total must be 0-100).\n";
	}
}
void decLevel(capability* capabilitiesP)
{
	short filter;
	cout << "Decrement by(Min total 0): ";
	cin >> filter;

	if (((capabilitiesP->level - filter) >= 0) && ((capabilitiesP->level - filter) <= 100))
	{
		capabilitiesP->level -= filter;
		cout << "Your level is " << capabilitiesP->level << " now.\n";
	}
	else
	{
		cout << "You can't decrement(total must be 0-100).\n";
	}
}
//strength
void setStrength(capability* capabilitiesP)
{
	short filter;
	cout << "Set strength(0-100): ";
	cin >> filter;

	if ((filter >= 0) && (filter <= 100))
	{
		capabilitiesP->strength = filter;
		cout << "Your strength is " << capabilitiesP->strength << " now.\n";
	}
	else
	{
		cout << "You can't set this number (try 0-100).\n";
	}
}
void incStrength(capability* capabilitiesP)
{
	short filter;
	cout << "Increment by(Max total 100): ";
	cin >> filter;

	if (((filter + capabilitiesP->strength) >= 0) && ((filter + capabilitiesP->strength) <= 100))
	{
		capabilitiesP->strength += filter;
		cout << "Your strength is " << capabilitiesP->strength << " now.\n";
	}
	else
	{
		cout << "You can't increment(total must be 0-100).\n";
	}
}
void decStrength(capability* capabilitiesP)
{
	short filter;
	cout << "Decrement by(Min total 0): ";
	cin >> filter;

	if (((capabilitiesP->strength - filter) >= 0) && ((capabilitiesP->strength - filter) <= 100))
	{
		capabilitiesP->strength -= filter;
		cout << "Your strength is " << capabilitiesP->strength << " now.\n";
	}
	else
	{
		cout << "You can't decrement(total must be 0-100).\n";
	}
}
//agility
void setAgility(capability* capabilitiesP)
{
	short filter;
	cout << "Set agility(0-100): ";
	cin >> filter;

	if ((filter >= 0) && (filter <= 100))
	{
		capabilitiesP->agility = filter;
		cout << "Your agility is " << capabilitiesP->agility << " now.\n";
	}
	else
	{
		cout << "You can't set this number (try 0-100).\n";
	}
}
void incAgility(capability* capabilitiesP)
{
	short filter;
	cout << "Increment by(Max total 100): ";
	cin >> filter;

	if (((filter + capabilitiesP->agility) >= 0) && ((filter + capabilitiesP->agility) <= 100))
	{
		capabilitiesP->agility += filter;
		cout << "Your agility is " << capabilitiesP->agility << " now.\n";
	}
	else
	{
		cout << "You can't increment(total must be 0-100).\n";
	}
}
void decAgility(capability* capabilitiesP)
{
	short filter;
	cout << "Decrement by(Min total 0): ";
	cin >> filter;

	if (((capabilitiesP->agility - filter) >= 0) && ((capabilitiesP->agility - filter) <= 100))
	{
		capabilitiesP->agility -= filter;
		cout << "Your agility is " << capabilitiesP->agility << " now.\n";
	}
	else
	{
		cout << "You can't decrement(total must be 0-100).\n";
	}
}
//speed
void setSpeed(capability* capabilitiesP)
{
	short filter;
	cout << "Set speed(0-100): ";
	cin >> filter;

	if ((filter >= 0) && (filter <= 100))
	{
		capabilitiesP->speed = filter;
		cout << "Your speed is " << capabilitiesP->speed << " now.\n";
	}
	else
	{
		cout << "You can't set this number (try 0-100).\n";
	}
}
void incSpeed(capability* capabilitiesP)
{
	short filter;
	cout << "Increment by(Max total 100): ";
	cin >> filter;

	if (((filter + capabilitiesP->speed) >= 0) && ((filter + capabilitiesP->speed) <= 100))
	{
		capabilitiesP->speed += filter;
		cout << "Your speed is " << capabilitiesP->speed << " now.\n";
	}
	else
	{
		cout << "You can't increment(total must be 0-100).\n";
	}
}
void decSpeed(capability* capabilitiesP)
{
	short filter;
	cout << "Decrement by(Min total 0): ";
	cin >> filter;

	if (((capabilitiesP->speed - filter) >= 0) && ((capabilitiesP->speed - filter) <= 100))
	{
		capabilitiesP->speed -= filter;
		cout << "Your speed is " << capabilitiesP->speed << " now.\n";
	}
	else
	{
		cout << "You can't decrement(total must be 0-100).\n";
	}
}
//all capabilites
void setAll(capability* capabilitiesP)
{
	short filter;
	cout << "Set all capabilities to(0-100): ";
	cin >> filter;

	if ((filter >= 0) && (filter <= 100))
	{
		capabilitiesP->level = filter;
		capabilitiesP->strength = filter;
		capabilitiesP->agility = filter;
		capabilitiesP->speed = filter;
		cout << "Your capabilities now are:\n";
		cout << "-Level\t\t" << capabilitiesP->level << " \n";
		cout << "-Strength\t" << capabilitiesP->strength << " \n";
		cout << "-Agility\t" << capabilitiesP->agility << " \n";
		cout << "-Speed\t\t" << capabilitiesP->speed << " \n";
	}
	else
	{
		cout << "You can't set this number (try 0-100).\n";
	}
}
void incAll(capability* capabilitiesP)
{
	short filter;
	cout << "Increment by(Max total 100): ";
	cin >> filter;

	if (((filter + capabilitiesP->level) >= 0) && ((filter + capabilitiesP->level) <= 100) && ((filter + capabilitiesP->strength) >= 0) && ((filter + capabilitiesP->strength) <= 100) && ((filter + capabilitiesP->agility) >= 0) && ((filter + capabilitiesP->agility) <= 100) && ((filter + capabilitiesP->speed) >= 0) && ((filter + capabilitiesP->speed) <= 100))
	{
		capabilitiesP->level += filter;
		capabilitiesP->strength += filter;
		capabilitiesP->agility += filter;
		capabilitiesP->speed += filter;
		cout << "Your capabilities now are:\n";
		cout << "-Level\t\t" << capabilitiesP->level << " \n";
		cout << "-Strength\t" << capabilitiesP->strength << " \n";
		cout << "-Agility\t" << capabilitiesP->agility << " \n";
		cout << "-Speed\t\t" << capabilitiesP->speed << " \n";
	}
	else
	{
		cout << "You can't increment(One or more capabilies are out 0-100).\n";
	}
}
void decAll(capability* capabilitiesP)
{
	short filter;
	cout << "Decrement by(Max total 100): ";
	cin >> filter;

	if (((capabilitiesP->level - filter) >= 0) && ((capabilitiesP->level - filter) <= 100) && ((capabilitiesP->strength - filter) >= 0) && ((capabilitiesP->strength - filter) <= 100) && ((capabilitiesP->agility - filter) >= 0) && ((capabilitiesP->agility - filter) <= 100) && ((capabilitiesP->speed - filter) >= 0) && ((capabilitiesP->speed - filter) <= 100))
	{
		capabilitiesP->level -= filter;
		capabilitiesP->strength -= filter;
		capabilitiesP->agility -= filter;
		capabilitiesP->speed -= filter;
		cout << "Your capabilities now are:\n";
		cout << "-Level\t\t" << capabilitiesP->level << " \n";
		cout << "-Strength\t" << capabilitiesP->strength << " \n";
		cout << "-Agility\t" << capabilitiesP->agility << " \n";
		cout << "-Speed\t\t" << capabilitiesP->speed << " \n";
	}
	else
	{
		cout << "You can't decrement(One or more capabilies are out 0-100).\n";
	}
}
