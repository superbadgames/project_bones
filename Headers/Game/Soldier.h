#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/GameObject.h>
#include <Engine/Timer.h>
#include <Engine/ErrorManager.h>
#include <Engine/AABB.h>
//Remove later
#include <Engine/Controller.h>

namespace KE = KillerEngine;
namespace KM = KillerMath;
namespace KC = KillerCollisions;

#include <Game/Projectile.h>

class Soldier : public KE::GameObject
{
public:
//==========================================================================================================================
//
//Constructors	 	
//
//==========================================================================================================================
	Soldier(void);

	~Soldier(void);

//==========================================================================================================================
//
//Virtual Functions
//
//==========================================================================================================================
	void v_Update(void) final;

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
	inline void Damage(U32 dmg=1)
	{
		_hp -= dmg;
	}

	inline void Heal(U32 health=1)
	{
		_hp += health;
	}

	void Fire(p_Projectile projectile);

	inline void Move(F32 xVal)
	{
		_position[x] += xVal * _speed * KM::Timer::Instance()->DeltaTime();
	}

//==========================================================================================================================
//
//Accessors
//
//==========================================================================================================================
	inline U32 GetHP(void) const
	{
		return _hp;
	}

	inline void SetSpeed(F32 speed)
	{
		if(speed < 0.0f)
		{
			KE::ErrorManager::Instance()->SetError(KE::APPLICATION, "Soldier::SetSpeed: Attempted to set speed less than 0");
			return;
		}

		_speed = speed; 
	}

	inline void SetFireRate(F32 rate)
	{
		_fireRate = rate;
	}

	inline ProjectileType GetActiveFireType(void) const
	{
		return _activeFireType;
	}

	inline void SetActiveFireType(ProjectileType type)
	{
		_activeFireType = type;
	}

private:
	bool	 _canFire;
	U32 	 _hp;
	F32 	 _speed;
	F32 	 _fireRate;
	F32		 _lastFire;
	KC::AABB _boundingBox;
	ProjectileType _activeFireType;

};//end Class

typedef shared_ptr<Soldier> p_Soldier;
