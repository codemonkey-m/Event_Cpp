#pragma once
#include <string>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

template<typename name_type, typename _param>
class Event
{
public:
	Event(){}
	~Event(){}

	void emit(name_type&& name, _param&& tp) {
		for (auto it = m_mapEvent.lower_bound(name); it != m_mapEvent.upper_bound(name); ++it) {
			it->second(tp);
		}
	}

	void on(name_type&& name, std::function<void(_param)>&& callback) {
		m_mapEvent.insert(make_pair(name, callback));
	}

private:
	multimap<name_type, std::function<void(_param)>> m_mapEvent;
};

