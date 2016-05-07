#ifndef _EVENT_EMITTER_HH
#define _EVENT_EMITTER_HH

#include <vector>
#include <functional>

namespace pattern {

template<class T>
class EventEmitter {

public:

EventEmitter() = default;

void subscribe(const std::function<void(const T&)>& listener) const {
    listeners.push_back(listener);
}

void emit(const T& event) const {
    notify(event);
}

template<class U>
static  std::function<void(const T&)> use_member(void (U::* member) (const T&), U* calle) {
    return std::bind(member, calle, std::placeholders::_1);
}

private:

static std::vector<std::function<void(const T&)>> listeners;

static void notify(const T& event) {
    for(std::function<void(const T&)>& listener : listeners) {
        listener(event);
    }
}

};

template<class T>
std::vector<std::function<void(const T&)>> EventEmitter<T>::listeners;

}

#endif
