#pragma once
#include <functional>
#include <unordered_map>
using namespace std;

template<typename _type, typename... _param>
class Event
{
public:
	Event(){}
	~Event(){}

	void dispatch(_type name, const _param ...tp) {
		auto _list = m_mapEvent.equal_range(name);
		for (auto& it = _list.first; it != _list.second; ++it)
			it->second(tp...);
	}

	//ÓÒÖµ
	void emit(_type&& name, const _param&& ...tp) {
		dispatch(name, tp...);
	}

	//×óÖµ
	void emit(_type&& name, const _param& ...tp) {
		dispatch(name, tp...);
	}

	void on(_type&& name, function<void(const _param&...)>&& callback) {
		m_mapEvent.insert(make_pair(name, callback));
	}

private:
	unordered_multimap<_type, function<void(const _param&...)> > m_mapEvent;
};

