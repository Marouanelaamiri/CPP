/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:58:03 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/17 15:20:53 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void testSubject()
{
	std::cout << "--- Test 1: Subject Main ---" << std::endl;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());  // Source now owns this "new Ice"
	src->learnMateria(new Cure()); // Source now owns this "new Cure"

	ICharacter *me = new Character("me");

	// Create CLONES from the source
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp); // "me" now owns this clone

	tmp = src->createMateria("cure");
	me->equip(tmp); // "me" now owns this clone

	ICharacter *bob = new Character("bob");

	// Use the materias
	me->use(0, *bob); // Should be ice
	me->use(1, *bob); // Should be cure

	// Destructors are called here.
	delete bob; // Bob is deleted
	delete me;	// "me" is deleted, which deletes its 2 equipped materias
	delete src; // "src" is deleted, which deletes its 2 learned templates

	std::cout << "------------------------------\n"
			  << std::endl;
}

/*
	Test 2: Inventory limits and edge cases.
	- Try to equip 5 materias.
	- Try to equip a NULL materia.
	- Try to use invalid slots.
*/

void testInventory()
{
	std::cout << "--- Test 2: Inventory & Limits ---" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice()); // takes slot 0

	ICharacter *hero = new Character("Hero");
	ICharacter *enemy = new Character("Enemy");

	// --- Fill the inventory ---
	std::cout << "\n[Equipping 4 materias...]" << std::endl;

	hero->equip(src->createMateria("ice")); // slot 0
	hero->equip(src->createMateria("ice")); // slot 1
	hero->equip(src->createMateria("ice")); // slot 2
	hero->equip(src->createMateria("ice")); // slot 3

	// --- Try to equip a 5th ---
	std::cout << "\n[Trying to equip 5th materia...]" << std::endl;
	
	AMateria *extra = src->createMateria("ice"); // we need to create it first so we save its pointer
	hero->equip(extra); // Should say "Inventory full"
	delete extra;      // 'hero' didn't take ownership, so we delete 'extra'
	
	// --- Try to equip NULL (from a failed creation) ---
	std::cout << "\n[Trying to equip NULL materia...]" << std::endl;
	hero->equip(src->createMateria("fire")); // returns NULL , and a <type> not found message
	// No delete needed, it's already NULL

	// --- Test using invalid slots ---
	std::cout << "\n[Using invalid slots...]" << std::endl;
	hero->use(-1, *enemy); // Should say "Invalid index"
	hero->use(4, *enemy);  // Should say "Invalid index"
	hero->use(10, *enemy); // Should say "Invalid index"

	// Cleanup
	delete hero;
	delete enemy;
	delete src;
	std::cout << "----------------------------------\n"
			  << std::endl;
}

/*
	Test 3: The unequip() function and memory leaks.
	This is the one you *really* have to get right.
	'unequip' means the Character gives up ownership.
	The pointer is now YOUR problem.
*/
void testUnequip()
{
	std::cout << "--- Test 3: Unequip & Memory Leaks ---" << std::endl;
	
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	ICharacter *hero = new Character("Hero");
	ICharacter *enemy = new Character("Enemy");

	AMateria *ice = src->createMateria("ice");

	hero->equip(ice); // slot 0
	hero->use(0, *enemy);

	std::cout << "\n[Unequipping slot 0...]" << std::endl;
	
	hero->unequip(0); // 'hero' no longer owns 'ice'. It's now a "floating" pointer.

	std::cout << "[Using slot 0 after unequip...]" << std::endl;
	hero->use(0, *enemy); // Should say "No materia to use"

	std::cout << "[Manually deleting unequipped materia...]" << std::endl;
	delete ice; // u have to delete it manually , its droped by hero , but not cleand 

	delete hero;
	delete enemy;
	delete src;
	std::cout << "--------------------------------------\n"
			  << std::endl;
}

