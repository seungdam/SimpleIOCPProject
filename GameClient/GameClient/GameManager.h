#pragma once
class CGameManager;

struct GameManagerDeleter
{
	void operator()(CGameManager*) {};
};

class CGameManager : public CSingleton<CGameManager, GameManagerDeleter>
{
	enum class GameState { Paused, Running };
	enum class GameScene { Title, Game, Menu };

	GameScene _gs{ GameScene::Title };
	std::stack<GameScene> _curScenes;
	sf::RenderWindow _winGame{{constants::window_width, constants::window_height },"Game Client 1.0"};
public:
	CGameManager() {};
	void InitGame() {};
	void ResetGame() {};
	void Update() {};
	void Render() {};
	~CGameManager() = default;
};

