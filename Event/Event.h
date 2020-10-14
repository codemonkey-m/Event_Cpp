#pragma once
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

template<typename _type, typename... _param>
class Event
{
public:
	Event(){}
	~Event(){}

	//右值
	void emit(_type&& name, const _param&& ...tp) {
		auto vec = m_mapEvent.find(name);
		if (vec == m_mapEvent.end())
			return;

		for (auto& it : vec->second)
			it(tp...);
	}

	//左值
	void emit(_type&& name, const _param& ...tp) {
		auto vec = m_mapEvent.find(name);
		if (vec == m_mapEvent.end())
			return;

		for (auto& it : vec->second)
			it(tp...);
	}

	void on(_type&& name, function<void(const _param&...)>&& callback) {
		m_mapEvent[name].push_back(callback);
	}

private:
	unordered_map<_type, vector<function<void(const _param&...)> > > m_mapEvent;
};

