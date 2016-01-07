#include "mod.h"

CGameControllerMOD::CGameControllerMOD(class CGameContext *pGameServer)
: IGameController(pGameServer)
{
	// Exchange this to a string that identifies your game mode.
	// DM, TDM and CTF are reserved for teeworlds original modes.
	m_pGameType = "MOD";
}

CGameControllerMOD::OnEntity(int Index, vec2 Pos)
{
	int Type = -1;

	switch(Index)
	{
		case ENTITY_SPAWN:
			m_aaSpawnPoints[0][m_aNumSpawnPoints[0]++] = Pos;
			break;
		case ENTITY_SPAWN_RED:
			m_aaSpawnPoints[1][m_aNumSpawnPoints[1]++] = Pos;
			break;
		case ENTITY_SPAWN_BLUE:
			m_aaSpawnPoints[2][m_aNumSpawnPoints[2]++] = Pos;
			break;
		case ENTITY_ARMOR_1:
		case ENTITY_HEALTH_1:
		case ENTITY_WEAPON_SHOTGUN:
		case ENTITY_WEAPON_GRENADE:
		case ENTITY_WEAPON_LASER:
		case ENTITY_POWERUP_NINJA:
			new CMod_Entity_Target(&GameServer()->m_World, Pos);
			return true;
	}

	return false;
}
