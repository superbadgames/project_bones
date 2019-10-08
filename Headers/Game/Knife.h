#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>

//===== Game Includes =====
#include <Game/I_Item.h>



class Knife : public I_Item
{
public:
//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
	Knife(void);

	~Knife(void);

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
	void v_PickupAction(p_Soldier actor) final;

private:
	U32 _dmg;
	F32 _effectActive;

};//end Class
typedef shared_ptr<Knife> p_Knife;
