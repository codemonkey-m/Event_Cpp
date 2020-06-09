#pragma once
#include <string>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

template<typename _tuple>
class Event
{
public:
	Event(){}
	~Event(){}

	void emit(string name, _tuple tp) {
		for (auto it = m_mapEvent.lower_bound(name); it != m_mapEvent.upper_bound(name); ++it) {
			it->second(tp);
		}
	}

	void on(string name, std::function<void(_tuple)> callback) {
		m_mapEvent.insert(make_pair(name, callback));
	}

private:
	multimap<string, std::function<void(_tuple)>> m_mapEvent;
};