/*
	 Test 4: Deep Copy (Copy Constructor & Assignment)
	 This proves you didn't just copy pointers (shallow copy).
	 We make a copy, delete the original, and prove the copy still works.
*/
void testDeepCopy()
{
	std::cout << "--- Test 4: Deep Copy (Segfault Test) ---" << std::endl;
	
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());
	ICharacter *enemy = new Character("Enemy");

	// --- 1. Test Copy Constructor ---
	std::cout << "\n[Testing Copy Constructor...]" << std::endl;
	Character *original = new Character("Original");
	original->equip(src->createMateria("cure")); // slot 0

	// This calls the Copy Constructor
	Character *copy = new Character(*original);
	copy->use(0, *enemy); // Should say "heals..."

	std::cout << "[Deleting ORIGINAL character...]" << std::endl;
	delete original; // This deletes 'original' AND its inventory[0]

	std::cout << "[Using COPY after original is deleted...]" << std::endl;
	// If this was a shallow copy, 'copy->inventory[0]' would be a
	// dangling pointer and this would SEGFAULT.
	copy->use(0, *enemy); // Still works! "heals..."
	std::cout << "(Copy works. Copy constructor is deep.)" << std::endl;

	// --- 2. Test Assignment Operator ---
	std::cout << "\n[Testing Assignment Operator...]" << std::endl;
	Character *charA = new Character("A");
	charA->equip(src->createMateria("cure"));
	Character *charB = new Character("B");

	// This calls the Assignment Operator
	*charB = *charA;

	std::cout << "[Deleting character A...]" << std::endl;
	delete charA;

	std::cout << "[Using character B after A is deleted...]" << std::endl;
	charB->use(0, *enemy); // Still works! "heals..."
	std::cout << "(Copy works. Assignment operator is deep.)" << std::endl;

	// Cleanup
	delete copy;
	delete charB;
	delete enemy;
	delete src;
	std::cout << "-----------------------------------------\n"
			  << std::endl;
}

/*
	- Test 5: MateriaSource limits
	- Try to learn 5 materias.
	- Try to create an unknown materia.
*/
void testMateriaSource()
{
	std::cout << "--- Test 5: MateriaSource Limits ---" << std::endl;
	IMateriaSource *src = new MateriaSource();

	std::cout << "\n[Learning 4 materias...]" << std::endl;
	src->learnMateria(new Ice());  // slot 0
	src->learnMateria(new Cure()); // slot 1
	src->learnMateria(new Ice());  // slot 2
	src->learnMateria(new Cure()); // slot 3

	std::cout << "\n[Trying to learn 5th materia...]" << std::endl;
	AMateria *extra = new Cure();
	src->learnMateria(extra); // Should say "MateriaSource is full"

	// 'src' didn't take ownership, so we delete 'extra'
	delete extra;

	std::cout << "\n[Trying to create unknown materia...]" << std::endl;
	AMateria *unknown = src->createMateria("fireball"); // Should say "not found"
	// 'unknown' is NULL here, no delete needed.
	(void)unknown;

	delete src;
	std::cout << "------------------------------------\n"
			  << std::endl;
}

void testDoubleEquipCrash()
{
    std::cout << "--- Test: Double Equip (CRASH) ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    ICharacter* hero = new Character("Hero");

    AMateria* myIce = src->createMateria("ice");

    hero->equip(myIce); // inventory[0] points to myIce
    hero->equip(myIce); // inventory[1] ALSO points to myIce

    delete hero; 
    // 1. Hero destructor deletes inventory[0] (myIce is destroyed).
    // 2. Hero destructor deletes inventory[1] (myIce is ALREADY destroyed).
    // 3. BOOM. Double Free corruption.
}

int main()
{
	// Run all the tests, one by one.
	testSubject();
	testInventory();
	testUnequip();
	testDeepCopy();
	testMateriaSource();
	testDoubleEquipCrash(); // Uncommenting this will likely crash due to double free.

	// You can run 'leaks ./Materia' to check for memory leaks.
	// If you see "All heap blocks were freed", you did it right.
	return 0;
}