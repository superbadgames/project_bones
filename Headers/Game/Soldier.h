#pragma once

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/GameObject.h>
#include <Engine/Timer.h>
#include <Engine/ErrorManager.h>
#include <Engine/AABB.h>
#include <Engine/AudioManager.h>
#include <Engine/AudioSource.h>
#include <Engine/GameWindow.h>
#include <Engine/LevelManager.h>

namespace KE = KillerEngine;
namespace KM = KillerMath;
namespace KC = KillerCollisions;

#include <Game/I_Actor.h>
#include <Game/Projectile.h>
#include <Game/HealthBar.h>

#include <vector>

typedef std::vector<p_HealthBar> HealthList;

class Soldier : public I_Actor
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

	void v_Damage(S32 dmg = 1) final;

	void v_Heal(S32 heal=1) final;

	void v_Reset(void);

//==========================================================================================================================
//
//Functions
//
//==========================================================================================================================
	void OnCollision(void);
	
	void Fire(p_Projectile projectile);

	inline void Move(F32 xVal)
	{
		//Consider stagger for player. May need another timer....
		AddScaledPosition(KM::Vector3(xVal, 0.0f), _speed * KM::Timer::Instance()->DeltaTime());
		//Need a better clip
		//_walkAudio.Play();
	}

//==========================================================================================================================
//
//Accessors
//
//==========================================================================================================================
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

	inline void AddHealthBar(HealthList bar)
	{
		_healthBar = bar;
	}

private:
	bool	 _canFire;
	bool	 _tookDamage;
	F32 	 _speed;
	F32 	 _fireRate;
	F32		 _lastFire;
	F32		 _lastDamaged;
	F32		 _immune;
	ProjectileType _activeFireType;
	KE::AudioSource _damageAudio;
	KE::AudioSource _deathAudio;
	KE::AudioSource _defaultFireAudio;
	KE::AudioSource _walkAudio;
	HealthList		_healthBar;

};//end Class

typedef shared_ptr<Soldier> p_Soldier;
