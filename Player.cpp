#include "Player.h"

namespace Logic
{
	Player::Player() : active(false) {};

	Player::~Player() = default;

	void Player::SetActive(bool Iactive)
	{
		active = Iactive;
	};

	bool Player::GetActive()
	{
		return active;
	};

	void Player::ChangeActive()
	{
		active = !active;
	};
}