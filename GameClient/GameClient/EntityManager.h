#pragma once
class CEntity;

class CEntityManager
{
	std::vector<std::unique_ptr<CEntity>> _gameObjs;
	std::unordered_map<int32, CEntity*> _groupedObjs;
public:
	template<class T,typename... Arg>
	T& CreateEntity(Arg&&...);
	void Init() {};
	void Clear() {};
	void Reset() {};
	void Update()
	{
		for (auto& i : _gameObjs) i->Update();
	};
	void Render(sf::RenderWindow& gameWindow) 
	{ 
		for (auto& i : _gameObjs) i->Render(gameWindow); 
	};
};

template<class T, typename ...Arg>
inline T& CEntityManager::CreateEntity(Arg&& ... args)
{
	static_assert(std::is_base_of<CEntity, T>::value);
	auto uObjPtr{ std::make_unique<T>(std::forward<Arg...>(args)) };
	auto hashValue{typeid(T).hash_code()};
	auto rawPtr = uObjPtr.get();
	_groupedObjs[hashValue] = rawPtr;
	_gameObjs.emplace_back(std::move(uObjPtr));
	return *rawPtr;
}
