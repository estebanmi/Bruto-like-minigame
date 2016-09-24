#include <iostream>
#include <string.h>


using namespace std;

struct capability
{
	unsigned short* level = 0;
	unsigned short lifeUnits = 100;
	unsigned short* strUnits = 0;
	unsigned short* agiUnits = 0;
	unsigned short* speedUnits = 0;
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

	/*setName(name);
	getName(name);
	printName(name);

	setDisciples(&disciples);
	getDisciples(disciples);
	printDisciples(disciples);

	setClanName(clanName);  
	getClanName(clanName);
	printClanName(clanName);

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
	
	printAvailableWeapons(weapons);*/
	
	////////////////////////////////////////

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
void setClanName(char* clanName)
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
unsigned short getNumWeapons(unsigned short weapons)
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
void setWeapon(char* weaponName, unsigned short* weapons)
{
	///////////SWORD///////////
	if (strcmp(weaponName,"Sword") == 0)
	{
		if ((*weapons & 0x1000) >> 8)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x1000;
		}
	}


	///////////KNIFE///////////
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