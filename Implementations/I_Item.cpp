#include <Game/I_Item.h>

//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
I_Item::I_Item(void)
	:
	_maxTimeAlive(10.0f),
	_timeAlive(0.0f),
	_type(),
	_boundingBox()
{
	GameObject::MakeSprite();
}

I_Item::~I_Item(void)
{  }

//==========================================================================================================================
//
//Virtual Functions
//
//==========================================================================================================================
void I_Item::v_Update(void)
{
	_timeAlive += KM::Timer::Instance()->DeltaTime();

	if(_timeAlive >= _maxTimeAlive)
	{
		SetActive(false);
	}
}

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
void I_Item::CollisionCheck(const KC::AABB& other)
{

}