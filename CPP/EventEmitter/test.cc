#include "EventEmitter.hh"
#include <iostream>
#include <functional>
#include <future>
#include <random>
#include <chrono>
#include <thread>

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
    typedef pattern::EventEmitter<SwitchEvent> Emitter;
    const Emitter listner;
    listner.subscribe(std::move(Emitter::use_member(&Controller::track, this)));
}

private:

int _count = 0;

void track(const SwitchEvent& event) {
    if(event.get_state()) {
        _count++;
        std::cout << "count: " << _count << std::endl;
    }
}

};

int main(void) {
    Controller ctrl;
    View v {false};
    std::random_device rnd_dev;
    std::mt19937 gen(rnd_dev());
    int times = ((gen() % 5) + 2) * 3;
    for(int i = 0; i < times * 5; ++i) {
        std::async(std::launch::async, [&v, times] {
            for(int k = 0; k < times / 2; ++k) {
                v.togle();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        });
    }

    return 0;
}
