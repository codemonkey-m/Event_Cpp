#pragma once
#include <string>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

template<typename _type, typename _param>
class Event
{
public:
	Event(){}
	~Event(){}

	void emit(_type&& name, _param&& tp) {
		for (auto it = m_mapEvent.lower_bound(name); it != m_mapEvent.upper_bound(name); ++it) {
			it->second(tp);
		}
	}

	void on(_type&& name, function<void(_param)>&& callback) {
		m_mapEvent.insert(make_pair(name, callback));
	}

private:
	multimap<_type, function<void(_param)>> m_mapEvent;
};

