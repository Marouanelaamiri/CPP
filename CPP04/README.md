
Each Family Has:

The "contract" (the Base Class / Interface): An Abstract Class That's Just A "to-do List. " It Has No Real Code, Just Pure Virtual Functions (= 0). Its Job Is To Define What Needs To Be Done. 

The "worker" (the Derived Class): A Concrete Class That Inherits The "to-do List" And Actually Does The Work. Its Job Is To Provide The Implementation. 

## 1. The "spell" Family
The Contract (base): Amateria

The Workers (derived): Ice And Cure

Inheritance
Ice Is-a Amateria. Cure Is-a Amateria. 

Jobs
Amateria's Job (the Contract):

To Be The Generic "spell" Type. 

To Force Every Spell That Inherits From It To Have Two Functions:

Use(icharacter& Target): A (virtual) Function To Perform The Spell's Action. 

Clone() Const = 0: A Pure Virtual Function. This Is The Prototype Pattern. Its Job Is To Guarantee That Every Real Spell Knows How To Make A Copy Of Itself. 

It's "abstract," So You Can't Create A Plain Amateria Object. 

Ice / Cure's Job (the Workers):

To Be Actual, Usable Spells. 

Ice's Job Is To Implement Use() By Printing "* Shoots An Ice Bolt. . . *". 

Cure's Job Is To Implement Use() By Printing "* Heals . . . Wounds *". 

Both Of Their Jobs Are To Implement Clone() By Returning A New Copy Of Themselves (e. G. , Return New Ice(*this);). 

## 2. The "user" Family
The Contract (base): Icharacter

The Worker (derived): Character

Inheritance
Character Is-a Icharacter. 

Jobs
Icharacter's Job (the Contract):

To Be The Generic "user" Type. It's A Pure Interface. 

Its Job Is To Guarantee That Any Class That Wants To Be A "character" (a Player, A Monster, Etc. ) Must Have These Four Functions: Getname, Equip, Unequip, And Use. 

Character's Job (the Worker):

To Be The Actual, Usable Character. 

Its Main Job Is To Manage The Amateria* Inventory[4]. 

It Implements Equip By Finding An Empty Slot. 

It Implements Unequip By Setting A Slot To Null. 

It Implements Use By Calling The Use() Function On The Spell In The Correct Slot. 

Its Most Important Job Is Memory Management. It Must Perform A Deep Copy In Its Copy Constructor/assignment Operator (by Cloneing Spells) And Delete All Spells In Its Inventory When It Dies (destructor). 

## 3. The "factory" Family
The Contract (base): Imateriasource

The Worker (derived): Materiasource

Inheritance
Materiasource Is-a Imateriasource. 

Jobs
Imateriasource's Job (the Contract):

To Be The Generic "spell Factory" Type. It's A Pure Interface. 

Its Job Is To Guarantee That Any "source" Must Have A Way To Learnmateria (templates) And Createmateria (by Name). 

Materiasource's Job (the Worker):

To Be The Actual Factory. 

Learnmateria's Job Is To Store "prototype" Spells (the Templates Like New Ice()) In Its Materiaslots[4] Array. 

Createmateria's Job Is To Find The Prototype By Type String (e. G. , "ice") And Then Use The Prototype Pattern: It Tells That Prototype To Clone() Itself, Returning A Brand New Ice Object For The Character To Use. 
