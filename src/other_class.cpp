#include "other_class.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void OtherClass::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_word"), &OtherClass::get_word);
    ClassDB::bind_method(D_METHOD("set_word", "p_word"), &OtherClass::set_word);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "word"), "set_word", "get_word");

    ClassDB::bind_method(D_METHOD("get_val"), &OtherClass::get_val);
    ClassDB::bind_method(D_METHOD("set_val", "p_val"), &OtherClass::set_val);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "val"), "set_val", "get_val");

    ADD_SIGNAL(MethodInfo("on_changed"));
}

OtherClass::OtherClass() {
    // Initialize any variables here.
    word="world";
    val=1;
}

OtherClass::~OtherClass() {
    // Add your cleanup here.
}


void OtherClass::set_word(const String p_word) {
    word = p_word;
    emit_signal("on_changed");
}

String OtherClass::get_word() const {
    return word;
}

void OtherClass::set_val(const int p_val) {
    val = p_val;
    emit_signal("on_changed");
}

int OtherClass::get_val() const {
    return val;
}
