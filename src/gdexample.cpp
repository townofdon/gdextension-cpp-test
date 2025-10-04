#include "gdexample.h"
#include "constants.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
    ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDExample::set_amplitude);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDExample::set_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}

GDExample::GDExample() {
    // Initialize any variables here.
    time_passed = 0.0;
    amplitude = 10.0;
    speed = 1.0;
}

GDExample::~GDExample() {
    // Add your cleanup here.
}

// use template, function pointer, and compile-time recursion to iterate over a tuple
template<size_t I = 0, typename... Tp>
void iterate_tuple(std::tuple<Tp...> t, void (*Func) (int val)) {
    // std::cout << std::get<I>(t) << " ";
    Func(std::get<I>(t));
    if constexpr(I+1 != sizeof...(Tp)) {
        iterate_tuple<I+1>(t, Func);
    }
}

void print_int(int val) {
    UtilityFunctions::print(val);
}

void GDExample::_process(double delta) {
    time_passed += speed * delta;

    Vector2 new_position = Vector2(
        amplitude + (amplitude * sin(time_passed * 2.0)),
        amplitude + (amplitude * cos(time_passed * 1.5))
    );

    time_emit += delta;
    if (time_emit > 1.0) {
        for (size_t i = 0; i < sizeof(ARRAY_TEST) / sizeof(ARRAY_TEST[0]); i++)
        {
            UtilityFunctions::print(ARRAY_TEST[i]);
        }

        iterate_tuple(TUPLE_TEST, print_int);

        for (size_t i = 0; i < 5; i++)
        {
            iterate_tuple(ARRAY_TUPLE_TEST[i], print_int);
        }

        emit_signal("position_changed", this, new_position);
        time_emit = 0.0;
    }

    set_position(new_position);
}

void GDExample::set_amplitude(const double p_amplitude) {
    amplitude = p_amplitude;
}

double GDExample::get_amplitude() const {
    return amplitude;
}

void GDExample::set_speed(const double p_speed) {
    speed = p_speed;
}

double GDExample::get_speed() const {
    return speed;
}
