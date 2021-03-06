#ifndef ROBOT_H
#define ROBOT_H

#include "shared.h"
#include "object.h"

class Robot : public Object
{
public:
	Robot();
	void Serialize(bool write, Serializer & data, Serializer * old = 0);
	void Tick(World & world);
	void HandleHit(World & world, Uint8 x, Uint8 y, Object & projectile);
	bool ImplantVirus(Uint16 teamid);
	Uint8 damaging;
	Sint16 originalx;
	Sint16 originaly;
	bool patrol;
	Uint16 virusplanter;
	
private:
	bool Look(World & world, Uint8 direction = 0);
	void StopAmbience(void);
	void Melee(Object & object, World & world);
	enum {NEW, SLEEPING, ASLEEP, AWAKENING, WALKING, SHOOTING, DYING, DEAD};
	Uint8 state;
	Uint8 state_i;
	Uint16 maxhealth;
	Uint16 maxshield;
	Uint8 respawnseconds;
	Uint8 shootcooldown;
	int soundchannel;
};

#endif