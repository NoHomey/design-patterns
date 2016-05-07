#include "EventEmitter.hh"
#include <iostream>
#include <functional>
#include <future>
#include <random>
#include <algorithm>

class SwitchEvent {

public:

SwitchEvent(const bool&  state) : _state(state) {}

const bool get_state(void) const {
    return _state;
}

private:
const bool _state;

};

class View {

public:

View(const bool& state): _state(state), _emitter() {}

void togle() {
    _state = !_state;
    _emitter.emit({_state});
}

private:

bool _state;
const pattern::EventEmitter<SwitchEvent> _emitter;

};

class Controller {

public:

Controller() {
    const pattern::EventEmitter<SwitchEvent> listner;
    listner.subscribe(std::move(std::bind(&Controller::track, this, std::placeholders::_1)));
}

private:

int _count = 0;

void track(const SwitchEvent& event) {
    if(event.get_state()) {
        this->_count++;
        std::cout << "count: " << this->_count << std::endl;
    }
}

};

int main(void) {
    Controller ctrl;
    View v {false};
    std::random_device rnd_dev;
	std::mt19937 generator(rnd_dev());
    v.togle();
    v.togle();
    v.togle();
    /*std::async(std::launch::async, [v]() {

    });*/

    return 0;
}
