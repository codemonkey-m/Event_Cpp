#pragma once
#include <string>
#include <functional>
#include <map>
#include <tuple>
#include <iostream>
using namespace std;

template<typename _type, typename _param>
class Event
{
public:
	Event(){}
	~Event(){}

	//ÓÒÖµ
	void emit(_type&& name, const _param&& tp) {
		for (auto it = m_mapEvent.lower_bound(name); it != m_mapEvent.upper_bound(name); ++it) {
			it->second(tp);
		}
	}

	//×óÖµ
	void emit(_type&& name, const _param& tp) {
		for (auto it = m_mapEvent.lower_bound(name); it != m_mapEvent.upper_bound(name); ++it) {
			it->second(tp);
		}
	}

	void on(_type&& name, function<void(const _param&)>&& callback) {
		m_mapEvent.insert(make_pair(name, callback));
	}

private:
	multimap<_type, function<void(const _param&)>> m_mapEvent;
};

