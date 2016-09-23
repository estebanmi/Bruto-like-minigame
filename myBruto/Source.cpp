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

//functions

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



int main()
{
	char* name = new char[10];

	unsigned short disciples = 0;
	unsigned short* disciplesPointer = &disciples;

	char* clanName = new char[20];
	capability capabilites;

	char weaponName[20];
	unsigned short weapons = 0;
	unsigned short animals = 0;
	bool registered = 0;

	setName(name);
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
	weapons = getNumWeapons(weapons);
	cout << "Total weapons: " << weapons << endl;

	cout << "Name of weapon(bitwise " << weapons << ")? ";

	cout << weapons << endl;
	cin >> weaponName;
	setWeapon(weaponName, &weapons);
	weapons = getNumWeapons(weapons);
	cout << "Total weapons: " << weapons << endl;

	
	//setWeapon(weaponName,&weapons);
	//hasWeapon(weaponName,weapons);


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
		if ((*weapons & 0x0100) >> 8)
		{
			cout << "You have " << weaponName << " already.\n";
		}
		else
		{
			*weapons = *weapons | 0x0100;
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
void hasWeapon(char* weaponName, unsigned int* weapons)
{

}