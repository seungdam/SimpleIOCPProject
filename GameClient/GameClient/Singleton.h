#pragma once

template<class T, class Deleter>
class CSingleton
{
public:
	static std::unique_ptr<T, Deleter>& getInstance()
	{
		std::call_once(_flag, []() {
			SingletonClass<T>::_uinst.reset(new T);
			char name[256] = { 0 };
			sprintf_s(name, "%s Instantiated\n", typeid(T).name());
			});
		return _uinst;
	}
	CSingleton() = default;
	virtual ~CSingleton() = default;
	// ���� �����ڿ� ���� �����ڴ� ������� ���ϵ��� ����
	CSingleton(const CSingleton&) = delete; 
	CSingleton(CSingleton&&) noexcept = delete; 
	CSingleton& operator=(const CSingleton&) = delete;
	CSingleton& operator=(CSingleton&&) noexcept = delete;
private:
	static std::once_flag _flag;
	static std::unique_ptr<T, Deleter> _uinst;
};

