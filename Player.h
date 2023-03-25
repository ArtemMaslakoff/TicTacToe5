#ifndef PLAYER_H
#define PLAYER_H


namespace Logic
{
	class Player
	{
	private:
		bool active;
	public:
		Player();

		~Player();

		void SetActive(bool Iactive);

		bool GetActive();

		void ChangeActive();
	};
}



#endif /* PLAYER_H */